# ENSF-337-Term-Project-Group-2
The repo for the term project of ENSF 337.

# Implementation
ONLY use C++ functions and class for this project
I.e. no printf(), no scanf(), no char* (use std::string instead), no dynamic array (use std::vector instead),...

Make sure to use "std::" instead of including "using namespace std;" at the start of file

# Compilation and testing
When compiling, use the following:
For Windows:
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o main.exe

For Macs (not sure, I'm using Windows):
clang++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp Passenger.cpp Flight.cpp Airline.cpp FileRecordIO.cpp -o main.exe

You can create test.cpp to test the functionality of your codes, it won't be committed.
main.exe will also not be committed.

As for the -D flag for testing file, we can do it later.
Might be a good idea to mark the -DTEST2 for accessing flights_test2.txt and passengers_test2.txt