// Implement the Flight member functions declared in Flight.h.
//
// Build the seat map from this flight's dimensions and passenger information.
// Implement the passenger display, addition and removal operations here.
#include "Flight.h"

Flight::Flight() {}

Flight::Flight(const FlightRecord& source) { (void)source; }

void Flight::displaySeatMap() const
{
    return;
}

void Flight::displayPassengers() const
{
    return;
}

void Flight::displayFlight() const
{
    return;
}

void Flight::addPassenger()
{
    return;
}

void Flight::removePassenger()
{
    return;
}

const std::string& Flight::getFlightCode() const
{
    return flight_code;
}

void Flight::getPassengerRecords(std::vector<PassengerRecord> &records) const
{
    (void)records;
    return;
}

bool addPassengerInternal(const PassengerRecord &record, std::string &err_msg)
{
    (void)record;
    (void)err_msg;
    return false;
}
