# ENSF-337-Term-Project-Group-2
The repo for the term project of ENSF 337.

# Implementation
ONLY use C++ functions and class for this project
I.e. no printf(), no scanf(), no char* (use std::string instead), no dynamic array (use std::vector instead),...

Make sure to use "std::" instead of including "using namespace std;" at the start of file

Make sure to clear the input buffer with clearInputBuffer after every input to prevent unintended behaviours

# Compilation and testing
When compiling, use the following:
For Windows:
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp AirlineUtility.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o main.exe

For Macs (not sure, I'm using Windows):
clang++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp AirlineUtility.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o main.exe

You can create test.cpp to test the functionality of your codes, it won't be committed.
main.exe will also not be committed.

When compiling for test case 2, use the following:
For Windows:
g++ -std=c++17 -Wall -Wextra -Wpedantic -DTEST2 main.cpp AirlineUtility.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o test2.exe

For Macs:
clang++ -std=c++17 -Wall -Wextra -Wpedantic -DTEST2 main.cpp AirlineUtility.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o test2.exe

# Test case 2 generation
To re-generate test case 2:
Compile with the following flags:
-std=c++17 -Wall -Wextra -Wpedantic generator.cpp AirlineUtility.cpp Passenger.cpp Flight.cpp FileRecordIO.cpp -o generator.exe

Then run with:
.\generator.exe