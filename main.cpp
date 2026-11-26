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

// Filepaths for flight and passenger data, defined as constants in this program
#define FLIGHTS_FILEPATH ".\\flights.txt"
#define PASSENGERS_FILEPATH ".\\passengers.txt"

// Character considered a "return"
#define RETURN_CHAR '\n'

void waitForReturn();
/* PROMISE
 *  Prints "<<< Press ENTER to continue >>>""
 *  and then waits for the user to input the constant RETURN_CHAR
 */

int main()
{
    // SETUP

    Airline main_airline; // Create the Airline object

    // Populate the Airline object with data from the hardcoded files
    if (!main_airline.loadData(FLIGHTS_FILEPATH, PASSENGERS_FILEPATH)) // If failed
    {
        std::cout << "Data loading failed, program terminated." << std::endl; // Output
        return 1; // Return 1 (program cannot continue, there is an issue)
    }
    
    Flight* selected_flight = NULL; // Create a variable to store the selected flight

    // USER INTERACTION BEGINS
    
    // "Title" message
    std::cout << "Version: PRE1.0\n"
    << "Term Project - Flight Management Program in C++\n"
    << "Produced by: Max MacPhee, [PLEASE ADD YOUR NAMES!]\n"
    << "Year: 2026" 
    << std::endl;
    
    // Stored here just so they don't get deallocated and reallocated every time the loop repeats
    int operation = 0; // Variable for current operation
    bool failure = false; // Variable for failure state 

    bool running = true; // Variable for if the program is currently running
    while (running) // Repeat while the program is running
    {
        waitForReturn(); // Wait for a return (always precedes the main menu)
        
        // Massive menu output block (formatted for readability)
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

        // Read the desired operation from the player, if failed set failure to true
        failure = !(std::cin >> operation);
        clearInputBuffer(); // Clear the input buffer after getting user input
        
        if (!failure && operation >= 1 && operation <= 8) // If not failed and operation in range
        {
            switch(operation) // Switch based on operation
            {
                // If 1 is entered, display all flights for the airline
                case 1: main_airline.displayFlights(); break;
                // If 2 is entered, find a flight to select
                case 2: selected_flight = main_airline.findFlight(); break;

                // All the Flight operations are reached via default case

                // If 7 is entered, save passenger data
                case 7: 
                    if (main_airline.savePassengerData(PASSENGERS_FILEPATH)) 
                        std::cout << "All passenger data succesfully saved!" << std::endl; 
                    else std::cout << "Passenger data was not saved." << std::endl; 

                    break; // End this case

                // If 8 is entered, set running to false (stops the program loop from repeating)
                case 8: running = false; break;

                // Other entries (Flight operations)
                default:
                    if (selected_flight != NULL) // If the selected Flight is NOT NULL
                    {
                        switch(operation) // Another switch statement for flight operations
                        {
                            // If 3 is selected, display the seat map for the selected flight
                            case 3: selected_flight -> displaySeatMap(); break;
                            // If 4 is selected, display the passengers for the selected flight
                            case 4: selected_flight -> displayPassengers(); break;
                            // If 5 is selected, add a passenger to the selected flight
                            case 5: selected_flight -> addPassenger(); break;
                            // If 6 is selected, remove a passenger from the selected flight
                            case 6: selected_flight -> removePassenger(); break;
                            // This default case should never trigger, 
                            // and if it does that means something went horribly wrong internally
                            default: std::cout << "Internal error: Invalid operation entered switch case." << std::endl; break;
                        }
                    } // If there is no selected flight, output and skip the operation
                    else std::cout << "Error: No flight selected" << std::endl; 

                    break;
            }
        }
        else std::cout << "Invalid operation. Please enter a number from 1 to 8." << std::endl; // Output invalid input
    }
    // When the loop ends, print a program termination message before the program ends
    std::cout << "\nProgram terminated. Thank you for using Term Project - Flight Management Program in C++";
    return 0; // (no issue)
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
