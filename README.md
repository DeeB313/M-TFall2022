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

11/28/2022 - Justin
So the inventory class is now done, changes had to be made so that it works with the rest of the functions. The main function still needs menuing, but most of the things in it should be functional. I think really all we have left to do is for Dee to finish up the Cart class and to implement a history file for each user/cart. Other than that I think we're pretty much done. I'll will be doing some debugging for the inventory code.
11/28/2022 - Justin
Update, almost everything is finished, just the cart management needs to be done now. Everything should be taken care of in the main. The only notable problem is that the program crashes if you try to add a game file that doesn't exist. This can probably be resolved using a try/catch.

11/29/2022 - Dee
Added display function + minor stuff. Checkout, Total function could be done in few minutes after everything is finished. The only thing remaining is add, remove function, and figuring out the format to add items into the cart.

11/29/2022 - Dee
Everything in cart class except the checkout() function is done.
