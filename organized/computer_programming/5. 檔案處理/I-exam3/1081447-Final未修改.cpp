#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

#include <vector>

using namespace std;

int adultTicketPrice[13][13] = {
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

char departureTimes[37][8] = { "",
   "06:00", "06:30", "07:00", "07:30", "08:00", "08:30", "09:00", "09:30",
   "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30",
   "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30",
   "18:00", "18:30", "19:00", "19:30", "20:00", "20:30", "21:00", "21:30",
   "22:00", "22:30", "23:00", "23:30" };

struct Reservation
{
	char reservationNumber[12]; // used to identify a reservation
	char trainNumber[8];  // used to identify a train
	char idNumber[12];    // the id number of the contact person
	char phone[12];       // the (local or mobile) phone number of the contact person
	char date[12];        // outbound date
	int originStation;      // the origin station code
	int destinationStation; // the destination station code
	int carClass;           // the car class code; 1:standard car, 2:business car
	int adultTickets;       // the number of adult tickets
	int concessionTickets;  // the number of concession tickets
};

struct Train
{
	char trainNumber[8];          // used to identify a train
	char departureTimes[13][8]; // the departure time of a train for each station,
};                                 // departureTimes[0] is not used

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end);

void makingReservation(Train southboundTimetable[100], Train northboundTimetable[100]);

// inputs originStation, destinationStation, carClass,
// date, departureTime, adultTickets and concessionTickets
void inputReservationDetails(Reservation& reservation, int& departureTime);

// loads the southbound timetable from the file "Southbound timetable.dat"
void loadSouthboundTimetable(Train southboundTimetable[100], int& numSouthboundTrains);

// loads the northbound timetable from the file "Northbound timetable.dat"
void loadNorthboundTimetable(Train northboundTimetable[100], int& numNorthboundTrains);

// displays timetables for 10 coming southbound trains, then let user select one
void selectSouthboundTrain(Train southboundTimetable[100], int numSouthboundTrains,
	Reservation& reservation, int departureTime);

// displays timetables for 10 coming northbound trains, then let user select one
void selectNorthboundTrain(Train northboundTimetable[100], int numNorthboundTrains,
	Reservation& reservation, int departureTime);

// inputs idNumber and phone, and randomly generate reservationNumber
void inputContactInfo(Reservation& reservation);

// save reservation to the end of the file Reservation details.dat
void saveReservation(Reservation reservation);

void reservationHistory(Train southboundTimetable[100],
	Train northboundTimetable[100]);

// inputs idNumber and reservationNumber, and
// checks if the corresponding reservation exists
bool existReservation(fstream& ioFile, Reservation& reservation);


void displayReservations(Train southboundTimetable[100],
	Train northboundTimetable[100], Reservation reservation);

// displays date, originStation, destinationStation, departureTime, arrival time,
// fare for adultTickets, fare for concessionTickets and total fare
void display(Reservation reservation, Train trainTimetable[100],
	char stations[13][12], char carClass[12]);

// reduces adultTickets and/or concessionTickets in reservation
void reduceSeats(fstream& ioFile, Train southboundTimetable[100],
	Train northboundTimetable[100], Reservation& reservation);

int main()
{
	cout << "Taiwan High Speed Rail Booking System\n";
	srand(static_cast<unsigned int>(time(0)));

	Train southboundTimetable[100];
	Train northboundTimetable[100];
	int choice; // store user choice

	// enable user to specify action
	while (true)
	{
		cout << "\nEnter Your Choice\n"
			<< "1. Booking\n"
			<< "2. Booking History\n"
			<< "3. End Program";

		do cout << "\n? ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice)
		{
		case 1:
			makingReservation(southboundTimetable, northboundTimetable);
			break;
		case 2:
			reservationHistory(southboundTimetable, northboundTimetable);
			break;
		case 3:
			cout << "Thank you! Goodbye!\n\n";
			system("pause");
			return 0;
		default: // display error if user does not select valid choice
			cerr << "Incorrect Choice!\n";
			break;
		}
	}

	system("pause");
} // end main

int inputAnInteger(int begin, int end)
{
	char input;
	cin >> input;
	char choice[1000];
	int number = 0, i = 0;
	while (true) {
		if (input == '\n')
			break;
		choice[i] = input;
		cin.get(input);
		i++;
	}
	for (int j = 0; j < i; j++) {
		number += (choice[j] - '0') * pow(10, i - j - 1);
	}
	cout << endl;
	if (number >= begin && number <= end)
		return number;
	else
		return -1;
}

void makingReservation(Train southboundTimetable[100], Train northboundTimetable[100])
{
	Reservation reservation;
	int departureNumber;
	inputReservationDetails(reservation, departureNumber);

	if (reservation.originStation > reservation.destinationStation) {
		loadNorthboundTimetable(northboundTimetable, reservation.originStation);
		selectNorthboundTrain(northboundTimetable, reservation.originStation, reservation, departureNumber);
	}
	else {
		loadSouthboundTimetable(southboundTimetable, reservation.originStation);
		selectSouthboundTrain(southboundTimetable, reservation.originStation, reservation, departureNumber);
	}
	inputContactInfo(reservation);
	saveReservation(reservation);
}

void inputReservationDetails(Reservation& reservation, int& departureTime)
{
	cout << "Origin Station\n1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan\n5. Hsinchu\n6. Miaoli\n"
		"6. Miaoli\n7. Taichung\n8. Changhua\n9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying\n";
	do cout << "\n? ";
	while ((reservation.originStation = inputAnInteger(1, 12)) == -1);

	cout << "Destination Station\n1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan\n5. Hsinchu\n6. Miaoli\n"
		"6. Miaoli\n7. Taichung\n8. Changhua\n9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying\n";
	do cout << "\n? ";
	while ((reservation.destinationStation = inputAnInteger(1, 12)) == -1 || reservation.destinationStation == reservation.originStation);

	
	if (reservation.originStation <= 3 && reservation.destinationStation <= 3) {
		cout << "Car Class\n1. Standard Car\n";
		do cout << "\n? ";
		while ((reservation.carClass = inputAnInteger(1, 1)) == -1);
	}
	else {
		cout << "Car Class\n1. Standard Car\n2. Business Car\n";
		do cout << "\n? ";
		while ((reservation.carClass = inputAnInteger(1, 2)) == -1);
	}

	cout << "Departure Date : ";
	cin >> reservation.date;

	cout << "\nDeparture Time\n";
	for (int i = 0; i < 34; i++)
		cout << i + 1 << " " << departureTimes[i + 1] << endl;
	do cout << "\n? ";
	while ((departureTime = inputAnInteger(1, 34)) == -1);
	while (1) {
		cout << "How many adult tickets? ";
		cin >> reservation.adultTickets;

		cout << "\nHow many concession tickets? ";
		cin >> reservation.concessionTickets;
		if (reservation.adultTickets > 0  && reservation.concessionTickets >= 0 || 
			reservation.concessionTickets > 0 && reservation.adultTickets >= 0)
			break;
	}

	cout << endl;
}

void loadSouthboundTimetable(Train southboundTimetable[100], int& numSouthboundTrains)
{
	ifstream inFile("Southbound timetable.txt", ios::in);
	int i = -1;
	while (!inFile.eof())
	{
		i++;
		inFile >> southboundTimetable[i].trainNumber;
		for (int j = 0; j < 12; j++)
			inFile >> southboundTimetable[i].departureTimes[j];
	}
	inFile.close();
}

void loadNorthboundTimetable(Train northboundTimetable[100], int& numNorthboundTrains)
{
	ifstream inFile("Northbound timetable.txt", ios::in);
	int i = -1;
	while (!inFile.eof())
	{
		i++;
		inFile >> northboundTimetable[i].trainNumber;
		for (int j = 0; j < 12; j++)
			inFile >> northboundTimetable[i].departureTimes[j];
	}
	inFile.close();
}

void selectSouthboundTrain(Train southboundTimetable[100], int numSouthboundTrains, Reservation& reservation, int departureTime)
{
	char stations[13][12] = { "", "Nangang", "Taipei", "Banqiao", "Taoyuan", "Hsinchu", "Miaoli", "Taichung", "Changhua"
							, "Yunlin", "Chiayi", "Tainan", "Zuoying"};
	char carClass[12];

	int i = 0;
	while (true) {
		if (strcmp(departureTimes[departureTime], southboundTimetable[i].departureTimes[reservation.originStation]) < 0)
			break;
		i++;
	}

	cout << setw(9) << "Train No." << setw(11) << "Departure" << setw(9) << "Arrival\n";
	for (int j = 0; j < 10; j++) {
		cout << setw(9) << southboundTimetable[i + j].trainNumber;
		cout << setw(11) << southboundTimetable[i + j].departureTimes[reservation.originStation - 1];
		cout << setw(9) << southboundTimetable[i + j].departureTimes[reservation.destinationStation - 1] << endl;
	}
	do {
		cout << "\nEnter Train Number: ";
		cin >> reservation.trainNumber;

		for (int j = 0; j < 10; j++)
			if (strcmp(reservation.trainNumber, southboundTimetable[i + j].trainNumber) == 0) {
				display(reservation, southboundTimetable, stations, carClass);
				cout << endl;
				return;
			}
		cout << "Wrong input. Please input again.";
	} while (true);
}

void display(Reservation reservation, Train trainTimetable[100], char stations[13][12], char carClass[12])
{
	int position = 0;
	for (int a = 0; a < 100; a++)
		if (strcmp(trainTimetable[a].trainNumber, reservation.trainNumber) == 0) {
			position = a;
			break;
		}
	cout << "\nTrip Details\n" << setw(10) << "Date" << setw(11) << "Train No." << setw(8) << "From" << setw(10) << "To" << setw(11)
		<< "Departure" << setw(9) << "Arrival" << setw(8) << "Adult" << setw(12) << "Concession" << setw(6) << "Fare" << setw(10)
		<< "Class\n" << setw(10) << reservation.date << setw(11) << reservation.trainNumber << setw(8) << stations[reservation.originStation]
		<< setw(10) << stations[reservation.destinationStation] << setw(11) << trainTimetable[position].departureTimes[reservation.originStation - 1] 
		<< setw(9) << trainTimetable[position].departureTimes[reservation.destinationStation - 1];

	if (reservation.carClass == 1 && reservation.originStation < reservation.destinationStation || 
		reservation.carClass == 2 && reservation.destinationStation < reservation.originStation) {
		cout << setw(6) << adultTicketPrice[reservation.destinationStation][reservation.originStation] << "*" << reservation.adultTickets
			<< setw(10) << adultTicketPrice[reservation.destinationStation][reservation.originStation] / 2 << "*" << reservation.concessionTickets
			<< setw(6) << adultTicketPrice[reservation.destinationStation][reservation.originStation] * reservation.adultTickets +
			adultTicketPrice[reservation.destinationStation][reservation.originStation] / 2 * reservation.concessionTickets;
		if (reservation.carClass == 1)
			cout << setw(10) << "Standard";
		else
			cout << setw(10) << "Business";
	}
	else {
		cout << setw(6) << adultTicketPrice[reservation.originStation][reservation.destinationStation] << "*" << reservation.adultTickets
			<< setw(10) << adultTicketPrice[reservation.originStation][reservation.destinationStation] / 2 << "*" << reservation.concessionTickets
			<< setw(6) << adultTicketPrice[reservation.originStation][reservation.destinationStation] * reservation.adultTickets +
			adultTicketPrice[reservation.originStation][reservation.destinationStation] / 2 * reservation.concessionTickets;
		if (reservation.carClass == 1)
			cout << setw(10) << "Standard";
		else
			cout << setw(10) << "Business";
	}
}

// displays timetables for 10 coming northbound trains, then let user select one
void selectNorthboundTrain(Train northboundTimetable[100], int numNorthboundTrains, Reservation& reservation, int departureTime)
{
	char stations[13][12] = { "", "Zuoying", "Tainan", "Chiayi", "Yunlin", "Changhua", "Taichung", "Miaoli", "Hsinchu"
							, "Taoyuan", "Banqiao", "Taipei", "Nangang" };
	char carClass[12];

	int i = 0;
	while (true) {
		if (strcmp(departureTimes[departureTime], northboundTimetable[i].departureTimes[reservation.originStation]) > 0)
			break;
		i++;
	}
	cout << setw(9) << "Train No." << setw(11) << "Departure" << setw(9) << "Arrival\n";
	for (int j = 0; j < 10; j++) {
		cout << setw(9) << northboundTimetable[i + j].trainNumber;
		cout << setw(11) << northboundTimetable[i + j].departureTimes[reservation.originStation - 1];
		cout << setw(9) << northboundTimetable[i + j].departureTimes[reservation.destinationStation - 1] << endl;
	}
	do {
		cin >> reservation.trainNumber;

		for (int j = 0; j < 10; j++)
			if (strcmp(reservation.trainNumber, northboundTimetable[i + j].trainNumber) == 0) {
				display(reservation, northboundTimetable, stations, carClass);
				cout << endl;
				return;
			}
			else
				cout << "Wrong input. Please input again.";
	} while (true);
}

void inputContactInfo(Reservation& reservation)
{
	cout << "\nEnter Contact Person Information\n\nID Number: ";
	cin >> reservation.idNumber;
	cout << "\nPhone: ";
	cin >> reservation.phone;
	for (int i = 0; i < 8; i++) {
		reservation.reservationNumber[i] = rand() % 10 + '0';
	}
	for (int i = 8; i < 12; i++) {
		reservation.reservationNumber[i] = '\0';
	}
	cout << "\nReservation Number: " << reservation.reservationNumber << "\n\nReservation Completed!\n\n\n";
}

void saveReservation(Reservation reservation)
{
	fstream File("Reservation details.dat", ios::in | ios::out | ios::binary);
	vector <Reservation> temp;
	int numberLine;
	if (!File) {
		ofstream outFile("Reservation details.dat", ios::out | ios::binary);
		outFile.write(reinterpret_cast<char*>(&reservation), sizeof(Reservation));
	}
	else {
		File.seekg(0, ios::end);
		numberLine = File.tellg() / sizeof(Reservation);
		File.seekg(0, ios::beg);
		temp.resize(numberLine);
		for (int i = 0; i < numberLine; i++) {
			File.read(reinterpret_cast<char*>(&temp[i]), sizeof(Reservation));
		}
		File.write(reinterpret_cast<char*>(&reservation), sizeof(Reservation));
	}
	
}

void reservationHistory(Train southboundTimetable[100],	Train northboundTimetable[100])
{
	fstream ioFile("Reservation details.dat", ios::in | ios::out | ios::binary);
	Reservation reservation;

	while (!existReservation(ioFile, reservation));

	displayReservations(southboundTimetable, northboundTimetable, reservation);

	while (true)
	{
		int choice;
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
			ioFile.seekg(0, ios::beg);
			reservation.adultTickets = 0;
			reservation.carClass = 0;
			reservation.concessionTickets = 0;
			for (int i = 0; i < sizeof(reservation.date); i++)
				reservation.date[i] = '\0';
			reservation.destinationStation = 0;
			reservation.originStation = 0;
			for (int i = 0; i < sizeof(reservation.reservationNumber); i++)
				reservation.reservationNumber[i] = '\0';
			for (int i = 0; i < sizeof(reservation.trainNumber); i++)
				reservation.trainNumber[i] = '\0';
			for (int i = 0; i < sizeof(reservation.idNumber); i++)
				reservation.idNumber[i] = '\0';
			for (int i = 0; i < sizeof(reservation.phone); i++)
				reservation.phone[i] = '\0';
			ioFile.write(reinterpret_cast<char*>(&reservation), sizeof(Reservation));
			ioFile.close();
			cout << "Reservation Cancelled!\n\n";
			return;
		case 2:
			reduceSeats(ioFile, southboundTimetable, northboundTimetable, reservation);
			return;
		case 3:
			return;
		default: // display error if user does not select valid choice
			cerr << "Incorrect Choice!\n";
			break;
		}
	}
}

bool existReservation(fstream& ioFile, Reservation& reservation)
{
	vector <Reservation> temp;

	ioFile.seekg(0, ios::end);
	int numberLine = ioFile.tellg() / sizeof(Reservation);
	ioFile.seekg(0, ios::beg);
	temp.resize(numberLine);
	for (int i = 0; i < numberLine; i++)
		ioFile.read(reinterpret_cast<char*>(&temp[i]), sizeof(Reservation));

	cout << "\nEnter ID Number: ";
	cin >> reservation.idNumber;
	cout << "\nEnter Reservation Number: ";
	cin >> reservation.reservationNumber;
	for (int i = 8; i < 12; i++) {
		reservation.reservationNumber[i] = '\0';
	}
	for (int i = 0; i < numberLine; i++) {
		if ((strcmp(temp[i].idNumber, reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber, reservation.reservationNumber) == 0)) {
			reservation.adultTickets = temp[i].adultTickets;
			reservation.carClass = temp[i].carClass;
			reservation.concessionTickets = temp[i].concessionTickets;
			strcpy_s(reservation.date, temp[i].date);
			reservation.destinationStation = temp[i].destinationStation;
			reservation.originStation = temp[i].originStation;
			strcpy_s(reservation.phone, temp[i].phone);
			strcpy_s(reservation.trainNumber, temp[i].trainNumber);
			return true;
		}
	}
	cout << "Your idNumber or Reservation Number is wrong. Please input again.";
		return false;
}

void displayReservations(Train southboundTimetable[100], Train northboundTimetable[100], Reservation reservation)
{
	char stations[13][12] = { "", "Nangang", "Taipei", "Banqiao", "Taoyuan", "Hsinchu", "Miaoli", "Taichung", "Changhua"
							   , "Yunlin", "Chiayi", "Tainan", "Zuoying" };
	if (reservation.originStation < reservation.destinationStation) {
		int position = 0;
		for (int a = 0; a < 100; a++)
			if (strcmp(southboundTimetable[a].trainNumber, reservation.trainNumber) > 0) {
				position = a;
				break;
			}
		cout << "\nTrip Details\n" << setw(10) << "Date" << setw(11) << "Train No." << setw(8) << "From" << setw(10) << "To" << setw(11)
			<< "Departure" << setw(9) << "Arrival" << setw(8) << "Adult" << setw(12) << "Concession" << setw(6) << "Fare" << setw(10)
			<< "Class\n" << setw(10) << reservation.date << setw(11) << reservation.trainNumber << setw(8) << stations[reservation.originStation]
			<< setw(10) << stations[reservation.destinationStation] << setw(11) << southboundTimetable[position].departureTimes[reservation.originStation - 1]
			<< setw(9) << southboundTimetable[position].departureTimes[reservation.destinationStation - 1];
	}
	else {
		char stations[13][12] = { "", "Zuoying", "Tainan", "Chiayi", "Yunlin", "Changhua", "Taichung", "Miaoli", "Hsinchu"
						, "Taoyuan", "Banqiao", "Taipei", "Nangang" };
		int position = 0;
		for (int a = 0; a < 100; a++)
			if (strcmp(northboundTimetable[a].trainNumber, reservation.trainNumber) > 0) {
				position = a;
				break;
			}
		cout << "\nTrip Details\n" << setw(10) << "Date" << setw(11) << "Train No." << setw(8) << "From" << setw(10) << "To" << setw(11)
			<< "Departure" << setw(9) << "Arrival" << setw(8) << "Adult" << setw(12) << "Concession" << setw(6) << "Fare" << setw(10)
			<< "Class\n" << setw(10) << reservation.date << setw(11) << reservation.trainNumber << setw(8) << stations[reservation.originStation]
			<< setw(10) << stations[reservation.destinationStation] << setw(11) << northboundTimetable[position].departureTimes[reservation.originStation - 1]
			<< setw(9) << northboundTimetable[position].departureTimes[reservation.destinationStation - 1];
	}


	if (reservation.carClass == 1 && reservation.originStation < reservation.destinationStation ||
		reservation.carClass == 2 && reservation.destinationStation < reservation.originStation) {
		cout << setw(6) << adultTicketPrice[reservation.destinationStation][reservation.originStation] << "*" << reservation.adultTickets
			<< setw(10) << adultTicketPrice[reservation.destinationStation][reservation.originStation] / 2 << "*" << reservation.concessionTickets
			<< setw(6) << adultTicketPrice[reservation.destinationStation][reservation.originStation] * reservation.adultTickets +
			adultTicketPrice[reservation.destinationStation][reservation.originStation] / 2 * reservation.concessionTickets;
		if (reservation.carClass == 1)
			cout << setw(10) << "Standard";
		else
			cout << setw(10) << "Business";
	}
	else {
		cout << setw(6) << adultTicketPrice[reservation.originStation][reservation.destinationStation] << "*" << reservation.adultTickets
			<< setw(10) << adultTicketPrice[reservation.originStation][reservation.destinationStation] / 2 << "*" << reservation.concessionTickets
			<< setw(6) << adultTicketPrice[reservation.originStation][reservation.destinationStation] * reservation.adultTickets +
			adultTicketPrice[reservation.originStation][reservation.destinationStation] / 2 * reservation.concessionTickets;
		if (reservation.carClass == 1)
			cout << setw(10) << "Standard";
		else
			cout << setw(10) << "Business";
	}
}

void reduceSeats(fstream& ioFile, Train southboundTimetable[100], Train northboundTimetable[100], Reservation& reservation)
{
	int adult, concession;
	cout << "How many adult tickets to cancel¡H";
	cin >> adult;
	cout << "How many concession tickets to cancel¡H";
	cin >> concession;

	if (reservation.originStation > reservation.destinationStation) {
		loadNorthboundTimetable(northboundTimetable, reservation.originStation);
	}
	else {
		loadSouthboundTimetable(southboundTimetable, reservation.originStation);
	}
	reservation.adultTickets -= adult;
	reservation.concessionTickets -= concession;
	ioFile.write(reinterpret_cast<char*>(&reservation), sizeof(Reservation));
	saveReservation(reservation);
	cout << "\nYou have successfully reduced the number of tickets!\n\n";
}