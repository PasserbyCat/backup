// ReservationDatabase.cpp
// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <fstream>
using namespace std;
#include "ReservationDatabase.h"

extern int inputAnInteger(int begin, int end);

// ReservationDatabase default constructor loads reservations from the file Reservation details.dat
ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

// ReservationDatabase destructor stores reservations into the file Reservation details.dat
ReservationDatabase::~ReservationDatabase()
{
   storeReservations();
}

void ReservationDatabase::loadReservations()
{
    fstream file("Reservation details.dat", ios::in | ios::out | ios::binary);
    file.seekg(0, ios::end);
    int truesize = file.tellg() / sizeof(Reservation);
    file.seekg(0, ios::beg);
    reservations.resize(truesize);
    for (int i = 0; i < truesize; i++) {
        file.read(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
    }
    file.close();
}

void ReservationDatabase::storeReservations()
{
    fstream file("Reservation details.dat", ios::in | ios::out | ios::binary);
    for (int i = 0; i < reservations.size(); i++) {
        file.write(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
    }
}

bool ReservationDatabase::exist( string idNumber, string reservationNumber )
{
   // loop through reservations searching for matching idNumber and reservationNumber
   for( vector< Reservation >::iterator it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getIdNumber() == idNumber && it->getReservationNumber() == reservationNumber )
         return true; // return true if match found

   return false; // if no matching reservation was found, return false
}

void ReservationDatabase::displayReservation( string idNumber, string reservationNumber )
{
    cout << "Reservation Details\n";

   vector< Reservation >::iterator it = searchReservation( idNumber, reservationNumber );
   it->displayReservationDetails();
}

void ReservationDatabase::cancelReservation( string idNumber, string reservationNumber )
{
   vector< Reservation >::iterator it = searchReservation( idNumber, reservationNumber );
   reservations.erase( it );
   cout << "Reservation Cancelled.\n\n";
}

void ReservationDatabase::addReservation( Reservation reservation )
{
   reservations.push_back( reservation );
}

void ReservationDatabase::reduceSeats( string idNumber, string reservationNumber )
{
    int i;
    for (i = 0; !exist(idNumber, reservationNumber); i++);
    int adult, concession;
    cout << "How many adult tickets to cancel? ";
    while ((adult = inputAnInteger(0, reservations[i].getAdultTickets())) == -1) { cout << "Input number is bigger than your adult tickets. Please choose again." << endl; }
    reservations[i].setAdultTickets(reservations[i].getAdultTickets() - adult);
    
    cout << "How many concession tickets to cancel? ";
    while ((concession = inputAnInteger(0, reservations[i].getConcessionTickets())) == -1) { cout << "Input number is bigger than your concession tickets. Please choose again." << endl; }
    reservations[i].setConcessionTickets(reservations[i].getAdultTickets() - concession);
    cout << endl;
   
    if (reservations[i].getConcessionTickets() == 0 && reservations[i].getAdultTickets() == 0)
        cancelReservation(idNumber, reservationNumber);

    displayReservation(idNumber, reservationNumber);

    cout << "\nYou have successfully reduced the number of tickets!\n";
}

vector< Reservation >::iterator ReservationDatabase::searchReservation( string idNumber, string reservationNumber )
{
   // loop through reservations searching for matching idNumber and reservationNumber
   for( vector< Reservation >::iterator it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getIdNumber() == idNumber && it->getReservationNumber() == reservationNumber )
         return it; // return iterator to thecurrent reservation if match found

   return reservations.end();
}