#ifndef GAME_H
#define GAME_H
#include <string>
using std::string;

class Game
{
private:

    //initial values for a game
    string name = "N/a";
    string genre = "N/a";
    string developer = "N/a";
    string publisher = "N/a";
    string release = "N/a";
    int rating = 0;

public:   

    Game();

    Game(string name, string genre, string developer, string publisher, string release, int rating); //This creates a default game object

    void setGame(string &name, string &genre, string &developer, string &publisher, string &release, int &rating); //Sets game data

    void display(Game &game); //displays game data

    void editGame(Game &game); //Allows the user to edit game data
};

#endif // GAME_H
