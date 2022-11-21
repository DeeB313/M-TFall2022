#include <iostream>
#include <fstream>
#include "user.h"
#include "cart.h"
#include "inventory.h"
#include "game.h"
#include <vector>

using namespace std;

//work in progress, but the idea is to load files in the beginning using load, and save whenever we change anything using save
void loadData(vector<User> users); //, vector <Cart> carts, Inventory inventory
void saveData();

int main()
{
    //loadData();

    //choice
    string choice;

    //list for the carts and users, might combine into a single vector later, but right now its fine
    vector<User> users;
    vector<Cart> carts;

    //inventory
    Inventory inventory;

    //flag for login
    int loginFlag = 0;

    //username
    string username;

    //the current user
    User user;

    loadData(users);

    cout << "Welcome to the Store!" << endl;
    while(1)
    {
        //if logged in
        if(loginFlag > 0)
        {
            while(1)
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
                if(choice == "inventory")
                {

                }

                //cart options
                if(choice == "cart")
                {

                }

                //account options
                if(choice == "account")
                {
                    while(1)
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
                        if(choice == "edit")
                        {
                            user.updateinfo();
                        }

                        //view history
                        if(choice == "history")
                        {

                        }

                        //exit
                        if(choice == "exit")
                        {
                            break;
                        }
                    }

                }

                //exit
                if(choice == "exit")
                {
                    saveData();
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
        if(choice == "login")
        {
            while(1)
            {
                //menu
                cout << "1. Enter account information: " << endl;
                cout << "2. Create account" << endl;
                cout << "3. Exit" << endl;
                cout << ">> ";
                cin >> choice;

                //login
                if(choice == "1")
                {
                    //login goes here
                    loginFlag += 1;
                }

                //if the user enters 2, prompts account creation
                if(choice == "2")
                {
                    std::cout << "Please enter a username: ";
                    std::cin >> username;
                    for(int i =0; i < users.size(); i++)
                    {
                        if(username == users[i].username)
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

                    //updates user file
                    ofstream outfile;
                    //appends user data
                    outfile.open("users.txt", ios::app);
                    //everything but admin is appended
                    outfile << endl << users.back().username << " " << users.back().password << " " << users.back().email << " " << users.back().address << " " << users.back().storeToken;
                    //updates loginFlag and goes to log in menu
                    loginFlag += 1;
                    break;
                }

                //exits login/account creation menu
                if(choice == "3")
                {
                    break;
                }
            }

        }
        if(choice == "exit")
        {
            saveData();
            break;
        }

        if(choice == "3")
        {
            for(int i = 0; i < users.size(); i++)
            {
                users[i].display();
            }
        }

        else
        {
            cout << "..." << endl;
        }
    }
}



//work in progress
void loadData(vector<User> users)
{
    //initializing things to be read from file
    string username, password, email, address;
    int storeToken;
    ifstream infile;

    //opens users file
    infile.open("users.txt");


    //initializing User object
    User temp;

    //loop to set users in the file
    while(infile >> username >> password >> email >> address >> storeToken)
    {
        //sets User
        temp.setUser(username, password, email, address, storeToken);

        //adds User object to users vector
        users.push_back(temp);
    }

    infile.close();
}

//work in progress
void saveData()
{
    cout << "yay" << endl;
}
