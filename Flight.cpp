// Implement the Flight member functions declared in Flight.h.
//
// Build the seat map from this flight's dimensions and passenger information.
// Implement the passenger display, addition and removal operations here.
#include "Flight.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Flight::Flight() : flight_code(), origin(),
        destination(), number_of_rows(), seats_per_row(), passengers() {}

Flight::Flight(const FlightRecord& source) : flight_code(source.flight_code), origin(source.origin),
        destination(source.destination), number_of_rows(source.number_of_rows),
        seats_per_row(source.seats_per_row), passengers() {}

void Flight::displaySeatMap() const
{
    std::vector< std::vector<char> > seatMap( number_of_rows, std::vector<char>( seats_per_row, '-' ) );

    for(std::size_t i = 0;i<passengers.size();i++){
        seatMap[ passengers[i].getSeatRow() ][ passengers[i].getSeatLetter() - 'A' ] = 'X';
    }

    std::cout << "Aircraft Seat Map" << std::endl;

    std::cout << "   ";
    for(int i = 0;i<seats_per_row;i++){
        std::cout << (char)('A' + i) << "   ";
    }
    std::cout << std::endl;

    for(int i = 0;i<number_of_rows;i++){
        std::cout << std::setw(3) << std::left << i + 1;
        for(int j = 0;j<seats_per_row;j++){
            std::cout << seatMap[i][j] << "   ";
        }
        std::cout << std::endl;
    }

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
    int p_id;
    std::cout << "Please enter the id of the passenger that needs to be removed: ";
    std::cin >> p_id;

    //Clearing the buffer
    char c;
    do{
        c = std::cin.get();
    }while(c!='\n' || c!=EOF);

    std::cout << std::endl;

    for(std::size_t i = 0;i<passengers.size();i++){
        if( p_id==passengers[i].getID() ){
            std::cout << "Passenger " << passengers[i].getID();
            passengers.erase( passengers.begin() + i );
            return;
        }
    }

    std::cout << "No passenger with the corresponding id exist in this flight." << std::endl;

    return;
}

const std::string& Flight::getFlightCode() const
{
    return flight_code;
}

void Flight::getPassengerRecords(std::vector<PassengerRecord> &records) const
{
    for(std::size_t i = 0;i<passengers.size();i++){
        records.push_back( passengers[i].getRecord(flight_code) );
    }
    return;
}

bool addPassengerInternal(const PassengerRecord &record, std::string &err_msg)
{
    (void)record;
    (void)err_msg;
    return false;
}
