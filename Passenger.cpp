// Implement the Passenger member functions declared in Passenger.h.
#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(const PassengerRecord& source) { (void)source; }

void Passenger::print() const
{
    return;
}

int Passenger::getID() const
{
    return 0;
}

int Passenger::getSeatRow() const
{
    return 0;
}

char Passenger::getSeatLetter() const
{
    return 0;
}

PassengerRecord Passenger::getRecord(const std::string& flight_code) const
{
    (void)flight_code;
    return PassengerRecord{};
}
