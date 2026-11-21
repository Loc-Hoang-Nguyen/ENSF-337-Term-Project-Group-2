// Implement the Passenger member functions declared in Passenger.h.
#include "Passenger.h"

#include <iomanip>
#include <iostream>

Passenger::Passenger()
    : passenger_id(0), first_name(""), last_name(""), phone_number(""),
      seat_row(0), seat_letter(' ')
{
}

Passenger::Passenger(const PassengerRecord& source)
    : passenger_id(source.passenger_id),
      first_name(source.first_name),
      last_name(source.last_name),
      phone_number(source.phone_number),
      seat_row(source.seat_row),
      seat_letter(source.seat_letter)
{
}

// Prints one row of the passenger table (columns separated by one space).
// Flight::displayPassengers should print its header using the same
// P_ID_SIZE / P_NAME_SIZE / P_PHONE_SIZE widths and setw(3) for Row.
void Passenger::print() const
{
    std::cout << std::left
              << std::setw(P_ID_SIZE)    << passenger_id << ' '
              << std::setw(P_NAME_SIZE)  << first_name   << ' '
              << std::setw(P_NAME_SIZE)  << last_name    << ' '
              << std::setw(P_PHONE_SIZE) << phone_number << ' '
              << std::setw(3)            << seat_row     << ' '
              << seat_letter
              << std::endl;
}

int Passenger::getID() const
{
    return passenger_id;
}

int Passenger::getSeatRow() const
{
    return seat_row;
}

char Passenger::getSeatLetter() const
{
    return seat_letter;
}

const std::string& Passenger::getFirstName() const
{
    return first_name;
}

const std::string& Passenger::getLastName() const
{
    return last_name;
}

PassengerRecord Passenger::getRecord(const std::string& flight_code) const
{
    PassengerRecord record;
    record.flight_code  = flight_code;
    record.passenger_id = passenger_id;
    record.first_name   = first_name;
    record.last_name    = last_name;
    record.phone_number = phone_number;
    record.seat_row     = seat_row;
    record.seat_letter  = seat_letter;
    return record;
}
