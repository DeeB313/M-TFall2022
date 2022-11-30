#include <iostream>
#include <fstream>
#include "user.h"
#include "cart.h"
#include "inventory.h"
#include "game.h"
#include <vector>

using namespace std;

//work in progress, but the idea is to load files in the beginning using load, and save whenever we change anything using save
void loadData(vector<User>& users, Inventory& inventory, vector<Game>& games); //, vector <Cart> carts, Inventory inventory
void saveData(vector<User>& users, Inventory& inventory, Cart& cart);

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

    cout << "Welcome to the Store!" << endl;
    while (1)
    {
        if (loginFlag < 0)
        {
            break;
        }
        //if logged in
        if (loginFlag > 0)
        {
            while (1)
            {
                //menu
                cout << "1. View Inventory" << endl;
                cout << "2. View Cart" << endl;
                cout << "3. View Account" << endl;
                if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                {
                    cout << "2213. Game Management" << endl;
                }
                cout << "4. Logout" << endl;
                cout << ">> ";

                //input
                cin >> choice;

                //inventory options
                if (choice == "inventory" || choice == "1")
                {
                    while (1)
                    {
                        int admin = 0;
                        //menu
                        if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                        {
                            admin = 1;
                            cout << "1. Check for Available Items" << endl;
                            cout << "2. Display Inventory" << endl;
                            cout << "3. Add Item" << endl;
                            cout << "4. Remove Item" << endl;
                            cout << "5. Return" << endl;
                            cout << ">> ";

                            cin >> choice;
                        }

                        //menu for non admins
                        else
                        {
                            cout << "1. Check for Available Items" << endl;
                            cout << "2. Display Inventory" << endl;
                            cout << "3. Return" << endl;
                            cout << ">> ";

                            cin >> choice;
                        }

                        //checks item availability
                        if (choice == "check" || choice == "1")
                        {
                            string item;
                            cout << "Enter the name of the item: ";
                            cin >> item;
                            inventory.checkAvailable(item);
                        }

                        //displays inventory
                        else if (choice == "display" || choice == "2")
                        {
                            cout << "Inventory: " << endl;
                            inventory.display(inventory);
                        }

                        //adds item
                        else if ((admin == 1 && choice == "add") || (choice == "3" && admin == 1))
                        {
                            string name;
                            int amount;
                            cout << "Games: " << endl << endl;
                            for (int i = 0; i < games.size(); i++)
                            {
                                games[i].display();
                            }
                            cout << "What game would you like to add: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "How much?" << endl;
                            cin >> amount;
                            inventory.addItem(name, amount);
                        }

                        //removes item
                        else if ((admin == 1 && choice == "remove") ||(choice == "4" && admin == 1))
                        {
                            string item;
                            int amount;
                            inventory.display(inventory);
                            cout << "What item would you like to remove: ";
                            getline(cin, item);
                            cout << "How much?" << endl;
                            cin >> amount;
                            inventory.removeItem(item, amount);
                        }

                        //exits
                        else if (choice == "return" || choice == "5")
                        {
                            saveData(users, inventory, cart);
                            break;
                        }

                        else
                        {
                            cout << "Error. Please try again." << endl;
                            cout << endl;
                        }
                    }
                }

                //cart options
                if (choice == "cart" || choice == "2")
                {
                    while (1)
                    {
                        cout << "1. View Cart" << endl;
                        cout << "2. Checkout" << endl;
                        cout << "3. View Order History" << endl;
                        cout << "4. Add to Cart" << endl;
                        cout << "5. Remove from Cart" << endl;
                        cout << "6. Return" << endl;
                        cout << ">> ";

                        cin >> choice;

                        if (choice == "view" || choice == "1")
                        {
                            cout << "Cart: " << endl;
                            cart.displayCart();
                        }

                        else if (choice == "checkout" || choice == "2")
                        {
                            cart.checkout(user, cart, inventory);
                        }

                        else if (choice == "history" || choice == "3")
                        {
                            int flag = 1;
                            ifstream infile;
                            infile.open(user.username + "history.txt");
                            if (!infile.is_open())
                            {
                                cout << "You haven't purchased anything." << endl;
                                //closes the file
                                infile.close();
                                //decrements flag so the section doesn't run
                                flag -= 1;
                            }

                            //if file opens, then outputs history
                            if (flag == 1)
                            {
                                string name, quantity, price;
                                while (getline(infile, name), getline(infile, quantity), getline(infile, price))
                                {
                                    cout << name << endl;
                                    cout << quantity << endl;
                                    cout << price << endl;
                                    cout << endl;
                                }
                            }
                        }

                        else if (choice == "add" || choice == "4")
                        {
                            int flag = 0;
                            string item;
                            int quantity;
                            while (1)
                            {
                                if (flag == 1)
                                {
                                    break;
                                }
                                inventory.display(inventory);
                                cout << "What item would you like to add?" << endl;
                                cin.ignore();
                                getline(cin, item);
                                for (int i = 0; i < games.size(); i++)
                                {
                                    if (item == games[i].name)
                                    {
                                        flag = 1;
                                        break;
                                    }
                                }
                            }
                            cout << "How many of this item?" << endl;
                            cin >> quantity;
                            cart.addItem(inventory, item, quantity);
                            cart.save();
                        }

                        else if (choice == "remove" || choice == "5")
                        {
                            string item;
                            int quantity;
                            cart.displayCart();
                            cout << "What item would you like to remove?" << endl;
                            cin.ignore();
                            getline(cin, item);
                            cout << "How many of this item?" << endl;
                            cin >> quantity;
                            cart.removeItem(inventory, item, quantity);
                        }

                        else if (choice == "return" || choice == "6")
                        {
                            saveData(users, inventory, cart);
                            break;
                        }

                        else
                        {
                            cout << "Error. Please try again" << endl;
                            cout << endl;
                        }
                    }
                }

                //account options
                if (choice == "account" || choice == "3")
                {
                    while (1)
                    {
                        user.display();
                        //menu
                        cout << "1. Edit Account" << endl;
                        cout << "2. Delete Account" << endl;
                        cout << "3. Return" << endl;
                        cout << ">> ";

                        //input
                        cin >> choice;

                        //account edit
                        if (choice == "edit" || choice == "1")
                        {
                            user.updateinfo();
                            saveData(users, inventory, cart);
                        }

                        else if (choice == "delete" || choice == "2")
                        {
                            for(int i = 0; i < users.size(); i++)
                            {
                                if(user.username == users[i].username)
                                {
                                    users.erase(users.begin()+ i);
                                    
                                    //opens the user files in write mode then closes them, effectively deleting them
                                    ofstream outfile;
                                    outfile.open(user.username + "txt");
                                    outfile.close();
                                    outfile.open(user.username + "history.txt");
                                    outfile.close();
                                    
                                    saveData(users, inventory, cart);
                                            
                                }
                            }
                            
                            string filename = user.username + ".txt";
                            remove(filename.c_str());
                            cout << "Account deleted..." << endl;
                        }

                        //exit
                        else if (choice == "exit" || choice == "3")
                        {
                            saveData(users, inventory, cart);
                            break;
                        }

                        else
                        {
                            cout << "Error. Please try again." << endl;
                            cout << endl;
                        }
                    }
                }

                if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                {
                    if (choice == "game" || choice == "2213")
                    {
                        while (1)
                        {
                            cout << "1. List Games" << endl;
                            cout << "2. Create Game" << endl;
                            cout << "3. Edit Game" << endl;
                            cout << ">> " << endl;

                            cin >> choice;

                            //lists games
                            if (choice == "list" || choice == "1")
                            {
                                for (int i = 0; i < games.size(); i++)
                                {
                                    games[i].display();
                                }
                            }

                            else if (choice == "create" || choice == "2")
                            {
                                cin.ignore();
                                Game game;
                                string name, genre, developer, publisher, release, temprat;
                                int rating;
                                cout << "Name: ";
                                getline(cin, name);
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
                            else if (choice == "edit" || choice == "3")
                            {
                                int flag = 0;
                                string name;
                                cout << "What game do you want to edit?";
                                cin >> name;
                                for (int i = 0; i < games.size(); i++)
                                {
                                    if (name == games[i].name)
                                    {
                                        games[i].editGame();
                                        cout << "Game edited. Please completely exit and reload the program for changes to take effect." << endl;
                                        flag += 1000000;
                                    }
                                }

                                if (flag < 0)
                                {
                                    cout << "Game not found." << endl;
                                }
                            }

                            else if (choice == "exit")
                            {
                                saveData(users, inventory, cart);
                                break;
                            }

                            else
                            {
                                cout << "Error. Please try again" << endl;
                                cout << endl;
                            }
                        }
                    }
                }

                //exit
                else if (choice == "logout" || choice == "4")
                {
                    User newuser;
                    saveData(users, inventory, cart);
                    cart.logout();
                    user = newuser;
                    loginFlag -= 1;
                    break;
                }

                //error
                else
                {
                    cout << "Error. Please try again" << endl;
                    cout << endl;
                }
            }
        }


        //if the user hasn't logged in
        if (loginFlag == 0)
        {
            while (loginFlag == 0)
            {
                //menu
                cout << "1. Login" << endl;
                cout << "2. Create Account" << endl;
                cout << "0. Exit" << endl;
                cout << ">> ";
                cin >> choice;

                //login
                if (choice == "login" || choice == "1")
                {
                    while (1)
                    {
                        int flag = 0;
                        cout << "Enter username: ";
                        cin >> username;
                        for (int i = 0; i < users.size(); i++)
                        {
                            if (username == users[i].username)
                            {
                                user = users[i];
                                cart.login(user, cart, inventory);
                                flag += 1;
                                cout << endl;
                            }
                        }

                        if (flag > 0)
                        {
                            break;
                        }
                    }


                    //login goes here
                    loginFlag = 1;
                }

                //if the user enters 2, prompts account creation
                else if (choice == "create" || choice == "2")
                {
                    while (1)
                    {
                        int flag = 0;
                        cout << "Please enter a username: ";
                        cin >> username;
                        for (int i = 0; i < users.size(); i++)
                        {
                            if (username == users[i].username)
                            {
                                cout << "That name already exists!" << endl;
                                flag -= 1;
                            }
                        }

                        if (flag == 0)
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
                    saveData(users, inventory, cart);

                    //updates loginFlag and goes to log in menu
                    loginFlag += 1;
                    break;
                }

                //exits login/account creation menu
                else if (choice == "exit" || choice == "0")
                {
                    loginFlag -= 10000;
                    break;
                }

                else
                {
                    cout << "Error. Please try again" << endl;
                    cout << endl;
                }
            }
        }
    }
}



//work in progress
void loadData(vector<User>& users, Inventory& inventory, vector<Game>& games)
{
    int flag = 1;
    //initializing things to be read from file
    string username, password, email, address, storeToken;

    //infile
    ifstream infile;

    //opens users.txt
    infile.open("users.txt");

    //if file doesn't open, then the user section does not run
    if (!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the user file section doesn't run
        flag -= 1;
    }

    //runs if the users file is opened
    if (flag == 1)
    {
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
    }

    //new initializers for inventory file
    string name, tempquant;

    infile.open("inventory.txt");

    //if the file doesn't open, then the inventory section will not run
    if (!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the inventory file section doesn't run
        flag -= 1;
    }


    //runs if the inventory file opens
    if (flag == 1)
    {
        while (getline(infile, name), getline(infile, tempquant))
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
    if (!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the section doesn't run
        flag -= 1;
    }

    //runs if the inventory file opens
    if (flag == 1)
    {
        Game temp;

        //none doesn't do anything except eat up the quantity value
        while (getline(infile, filename), getline(infile, none))
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
void saveData(vector<User>& users, Inventory& inventory, Cart& cart)
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

    //saves inventory
    inventory.save();

    //saves cart
    cart.save();
}
