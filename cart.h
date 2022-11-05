#ifndef CART_H
#define CART_H
#include "user.h"
#include "inventory.h"

class Cart
{
public:
    Cart();

    void login(string &username, string &password); //logs in to a user

    void logout(); //logs out of current user

    void checkout(Cart &cart); //checks out, item gets annihilated, money gets stolen

    void addItem(string &item, int &amount, Inventory &inventory); //adds item to cart

    void removeItem(string &item, int &amount, Inventory &inventory); //removes item from cart

    void displayCart(Cart &cart); //displays cart contents

    double Total(Cart &cart); //displays cart total, this will be called by displayCart

};

#endif // CART_H
