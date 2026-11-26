/*
THIS FILE IS USED FOR GENERATING TEST CASE
it is also ugly as hell, don't bother too much with it
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <random>

#include "Flight.h"

using namespace std;

int ranrange(int l,int r){
    //Random int from 10^l (inclusive) to 10^r (exclusive)
    
    return ( 1ll*rand()*rand()*rand() % ( (int)(pow(10, r)) - (int)(pow(10, l)) ) ) + (int)(pow(10, l));
}

string phonegen(){
    return to_string( ranrange(2,3) ) + "-" + to_string( ranrange(2,3) ) + "-" + to_string( ranrange(3,4) );
}

int main()
{
    ofstream flight(".\\flights_test2.txt");
    //ofstream pass(".\\passengers_test2.txt");

    srand( time_t(NULL) );

    //Create 10 distinct flights
    vector<string> fcode{"AC", "WS", "PD", "F8", "AJ", "ME", "SW", "VA", "JJ", "FT"};
    for(auto &f : fcode){
        f.append( to_string( ranrange(2, 3) ) );
        cout << f << endl;
    }

    vector<string> places{"Calgary", "Edmonton", "Toronto", "Vancouver", "Victoria", "Montreal"};

    vector<FlightRecord> flights(10);
    vector<Flight> ff;
    ff.reserve(10);
    for(int i = 0;i<10;i++){
        if( rand()%3 ) //2 type, long (2 in 3), or wide (1 in 3)
            flights[i] = { fcode[i],
                        places[ rand() % places.size() ],
                        places[ rand() % places.size() ],
                        rand() % 40 + 1, 
                        rand() % 10 + 1 }; //technically can go to 26, but that's a bit much
        else
            flights[i] = { fcode[i],
                        places[ rand() % places.size() ],
                        places[ rand() % places.size() ],
                        rand() % 10 + 1, 
                        rand() % 26 + 1 };
        
        ff.emplace_back( flights[i] );
        flight << flights[i].flight_code << ' '
                << flights[i].origin << ' '
                << flights[i].destination << ' '
                << flights[i].number_of_rows << ' '
                << flights[i].seats_per_row << ' '
                << '\n'; //endl is expensive as hell for ofstream
    }

    //Random First Name and Last name, 30 each
    vector<string> fname{"Jade", "Lilyana", "Destinee", "Kassandra", "Amara", "Dane", "Yoselin", "Kamari", "Ramon", "Brenton", "Gabriel", "Beatrice", "Lilah", "Kade", "Isis", "Lilliana", "Jamarion", "Guillermo", "Josh", "Killian", "Raina", "Alondra", "Maya", "Frankie", "Ismael", "Leonel", "Zaniyah", "Casey", "Miracle", "Zariah"};
    vector<string> lname{"Pollard", "Frey", "Gill", "Velez", "Turner", "Hayes", "Wilkins", "Fernandez", "Fisher", "Lambert", "Nixon", "Thomas", "Hampton", "Shaw", "Suarez", "Stevens", "Mcintosh", "Lutz", "Davies", "Dillon", "Wang", "Clark", "Santos", "Sweeney", "Clements", "Hurst", "Sampson", "Kemp", "Ewing", "Vaughan"};

    //Randomly generate 300 record and throw 'em into random flights, some may survive, some may not, survival for the fittest (?)
    string err_msg;
    int fcoun = 0;
    for(int i = 300;i>=0;i--){

        int cur = rand() % 10;
        ff[ cur ].addPassengerInternal(
            {
                "",
                (int)(1ll * rand() * rand() * rand() % 100000),
                fname[ rand() % 30 ],
                lname[ rand() % 30 ],
                phonegen(),
                rand() % (flights[ cur ].number_of_rows) + 1,
                (char)( ( rand() % flights[ cur ].seats_per_row ) + 'A' )
            },
            err_msg
        );
        if( !err_msg.empty() ){
            err_msg.clear();
            fcoun++;
        }

    }

    vector<PassengerRecord> outfile;

    for(int i = 0;i<10;i++){
        cout << "\n\n=== " << ff[i].getFlightCode() << endl;
        ff[i].displayPassengers();
        ff[i].displaySeatMap();
        ff[i].getPassengerRecords(outfile);
    }

    auto rng = default_random_engine{};
    ranges::shuffle( outfile, rng );

    cout << "\n\nDeath count: " << fcoun << endl;

    writePassengerRecords(".\\passengers_test2.txt", outfile, err_msg);

    return 0;
}