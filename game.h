#ifndef GAME_H
#define GAME_H
#include <string>
using std::string;

class Game
{
private:

    //initial values for a game
    string name, genre, developer, publisher, release;
    int rating;

public:

    //empty constructor
    Game() : name("N/a"), genre("N/a"), developer("N/a"), publisher("N/a"), release("N/a"), rating(0) {}

    //defined constructor
    Game(string name, string genre, string developer, string publisher, string release, int rating) : name(name), genre(genre), developer(developer), publisher(publisher), release(release), rating(rating) {} //This creates a default game object


    //sets variables of game
    void setGame(string name, string genre, string developer, string publisher, string release, int rating); //Sets game data

    //displays game data
    void display(); //displays game data

    //edits game information
    void editGame(); //Allows the user to edit game data
};

#endif // GAME_H
