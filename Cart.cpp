#include "Cart.h"
#include "User.h"
#include "Inventory.h"
#include "game.h"
#include "Tokenizer.h"
#include <iostream>
using std::istream;
using std::stringstream;
using std::string;

Cart::Cart()
{
	username = "empty";
	itemID = 0;
	cartID = 1;
	quantity = 0;
}

bool Cart::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

inline bool Cart::exist(const std::string& name) ///
{
	ifstream file(name);
	if (!file)            // If the file was not found, then file is 0, i.e. !file=1 or true.
		return false;    // The file was not found.
	else                 // If the file was found, then file is non-0.
		return true;     // The file was found.
}

void Cart::createCart() ///
{
	string cartname = username + ".txt";
	ofstream file1;
	if (exist(cartname) == true)
	{
		cout << "Cart history for user " << username << " exists" << endl;
	}
	else
	{
		file1.open(cartname);
		cartID += 1;
		cout << "Cart history does not exist. New cart created." << endl;
	}
}

void Cart::login(User* user) ///
{
	bool ex = true;
	string username, password;


	while (ex)
	{
		cout << "Enter your username: ";
		cin >> username;
		this->username = username;

		if (user->username == this->username)
		{
			cout << "Enter your password: ";
			cin >> password;
			this->password = password;

			if (user->password == this->password)
			{
				cout << "logged in" << endl;
				createCart();
				ex = false;
			}
			else
			{
				cout << "wrong password" << endl;
			}
		}
		else
		{
			cout << "wrong username" << endl;
		}

	}
}
void Cart::logout() ///
{
	string confirm;

	cin >> confirm;
	if (confirm == "confirm")
	{
		this->username = "";
		this->password = "";
		cout << "You are logged out." << endl;
	}
}//logs out of current user

void Cart::checkout(User* user, Cart* cart)
{
	logout();
}//checks out, item gets annihilated, money gets stolen

void Cart::addItem(Inventory inventory, string& item, int quantity)
{
	//inventory.checkAvailable(item);
	Tokenizer tkn;
	string a1, b1, c1;
	ifstream file2;
	string line1;
	string line2;
	file2.open(username + ".txt");
	if (file2.is_open())
	{
		getline(file2, line1);
		if (line1 == "")
		{
			ofstream file1(username + ".txt", std::ios_base::app | std::ios_base::out);
			if (file1.is_open())
			{
				file1 << cartID;
				file1 << " ";
				file1 << item + " ";
				file1 << quantity;
				file1 << "\n";
				cout << "new item added" << endl;
				file1.close();
			}
		}
		else
		{
			file2.clear();
			file2.seekg(0);
			while (getline(file2, line2))
			{
				tkn.setString(line2);
				tkn.readWord(a1);
				tkn.readWord(b1);
				tkn.readWord(c1);
				if (b1 == item)
				{
					ofstream file1("dummy.txt", std::ios_base::app | std::ios_base::out);
					if (file1.is_open())
					{
							int num = stoi(c1);
							num += quantity;
							file1 << cartID;
							file1 << " ";
							file1 << item + " ";
							file1 << num;
							file1 << "\n";
							cout << "previous item updated" << endl;
							file1.close();

							string line2;
							ifstream file1("dummy.txt");
							ofstream file2(username + ".txt");

							getline(file1, line2);
							file2 << line2;

							file1.close();

							ofstream test("dummy.txt", std::ios_base::out | std::ios_base::trunc);
							test.close();

							inventory.removeItem(item, quantity);
					}
				}
				else
				{
					ofstream file1(username + ".txt", std::ios_base::app | std::ios_base::out);
					if (file1.is_open())
					{
						file1 << "\n";
						file1 << cartID;
						file1 << " ";
						file1 << item + " ";
						file1 << quantity;
						file1 << "\n";
						cout << "new item added" << endl;
						file1.close();
					}
				}
			}	
		}
	}
}

void Cart::removeItem(Inventory inventory, string& item, int quantity)
{
	Tokenizer tkn;
	ifstream file1;
	string line1;
	string line2;
	string a1, b1, c1;
	file1.open(username + ".txt", std::ios_base::app || std::ios_base::out);
	if (file1.is_open())
	{
		getline(file1, line1);
		if (line1 == "")
		{
			cout << "The cart is empty. There is no item to remove in the cart." << endl;
		}
		else
		{
			file1.clear();
			file1.seekg(0);
			while (getline(file1, line2))
			{
				tkn.setString(line2);
				tkn.readWord(a1);
				tkn.readWord(b1);
				tkn.readWord(c1);
				if (b1 != item)
				{
					ofstream file1("dummy.txt", std::ios_base::app | std::ios_base::out);
					if (file1.is_open())
					{
						file1 << a1 + " ";
						file1 << b1 + " ";
						file1 << c1 + "\n";
					}
				}
				else if (b1 == item)
				{
					int num = stoi(c1);
					if (num >= quantity && quantity > 0)
					{
						num -= quantity;
					}
					else
					{
						num = 0;
					}

					ofstream file2("dummy.txt", std::ios_base::app | std::ios_base::out);
					if (file2.is_open())
					{
						file2 << cartID;
						file2 << " ";
						file2 << item + " ";
						file2 << num;
						file2 << "\n";
						cout << quantity + " item deleted." << num << " number of said item is left in the cart" << endl;
						file2.close();
					}
				}
			}
		}
		string line3;
		ifstream file2("dummy.txt");
		ofstream file1(username + ".txt");

		while (getline(file2, line3))
		{
			file1 << line3;
			file1 << "\n";
		}

		file1.close();

		ofstream test("dummy.txt", std::ios_base::out | std::ios_base::trunc);
		test.close();

		inventory.addItem(item, quantity);
	}
}
//removes item from cart

void Cart::displayCart() ///
{
	Tokenizer tkn;
	string name, cartid, itemid, quantit;
	ifstream cartfile;
	cartfile.open(username + ".txt");
	if (cartfile.is_open())
	{
		std::cout << "---Currently whats in the cart: ---" << endl;
		string line;
		while (getline(cartfile, line))
		{
			tkn.setString(line);
			tkn.readWord(cartid);
			tkn.readWord(itemid);
			tkn.readWord(quantit);
			cout << "CartID: " << cartid << "		";
			cout << "Item: " << itemid << "		";
			cout << "Quantity: " << quantit << endl;

		}
	}
}//displays cart contents
