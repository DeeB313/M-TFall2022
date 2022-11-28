#include <iostream>
#include <fstream>
#include "user.h"
#include "cart.h"
#include "inventory.h"
#include "game.h"
#include <vector>

using namespace std;

//work in progress, but the idea is to load files in the beginning using load, and save whenever we change anything using save
void loadData(vector<User> &users, Inventory &inventory); //, vector <Cart> carts, Inventory inventory
void saveData(vector<User> &users, Inventory &inventory);

int main()
{
    //choice
    string choice;

    //list for the carts and users
    vector<User> users;
    vector<Cart> carts;
    vector<Game> games;
    
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
                    if (user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                    {
                    }

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
                            saveData(users, inventory);
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
                
                if(user.username == "Justin" || user.username == "Marc" || user.username == "Dee" || user.username == "Brian")
                {
                    if(choice == "game")
                    {
                        while(1)                   
                        {
                            cout << "Create Game" << endl;
                            cout << "Edit Game" << endl;
                            cout << ">> " << endl;
                            
                            cin >> choice;
                            if(choice == "create")
                            {
                                Game game;
                                string name, genre, developer, publisher, release, temprat;
                                int rating;
                                cout << "Name: " << endl;
                                getline(cin,name);
                                cout << "Genre: " << endl;
                                getline(cin, genre);
                                cout << "Developer: " << endl;
                                getline(cin, developer);
                                cout << "Publisher: " << endl;
                                getline(cin, publisher);
                                cout << "Release: " << endl;
                                getline(cin, release);
                                cout << "Rating: " << endl;
                                getline(cin, temprat);
                                rating = stoi(temprat);
                                game.setGame(name, genre, developer, publisher, release, rating);
                                games.push_back(game);
                                
                            }
                            if(choice == "edit")
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
                            
                            if(choice == "exit")
                            {
                                saveData(users, inventory);
                                break;
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

                    //saves data to file
                    saveData(users, inventory);

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
            saveData(users, inventory);
            break;
        }

        if(choice == "3")
        {
            if(!users.empty())
            {
                cout << " you have stuff";
            }
            else
            {
                cout << "you have nothing";
            }
            for(int i = 0; i < users.size(); i++)
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
void loadData(vector<User> &users, Inventory &inventory)
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
    
    /*
    insert cart stuff here
    */
    
    
    //new initializers for inventory file
    string name, tempquant;

    infile.open("inventory.txt");
    
    //if the file doesn't open, then the inventory section will not run
    if(!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the user file section doesn't run
        flag -= 1;
    }
    
    //runs if the inventory file opens
    if(flag == 1)
    {
        while(getline(infile, name), getline(infile, tempquant))
        {
            //converts the string input into an int
            int quantity = stoi(tempquant);
            
            inventory.addItem(name, quantity);
        }
    }
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
    
    inventory.save();
}
