#include "cart.h"
#include "user.h"
#include "inventory.h"
#include "game.h"
#include <iostream>
#include <stdio.h>
using std::istream;
using std::stringstream;
using std::string;

Cart::Cart()
{
    username = "";
    quantity = 0;
    head = nullptr;
    tail = nullptr;
}

Cart::~Cart()
{
    //desconstructor, loops and deletes every node
    Node *temp = head;
    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    tail = nullptr;
}

bool Cart::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

inline bool Cart::exist(const std::string& name) ///
{
    ifstream file(name);
    if (!file)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        return false;    // The file was not found.
    else                 // If the file was found, then file is non-0.
        return true;     // The file was found.
}

void Cart::createCart() ///
{
    string cartname = username + ".txt";
    ofstream file1;
    if (exist(cartname) == true)
    {
        cout << "Cart history for user " << username << " exists" << endl;
    }
    else
    {
        file1.open(cartname);
        cout << "Cart history does not exist. New cart created." << endl;
    }
}

void Cart::login(User &user, Cart &cart, Inventory &inventory)
{
    int flag = 1;
    ifstream infile;
    string name, tempquant;
    bool ex = true;
    string password;
    this->username = user.username;

    while (ex)
    {
        cout << "Enter your password: ";
        cin >> password;


        if (password == user.password)
        {
            cout << "Logged in" << endl;
            createCart();
            ex = false;
        }
        else
        {
            cout << "Wrong password" << endl;
        }
    }

    infile.open(user.username+".txt");

    //if the file doesn't open, then the inventory section will not run
    if(!infile.is_open())
    {
        //closes the file
        infile.close();
        //decrements flag so the inventory file section doesn't run
        flag -= 1;
    }

    //runs if the inventory file opens
    if(flag == 1)
    {
        while(getline(infile, name), getline(infile, tempquant))
        {
            //converts the string input into an int
            int quantity = stoi(tempquant);

            //adds item into inventory
            //this code chunk creates the game object
            Game addgame;

            //creates the game using fileGame
            addgame.fileGame(name + ".txt");

            //creates new node with the inserted character as data
            Node *cartitem = new Node;
            cartitem->game = addgame;

            //sets temp equal to head
            Node *temp = head;

            //if head is empty, sets head to added Character, next and prev to null, and tail equal to head
            if(head == nullptr)
            {
                head = cartitem;
                head->next = nullptr;
                head->prev = nullptr;
                tail = head;
                head->quantity += quantity;

                //sets price
                if(cartitem->game.developer == "Ubisoft")
                {
                    head->price = 50;
                }

                else if(cartitem->game.developer == "Activision")
                {
                    head->price = 60;
                }

                else if(cartitem->game.developer == "Bungie")
                {
                    head->price = 25;
                }

                else if(cartitem->game.developer == "Nintendo")
                {
                    head->price = 35;
                }

                else if(cartitem->game.developer == "Square Enix")
                {
                    head->price = 40;
                }

                else if(cartitem->game.developer == "Capcom")
                {
                    head->price = 55;
                }

                else if(cartitem->game.developer == "Fromsoftware")
                {
                    head->price = 60;
                }

                else if(cartitem->game.developer == "Sony")
                {
                    head->price = 60;
                }

                //static price of 25 for "unknown" developers
                else
                {
                    head->price = 25;
                }
                return;
            }

            //loops while temp isn't null
            while(temp != nullptr)
            {
                //sets Game class insert and current equal to addedCharacter and temp
                Game insert = cartitem->game;
                Game current = temp->game;

                //if the added item is earlier in the alphabet than temp
                if(insert.name < current.name)
                {
                    //if temp is at the head
                    if(temp == head)
                    {
                        //increments quantity
                        cartitem->quantity += quantity;
                        //sets the added item as the head of the list and ends the function
                        cartitem->next = head;
                        cartitem->prev = nullptr;
                        head->prev = cartitem;
                        head = cartitem;
                        break;
                    }


                    //if temp is anything within the list
                    else
                    {
                        cartitem->quantity += 1;
                        //puts the added item between temp and temp's previous node and ends the function
                        temp->prev->next = cartitem;
                        cartitem->prev = temp->prev;
                        temp->prev = cartitem;

                        //if the next node isn't null
                        if(cartitem->next != nullptr)
                        {
                            cartitem->next = temp;
                            break;
                        }
                    }
                }

                //if the game is already in the list
                if(insert.name == current.name)
                {
                   temp->quantity += quantity;
                   delete cartitem;
                   break;
                }

                //if the inserted item is bigger than temp, and if temp is at the tail/end
                else
                {
                    //sets the added item as the tail of the list and ends the function
                    if(temp == tail)
                    {
                        cartitem->quantity += quantity;
                        tail->next = cartitem;
                        cartitem->next = nullptr;
                        cartitem->prev = tail;
                        tail = cartitem;
                        break;
                    }
                }
                //goes to the next node
                temp = temp->next;
            }

            //sets price
            if(cartitem->game.developer == "Ubisoft")
            {
                cartitem->price = 50;
            }

            else if(cartitem->game.developer == "Activision")
            {
                cartitem->price = 60;
            }

            else if(cartitem->game.developer == "Bungie")
            {
                cartitem->price = 25;
            }

            else if(cartitem->game.developer == "Nintendo")
            {
                cartitem->price = 35;
            }

            else if(cartitem->game.developer == "Square Enix")
            {
                cartitem->price = 40;
            }

            else if(cartitem->game.developer == "Capcom")
            {
                cartitem->price = 55;
            }

            else if(cartitem->game.developer == "Fromsoftware")
            {
                cartitem->price = 60;
            }

            else if(cartitem->game.developer == "Sony")
            {
                cartitem->price = 60;
            }

            //static price of 25 for "unknown" developers
            else
            {
                cartitem->price = 25;
            }
        }
    }
    //closes the file
    infile.close();
}
void Cart::logout() ///
{
    this->username = "";
    //desconstructor, loops and deletes every node
    Node *temp = head;
    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    tail = nullptr;
}//logs out of current user

void Cart::checkout(User &user, Cart &cart)
{
    ofstream outfile;
    string filename = user.username + "history.txt";
    Node *temp = head;
    int total = 0;

    outfile.open(filename, std::ios_base::app);

    while(temp != nullptr)
    {
        outfile << "Item name: " << temp->game.name << std::endl;
        outfile << "Quantity bought: " << temp->quantity << std::endl;
        outfile << "Total Price: " << temp->quantity*temp->price << std::endl;
        total += temp->quantity*temp->price;
        temp = temp->next;
    }
    outfile.close();
    cout << "Your total is " << total << endl;
    if (user.storeToken >= total)
    {
        cout << "You have total of " << user.storeToken << " StoreCredit." << endl;
        cout << "Your total of " << total << " has been deducted from your " << user.storeToken << " StoreCredit" << endl;
        user.storeToken -= total;
        cout << "You have total of " << user.storeToken << " StoreCredit left." << endl;

        Node *temp = head;
        while(temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }

        head = nullptr;
        tail = nullptr;
    }

    else
    {
        cout << "You don't have enough money." << endl;
    }
}

void Cart::addItem(string& item, int quantity)
{
    //this code chunk creates the game object
    Game addgame;
    //filename
    string filename = "";

    //creates the game using fileGame
    addgame.fileGame(item + ".txt");

    //creates new node with the inserted character as data
    Node *cartitem = new Node;
    cartitem->game = addgame;

    //sets temp equal to head
    Node *temp = head;

    //if head is empty, sets head to added Character, next and prev to null, and tail equal to head
    if(head == nullptr)
    {
        head = cartitem;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        head->quantity += quantity;

        //sets price
        if(cartitem->game.developer == "Ubisoft")
        {
            head->price = 50;
        }

        else if(cartitem->game.developer == "Activision")
        {
            head->price = 60;
        }

        else if(cartitem->game.developer == "Bungie")
        {
            head->price = 25;
        }

        else if(cartitem->game.developer == "Nintendo")
        {
            head->price = 35;
        }

        else if(cartitem->game.developer == "Square Enix")
        {
            head->price = 40;
        }

        else if(cartitem->game.developer == "Capcom")
        {
            head->price = 55;
        }

        else if(cartitem->game.developer == "Fromsoftware")
        {
            head->price = 60;
        }

        else if(cartitem->game.developer == "Sony")
        {
            head->price = 60;
        }

        //static price of 25 for "unknown" developers
        else
        {
            head->price = 25;
        }
        return;
    }


    //loops while temp isn't null
    while(temp != nullptr)
    {
        //sets Game class insert and current equal to addedCharacter and temp
        Game insert = cartitem->game;
        Game current = temp->game;

        //if the added item is earlier in the alphabet than temp
        if(insert.name < current.name)
        {
            //if temp is at the head
            if(temp == head)
            {
                //increments quantity
                cartitem->quantity += quantity;
                //sets the added item as the head of the list and ends the function
                cartitem->next = head;
                cartitem->prev = nullptr;
                head->prev = cartitem;
                head = cartitem;
                break;
            }


            //if temp is anything within the list
            else
            {
                cartitem->quantity += 1;
                //puts the added item between temp and temp's previous node and ends the function
                temp->prev->next = cartitem;
                cartitem->prev = temp->prev;
                temp->prev = cartitem;

                //if the next node isn't null
                if(cartitem->next != nullptr)
                {
                    cartitem->next = temp;
                    break;
                }
            }
        }

        //if the game is already in the list
        if(insert.name == current.name)
        {
           temp->quantity += quantity;
           delete cartitem;
           break;
        }

        //if the inserted item is bigger than temp, and if temp is at the tail/end
        else
        {
            //sets the added item as the tail of the list and ends the function
            if(temp == tail)
            {
                cartitem->quantity += quantity;
                tail->next = cartitem;
                cartitem->next = nullptr;
                cartitem->prev = tail;
                tail = cartitem;
                break;
            }
        }
        //goes to the next node
        temp = temp->next;
    }

    //sets price
    if(cartitem->game.developer == "Ubisoft")
    {
        cartitem->price = 50;
    }

    else if(cartitem->game.developer == "Activision")
    {
        cartitem->price = 60;
    }

    else if(cartitem->game.developer == "Bungie")
    {
        cartitem->price = 25;
    }

    else if(cartitem->game.developer == "Nintendo")
    {
        cartitem->price = 35;
    }

    else if(cartitem->game.developer == "Square Enix")
    {
        cartitem->price = 40;
    }

    else if(cartitem->game.developer == "Capcom")
    {
        cartitem->price = 55;
    }

    else if(cartitem->game.developer == "Fromsoftware")
    {
        cartitem->price = 60;
    }

    else if(cartitem->game.developer == "Sony")
    {
        cartitem->price = 60;
    }

    //static price of 25 for "unknown" developers
    else
    {
        cartitem->price = 25;
    }
}

void Cart::removeItem(string& item, int quantity)
{
    //starts at head
    Node *temp = head;

    int flag = 0;

    //if list is empty tells the user
    if(head == nullptr)
    {
        std::cout << "The cart is empty." << std::endl;
    }

    //while temp isn't null loops until the item is found
    while(temp != nullptr)
    {
        if(temp->game.name == item)
        {
            if(temp->quantity > 0)
            {
                if((temp->quantity - quantity) < 0)
                {
                    std::cout << "You don't have that much of that item in your cart!" << std::endl;
                    std::cout << "Instead you have: " << temp->quantity << std::endl;
                    std::cout << temp->quantity << " item removed." << std::endl;
                    temp->quantity = 0;
                    flag += 1;
                }
                else
                {
                    temp->quantity = temp->quantity - quantity;
                    flag += 1;
                }
            }
        }
        temp = temp->next;
    }

    if(flag == 0)
    {
        std::cout << "That item is not in your cart." << std::endl;
        return;
    }
}
//removes item from cart

void Cart::displayCart() ///
{
    Node *temp = head;
    if(head == nullptr)
    {
        std::cout << "Cart is empty." << std::endl;
    }

    while(temp != nullptr)
    {
        //displays information
        temp->game.display();
        std::cout << std::endl;
        std::cout << "Quantity left: " << temp->quantity << std::endl;
        std::cout << "Price: " << temp->price << std::endl << std::endl;
        temp = temp->next;
    }
}

//displays cart contents
void Cart::save()
{
    //writes to outfile
    ofstream outfile;
    outfile.open(this->username + ".txt");

    //sets temp equal to head
    Node *temp = head;

    //if inventory hasn't been made, output that it's empty
    if(head == nullptr)
    {
        outfile.close();
        return;
    }

    //loops and writes the game name and quantity into inventory.txt
    while(temp != nullptr)
    {
        if(temp->quantity != 0)
        {
            outfile << temp->game.name << std::endl;
            outfile << temp->quantity << std::endl;
        }
        temp = temp->next;
    }
    outfile.close();
}
