#include "user.h"
#include <iostream>
using std::cout;

User::User()
{

}


User::User(string username, string password, string email, string address, int storeToken) //default constructor
{
  this->username = username;
  this->password = password;
  this->email = email;
  this->storeToken = storeToken;
  this->address = address;
}

void User::updateinfo(User &user)
{
    string answer, username, password, newpassword, address, email;
    int money;
    std::cout << "What do you want to update?" << std::endl;

    while(1)
    {
        std::cout << "Username" << std::endl;
        std::cout << "Password" << std::endl;
        std::cout << "Address" << std::endl;
        std::cout << "Email" << std::endl;
        std::cout << "Add funds" << std::endl;
        std::cout << "Exit" << std::endl;

        std::cin >> answer;

        if(answer == "Username" && answer == "username")
        {
            std::cout << "Enter new username: " << std::endl;
            std::cin >> username;
            this->username = username;
        }

        if(answer == "Password" && answer == "password")
        {
            int flag = 0;
            std::cout << "Please enter your old password: " << std::endl;
            while(1)
            {
                std::cin >> password;
                if(this->password == password)
                {
                    break;
                }

                if(this->password != password)
                {
                    flag +=1;
                    std::cout << "Password incorrect. You have " << 3-flag << " attempts remaining." << std::endl;
                }
                if(flag == 3)
                {
                    std::cout << "Attempts maxed out. Exiting..." << std::endl;
                    break;
                }
            }

            if(flag ==3)
            {
                break;
            }

            else
            {
                std::cout << "Please enter new password: " << std::endl;
                std::cin >> newpassword;
                string temp = newpassword;
                std::cout << "Please reenter new password: " << std::endl;
                while(1)
                {
                    int flag = 0;
                    std::cin >> newpassword;
                    if(flag == 1)
                    {
                        break;
                    }

                    if(newpassword == temp)
                    {
                        password = newpassword;
                        std::cout << "Password updated!" << std::endl;
                        break;
                    }

                    else
                    {
                        string choice;
                        std::cout << "Password does not match! Try again? (Yes/No)" << std::endl;
                        while(1)
                        {
                            std::cin >> choice;

                            if(choice == "Yes" && choice == "yes")
                            {
                                break;
                            }

                            if(choice == "No" && choice == "no")
                            {
                                flag += 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if(answer == "Address" && answer == "address")
        {
            std::cout << "Enter new address: " << std::endl;
            std::getline(std::cin,address);
            this->address = address;
            std::cin.ignore();
        }

        if(answer == "Email" && answer == "email")
        {
            std::cout << "Enter new email: " << std::endl;
            std::cin >> email;
            this->email = email;
        }

        if(answer == "Add funds" && answer == "add funds")
        {
            std::cout << "How much fund?" << std::endl;
            std::cin >> money;
            storeToken = money;;
        }
        if(answer != "Username" && answer != "username" && answer != "Password" && answer != "password" && answer != "Address" && answer != "address" && answer != "Email" && answer != "email" && answer != "Exit" && answer != "Add funds" && answer != "add funds" && answer != "exit")
        {
            std::cout << "Error 404" << std::endl;
        }
    }




}

void User::createUser(User &user)
{
  string username, password, email, address;
  int storeToken;

  std::cout << "Please enter a username: ";
  std::cin >> username;
  this->username = username;

  std::cout << "Please enter a password: ";
  std::cin >> password;
  this->password = password;

  std::cout << "Please enter your email: ";
  std::cin >> email;
  this->email = email;

  std::cout << "Please enter your address: ";
  std::cin.ignore();
  std::getline(std::cin, address);
  this->address = address;


  std::cout << "How much money do you have, rounded down: ";
  std::cin >> storeToken;
  this->storeToken = storeToken;

  if(username == "Justin")
  {
    admin = true;
  }

}

void User::display()
{
    std::cout << "User Profile: " << std::endl;
    std::cout << username << std::endl;
    std::cout << email << std::endl;
    std::cout << "Shipping address: " << address << std::endl;
    std::cout << "Money: " << storeToken << std::endl;
}
bool User::checkAdmin(User &user)
{
    if(admin == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

