#include "user.h"
#include <iostream>
#include <sstream>
#include <fstream>
using std::istream;
using std::stringstream;
using std::string;
User::User()
{

}

User::User(string username, string password, string email, string address, int storeToken) //default constructor
{
    //creates a default user
    this->username = username;
    this->password = password;
    this->email = email;
    this->storeToken = storeToken;
    this->address = address;
    this->admin = false;
}

void User::setUser(string &username, string &password, string &email, string &address, int &storeToken) //used by file managing
{
    //sets a user
    this->username = username;
    this->password = password;
    this->email = email;
    this->storeToken = storeToken;
    this->address = address;

    //if the user has a specific username, then that means they are an admin
    if(username == "Justin" || username == "Marc" || username == "Dee" || username == "Brian")
    {
        this->admin = true;
    }
    else
    {
        this->admin = false;
    }
}


void User::updateinfo() //updates information
{
    //initial values
    string answer, username, password, newpassword, address, email, temptoken;
    int money;

    std::cout << "What do you want to update?" << std::endl;

    //menu loop
    while(1)
    {
        //menu
        std::cout << "Username" << std::endl;
        std::cout << "Password" << std::endl;
        std::cout << "Address" << std::endl;
        std::cout << "Email" << std::endl;
        std::cout << "Add funds" << std::endl;
        std::cout << "Exit" << std::endl;

        //takes user input
        std::getline(std::cin,answer);

        //changes username
        if(answer == "Username" || answer == "username")
        {
            std::cout << "Enter new username: " << std::endl;
            std::cin >> username;
            this->username = username;
        }

        //changes password
        if(answer == "Password" || answer == "password")
        {
            //sets a flag
            int flag = 0;

            //the user will need to enter their old password
            std::cout << "Please enter your old password: " << std::endl;

            //input loop, the user will have 3 attempts to enter their old password
            while(1)
            {
                //takes input for old password
                std::cin >> password;

                //if input matches, break the loop
                if(this->password == password)
                {
                    break;
                }

                //if the input doesn't match, subtracts an attempt and iterates flag
                if(this->password != password)
                {
                    flag +=1;
                    std::cout << "Password incorrect. You have " << 3-flag << " attempts remaining." << std::endl;
                }

                //if attempts have run out, ends the program
                if(flag == 3)
                {
                    std::cout << "Attempts maxed out. Exiting..." << std::endl;
                    break;
                }
            }

            //if flag equals 3, then the user has maxed out their password attempts and will not be allowed to change their password
            if(flag ==3)
            {
                break;
            }

            //else prompts the user to create a new password
            else
            {
                //sets a flag
                int flag = 0;

                //input loop
                while(1)
                {
                    //takes input for new password
                    std::cout << "Please enter new password: " << std::endl;
                    std::cin >> newpassword;



                    //if the new password is the same as the old password, tells the user and loops
                    if(newpassword == password)
                    {
                        std::cout << "That's the same password!" << std::endl;
                        continue;
                    }

                    //breaks if passwords don't match
                    else
                    {
                        break;
                    }
                }

                //sets temp equal to new password
                string temp = newpassword;

                //input loop
                while(1)
                {
                    //if the flag is 1, then exits out of update password
                    if(flag == 1)
                    {
                        std::cout << "User decided to not change password." << std::endl;
                        break;
                    }

                    //prompts the user to reenter their new password
                    std::cout << "Please reenter new password: " << std::endl;
                    std::cin >> newpassword;

                    //if the password matches, sets the new password as password and exits update
                    if(newpassword == temp)
                    {
                        password = newpassword;
                        std::cout << "Password updated!" << std::endl;
                        break;
                    }

                    //if the passwords don't match, then asks the user if they want to try again or give up
                    else
                    {
                        string choice;
                        std::cout << "Password does not match! Try again? (Yes/No)" << std::endl;
                        while(1)
                        {
                            //takes input for choice
                            std::cin >> choice;

                            //if yes, breaks the loop
                            if(choice == "Yes" || choice == "yes")
                            {
                                break;
                            }

                            //if no, updates flag and breaks the loop
                            if(choice == "No" || choice == "no")
                            {
                                flag += 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        //sets new address
        if(answer == "Address" || answer == "address")
        {
            std::cout << "Enter new address: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin,address);
            this->address = address;
        }

        //sets new email
        if(answer == "Email" || answer == "email")
        {
            std::cout << "Enter new email: " << std::endl;
            std::cin >> email;
            this->email = email;
        }

        //gives more money
        if(answer == "Add funds" || answer == "add funds")
        {
            //input loop
            while(1)
            {
                //sets a flag
                int flag = 0;

                //initializes a stringstream
                stringstream ss;
                std::cout << "How much money do you want to add? ";
                //stores user string input into temptoken
                std::cin >> temptoken;
                //stores temptoken into stringstream
                ss.str(temptoken);

                //for loop, checks each character in temptoken to see if it is an integer
                for(int i = 0; i <temptoken.length(); i++)
                {
                    //checks for integer
                    bool check = isdigit(temptoken[i]);

                    //if true, iterates flag and keeps looping
                    if(check == true)
                    {
                        flag+=1;
                    }

                    //if false, flag becomes some negative number and breaks the loop
                    if(check == false)
                    {
                        std::cout << "THAT'S NOT A NUMBER" << std::endl;
                        flag -= 1000000000;
                        break;
                    }
                }

                //stores what the stringstream stores into money
                ss>>money;

                //if flag is positive, then that means the user entered a number, breaks the loop
                if(flag > 0)
                {
                    break;
                }
            }

            //adds the extra money into the user account
            storeToken += money;
        }

        //exits the update menu
        if(answer == "Exit" || answer == "exit")
        {
            break;
        }

        //if the user enters a wrong input
        if(answer != "Username" && answer != "username" && answer != "Password" && answer != "password" && answer != "Address" && answer != "address" && answer != "Email" && answer != "email" && answer != "Exit" && answer != "Add funds" && answer != "add funds" && answer != "exit")
        {
            std::cout << "Error 404" << std::endl;
        }
    }
}

//creates a new user, takes input for everything
void User::createUser(string &username)
{
    //initial values
    string password, email, address, temptoken;
    int storeToken;

    //sets username
    this->username = username;

    //sets password
    std::cout << "Please enter a password: ";
    std::cin >> password;
    this->password = password;

    //sets email
    std::cout << "Please enter your email: ";
    std::cin >> email;
    this->email = email;

    //sets address
    std::cout << "Please enter your address: ";
    std::cin.ignore();
    std::getline(std::cin, address);
    this->address = address;


    //input loop
    while(1)
    {
        //sets a flag
        int flag = 0;

        //initializes a stringstream
        stringstream ss;
        std::cout << "How much money do you have, rounded down: ";
        //stores user string input into temptoken
        std::cin >> temptoken;
        //stores temptoken into stringstream
        ss.str(temptoken);

        //for loop, checks each character in temptoken to see if it is an integer
        for(int i = 0; i <temptoken.length(); i++)
        {
            //checks for integer
            bool check = isdigit(temptoken[i]);

            //if true, iterates flag and keeps looping
            if(check == true)
            {
                flag+=1;
            }

            //if false, flag becomes some negative number and breaks the loop
            if(check == false)
            {
                std::cout << "..." << std::endl;
                flag -= 1000000000;
                break;
            }
        }

        //stores what the stringstream stores into storeToken
        ss>>storeToken;

        //if flag is positive, then that means the user entered a number, breaks the loop
        if(flag > 0)
        {
            break;
        }
    }

    //sets funds
    this->storeToken = storeToken;

    //if the user has a specific username, then that means they are an admin
    if(username == "Justin" || username == "Marc" || username == "Dee" || username == "Brian")
    {
        admin = true;
    }
}

//displays user info, except password
void User::display()
{
    std::cout << "User Profile: " << std::endl;
    std::cout << username << std::endl;
    std::cout << email << std::endl;
    std::cout << "Shipping address: " << address << std::endl;
    std::cout << "Money: " << storeToken << std::endl;
}

//checks if the user is an admin, returns true if they are, false if they aren't
bool User::checkAdmin()
{
    if(this->admin == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}


