#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
using namespace std;

class inventory
{
private:

	//admin
	bool admin = false;

public:

	//initial values for inventory data
	string item = "";
	double price = 0;
	int quantity = 0;
	int itemID = 0;

	inventory();
	//constructor
	inventory(string item, double price, int quantity, int itemID);

	//adds item to file
	void addItem();

	//removes item from file
	//void removeItem();

	//checks for item in file
	void checkAvailable();

	//displays the file content
	void display();

	//checks to see if the user is an admin
	bool checkAdmin();
};

#endif