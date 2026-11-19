// Create the program entry point in this file.
//
// Your main function should:
// - create the Airline object;
// - load flights.txt and passengers.txt;
// - keep track of the currently selected flight;
// - display the menu and read the user's choices;
// - call the appropriate Airline or Flight operation for each menu choice;
// - continue until the user chooses to quit.
#include <iostream>
#include "Airline.h"

void waitForReturn();
/* PROMISE
 *  <<< Press Return to Continue >>>
 *  Prompt the user to press Return to continue, that's it
 *  Can either use cin.get() or cin >> [some string variable];
 *  If use cin.get() make sure to clear the buffer beforehand
 *  Reference the D2L Example for formatting
 */

void clearInputBuffer();
/* PROMISE
 *  Clear the cin buffer and it's error
 * Comment
 *  Is used A LOT, so seperate out for readability
 */

int main()
{
    return 0;
}

void clearInputBuffer()
{
    //cin.clear() is needed since if user try something like inputing letter to int
    //it will spontanously explode
    std::cin.clear();
    char c;
    do{
        c = std::cin.get();
    }while(c!='\n' && c!=EOF);
    return;
}
