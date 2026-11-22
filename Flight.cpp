// Implement the Flight member functions declared in Flight.h.
//
// Build the seat map from this flight's dimensions and passenger information.
// Implement the passenger display, addition and removal operations here.
#include "Flight.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Flight::Flight() : flight_code(), origin(),
        destination(), number_of_rows(), seats_per_row(), passengers(), seatMap() {}

Flight::Flight(const FlightRecord& source) : flight_code(source.flight_code), origin(source.origin),
        destination(source.destination), number_of_rows(source.number_of_rows),
        seats_per_row(source.seats_per_row), passengers(),
        seatMap( source.number_of_rows, std::vector<char>( source.seats_per_row, '-' ) ) {}

void Flight::displaySeatMap() const
{
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
    std::cout << std::setw(F_CODE_SIZE) << std::left << flight_code << "   "
            << std::setw(F_ORG_SIZE) << std::left << origin << "  "
            << std::setw(F_DEST_SIZE) << std::left << destination << "  "
            << std::setw(3) << std::left << number_of_rows << " "
            << seats_per_row << std::endl;
    return;
}

void Flight::addPassenger()
{
    PassengerRecord record;

    //Prompt the user for ID
    std::cout << "\nPlease enter the passenger id: ";
    if(!(std::cin >> record.passenger_id)){
        clearInputBuffer();
        std::cerr << "Error: Please enter a number." << std::endl;
        return;
    }
    clearInputBuffer();

    //Prompt the user for first name
    std::cout << "Please enter the passenger first name: ";
    std::cin >> record.first_name;
    clearInputBuffer();

    //Prompt the user for last name
    std::cout << "Please enter the passenger last name: ";
    std::cin >> record.last_name;
    clearInputBuffer();

    //Prompt the user for phone number
    std::cout << "Please enter the passenger phone number: ";
    std::cin >> record.phone_number;
    clearInputBuffer();

    //Prompt the user for row number
    std::cout << "Enter the passenger's desired row: ";
    if(!(std::cin >> record.seat_row)){
        clearInputBuffer();
        std::cerr << "Error: Please enter a number." << std::endl;
        return;
    }
    clearInputBuffer();

    //Prompt the user for seat letter
    std::cout << "Enter the passenger's desired seat: ";
    std::cin >> record.seat_letter;
    clearInputBuffer();

    std::string err_msg;
    if( !addPassengerInternal( record, err_msg ) ){
        std::cerr << "Error: " << err_msg << std::endl;
        return;
    }

    std::cout << "Passenger " << record.first_name << " " << record.last_name << " was added to flight " << flight_code << "." << std::endl;

    return;
}

void Flight::removePassenger()
{
    int p_id;
    std::cout << "\nPlease enter the id of the passenger that needs to be removed: ";
    if(!(std::cin >> p_id)){
        clearInputBuffer();
        std::cerr << "Error: Please enter a number." << std::endl;
        return;
    }
    clearInputBuffer();

    std::cout << std::endl;

    for(std::size_t i = 0;i<passengers.size();i++){
        if( p_id==passengers[i].getID() ){
            std::cout << "Passenger " << passengers[i].getFirstName() << " " << passengers[i].getLastName()
                    << " was successfully removed from flight " << flight_code << "." << std::endl;

            seatMap[ passengers[i].getSeatRow() - 1 ][ passengers[i].getSeatLetter() - 'A' ] = '-';
            
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

const std::string& Flight::getOrigin() const
{
    return origin;
}

const std::string& Flight::getDestination() const
{
    return destination;
}


void Flight::getPassengerRecords(std::vector<PassengerRecord> &records) const
{
    for(std::size_t i = 0;i<passengers.size();i++){
        records.push_back( passengers[i].getRecord(flight_code) );
    }
    return;
}

bool Flight::addPassengerInternal(const PassengerRecord &record, std::string &err_msg)
{
    if( record.passenger_id<0 ){
        err_msg = "The passenger ID was negative.";
        return false;
    }

    if( record.passenger_id>(int)(pow(10, P_ID_SIZE) - 1) ){
        err_msg = "The passenger ID exceeded +" + std::to_string(P_ID_SIZE) + " digits.";
        return false;
    }

    if( record.first_name.size() > P_NAME_SIZE || record.last_name.size() > P_NAME_SIZE ){
        err_msg = "The passenger's first or last name exceeded the letter limit, please truncate them to " + std::to_string(P_NAME_SIZE) + " letters only.";
        return false;
    }

    if( record.phone_number.size() != P_PHONE_SIZE || record.phone_number[3]!='-' || record.phone_number[7]!='-' ){
        err_msg = "The phone number was not in the correct format, please correct it to the xxx-xxx-xxxx format.";
        return false;        
    }

    if( record.seat_row <= 0 ){
        err_msg = "The seat row number was 0 or negative.";
        return false;
    }

    if( record.seat_row > number_of_rows ){
        err_msg = "The rows available for flight " + flight_code + " is only up to " + std::to_string(number_of_rows);
        return false;
    }

    if( record.seat_letter < 'A' || record.seat_letter > 'Z' ){
        err_msg = "The seat letter was incorrect, it must a capitalized letter.";
        return false;
    }

    if( (record.seat_letter - 'A' + 1) > seats_per_row ){
        err_msg = "The number of seats per row available for flight " + flight_code + " is only up to " + std::to_string(seats_per_row);
        return false;
    }

    if( seatMap[ record.seat_row - 1 ][ record.seat_letter - 'A' ]=='X' ){
        err_msg = "The seat position " + std::to_string(record.seat_row) + record.seat_letter + " on flight " + flight_code + " has already been occupied.";
        return false;
    }

    seatMap[ record.seat_row - 1 ][ record.seat_letter - 'A' ] = 'X';
    passengers.emplace_back( record );
    err_msg.clear();

    return true;
}
