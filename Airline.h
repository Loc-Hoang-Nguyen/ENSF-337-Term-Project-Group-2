// Declare the Airline class in this file.
//
// Store the collection of Flight objects.
// Declare the operations shown in the project class diagram for loading data,
// displaying flights, finding a flight and saving passenger data.
// Add any private helper functions needed by your design.
#ifndef AIRLINE_H
#define AIRLINE_H

#include "FileRecordIO.h"
#include "Flight.h"

#include <string>
#include <vector>

class Airline{
    private:
        std::string name;
        std::vector<Flight> flights;
    public:
        Airline();
        /* PROMISE
         *  A Default Value for Flight
         * Comment
         *  Initialize with empty string and vector
         */

        void displayFlights() const;
        /* PROMISE
         *  Display the Flights of this Airline
         *  Reference the option 1 in the D2L example for formatting
         * Comment
         *  The person who handle this file probably should also handle displayFlight from Flight.h
         */

        Flight* findFlight() const;
        /* PROMISE
         *  Prompt the user for the position of the flight they want
         *  Reference option 2 on the D2L example for what to do
         *  Inform the user if they have successfully selected the flight or if it doesn't exist
         * 
         *  Return the pointer to that Flight if successful, otherwise return NULL 
         */

        bool loadData();
        /* PROMISE
         *  Load the data from a file in a hardcoded path
         *  Return true if successful, false if not
         * Comment
         *  Might be a good idea to implement macro so when a flag is define during compilation
         *  A good idea is a TEST2 flag
         *  it can easily switch to a different file.
         */

        bool savePassengerData() const;
        /* PROMISE
         *  Save the data from a file in a hardcoded path
         *  Return true if successful, false if not
         * Comment
         *  Might be a good idea to implement macro so when a flag is define during compilation
         *  A good idea is a TEST2 flag
         *  it can easily switch to a different file.
         */
};

#endif
