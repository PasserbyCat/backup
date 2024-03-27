// FlightSchedule.cpp
// Member-function definitions for class SouthboundTimetable.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SouthboundTimetable.h"

extern string departureTimes[ 37 ];

// SouthboundTimetable default constructor
// loads southbound timetable from the file "Southbound timetable.dat"
SouthboundTimetable::SouthboundTimetable()
{
   loadSouthboundTimetable();
}

void SouthboundTimetable::loadSouthboundTimetable()
{
    fstream file("Southbound timetable.dat", ios::in | ios::out | ios::binary);
    file.seekg(0, ios::end);
    int truesize = file.tellg() / sizeof(Train);
    file.seekg(0, ios::beg);
    southboundTimetable.resize(truesize);
    for (int i = 0; i < truesize; i++) {
        file.read(reinterpret_cast<char*>(&southboundTimetable[i]), sizeof(Train));
    }
    file.close();
}

// returns departureTimes[ station ]
string SouthboundTimetable::getDepartureTimes( string trainNumber, int station )
{
   vector< Train >::iterator it = searchTrain( trainNumber );
   return it->getDepartureTimes( station );
}

bool SouthboundTimetable::trainsAvailable( int departureTime,
     int originStation, int destinationStation )
{
    for (int i = 0; i < southboundTimetable.size(); i++) {
        if (departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(originStation) &&
            departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(destinationStation)) {
            return true;
        }
    }
    return false;
}

void SouthboundTimetable::displayComingTrains( int departureTime,
     int originStation, int destinationStation )
{
    bool times = true;
    int test = 0;
    cout << endl << "Train No.  Departure  Arrival" << endl;
    for (int i = 0; i < southboundTimetable.size(); i++) {
        if (departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(originStation) &&
            departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(destinationStation)) {
            times = false;
            cout << setw(9) << southboundTimetable[i].getTrainNumber()
                << setw(11) << southboundTimetable[i].getDepartureTimes(originStation)
                << setw(9) << southboundTimetable[i].getDepartureTimes(destinationStation)
                << endl;
            test++;
        }
        if (test == 10)
            break;
        if (i == southboundTimetable.size() - 1 && times)
            cout << "Sorry! No train is available!" << endl;
    }
    cout << endl;
}

vector< Train >::iterator SouthboundTimetable::searchTrain( string trainNumber )
{
   vector< Train >::iterator it = southboundTimetable.begin();
   for( ; it != southboundTimetable.end(); ++it )
      if( it->getTrainNumber() == trainNumber )
         return it;

   return southboundTimetable.end();
}