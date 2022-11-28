#include "Cart.h"
#include "User.h"
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

void Cart::login(User *user) //login
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
void Cart::logout()
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

void Cart::checkout(Cart& cart)
{

}//checks out, item gets annihilated, money gets stolen

void Cart::addItem()
{

}//adds item to cart

void Cart::removeItem()
{
	string deleteline;
	string line;
	ifstream fin;
	fin.open("cart.txt");
	ofstream tmp;
	tmp.open("tmp.txt");
	cout << "What item would you like to remove?" << endl;
	cin >> deleteline;

	while (getline(fin, line))
	{
		line.replace(line.find(deleteline), deleteline.length(), " ");
		tmp << line << endl;
	}

	tmp.close();
	fin.close();
}//removes item from cart

void Cart::displayCart(Cart *cart)
{
	Tokenizer tkn;
	string name, cartid, itemid, quantit;
	fstream cartfile;
	cartfile.open("cart.txt");
	if (cartfile.is_open())
	{
		string line;
		while (getline(cartfile, line))
		{
			tkn.setString(line);
			tkn.readWord(name);
			if (name == cart->username)
			{
				tkn.readWord(cartid);
				tkn.readWord(itemid);
				tkn.readWord(quantit);
				cout << "Name: " << name << endl;;
				cout << "CartID: " << cartid << endl;
				cout << "ItemID: " << itemid << endl;
				cout << "Quantity: " << quantit << endl;
			}

		}
	}

}//displays cart contents

