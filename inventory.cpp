#include "inventory.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;

Inventory::Inventory()
{
    head = nullptr;
    tail = nullptr;
}

Inventory::~Inventory()
{
    //desconstructor, loops and deletes every node
    Node *temp = head;
    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    tail = nullptr;
}

bool Inventory::checkAvailable(string &item) //Checks if an item is available in the inventory(if there is more than one item of that name)
{
    Node *temp = head;

    //if list is empty tells the user
    if(head == nullptr)
    {
        std::cout << "The inventory is empty." << std::endl;
    }

    //while temp isn't null loops and checks if there is 1 or more of an item left
    while(temp != nullptr)
    {
        if(temp->game.name == item)
        {
            //if there is more than 0
            if(temp->quantity > 0)
            {
                //different outputs for grammar
                if(temp->quantity == 1)
                {
                    std::cout << "There is " << temp->quantity << " remaining." << std::endl;
                    return true;
                }
                else
                {
                    std::cout << "There are " << temp->quantity << " remaining." << std::endl;
                    return true;
                }
            }
        }
        //goes to the next node
        temp = temp->next;
    }

    //if item wasn't found or if the quantity was 0, return false
    std::cout << "This item is not available." << std::endl;
    return false;
}

void Inventory::addItem(string &name, int &amount) //Adds an item to the inventory
{
    //this code chunk creates the game object
    Game addgame;
    //filename
    string filename = "";

    //creates the game using fileGame
    addgame.fileGame(name + ".txt");

    //creates new node with the inserted character as data
    Node *item = new Node;
    item->game = addgame;

    //sets temp equal to head
    Node *temp = head;

    //if head is empty, sets head to added Character, next and prev to null, and tail equal to head
    if(head == nullptr)
    {
        head = item;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        head->quantity += amount;

        //sets price
        if(item->game.developer == "Ubisoft")
        {
            head->price = 50;
        }

        else if(item->game.developer == "Activision")
        {
            head->price = 60;
        }

        else if(item->game.developer == "Bungie")
        {
            head->price = 25;
        }

        else if(item->game.developer == "Nintendo")
        {
            head->price = 35;
        }

        else if(item->game.developer == "Square Enix")
        {
            head->price = 40;
        }

        else if(item->game.developer == "Capcom")
        {
            head->price = 55;
        }

        else if(item->game.developer == "Fromsoftware")
        {
            head->price = 60;
        }

        else if(item->game.developer == "Sony")
        {
            head->price = 60;
        }

        //static price of 25 for "unknown" developers
        else
        {
            head->price = 25;
        }

        return;
    }


    //loops while temp isn't null
    while(temp != nullptr)
    {
        //sets Game class insert and current equal to addedCharacter and temp
        Game insert = item->game;
        Game current = temp->game;

        //if the added item is earlier in the alphabet than temp
        if(insert.name < current.name)
        {
            //if temp is at the head
            if(temp == head)
            {
                //increments quantity
                item->quantity += amount;
                //sets the added item as the head of the list and ends the function
                item->next = head;
                item->prev = nullptr;
                head->prev = item;
                head = item;
                break;
            }


            //if temp is anything within the list
            else
            {
                item->quantity += 1;
                //puts the added item between temp and temp's previous node and ends the function
                temp->prev->next = item;
                item->prev = temp->prev;
                temp->prev = item;

                //if the next node isn't null
                if(item->next != nullptr)
                {
                    item->next = temp;
                    break;
                }
            }
        }

        //if the game is already in the list
        if(insert.name == current.name)
        {
           temp->quantity += amount;
           delete item;
           break;
        }

        //if the inserted item is bigger than temp, and if temp is at the tail/end
        else
        {
            //sets the added item as the tail of the list and ends the function
            if(temp == tail)
            {
                item->quantity += amount;
                tail->next = item;
                item->next = nullptr;
                item->prev = tail;
                tail = item;
                break;
            }
        }
        //goes to the next node
        temp = temp->next;
    }

    //sets price
    if(item->game.developer == "Ubisoft")
    {
        item->price = 50;
    }

    else if(item->game.developer == "Activision")
    {
        item->price = 60;
    }

    else if(item->game.developer == "Bungie")
    {
        item->price = 25;
    }

    else if(item->game.developer == "Nintendo")
    {
        item->price = 35;
    }

    else if(item->game.developer == "Square Enix")
    {
        item->price = 40;
    }

    else if(item->game.developer == "Capcom")
    {
        item->price = 55;
    }

    else if(item->game.developer == "Fromsoftware")
    {
        item->price = 60;
    }

    else if(item->game.developer == "Sony")
    {
        item->price = 60;
    }

    //static price of 25 for "unknown" developers
    else
    {
        item->price = 25;
    }
}

void Inventory::removeItem(string &item, int &amount) //Removes item from the inventory, doesn't actually erase it, just decrements the quantity
{
    //starts at head
    Node *temp = head;

    int flag = 0;
    //if list is empty tells the user
    if(head == nullptr)
    {
        std::cout << "The inventory is empty." << std::endl;
    }

    //while temp isn't null loops until the item is found
    while(temp != nullptr)
    {
        if(temp->game.name == item)
        {
            if(temp->quantity > 0)
            {
                if((temp->quantity - amount) < 0)
                {
                    std::cout << "You can't buy that much!" << std::endl;
                    std::cout << "Instead you got: " << temp->quantity << std::endl;
                    temp->quantity = 0;
                    flag += 1;
                }
                else
                {
                    temp->quantity = temp->quantity - amount;
                    flag += 1;
                }
            }
        }
        temp = temp->next;
    }

    if(flag == 0)
    {
        std::cout << "That item is not in the inventory." << std::endl;
        return;
    }
}

void Inventory::display(Inventory &inventory)//Displays all the items in the inventory
{
    //starts at head
    Node *temp = head;

    //if list is empty tells the user
    if(head == nullptr)
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    //while temp isn't null loops and prints out character stats
    while(temp != nullptr)
    {
        //displays information
        temp->game.display();
        std::cout << std::endl;

        //if the item is out of stock, outputs that, else output how much is left
        if(temp->quantity == 0)
        {
            std::cout << "This item is out of stock." << std::endl;
        }
        else
        {
            std::cout << "Quantity left: " << temp->quantity << std::endl;
        }
        std::cout << "Price: " << temp->price << std::endl << std::endl;
        temp = temp->next;
    }
}

void Inventory::save()
{
    //writes to outfile
    ofstream outfile;
    outfile.open("inventory.txt");
    string name, amount;

    //sets temp equal to head
    Node *temp = head;

    //if inventory hasn't been made, output that it's empty
    if(head == nullptr)
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    //loops and writes the game name and quantity into inventory.txt
    while(temp != nullptr)
    {
        outfile << temp->game.name << std::endl;
        outfile << temp->quantity << std::endl;
        temp = temp->next;
    }
}
