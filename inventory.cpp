#include "inventory.h"
//#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::ofstream;
using std::ifstream;
using namespace std;


inventory::inventory(){};

//default constructor
inventory::inventory(string item, double price, int quantity, int itemID)
{
	
	this->item = item;
	this->price = price;
	this->quantity = quantity;
	this->itemID = itemID;
	this->admin = false;
}

//adds item to inventory
void inventory::addItem()
{

	string name;
	double price;
	int itemID, quantity;

	ofstream outfile;

	//if (username == "Justin" || username == "Marc" || username == "Dee" || username == "Brian")
	//{
		outfile.open("inventory.txt");

		//adds item name
		cout << "Please enter item name." << endl;
		cin >> name;
		outfile << "Item name: " << name << endl;

		//adds item price
		cout << "Please enter item price." << endl;
		cin >> price;
		outfile << "Item price: " << price << endl;

		//adds item quantity
		cout << "Please enter item quantity." << endl;
		cin >> quantity;
		outfile << "Item quantity: " << quantity << endl;

		//adds item ID
		cout << "Please enter item ID." << endl;
		cin >> itemID;
		outfile << "Item ID: " << itemID << endl;
	//}
	//else
	//{
		//cout << "This command requires admin access!" << endl;
	//}
}

//removes item from inventory
/*void inventory::removeItem()
{
	
}*/

//checks an item to see if it is available
void inventory::checkAvailable()
{
	string search;
	cout << "What are you looking for?" << endl;
	cin >> search;
	ifstream infile;
	string line;

	infile.open("inventory.txt");

	size_t pos;
	while (infile.good())
	{
		getline(infile, line);
		pos = line.find(search);
		if (pos != string::npos)
		{
			cout << "The item is in stock." << endl;
			break;
		}
		else 
		{
			cout << "The item is not available." << endl;
			break;
		}
	}
	
}

//displays items in inventory
void inventory::display()
{
	string items;


	ifstream infile("inventory.txt");

	//displays all content from the text file
	if (infile.is_open())
	{
		while (getline(infile, items))
		{
			cout << items << endl;
		}
		infile.close();
	}

}

//checks for admin
bool inventory::checkAdmin()
{
	if (this->admin == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}