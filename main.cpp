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
#include "Airline_utility.h"

#define RETURN_CHAR '\n'

void waitForReturn();
/* PROMISE
 *  <<< Press Return to Continue >>>
 *  Prompt the user to press Return to continue, that's it
 *  Can either use cin.get() or cin >> [some string variable];
 *  If use cin.get() make sure to clear the buffer beforehand
 *  Reference the D2L Example for formatting
 */

int main()
{
    // SETUP
    Airline main_airline;

    if (!main_airline.loadData())
    {
        return 0;
    }
    
    Flight* selected_flight = NULL;

    // USER INTERACTION BEGINS
    
    std::cout << "Version: PRE1.0\nTerm Project - Flight Management Program in C++\nProduced by: \nYear: 2026" << std::endl;
    
    int operation = 0;
    bool failure = false;
    
    bool running = true;
    while (running)
    {
        waitForReturn();
        std::cout << "Please select one of the following options:\n" 
        << "\t1. Display all flights\n"
        << "\t2. Select a flight\n\n"

        << "\t3. Display flight seat map\n"
        << "\t4. Display passenger list\n"
        << "\t5. Add a new passenger\n"
        << "\t6. Remove an existing passenger\n\n"

        << "\t7. Save passenger data for all flights\n"
        << "\t8. Quit program\n\n"

        << "Enter your choice (1-8): ";

        failure = !(std::cin >> operation);
        clearInputBuffer();
        
        if (!failure && operation >= 1 && operation <= 8)
        {
            switch(operation)
            {
                case 1: main_airline.displayFlights(); break;
                case 2: selected_flight = main_airline.findFlight(); break;

                case 7: 
                if (main_airline.savePassengerData()) std::cout << "Passenger data succesfully saved!" << std::endl; 
                else std::cout << "Passenger data save failed." << std::endl;
                break;

                case 8: running = false; break;

                default:
                if (selected_flight != NULL)
                {
                    switch(operation)
                    {
                        case 3: selected_flight -> displaySeatMap(); break;
                        case 4: selected_flight -> displayPassengers(); break;
                        case 5: selected_flight -> addPassenger(); break;
                        case 6: selected_flight -> removePassenger(); break;
                    }
                }
                else std::cout << "Error: No flight selected" << std::endl;

                break;
            }
        }
        else std::cout << "Invalid operation. Please enter a number from 1 to 8." << std::endl;
    }
    std::cout << "\nProgram terminated. Thank you for using Term Project - Flight Management Program in C++";
}

void waitForReturn()
{
    std::cout << "\n<<< Press ENTER to continue >>>" << std::endl; // Output

    while (std::cin.get() != RETURN_CHAR); // Wait until the RETURN_CHAR is entered (newline)
    // Note: buffer is not cleared since it will then wait for ANOTHER newline, since this one is already consumed here.
    // This loop is already effectively a mini buffer clear, although no .clear() since cin is not being used with the
    // extraction operator.
    return; // Return
}
