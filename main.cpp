#include <iostream>
#include <fstream>
#include "user.h"
#include "cart.h"
#include "inventory.h"
#include "game.h"
#include <vector>

using namespace std;

//work in progress, but the idea is to load files in the beginning using load, and save whenever we change anything using save
void loadData(vector<User>& users, Inventory& inventory); //, vector <Cart> carts, Inventory inventory
void saveData(vector<User>& users, Inventory& inventory);

int main()
{
    //choice
    string choice;

    //list for the carts and users
    vector<User> users;
    vector<Cart> carts;

    //the inventory
    Inventory inventory;


    //flag for login
    int loginFlag = 0;

    //username
    string username;

    //the current user
    User user;


    //loads data, if no data returns and continues
    loadData(users, inventory);

    cout << "Welcome to the Store!" << endl;
    while (1)
    {
        //if logged in
        if (loginFlag > 0)
        {
            while (1)
            {
                //menu
                cout << "View Inventory" << endl;
                cout << "View Cart" << endl;
                cout << "View Account" << endl;
                cout << "Exit" << endl;
                cout << ">> ";

                //input
                cin >> choice;

                //inventory options
                if (choice == "inventory")
                {
                    while (1)
                    {

                        if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                        {
                            cout << "Check for available items." << endl;
                            cout << "Display full iventory." << endl;
                            cout << "Add item." << endl;
                            cout << "Remove item." << endl;
                            cout << "Exit." << endl;

                            cin >> choice;
                        }
                        else
                        {
                            cout << "Check for available items." << endl;
                            cout << "Display full inventory." << endl;
                            cout << "Exit." << endl;

                            cin >> choice;
                        }

                        if (choice == "check")
                        {
                            inventory.checkAvailable(item);
                        }

                        if (choice == "display")
                        {
                            inventory.display(inventory);
                        }

                        if (choice == "add")
                        {
                            cout << "What item would you like to add?" << endl;


                            inventory.addItem(name, amount);
                        }

                        if (choice == "remove")
                        {
                            cout << "What item would you like to remove?" << endl;

                            inventory.removeItem(item, amount)
                        }

                        if (choice == "exit")
                        {
                            break;
                        }

                    }
                    

                }

                //cart options
                if (choice == "cart")
                {

                }

                //account options
                if (choice == "account")
                {
                    while (1)
                    {
                        user.display();
                        //menu
                        cout << "Edit account" << endl;
                        cout << "View order history" << endl;
                        cout << "Exit" << endl;
                        cout << ">> ";

                        //input
                        cin >> choice;

                        //account edit
                        if (choice == "edit")
                        {
                            user.updateinfo();
                            saveData(users, inventory);
                        }

                        //view history
                        if (choice == "history")
                        {

                        }

                        //exit
                        if (choice == "exit")
                        {
                            break;
                        }
                    }

                }

                //exit
                if (choice == "exit")
                {
                    saveData(users, inventory);
                    loginFlag -= 1;
                    break;
                }

                //error
                else
                {
                    cout << "..." << endl;
                }
            }
        }

        //input
        cout << ">> ";
        cin >> choice;
        if (choice == "login")
        {
            while (1)
            {
                //menu
                cout << "1. Enter account information: " << endl;
                cout << "2. Create account" << endl;
                cout << "3. Exit" << endl;
                cout << ">> ";
                cin >> choice;

                //login
                if (choice == "1")
                {
                    //login goes here
                    loginFlag += 1;
                }

                //if the user enters 2, prompts account creation
                if (choice == "2")
                {
                    std::cout << "Please enter a username: ";
                    std::cin >> username;
                    for (int i = 0; i < users.size(); i++)
                    {
                        if (username == users[i].username)
                        {
                            cout << "The name already exists!" << endl;
                            break;
                        }
                    }
                    //makes a new user
                    User newuser;

                    newuser.createUser(username);
                    users.push_back(newuser);

                    //sets the current user as the last user in the vector(most recent user)
                    user = users.back();
                    cout << user.username << " has logged in." << endl;

                    //saves data to file
                    saveData(users);

                    //updates loginFlag and goes to log in menu
                    loginFlag += 1;
                    break;
                }

                //exits login/account creation menu
                if (choice == "3")
                {
                    break;
                }
            }

        }
        if (choice == "exit")
        {
            saveData(users);
            break;
        }

        if (choice == "3")
        {
            if (!users.empty())
            {
                cout << " you have stuff";
            }
            else
            {
                cout << "you have nothing";
            }
            for (int i = 0; i < users.size(); i++)
            {
                users[i].display();
                cout << endl;
            }

        }

        else
        {
            cout << "..." << endl;
        }
    }
}



//work in progress
void loadData(vector<User>& users)
{
    //initializing things to be read from file
    string username, password, email, address, storeToken;

    //infile
    ifstream infile;

    //opens users.txt
    infile.open("users.txt");

    //if file doesn't exist, ends the load
    if (!infile.is_open())
    {
        infile.close();
        return;
    }

    //initializing User object
    User temp;

    //loop to set users in the file
    while (getline(infile, username), getline(infile, password), getline(infile, email), getline(infile, address), getline(infile, storeToken))
    {
        //converts the string input into an int
        int tempToken = stoi(storeToken);

        //sets User
        temp.setUser(username, password, email, address, tempToken);

        //adds User object to users vector
        users.push_back(temp);
    }

    //closes file
    infile.close();


    //insert other file loading here
}

//work in progress
void saveData(vector<User>& users, Inventory& inventory)
{
    //outfile
    ofstream outfile;

    //opens or creates users.txt in write mode
    outfile.open("users.txt");

    //loops and writes the user information into the file
    for (int i = 0; i < users.size(); i++)
    {
        //writes the user data into users.txt
        outfile << users[i].username << std::endl;
        outfile << users[i].password << std::endl;
        outfile << users[i].email << std::endl;
        outfile << users[i].address << std::endl;
        outfile << users[i].storeToken << std::endl;
    }

    //closes the file
    outfile.close();

    inventory.save();
}


