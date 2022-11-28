#include "game.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

void Game::setGame(string name, string genre, string developer, string publisher, string release, int rating)
{
    ofstream outfile;
    string filename = "";
    filename += name + ".txt";
    outfile.open(filename);

    if (!outfile.is_open())
    {
        cout << "Error creating/opening file." << endl;
        return;
    }
    outfile << name << endl;
    outfile << genre << endl;
    outfile << developer << endl;
    outfile << publisher << endl;
    outfile << release << endl;
    outfile << rating << endl;

    outfile.close();

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
void Game::fileGame(string filename)
{
    ifstream infile;
    string nam2, gen2, dev2, pub2, rel2, temprat2;
    int rat2;

    infile.open(filename);

    if (!infile.is_open())
    {
        cout << "That file does not exist" << endl;
        return;
    }
    getline(infile, nam2);
    getline(infile, gen2);
    getline(infile, dev2);
    getline(infile, pub2);
    getline(infile, rel2);
    getline(infile, temprat2);

    rat2 = stoi(temprat2);

    infile.close();

    setGame(nam2, gen2, dev2, pub2, rel2, rat2);

}
