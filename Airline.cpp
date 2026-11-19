// Implement the Airline member functions declared in Airline.h.
//
// Use the supplied FileRecordIO functions when loading and saving records.
// Convert the loaded FlightRecord and PassengerRecord values into the
// appropriate Flight and Passenger objects.
// Ensure each Passenger object is placed in the appropriate Flight object.
#include "Airline.h"

#include <iostream>
#include <iomanip>

Airline::Airline() {}

void Airline::displayFlights() const
{
    std::cout << "Here is the list of available flights:\n" << std::endl;
    for(std::size_t i = 0;i<flights.size();i++){
        std::cout << "   " << std::setw(4) << std::left << std::to_string(i+1) + '.';
        flights[i].displayFlight();
    }
    return;
}

Flight* Airline::findFlight() const
{
    return NULL;
}

bool Airline::loadData()
{
    return 0;
}

bool Airline::savePassengerData() const
{
    return 0;
}
