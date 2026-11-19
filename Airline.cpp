// Implement the Airline member functions declared in Airline.h.
//
// Use the supplied FileRecordIO functions when loading and saving records.
// Convert the loaded FlightRecord and PassengerRecord values into the
// appropriate Flight and Passenger objects.
// Ensure each Passenger object is placed in the appropriate Flight object.
#include "Airline.h"

#include <iostream>
#include <iomanip>

#define FLIGHTS_FILEPATH "\\flights.txt"
#define PASSENGERS_FILEPATH "\\passengers.txt"

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

Flight* Airline::findFlight()
{
    std::size_t index; // Input variable

    std::cout << "Enter the flight number: "; // Input instructions
    std::cin >> index; // Get input

    if (index < flights.size() && index >= 0) // If the received input is in range (not below 0 or above the vector length)
    {
        Flight f = flights[index]; // Get the flight at that index (mostly to make output nicer)

        std::cout << "You have selected flight " << f.getFlightCode() << " from " 
        << f.getOrigin() << " to " << f.getDestination() << "." << std::endl; // Output

        return &f; // Return the address of the flight
    }
    // If the received input is OUT of range
    std::cout << "Invalid flight number: " << index << std::endl; // Output
    return NULL; // Return NULL
}

bool Airline::loadData()
{
    std::string error_message; // Container for any error messages that are triggered

    std::vector<FlightRecord> flight_records; // Vector to contain collected flight records

    // Read flight records from the constant filepath, store records in the vector and errors in the string
    if (readFlightRecords(FLIGHTS_FILEPATH, flight_records, error_message)) // If flights are read successfully
    {
        for (std::size_t f = 0; f < flight_records.size(); f++) // For each flight record
        {
            flights.push_back(Flight(flight_records[f])); // Add a new flight based on the record into flights member
        }

        std::vector<PassengerRecord> passenger_records; // Vector to contain collected passenger records

        // Read passenger records from the constant filepath, store records in the vector and errors in the same string as before
        if (readPassengerRecords(PASSENGERS_FILEPATH, passenger_records, error_message)); // If passengers are read successfully
        {
            bool success = true; // Boolean for if everything was successful

            for (std::size_t p = 0; p < passenger_records.size(); p++) // For each passenger record
            {
                // Determine if the passenger's flight code exists

                int index = -1; // Index of matching flight
                for (std::size_t f = 0; f < flights.size(); f++) // For each flight
                {
                    // If the flight code is the passenger's flight code
                    if (flights[f].getFlightCode() == passenger_records[p].flight_code) 
                    {
                        index = f; // Store the index of the flight
                        break; // Break the flight loop
                    }
                }
                if (index == -1) // If the index was never changed (flight code never found)
                {
                    error_message = "Flight code not found: " + passenger_records[p].flight_code; // Set error message
                    success = false; // Set success to false
                    break; // Break the passenger loop
                }
                
                // Add the passenger to the flight, and store the success in the boolean
                success = flights[index].addPassengerInternal(passenger_records[p], error_message); // Store the error message too
                if (!success) break; // If unsuccessful, break the passenger loop
            }
            if (success) return true; //If the passenger loop completed successfully, return true
            // If the passenger loop did not complete successfully
        }
        // If passenger records are not correctly returned
    }
    // If flight records are not correctly returned

    std::cerr << error_message << std::endl; // Output whatever error message caused the logic structure to end
    return false; // Return false
}

bool Airline::savePassengerData() const
{  
    std::vector<PassengerRecord> records; // Vector to store passenger records in

    for (int f = 0; f < flights.size(); f++) // For each flight
    {
        flights[f].getPassengerRecords(records); // Get all passenger records for the flight, and append them to records
    }

    std::string error_message; // String to store any error messages

    // Write all records to the constant filepath from records vector, holding any error message
    if (writePassengerRecords(PASSENGERS_FILEPATH, records, error_message)) return true; // If successful, return true
    // If unsuccessful
    std::cerr << error_message << std::endl; // Error message
    return false; // Return false
}
