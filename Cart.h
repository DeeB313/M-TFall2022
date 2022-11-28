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
    string username;
    string password;
    int quantity;
    int itemID;
    int cartID;

    Cart();

    void login(User *user); //logs in to a user

    void logout(); //logs out of current user

    void checkout(Cart& cart); //checks out, item gets annihilated, money gets stolen

    void addItem(); //adds item to cart

    void removeItem(); //removes item from cart

    void displayCart(Cart *cart); //displays cart contents

    double Total(Cart& cart); //displays cart total, this will be called by displayCart

};

#endif // CART_H