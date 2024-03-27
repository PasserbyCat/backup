// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include <iomanip>
#include "MakingReservation.h" // MakingReservation class definition

extern int inputAnInteger( int begin, int end );

extern string departureTimes[ 37 ];

// MakingReservation constructor
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
                                      SouthboundTimetable &theSouthboundTimetable,
                                      NorthboundTimetable &theNorthboundTimetable )
   : reservationDatabase( theReservationDatabase ),
     southboundTimetable( theSouthboundTimetable ),
     northboundTimetable( theNorthboundTimetable )
{
}

void MakingReservation::execute()
{
   if( chooseTrain() ) // displays timetables for 10 coming trains, then let user choose a train
   {
      inputReservationDetails();

      inputContactPersonInfo();

      reservationDatabase.addReservation( reservation );

      cout << "\nReservation Completed!\n\n";
   }
   else
      cout << "\nSorry! No train is available!\n\n";
}

bool MakingReservation::chooseTrain()
{
    int originStation;
    cout << endl << "Origin Station" << endl
        << "1. Nangang" << endl
        << "2. Taipei" << endl
        << "3. Banqiao" << endl
        << "4. Taoyuan" << endl
        << "5. Hsinchu" << endl
        << "6. Miaoli" << endl
        << "7. Taichung" << endl
        << "8. Changhua" << endl
        << "9. Yunlin" << endl
        << "10. Chiayi" << endl
        << "11. Tainan" << endl
        << "12. Zuoying" << endl
        << "? ";
    while ((originStation = inputAnInteger(1, 12)) == -1) { cout << "Your input is incorrect. Please choose again." << endl; }
    reservation.setOriginStation(originStation);

    int destinationStation;
    cout << endl << "Destination Station" << endl
        << "1. Nangang" << endl
        << "2. Taipei" << endl
        << "3. Banqiao" << endl
        << "4. Taoyuan" << endl
        << "5. Hsinchu" << endl
        << "6. Miaoli" << endl
        << "7. Taichung" << endl
        << "8. Changhua" << endl
        << "9. Yunlin" << endl
        << "10. Chiayi" << endl
        << "11. Tainan" << endl
        << "12. Zuoying" << endl
        << "? ";
    while (1)
    {
        destinationStation = inputAnInteger(1, 12);
        if (destinationStation == -1)
            cout << "Your input is incorrect. Please choose again." << endl;
        else if (destinationStation == originStation)
            cout << "The destinationStation cannot be same as the originStation. Please choose again." << endl;
        else
            break;
    }
    reservation.setDestinationStation(destinationStation);

    int departureTime;
    cout << endl << "Departure Time" << endl
        << "1. 06 : 00" << endl
        << "2. 06 : 30" << endl
        << "3. 07 : 00" << endl
        << "4. 07 : 30" << endl
        << "5. 08 : 00" << endl
        << "6. 08 : 30" << endl
        << "7. 09 : 00" << endl
        << "8. 00 : 30" << endl
        << "9. 10 : 00" << endl
        << "10. 10 : 30" << endl
        << "11. 11 : 00" << endl
        << "12. 11 : 30" << endl
        << "13. 12 : 00" << endl
        << "14. 12 : 30" << endl
        << "15. 13 : 00" << endl
        << "16. 13 : 30" << endl
        << "17. 14 : 00" << endl
        << "18. 14 : 30" << endl
        << "19. 15 : 00" << endl
        << "20. 15 : 30" << endl
        << "21. 16 : 00" << endl
        << "22. 16 : 30" << endl
        << "23. 17 : 00" << endl
        << "24. 17 : 30" << endl
        << "25. 18 : 00" << endl
        << "26. 18 : 30" << endl
        << "27. 19 : 00" << endl
        << "28. 19 : 30" << endl
        << "29. 20 : 00" << endl
        << "30. 20 : 30" << endl
        << "31. 21 : 00" << endl
        << "32. 21 : 30" << endl
        << "33. 22 : 00" << endl
        << "34. 22 : 30" << endl
        << "35. 23 : 00" << endl
        << "36. 23 : 30" << endl
        << "? ";
    while ((departureTime = inputAnInteger(1, 36)) == -1) { cout << "Your input is incorrect. Please choose again." << endl; }

    if (originStation < destinationStation) {
        if (!southboundTimetable.trainsAvailable(departureTime, originStation, destinationStation)) {
            return false;
        }
        southboundTimetable.displayComingTrains(departureTime, originStation, destinationStation);
    }
    else {
        if (!northboundTimetable.trainsAvailable(departureTime, originStation, destinationStation)) {
            return false;
        }
        northboundTimetable.displayComingTrains(departureTime, originStation, destinationStation);
    }
    string temp;
    cout << "Enter Train Number: ";
    cin >> temp;
    cin.ignore();
    reservation.setTrainNumber(temp);
    return true;
}

void MakingReservation::inputReservationDetails()
{
   cout << "\nCar Class\n" << "1. Standard Car\n" << "2. Business Car";

   int carClass;
   do cout << "\n? ";
   while( ( carClass = inputAnInteger( 1, 2 ) ) == -1 );
   reservation.setCarClass( carClass );

	cout << "\nDeparture Date: ";

   char date[12];
   cin >> date;
   reservation.setDate( date );
   cin.ignore();

	cout << "\nHow many adult tickets? ";

   int adultTickets;
   cin >> adultTickets;
   reservation.setAdultTickets( adultTickets );

	cout << "\nHow many concession tickets? ";

   int concessionTickets;
   cin >> concessionTickets;
   reservation.setConcessionTickets( concessionTickets );

   cout << "\nTrip Details\n";
   reservation.displayReservationDetails();
}

void MakingReservation::inputContactPersonInfo()
{
   cout << "\nEnter Contact Person Information\n\n";

   cout << "ID Number: ";
   string idNumber;
   cin >> idNumber;
   reservation.setIdNumber( idNumber );

   cout << "\nPhone: ";
   string phone;
   cin >> phone;
   cin.ignore();
   reservation.setPhone( phone );

   srand( static_cast< unsigned int >( time( 0 ) ) );
   char reservationNumber[ 12 ];
   for( int i = 0; i < 8; i++ )
      reservationNumber[ i ] = rand() % 10 + '0';
   reservationNumber[ 8 ] = '\0';
   reservation.setReservationNumber( reservationNumber );
   
	cout << "\nReservation Number: " << reservationNumber << endl;
}