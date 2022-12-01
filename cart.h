#ifndef CART_H
#define CART_H
#include "user.h"
#include "inventory.h"
#include <fstream>
using std::ifstream;
using namespace std;


class Cart
{

public:
    Node *head;
    Node *tail;
    string username;
    string password;
    int quantity;

    Cart();
    ~Cart();

    void createCart();

    void login(User &user, Cart &cart, Inventory &inventory); //logs in to a user

    void logout(); //logs out of current user

    void checkout(User& user, Cart &cart); //checks out, item gets annihilated, money gets stolen

    void addItem(string& item, int quantity); //adds item to cart

    void removeItem(string& item, int quantity); //removes item from cart

    void displayCart(); //displays cart contents

    inline bool exist(const std::string& name);

    bool is_empty(std::ifstream& pFile);

    void save();




};

#endif // CART_H
