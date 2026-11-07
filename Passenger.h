// Declare the Passenger class in this file.
//
// Add the passenger information shown in the project class diagram.
// Declare the constructor and any accessors needed by the other classes.
// Declare the operation that displays one passenger's information.
#ifndef PASSENGER_H
#define PASSENGER_H

#include "FileRecordIO.h"

#include <string>

/* These are the length of passenger ID,
 * passenger name (for last name and first name both individually),
 * and phone number, use these to format the printing of tables
 */
#define P_ID_SIZE 5
#define P_NAME_SIZE 12
#define P_PHONE_SIZE 12

class Passenger{
    private:
        int passenger_id;
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        int seat_row;
        char seat_letter;
    public:
        Passenger();
        /* PROMISE
         *  A Default Value for Passenger
         * Comment
         *  Just use any value really, this is only neccesary for vector
         */

        Passenger(const PassengerRecord& source);
        /* PROMISE
         *  Initialize with the value from PassengerRecord
         * Comment
         *  FileRecordIO get values for PassengerRecord
         *  so need intermediate step
         */

        //Copy initializer, assignment operator and destructor not needed

        void print() const;
        /* PROMISE
         *  Print out a row of data
         *  Reference the option 4 in the D2L example for formatting
         */

        int getID() const;
        /* PROMISE
         *  Return the passenger_id
         */

        int getSeatRow() const;
        /* PROMISE
         *  Return the seat_row
         */

        char getSeatLetter() const;
        /* PROMISE
         *  Return the seat_letter
         */

        PassengerRecord getRecord(const std::string& flight_code) const;
        /* PROMISE
         *  Return an equivalent PassengerRecord object with this class data for exporting
         */
};

#endif