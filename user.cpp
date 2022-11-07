#include "user.h"

User::User()
{
}


User(string username, string password, string email, string address, int paytype) //default constructor
{
  this->username = "";
  this->password = "";
  this->email = email;
  this->storeToken = storeToken;
  this->address = address;
}

void User::updateinfo(string username); //lets the user update their information
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
  std::cin >> address;
  this->address = address;
  
  std::cout << "How much money do you have, rounded down: ";
  std::cin >> storeToken;
  
  
  if(username == "Justin")
  {
    admin = true;
  }
}

void User::display(User &user); //displays user attributes
bool User::checkAdmin(User &user);//checks if the user is an admin

