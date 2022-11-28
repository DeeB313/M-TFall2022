This is a information file- Justin
So currently, I've made all the class and header files.

The first meeting will basically just be us filling in the information for the rest of the files. 
Later, when we can all get together, or over discord, we can decide who does what class.

November 14th, get all the classes finished to be tested and debugged.
I would prefer to be able to debug as I make my code, so if you guys can push commits every 2-3 days that'll be great - Justin


11/7/22-Justin
So I've pretty much finished the user class, now we just need the other three to be done.
things to note (for me mainly, and anyone else interested to test):
The storetoken needs to have a flag for when the user doesn't enter a number.
Usernames are unique, so we need to check for that somewhere, probably in the main function.

11/20/22-Justin
I did some work on the main cpp, so far creating a user works fine. Login with an existent user still is not functional. 
File writing works well enough. File reading does not work yet.

11/25/22-Justin
User file handling is done, the rest of the code still needs to be implemented. As for the games file handling, we would have to arbitrarily decide on using multiple
files per game or a single file for all the games. Personally, I think using a single file would make file handling a lot easier. If that's the case all we have to do
is move Marc's code into the save and load functions in main. If we are to use multiple files per game, then we will have to decide on a set number of games
or create a separate file storing the list of all the .txts to be read from.


11/27/2022 - Dee
Just uploaded the cart class. The login, logout, displayCart, and removeItem functions are working now. I need the inventory class to finish up the remaining functions so right now i'm waiting on the inventory class to finish to add the final 2 functions. 
