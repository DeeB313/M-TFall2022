#ifndef USER_H
#define USER_H
#include <string>
using std::string;

class User
{
private:
    //initial values for some user attributes
    string email = "N/a";
    string address = "N/a";
    int storeToken = 0; //Starts at 0, this is essentially how much money a user has
    bool admin = false; //always initially set to false, can be changed later

public:
    //initial values for username and password, usernames are unique; passwords are not
    string username;
    string password;

    User();

    User(string username, string password, string email, int paytype); //default constructor

    void updateinfo(string username); //lets the user update their information

    void createUser(User &user); //sets all the user attributes, provided there is input

    void display(User &user); //displays user attributes

    bool checkAdmin(User &user);//checks if the user is an admin

};

#endif // USER_H
