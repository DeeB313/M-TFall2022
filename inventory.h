#ifndef INVENTORY_H
#define INVENTORY_H
#include "game.h"

//possibly do this with some sort of list, like linked list/array/vector

//possible doubly linked list implementation
struct Node
{
    //these will store our individual game information
    int quantity = 0; //initial quantity is always 0
    int itemID = -1; //itemID should only be positive, so when changing it make sure to make it a positive number
    double price = 0.00; //price starts at 0
    Game game;

    Node *next;
    Node *prev;
};

class Inventory
{
private:
    Node *head;
    Node *tail;

public:



    Inventory();


    bool checkAvailable(string &item); //Checks if an item is available in the inventory(if there is more than one item of that name)

    void addItem(string &item, int &amount); //Adds an item to the inventory

    void removeItem(string &item, int &amount); //Removes item from the inventory

    void display(Inventory &inventory); //Displays all the items in the inventory

};

#endif // INVENTORY_H