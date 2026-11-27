// Declares the Airline class

#ifndef AIRLINE_H
#define AIRLINE_H

#include "AirlineUtility.h"
#include "FileRecordIO.h"
#include "Flight.h"

#include <string>
#include <vector>

class Airline
{
    private:
        std::string name;
        std::vector<Flight> flights;
    public:
        Airline();
        /* PROMISES:
         *  Provides default empty values for an Airline object.
         */

        void displayFlights() const;
        /* PROMISES:
         *  Displays the flights stored in the Airline object it is called on.
         */

        Flight* findFlight();
        /* PROMISES:
         *  Prompts the user to select a flight by index (indices viewable via displayFlights())
         *  Informs the user if they have successfully selected the flight or if the process failed
         * 
         *  Returns the pointer to the selected Flight if successful, otherwise returns NULL 
         */

        bool loadData(const std::string& flights_filepath, const std::string& passengers_filepath);
        /*  PROMISES:
         *  Loads PassengerRecord data from the supplied filepaths in a hardcoded path
         *  Returns true if successful, and returns false and prints an error message if not
         *  Failure can occur due to invalid file contents or an inability to locate and read the files
         */

        bool savePassengerData(const std::string& passengers_filepath) const;
        /* PROMISES
         *  Prompts the user for confirmation
         *  If confirmed, saves the Airline's passenger data to the supplied filepath
         *  Returns true if successful, false if not
         */
};

#endif
