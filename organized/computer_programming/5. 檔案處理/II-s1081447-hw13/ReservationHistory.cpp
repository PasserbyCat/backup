#include <iostream>
#include "ReservationHistory.h" // ReservationHistory class definition

extern int inputAnInteger( int begin, int end );

// ReservationHistory default constructor
ReservationHistory::ReservationHistory( ReservationDatabase &theReservationDatabase,
                                        SouthboundTimetable &theSouthboundTimetable,
                                        NorthboundTimetable &theNorthboundTimetable )
   : idNumber(),
     reservationNumber(),
     reservationDatabase( theReservationDatabase ),
     southboundTimetable( theSouthboundTimetable ),
     northboundTimetable( theNorthboundTimetable )
{
} // end ReservationHistory default constructor

void ReservationHistory::execute()
{
    cout << "Enter ID Number: ";
    cin >> idNumber;
    cin.ignore();
    cout << endl;
    cout << "Enter Reservation Number : ";
    cin >> reservationNumber;
    cin.ignore();
    cout << endl;

    if (reservationDatabase.exist(idNumber, reservationNumber)) {
        reservationDatabase.displayReservation(idNumber, reservationNumber);

        int choice;
        while (true)
        {
            cout << "\nEnter Your Choice\n"
                << "1. Cancellation\n"
                << "2. Reduce\n"
                << "3. End";

            do cout << "\n? ";
            while ((choice = inputAnInteger(1, 3)) == -1);
            cout << endl;

            switch (choice)
            {
            case 1:
                reservationDatabase.cancelReservation(idNumber, reservationNumber);
                return;
            case 2:
                reservationDatabase.reduceSeats(idNumber, reservationNumber);
                return;
            case 3:
                return;
            default:
                cerr << "Incorrect Choice!\n";
                break;
            }
        }
    }
    else {
        cout << "Reservation record not found.\n";
    }
}