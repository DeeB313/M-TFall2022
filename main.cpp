#include <iostream>
#include <fstream>
#include "user.h"
#include "cart.h"
#include "inventory.h"
#include "game.h"
#include <vector>

using namespace std;

//work in progress, but the idea is to load files in the beginning using load, and save whenever we change anything using save
void loadData(vector<User> &users, Inventory &inventory, vector<Game> &games); //, vector <Cart> carts, Inventory inventory
void saveData(vector<User> &users, Inventory &inventory);

int main()
{
    //choice
    string choice;

    //username
    string username;

    //list for the games and users
    vector<User> users;
    vector<Game> games;

    //the inventory
    Inventory inventory;

    //the current user
    User user;

    //cart for current user
    Cart cart;


    //flag for login
    int loginFlag = 0;

    //loads data, if no data returns and continues
    loadData(users, inventory, games);


    //display to see if the load works
    //DELETE LATER JUSTIN
    for(int i = 0; i < users.size(); i++)
    {
        users[i].display();
    }

    for(int i = 0; i < games.size(); i++)
    {
        games[i].display();
    }

    inventory.display(inventory);

    cout << "Welcome to the Store!" << endl;
    while(1)
    {
        cout << ">> ";
        cin >> choice;
        //if logged in
        if(loginFlag > 0)
        {
            while(1)
            {
                //menu
                cout << "View Inventory" << endl;
                cout << "View Cart" << endl;
                cout << "View Account" << endl;
                if(user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                {
                    cout << "Game Management" << endl;
                }
                cout << "Exit" << endl;
                cout << ">> ";

                //input
                cin >> choice;

                //inventory options
                if(choice == "inventory")
                {
                    while (1)
                    {
                        if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                        {
                            cout << "Check for Available Items" << endl;
                            cout << "Display Inventory" << endl;
                            cout << "Add Item" << endl;
                            cout << "Remove Item" << endl;
                            cout << "Exit" << endl;
                            cout << ">> ";

                            cin >> choice;
                        }

                        else
                        {
                            cout << "Check for Available Items" << endl;
                            cout << "Display Inventory" << endl;
                            cout << "Exit" << endl;
                            cout << ">> ";

                            cin >> choice;
                        }

                        if (choice == "check")
                        {
                            string item;
                            cout << "Enter the name of the item: ";
                            cin >> item;
                            inventory.checkAvailable(item);
                        }

                        else if (choice == "display")
                        {
                            inventory.display(inventory);
                        }

                        else if (choice == "add")
                        {
                            string name;
                            int amount;
                            cout << "Games: " << endl << endl;
                            for(int i = 0; i<games.size(); i++)
                            {
                                games[i].display();
                            }
                            cout << "What game would you like to add: ";
                            cin >> name;
                            cout << "How much?" << endl;
                            cin >> amount;
                            inventory.addItem(name, amount);
                        }

                        else if (choice == "remove")
                        {
                            string item;
                            int amount;
                            inventory.display(inventory);
                            cout << "What item would you like to remove: ";
                            cin >> item;
                            cout << "How much?" << endl;
                            cin >> amount;
                            inventory.removeItem(item, amount);
                        }

                        else if (choice == "exit")
                        {
                            saveData(users, inventory);
                            break;
                        }

                        else
                        {
                            cout << "..." << endl;
                        }
                    }
                }

                //cart options
                if(choice == "cart")
                {
                    while(1)
                    {
                        cout << "View Cart" << endl;
                        cout << "View Order History" << endl;
                        cout << "Add to Cart" << endl;
                        cout << "Remove from Cart" << endl;
                        cout << "Exit" << endl;
                        cout << ">> ";

                        cin >> choice;

                        if(choice == "view")
                        {
                            //display cart
                        }

                        else if(choice == "history")
                        {
                            //display history file
                        }

                        else if(choice == "add")
                        {
                            string item;
                            int quantity;
                            while(1)
                            {
                                inventory.display(inventory);
                                cout << "What item would you like to add?" << endl;
                                cin >> item;
                                for(int i = 0; i<games.size(); i++)
                                {
                                    if(item==games[i].name)
                                    {
                                        break;
                                    }
                                }
                            }
                            cout << "How many of this item?" << endl;
                            cin >> quantity;
                            //additem in cart here


                        }

                        else if(choice == "remove")
                        {
                            string item;
                            int quantity;
                            //display cart here
                            while(1)
                            {
                                inventory.display(inventory);
                                cout << "What item would you like to remove?" << endl;
                                cin >> item;
                                //do some check here with the cart
                            }
                            cout << "How many of this item?" << endl;
                            cin >> quantity;

                            //removeitem in cart here
                        }

                        else if(choice == "exit")
                        {
                            saveData(users,inventory);
                            break;
                        }

                        else
                        {
                            cout << "..." << endl;
                        }
                    }
                }

                //account options
                if(choice == "account")
                {
                    while(1)
                    {
                        user.display();
                        //menu
                        cout << "Edit account" << endl;
                        cout << "Exit" << endl;
                        cout << ">> ";

                        //input
                        cin >> choice;

                        //account edit
                        if(choice == "edit")
                        {
                            user.updateinfo();
                            saveData(users, inventory);
                        }

                        //exit
                        else if(choice == "exit")
                        {
                            saveData(users, inventory);
                            break;
                        }

                        else
                        {
                            cout << "..." << endl;
                        }
                    }
                }

                if(user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                {
                    if(choice == "game")
                    {
                        while(1)
                        {
                            cout << "List Games" << endl;
                            cout << "Create Game" << endl;
                            cout << "Edit Game" << endl;
                            cout << ">> " << endl;

                            cin >> choice;

                            //lists games
                            if(choice == "list")
                            {
                                for(int i = 0; i < games.size(); i++)
                                {
                                    games[i].display();
                                }
                            }

                            else if(choice == "create")
                            {
                                cin.ignore();
                                Game game;
                                string name, genre, developer, publisher, release, temprat;
                                int rating;
                                cout << "Name: ";
                                getline(cin,name);
                                cout << "Genre: ";
                                getline(cin, genre);
                                cout << "Developer: ";
                                getline(cin, developer);
                                cout << "Publisher: ";
                                getline(cin, publisher);
                                cout << "Release: ";
                                getline(cin, release);
                                cout << "Rating: ";
                                getline(cin, temprat);
                                rating = stoi(temprat);
                                game.setGame(name, genre, developer, publisher, release, rating);
                                games.push_back(game);
                                cout << endl;

                            }
                            else if(choice == "edit")
                            {
                                int flag = 0;
                                string name;
                                cout << "What game do you want to edit?";
                                cin >> name;
                                for(int i = 0; i < games.size(); i++)
                                {
                                    if(name == games[i].name)
                                    {
                                        games[i].editGame();
                                        cout << "Game edited. Please completely exit and reload the program for changes to take effect." << endl;
                                        flag += 1000000;
                                    }
                                }

                                if(flag < 0)
                                {
                                    cout << "Game not found." << endl;
                                }
                            }

                            else if(choice == "exit")
                            {
                                saveData(users, inventory);
                                break;
                            }

                            else
                            {
                                cout << "..." << endl;
                            }
                        }
                    }
                }

                //exit
                if(choice == "exit")
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


        //if the user hasn't logged in
        if(choice == "login")
        {
            while(1)
            {
                //menu
                cout << "Login" << endl;
                cout << "Create Account" << endl;
                cout << "Exit" << endl;
                cout << ">> ";
                cin >> choice;

                //login
                if(choice == "login")
                {
                    //login goes here
                    loginFlag += 1;
                }

                //if the user enters 2, prompts account creation
                else if(choice == "create")
                {
                    while(1)
                    {
                        int flag = 0;
                        cout << "Please enter a username: ";
                        cin >> username;
                        for(int i =0; i < users.size(); i++)
                        {
                            if(username == users[i].username)
                            {
                                cout << "That name already exists!" << endl;
                                flag -= 1;
                            }
                        }

                        if(flag == 0)
                        {
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
                    saveData(users, inventory);

                    //updates loginFlag and goes to log in menu
                    loginFlag += 1;
                    break;
                }

                //exits login/account creation menu
                else if(choice == "exit")
                {
                    break;
                }
            }

        }

        //exits
        else if(choice == "exit")
        {
            saveData(users, inventory);
            break;
        }

        else
        {
            cout << "..." << endl;
        }
    }
}



//work in progress
void loadData(vector<User> &users, Inventory &inventory, vector<Game> &games)
{
    int flag = 1;
    //initializing things to be read from file
    string username, password, email, address, storeToken;

    //infile
    ifstream infile;

    //opens users.txt
    infile.open("users.txt");

    //if file doesn't open, then the user section does not run
    if(!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the user file section doesn't run
        flag -= 1;
    }

    //runs if the users file is opened
    if(flag == 1)
    {
        //initializing User object
        User temp;
        //loop to set users in the file
        while(getline(infile, username), getline(infile, password), getline(infile, email), getline(infile, address), getline(infile, storeToken))
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
    }

    //new initializers for inventory file
    string name, tempquant;

    infile.open("inventory.txt");

    //if the file doesn't open, then the inventory section will not run
    if(!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the inventory file section doesn't run
        flag -= 1;
    }


    //runs if the inventory file opens
    if(flag == 1)
    {
        while(getline(infile, name), getline(infile, tempquant))
        {
            //converts the string input into an int
            int quantity = stoi(tempquant);

            //adds item into inventory
            inventory.addItem(name, quantity);
        }
    }

    //closes the file
    infile.close();

    //Sets games
    string filename, none;

    infile.open("inventory.txt");

    //if the file doesn't open, then the section will not run
    if(!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the section doesn't run
        flag -= 1;
    }

    //runs if the inventory file opens
    if(flag == 1)
    {
        Game temp;

        //none doesn't do anything except eat up the quantity value
        while(getline(infile, filename), getline(infile, none))
        {
            //sets the filename
            filename = filename + ".txt";

            //sets the game and pushes it into the vector
            temp.fileGame(filename);
            games.push_back(temp);
        }
    }

    //closes the file
    infile.close();
}

//work in progress
void saveData(vector<User> &users, Inventory &inventory)
{
    //outfile
    ofstream outfile;

    //opens or creates users.txt in write mode
    outfile.open("users.txt");

    //loops and writes the user information into the file
    for(int i = 0; i < users.size(); i++)
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

    //saves inventory
    inventory.save();
}
