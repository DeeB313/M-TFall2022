#include "game.h"

void Game::setGame(string &name, string &genre, string &developer, string &publisher, string &release, int &rating)
{
  this->name = name;
  this->genre = genre;
  this->developer = developer;
  this->publisher = publisher;
  this->release = release;
  this->rating = rating;
}

void Game::display(Game &game)
{
  cout << this->name << " " << this->genre << " " << this->developer << " " << this->publisher << " " << this->release << " " << this->rating << endl;
}

void Game::edit(Game &game)
{
  string option, new_val;
  int new_val2;
  cout << "What would you like to edit about the game information?" << endl;
  cin >> option;
  cout << "And what would you like to change it to?" << endl;
  if (option == "name")
  {
    cin >> new_val;
    setGame(new_val, this->genre, this->developer, this->publisher, this->release, this->rating);
  }
  if (option == "genre")
  {
    cin >> new_val;
    setGame(this->name, new_val, this->developer, this->publisher, this->release, this->rating);
  }
  if (option == "developer")
  {
    cin >> new_val;
    setGame(this->name, this->genre, new_val, this->publisher, this->release, this->rating);
  }
  if (option == "publisher")
  {
    cin >> new_val;
    setGame(this->name, this->genre, this->developer, new_val, this->release, this->rating);
  }
  if (option == "release")
  {
    cin >> new_val;
    setGame(this->name, this->genre, this->developer, this->publisher, new_val, this->rating);
  }
  if (option == "rating")
  {
    cin >> new_val2;
    setGame(this->name, this->genre, this->developer, this->publisher, this->release, new_val2);
  }
}
