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

    void createCart();

    void login(User* user); //logs in to a user

    void logout(); //logs out of current user

    void checkout(User* user, Cart* cart); //checks out, item gets annihilated, money gets stolen

    void addItem(Inventory inventory, string& item, int quantity); //adds item to cart

    void removeItem(Inventory inventory, string& item, int quantity); //removes item from cart

    void displayCart(); //displays cart contents

    inline bool exist(const std::string& name);

    bool is_empty(std::ifstream& pFile);




};

#endif // CART_H
