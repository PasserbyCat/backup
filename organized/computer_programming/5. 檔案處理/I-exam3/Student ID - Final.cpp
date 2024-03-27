#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

int adultTicketPrice[ 13 ][ 13 ] = {
   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,  500,  700,  920, 1330, 1510, 1660, 1880, 2290, 2500,
   0,   40,    0,    0,  440,  640,  850, 1250, 1430, 1600, 1820, 2230, 2440,
   0,   70,   40,    0,  400,  590,  800, 1210, 1390, 1550, 1780, 2180, 2390,
   0,  200,  160,  130,    0,  400,  620, 1010, 1210, 1370, 1580, 1990, 2200,
   0,  330,  290,  260,  130,    0,  410,  820, 1010, 1160, 1390, 1790, 2000,
   0,  480,  430,  400,  280,  140,    0,  610,  790,  950, 1160, 1580, 1790,
   0,  750,  700,  670,  540,  410,  270,    0,  400,  550,  770, 1180, 1390,
   0,  870,  820,  790,  670,  540,  390,  130,    0,  370,  580, 1000, 1210,
   0,  970,  930,  900,  780,  640,  500,  230,  110,    0,  430,  830, 1040,
   0, 1120, 1080, 1050,  920,  790,  640,  380,  250,  150,    0,  620,  820,
   0, 1390, 1350, 1320, 1190, 1060,  920,  650,  530,  420,  280,    0,  410,
   0, 1530, 1490, 1460, 1330, 1200, 1060,  790,  670,  560,  410,  140,    0 };

char departureTimes[ 37 ][ 8 ] = { "",
   "06:00", "06:30", "07:00", "07:30", "08:00", "08:30", "09:00", "09:30",
   "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30",
   "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30",
   "18:00", "18:30", "19:00", "19:30", "20:00", "20:30", "21:00", "21:30",
   "22:00", "22:30", "23:00", "23:30" };

struct Reservation
{
   char reservationNumber[ 12 ]; // used to identify a reservation
   char trainNumber[ 8 ];  // used to identify a train
   char idNumber[ 12 ];    // the id number of the contact person
   char phone[ 12 ];       // the (local or mobile) phone number of the contact person
   char date[ 12 ];        // outbound date
   int originStation;      // the origin station code
   int destinationStation; // the destination station code
   int carClass;           // the car class code; 1:standard car, 2:business car
   int adultTickets;       // the number of adult tickets
   int concessionTickets;  // the number of concession tickets
};

struct Train
{
   char trainNumber[ 8 ];          // used to identify a train
   char departureTimes[ 13 ][ 8 ]; // the departure time of a train for each station,
};                                 // departureTimes[0] is not used

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

void makingReservation( Train southboundTimetable[ 100 ], Train northboundTimetable[ 100 ] );

// inputs originStation, destinationStation, carClass,
// date, departureTime, adultTickets and concessionTickets
void inputReservationDetails( Reservation &reservation, int &departureTime );

// loads the southbound timetable from the file "Southbound timetable.dat"
void loadSouthboundTimetable( Train southboundTimetable[ 100 ], int &numSouthboundTrains );

// loads the northbound timetable from the file "Northbound timetable.dat"
void loadNorthboundTimetable( Train northboundTimetable[ 100 ], int &numNorthboundTrains );

// displays timetables for 10 coming southbound trains, then let user select one
void selectSouthboundTrain( Train southboundTimetable[ 100 ], int numSouthboundTrains,
                            Reservation &reservation, int departureTime );

// displays timetables for 10 coming northbound trains, then let user select one
void selectNorthboundTrain( Train northboundTimetable[ 100 ], int numNorthboundTrains,
                            Reservation &reservation, int departureTime );

// inputs idNumber and phone, and randomly generate reservationNumber
void inputContactInfo( Reservation &reservation );

// save reservation to the end of the file Reservation details.dat
void saveReservation( Reservation reservation );

void reservationHistory( Train southboundTimetable[ 100 ],
                         Train northboundTimetable[ 100 ] );

// inputs idNumber and reservationNumber, and
// checks if the corresponding reservation exists
bool existReservation( fstream &ioFile, Reservation &reservation );


void displayReservations( Train southboundTimetable[ 100 ],
                          Train northboundTimetable[ 100 ], Reservation reservation );

// displays date, originStation, destinationStation, departureTime, arrival time,
// fare for adultTickets, fare for concessionTickets and total fare
void display( Reservation reservation, Train trainTimetable[ 100 ],
              char stations[ 13 ][ 12 ], char carClass[ 12 ] );

// reduces adultTickets and/or concessionTickets in reservation
void reduceSeats( fstream &ioFile, Train southboundTimetable[ 100 ],
                  Train northboundTimetable[ 100 ], Reservation &reservation );

int main()
{
   cout << "Taiwan High Speed Rail Booking System\n";
   srand( static_cast< unsigned int >( time( 0 ) ) );

   Train southboundTimetable[ 100 ];
   Train northboundTimetable[ 100 ];
   int choice; // store user choice

   // enable user to specify action
   while( true )
   {
      cout << "\nEnter Your Choice\n"
         << "1. Booking\n"
         << "2. Booking History\n"
         << "3. End Program";

      do cout << "\n? ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      cout << endl;

      switch( choice )
      {
      case 1:
         makingReservation( southboundTimetable, northboundTimetable );
         break;
      case 2:
         reservationHistory( southboundTimetable, northboundTimetable );
         break;
      case 3:
         cout << "Thank you! Goodbye!\n\n";
         system( "pause" );
         return 0;
      default: // display error if user does not select valid choice
         cerr << "Incorrect Choice!\n";
         break;
      }
   }

   system( "pause" );
} // end main