#include "game.h"
using std::cout;
using std::cin;
using std::endl;

void Game::setGame(string name, string genre, string developer, string publisher, string release, int rating)
{
    //sets variable in Game to argument
    this->name = name;
    this->genre = genre;
    this->developer = developer;
    this->publisher = publisher;
    this->release = release;
    this->rating = rating;
}


void Game::display()
{
    //outputs all data in game
    cout << this->name << " " << this->genre << " " << this->developer << " " << this->publisher << " " << this->release << " " << this->rating << endl;
}

void Game::editGame()
{
    //edits Game information
    string option, new_val = "";
    int new_val2;

    while (option != "done")
    {
        while (option != "name" && option != "genre" && option != "developer" && option != "publisher" && option != "release" && option != "rating")
        {
            cout << "What would you like to edit about the game information?" << endl << "Enter done to exit" << endl;
            cin >> option;

            if (option == "done") break;
        }
        if (option == "done") break;
        cout << "And what would you like to change it to?" << endl;
        cin.ignore();
        if (option == "name")
        {
            getline(cin, new_val);
            setGame(new_val, this->genre, this->developer, this->publisher, this->release, this->rating);
        }
        if (option == "genre")
        {
            getline(cin, new_val);
            setGame(this->name, new_val, this->developer, this->publisher, this->release, this->rating);
        }
        if (option == "developer")
        {
            getline(cin, new_val);
            setGame(this->name, this->genre, new_val, this->publisher, this->release, this->rating);
        }
        if (option == "publisher")
        {
            getline(cin, new_val);
            setGame(this->name, this->genre, this->developer, new_val, this->release, this->rating);
        }
        if (option == "release")
        {
            getline(cin, new_val);
            setGame(this->name, this->genre, this->developer, this->publisher, new_val, this->rating);
        }
        if (option == "rating")
        {
            cin >> new_val2;
            setGame(this->name, this->genre, this->developer, this->publisher, this->release, new_val2);
        }
        option = "";
    }
}

