// Declare the Flight class in this file.
//
// Add the flight information shown in the project class diagram.
// Store the Passenger objects that belong to this flight.
// Declare the constructor and any accessors needed by the other classes.
// Declare the operations for displaying the seat map, displaying passengers,
// adding a passenger and removing a passenger.
#ifndef FLIGHT_H
#define FLIGHT_H

#include "FileRecordIO.h"
#include "Passenger.h"

#include <string>
#include <vector>

//This is the length of flight_code, origin, and destination, use them for output format
#define F_CODE_SIZE 5
#define F_ORG_SIZE 12
#define F_DEST_SIZE 12

class Flight {
    private:
        std::string flight_code;
        std::string origin;
        std::string destination;
        int number_of_rows;
        int seats_per_row;
        std::vector<Passenger> passengers;
    public:
        Flight();
        /* PROMISE
         *  A Default Value for Flight
         * Comment
         *  Just use an empty/0 value really, this is only neccesary for vector
         */

        Flight(const FlightRecord& source);
        /* PROMISE
         *  Initialize with the value from FlightRecord
         * Comment
         *  FileRecordIO get values for FlightRecord
         *  so need intermediate step
         */

        //Copy initializer, assignment operator and destructor not needed
        
        void displaySeatMap() const;
        /* PROMISE
         *  Display the Seat Map of this Flight
         *  Reference the option 3 in the D2L example for formatting
         */

        void displayPassengers() const;
        /* PROMISE
         *  Display the Passengers of this Flight
         *  Reference the option 4 in the D2L example for formatting
         * Comment
         *  The person who handle Passenger.cpp probably should also handle this
         */

        void displayFlight() const;
        /* PROMISE
         *  Display the Flight Information
         *  Reference the option 1 in the D2L example for formatting
         * Comment
         *  The person who handle Airline.cpp probably should also handle this
         */

        void addPassenger();
        /* PROMISE
         *  Prompt the user for data of the passanger to add
         *  Reference the option 5 in the D2L example for formatting
         *  Check the passenger ID and seat location against all current Passenger to prevent overlap
         *  Also check if the ID is in range (i.e. if P_ID_SIZE is 5, number must not exceed 5 digits)
         *  Also check if seat location is in range of this Flight
         */

        void removePassenger();
        /* PROMISE
         *  Prompt the user for ID of the passanger to remove
         *  Reference the option 6 in the D2L example for formatting
         *  Inform the user if the Passenger has been removed or they doesn't exist in list
         */

        const std::string& getFlightCode() const;
        /* PROMISE
         *  Return flight_code
         */

        void getPassengerRecords(std::vector<PassengerRecord> &records) const;
        /* PROMISE
         *  Insert the getRecord() from all Passenger to the vector of PassengerRecord (records)
         */
};

#endif