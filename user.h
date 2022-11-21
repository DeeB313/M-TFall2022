#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
using std::string;

class User
{
protected:

    //admin
    bool admin = false; //always initially set to false, can be changed later

public:
    std::vector<User> users;
    //initial values for username and password, usernames are unique; passwords are not
    string username = "";
    string password = "";
    //initial values for some user attributes
    string email = "N/a";
    string address = "N/a";
    int storeToken = 0; //Starts at 0, this is essentially how much money a user has

    User();

    User(string username, string password, string email, string address, int storeToken); //default constructor

    void setUser(string username, string password, string email, string address, int storeToken); // sets user, only used by file managing

    void updateinfo(); //lets the user update their information

    void createUser(string &username); //sets all the user attributes, provided there is input

    void display(); //displays user attributes

    bool checkAdmin();//checks if the user is an admin

};

#endif // USER_H
