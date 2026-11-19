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

void Flight::clearInputBuffer() const
{
    //cin.clear() is needed since if user try something like inputing letter to int
    //it will spontanously explode
    std::cin.clear();
    char c;
    do{
        c = std::cin.get();
    }while(c!='\n' && c!=EOF);
    return;
}

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
    PassengerRecord record;

    //Prompt the user for ID
    std::cout << "Please enter the passenger id: ";
    if(!(std::cin >> record.passenger_id)){
        clearInputBuffer();
        std::cout << "Error: Please enter a number." << std::endl;
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
        std::cout << "Error: Please enter a number." << std::endl;
        return;
    }
    clearInputBuffer();

    //Prompt the user for seat letter
    std::cout << "Enter the passenger's desired seat: ";
    std::cin >> record.seat_letter;
    clearInputBuffer();

    std::string err_msg;
    if( !addPassengerInternal( record, err_msg ) ){
        std::cout << "Error: " << err_msg << std::endl;
        return;
    }

    std::cout << "Passenger " << record.first_name << " " << record.last_name << " was added to flight " << flight_code << "." << std::endl;

    return;
}

void Flight::removePassenger()
{
    int p_id;
    std::cout << "Please enter the id of the passenger that needs to be removed: ";
    std::cin >> p_id;

    clearInputBuffer();

    std::cout << std::endl;

    for(std::size_t i = 0;i<passengers.size();i++){
        if( p_id==passengers[i].getID() ){
            std::cout << "Passenger " << passengers[i].getFirstName() << " " << passengers[i].getLastName()
                    << " was successfully removed from flight " << flight_code << "." << std::endl;
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
        err_msg = "A passenger ID was negative.";
        return false;
    }

    if( record.passenger_id>(int)(pow(10, P_ID_SIZE) - 1) ){
        err_msg = "A passenger ID exceeded 5 digits.";
        return false;
    }

    if( record.first_name.size() > P_NAME_SIZE || record.last_name.size() > P_NAME_SIZE ){
        err_msg = "A passenger name exceeded the letter limit, please truncate them to " + P_NAME_SIZE + '.';
        return false;
    }

    if( record.phone_number.size() != P_PHONE_SIZE || record.phone_number[3]!='-' || record.phone_number[7]!='-' ){
        err_msg = "A passenger phone number is not in the correct format, please correct it to the xxx-xxx-xxxx format.";
        return false;        
    }

    if( record.seat_row <= 0 ){
        err_msg = "A passenger seat row number is 0 or negative.";
        return false;
    }

    if( record.seat_row > number_of_rows ){
        err_msg = "A passenger seat row number exceeded number of rows available.";
        return false;
    }

    if( record.seat_letter < 'A' || record.seat_letter > 'Z' ){
        err_msg = "A passenger seat letter is incorrect, please capitalize the row letter.";
        return false;
    }

    if( (record.seat_letter - 'A' + 1) > seats_per_row ){
        err_msg = "A passenger seat letter exceeded the number of seats available per row.";
        return false;
    }

    passengers.emplace_back( record );
    err_msg.clear();

    return true;
}
