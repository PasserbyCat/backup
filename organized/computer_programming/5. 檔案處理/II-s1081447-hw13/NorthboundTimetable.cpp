// NorthboundTimetable.cpp
// Member-function definitions for class NorthboundTimetable.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "NorthboundTimetable.h"

extern string departureTimes[ 37 ];

// NorthboundTimetable default constructor
// loads northbound timetable from the file "Northbound timetable.dat"
NorthboundTimetable::NorthboundTimetable()
{
   loadNorthboundTimetable();
}

void NorthboundTimetable::loadNorthboundTimetable()
{
    fstream file("Northbound timetable.dat", ios::in | ios::out | ios::binary);
    file.seekg(0, ios::end);
    int truesize = file.tellg() / sizeof(Train);
    file.seekg(0, ios::beg);
    northboundTimetable.resize(truesize);
    for (int i = 0; i < truesize; i++) {
        file.read(reinterpret_cast<char*>(&northboundTimetable[i]), sizeof(Train));
    }
    file.close();
}

// returns departureTimes[ station ]
string NorthboundTimetable::getDepartureTimes( string trainNumber, int station )
{
   vector< Train >::iterator it = searchTrain( trainNumber );
   return it->getDepartureTimes( station );
}

bool NorthboundTimetable::trainsAvailable( int departureTime,
     int originStation, int destinationStation )
{
    for (int i = 0; i < northboundTimetable.size(); i++) {
        if (departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(originStation) &&
            departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(destinationStation)) {
            return true;
        }
    }
    return false;
}

void NorthboundTimetable::displayComingTrains( int departureTime,
     int originStation, int destinationStation )
{
    bool times = true;
    int test = 0;
    cout << endl << "Train No.  Departure  Arrival" << endl;
    for (int i = 0; i < northboundTimetable.size(); i++) {
        if (departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(13 - originStation) &&
            departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(13 - destinationStation)) {
            times = false;
            cout << setw(9) << northboundTimetable[i].getTrainNumber()
                << setw(11) << northboundTimetable[i].getDepartureTimes(13 - originStation)
                << setw(9) << northboundTimetable[i].getDepartureTimes(13 - destinationStation)
                << endl;
            test++;
        }
        if (test == 10)
            break;
        if (i == northboundTimetable.size() - 1 && times)
            cout << "Sorry! No train is available!" << endl;
    }
    cout << endl;
}

vector< Train >::iterator NorthboundTimetable::searchTrain( string trainNumber )
{
   vector< Train >::iterator it = northboundTimetable.begin();
   for( ; it != northboundTimetable.end(); ++it )
      if( it->getTrainNumber() == trainNumber )
         return it;

   return northboundTimetable.end();
}