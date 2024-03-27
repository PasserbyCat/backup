#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
using namespace::std;

struct Date
{
	int year;
	int month;
	int day;
	int hour;
};

struct MemberRecord
{
	char IDNumber[12];   // account number
	char password[24];   // password
	char name[8];        // name
};

struct ReservationRecord
{
	char IDNumber[12]; // account number
	int branchCode;      // branch code
	Date date;           // reservation date
	int numCustomers;    // number of customers
};

char branchNames[17][24] = { "", "Taipei Dunhua South", "Taipei SOGO",
									 "Taipei Songjiang",    "Taipei Nanjing",
									 "Taipei Linsen",       "Taipei Zhonghua New",
									 "Banqiao Guanqian",    "Yonghe Lehua",
									 "Taoyuan Zhonghua",    "Taoyuan Nankan",
									 "Zhongli Zhongyang",   "Hsinchu Beida",
									 "Taichung Ziyou",      "Chiayi Ren'ai",
									 "Tainan Ximen",        "Kaohsiung Zhonghua New" };

// input memberDetails from the file Members.dat
void loadMemberDetails(vector< MemberRecord >& memberDetails);

// input reservations from the file Reservations.dat
void loadReservations(vector< ReservationRecord >& reservations);

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end);

// login and display the submenu
void login(const vector< MemberRecord >& memberDetails,
	vector< ReservationRecord >& reservations);

// there exists a member with specified IDNumber and password
bool valid(char IDNumber[], char password[],
	const vector< MemberRecord >& memberDetails);

// add a new reservation for the member with specified IDnumber
void reservation(char IDNumber[], vector< ReservationRecord >& reservations);

// compute the current date
void compCurrentDate(Date& currentDate);

// compute 7 dates which is starting from the current date
void compAvailableDates(Date currentDate, Date availableDates[]);

// display all fields of reservation
void output(ReservationRecord reservation);

// display all reservations for the member with specified IDnumber,
// then let the member to choose one of them to delete
void queryDelete(char IDNumber[], vector< ReservationRecord >& reservations);

// add a new member
void registration(vector< MemberRecord >& memberDetails);

// return true if IDNumber is a legal ID number
bool legalID(char IDNumber[]);

// return true if IDNumber belongs to memberDetails
bool existingID(char IDNumber[], const vector< MemberRecord >& memberDetails);

// output all memberDetails into the file Members.dat
void saveMemberDetails(const vector< MemberRecord >& memberDetails);

// output all reservations into the file Reservations.dat
void saveReservations(const vector< ReservationRecord >& reservations);

int main()
{
	vector< MemberRecord > memberDetails; // member details for all members
	vector< ReservationRecord > reservations; // all reservations

	loadMemberDetails(memberDetails);
	loadReservations(reservations);

	cout << "Welcome to the Cashbox Party World!\n\n";

	int choice;

	while (true)
	{
		cout << "1 - Login\n";
		cout << "2 - Registration\n";
		cout << "3 - End\n";

		do cout << "\nEnter your choice (1~3): ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice)
		{
		case 1:
			login(memberDetails, reservations);
			break;

		case 2:
			registration(memberDetails);
			break;

		case 3:
			saveMemberDetails(memberDetails);
			saveReservations(reservations);
			cout << "Thank you! Goodbye!\n\n";
			system("pause");
			return 0;

		default:
			cout << "\nIncorrect choice!\n";
			break;
		}
	}

	system("pause");
}

// input memberDetails from the file Members.dat
void loadMemberDetails(vector< MemberRecord >& memberDetails)
{
	fstream inFile("Members.dat", ios::in | ios::out | ios::binary);

	if (!inFile) {
		ofstream outFile("Members.dat", ios::out | ios::binary);
		outFile.close();
	}
	else
	{
		inFile.seekg(0, ios::end);
		int numLine = inFile.tellg() / sizeof(MemberRecord);
		inFile.seekg(0, ios::beg);
		for (int i = 0; i < numLine; i++)
		{
			memberDetails.resize(numLine);
			inFile.read(reinterpret_cast<char*>(&memberDetails[i]), sizeof(memberDetails[i]));
		}
	}

	inFile.close();
}

// input reservations from the file Reservations.dat
void loadReservations(vector< ReservationRecord >& reservations)
{
	fstream inFile("Reservations.dat", ios::in | ios::out | ios::binary);

	if (!inFile) {
		ofstream outFile("Reservations.dat", ios::out | ios::binary);
		outFile.close();
	}
	else {
		inFile.seekg(0, ios::end);
		int numLine = inFile.tellg() / sizeof(ReservationRecord);
		inFile.seekg(0, ios::beg);
		for (int i = 0; i < numLine; i++) {
			reservations.resize(numLine);
			inFile.read(reinterpret_cast<char*>(&reservations[i]), sizeof(reservations[i]));
		}
	}

	inFile.close();
}

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end)
{
	char choice;
	vector<char>data;
	int number = 0;
	cin >> choice;

	while (1) {
		//當cin.get讀到非數字的字符時，代表已經做出選擇了
		if (choice == '\n')
			break;
		data.resize(data.size() + 1);
		data[data.size() - 1] = choice;
		cin.get(choice);
	}

	for (int i = 0; i < data.size(); i++)
		number += (data[i] - '0') * pow(10, (data.size() - i - 1));

	if (number >= begin && number <= end)
		return number;
	else
		return -1;
}

// login and display the submenu
void login(const vector< MemberRecord >& memberDetails, vector< ReservationRecord >& reservations)
{
	MemberRecord log;

	//第一次必須進去，使用do while
	do
	{
		cout << "Input your ID Number: ";
		cin >> log.IDNumber;
		cout << endl;
		cout << "Enter your password: ";
		cin >> log.password;
		if (!valid(log.IDNumber, log.password, memberDetails))
			cout << "\nInvalid account number or password. Please try again." << endl << endl;
	} while (!valid(log.IDNumber, log.password, memberDetails));//直到帳號密碼皆正確

	int choice;
	//引用main function裡的chioce，並加以改編
	do {
		cout << "\n1 - Make Reservation\n";
		cout << "2 - Reservation Enquiry/Canceling\n";
		cout << "3 - End\n";

		do cout << "\nEnter your choice (1~3): ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice) {
		case 1:
			reservation(log.IDNumber, reservations);
			break;

		case 2:
			queryDelete(log.IDNumber, reservations);
			break;

		case 3:
			break;

		default:
			cout << "\nIncorrect choice!\n";
			break;
		}
	} while (choice != 3);
}

// there exists a member with specified IDNumber and password
bool valid(char IDNumber[], char password[], const vector< MemberRecord >& memberDetails)
{
	for (int i = 0; i < memberDetails.size(); i++)
		//使用strcmp比較帳號與密碼是否一樣
		if (strcmp(IDNumber, memberDetails[i].IDNumber) == 0 && strcmp(password, memberDetails[i].password) == 0)
			return true;
	return false;
}

// add a new reservation for the member with specified IDnumber
void reservation(char IDNumber[], vector< ReservationRecord >& reservations)
{
	//輸出分店名稱
	for (int i = 1; i <= 16; i++)
		cout << setw(2) << i << ". " << branchNames[i] << endl;

	int choice;
	ReservationRecord reserv;
	strcpy_s(reserv.IDNumber, IDNumber);

	do cout << "\nEnter your choice (0 to end): ";
	while ((choice = inputAnInteger(0, 16)) == -1);

	if (choice == 0)
		return;

	reserv.branchCode = choice;

	Date currentDate;
	compCurrentDate(currentDate);

	cout << "\nThe current hour is " << currentDate.year << '/' << currentDate.month << '/' << currentDate.day << ':' << currentDate.hour << endl;

	//避免原始時間被複寫，新建一個時間儲存
	Date availableDates[7];
	compAvailableDates(currentDate, availableDates);

	cout << "\nAvailable days:" << endl << endl;

	for (int i = 0; i < 7; i++)
		cout << i + 1 << ". " << availableDates[i].year << '/' << availableDates[i].month << '/' << availableDates[i].day << endl;

	do cout << "\nEnter your choice (0 to end): ";
	while ((choice = inputAnInteger(0, 7)) == -1);

	if (choice == 0)
		return;

	reserv.date = availableDates[choice - 1];

	int hour = availableDates[choice - 1].hour;

	do cout << "\nEnter hour  (" << hour << "~23): ";
	while ((choice = inputAnInteger(hour, 23)) == -1);

	reserv.date.hour = choice;

	do cout << "\nEnter the number of customers(1~30, 0 to end) : ";
	while ((choice = inputAnInteger(0, 30)) == -1);

	if (choice == 0)
		return;

	cout << endl;
	reserv.numCustomers = choice;

	//純屬排版，不論天數為個位數或十位數都能排列整齊
	int n = 8;
	if (reserv.date.day < 10)
		n++;

	cout << setw(26) << "Brach" << setw(14) << "Date" << setw(8) << "Hour" << setw(19) << "No of Customers" << endl
	     << setw(26) << branchNames[reserv.branchCode] << setw(n) << reserv.date.year << "-" << reserv.date.month << "-" << reserv.date.day
		 << setw(8) << reserv.date.hour << setw(19) << reserv.numCustomers << endl << endl << "Reservation Completed!" << endl;

	reservations.resize(reservations.size() + 1);
	reservations[reservations.size() - 1] = reserv;
}

// compute the current date
void compCurrentDate(Date& currentDate)
{
	//使用tm這種class直接找出本地時間(localtime)
	tm timeN;
	time_t rawTime = time(0);
	localtime_s(&timeN, &rawTime);
	currentDate.year = timeN.tm_year + 1900;
	currentDate.month = timeN.tm_mon + 1;
	currentDate.day = timeN.tm_mday;
	currentDate.hour = timeN.tm_hour;
}

// compute 7 dates which is starting from the current date
void compAvailableDates(Date currentDate, Date availableDates[])
{
	availableDates[0] = currentDate;

	//下午11時定位的話只能從隔天開始訂
	if (currentDate.hour == 23) {
		availableDates[0].day++;
		availableDates[0].hour = 0;
	}
	else
		availableDates[0].hour++;

	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	//找閏年
	if ((currentDate.year % 4 && currentDate.year % 100 != 0) || currentDate.year % 400 == 0)
		month[2]++;

	//把接下來7天顯示出來
	for (int i = 1; i < 7; i++) {
		//解決天數超過該月總天數的情況
		if (availableDates[i - 1].day + 1 > month[availableDates[i - 1].month]) {
			//解決月數超過12的情況
			if (availableDates[i - 1].month == 12) {
				availableDates[i].year = availableDates[i - 1].year + 1;
				availableDates[i].month = 1;
				availableDates[i].day = 1;
			}
			else {
				availableDates[i] = availableDates[i - 1];
				availableDates[i].month += 1;
				availableDates[i].day = 1;
			}
		}
		else {
			availableDates[i] = availableDates[i - 1];
			availableDates[i].day++;
		}
	}

	for (int i = 1; i < 7; i++)
		availableDates[i].hour = 0;
}

// display all fields of reservation
void output(ReservationRecord reservation)
{
	int n = 8;

	//純屬排版，不論天數為個位數或十位數都能排列整齊
	if (reservation.date.day < 10)
		n++;

	cout << setw(23) << branchNames[reservation.branchCode] << setw(n) << reservation.date.year << "-" << reservation.date.month << "-" <<
		reservation.date.day << setw(8) << reservation.date.hour << setw(19) << reservation.numCustomers << endl;
}

// display all reservations for the member with specified IDnumber,
// then let the member to choose one of them to delete
void queryDelete(char IDNumber[], vector< ReservationRecord >& reservations)
{
	vector<int> position;

	cout << setw(26) << "Brach" << setw(14) << "Date" << setw(8) << "Hour" << setw(19) << "No of Customers" << endl;

	for (int i = 0; i < reservations.size(); i++)
		//找到對的ID
		if (strcmp(reservations[i].IDNumber, IDNumber) == 0) {
			cout << position.size() + 1 << ". ";
			output(reservations[i]);
			position.resize(position.size() + 1);
			position[position.size() - 1] = i;
		}

	int choice;

	do cout << "\nChoose a reservation to cancel (0: keep all reservations): ";
	while ((choice = inputAnInteger(0, position.size())) == -1);

	if (choice == 0)
		return;

	reservations.erase(reservations.begin() + position[choice - 1]);
}

// add a new member
void registration(vector< MemberRecord >& memberDetails)
{
	MemberRecord regis;

	cout << "Input your ID Number: ";
	cin >> regis.IDNumber;
	cout << endl;

	if (legalID(regis.IDNumber)) {
		if (existingID(regis.IDNumber, memberDetails))
			cout << "You are already a member!" << endl << endl;
		else {
			cout << "Input your Name: ";
			cin >> regis.name;
			cout << "\nChoose a password: ";
			cin >> regis.password;
			cout << "\nRegistration Completed!" << endl << endl;
			memberDetails.resize(memberDetails.size() + 1);
			memberDetails[memberDetails.size() - 1] = regis;
		}
	}
	else
		cout << "The ID number " << regis.IDNumber << " is illegal." << endl << endl;
}

// return true if IDNumber is a legal ID number
bool legalID(char IDNumber[])
{
	char count[12];

	if (IDNumber[10] != '\0')
		return false;

	strcpy_s(count, IDNumber);

	if (count[0] >= 'A' && count[0] <= 'H')
		count[0] -= 55;
	else if (count[0] >= 'J' && count[0] <= 'N')
		count[0] -= 56;
	else if (count[0] >= 'P' && count[0] <= 'V')
		count[0] -= 57;
	else if (count[0] == 'X' || count[0] == 'Y')
		count[0] -= 58;
	else if (count[0] == 'I')
		count[0] -= 39;
	else if (count[0] == 'O')
		count[0] -= 44;
	else if (count[0] == 'W')
		count[0] = 32;
	else if (count[0] == 'Z')
		count[0] = 33;
	else
		return false;

	for (int i = 1; i < 10; i++) // 轉int
		count[i] -= '0';

	int sum = count[0] / 10 + (count[0] % 10) * 9; //計算

	for (int i = 1; i < 9; i++) // 規則
		sum += count[i] * (9 - i);

	if (sum % 10 == 10 - count[9])
		return true;
	else if (sum % 10 == 0 && count[9] == 0)
		return true;
	else
		return false;
}

// return true if IDNumber belongs to memberDetails
bool existingID(char IDNumber[], const vector< MemberRecord >& memberDetails)
{
	for (int i = 0; i < memberDetails.size(); i++)
		if (strcmp(IDNumber, memberDetails[i].IDNumber) == 0)
			return true;
	return false;
}

// output all memberDetails into the file Members.dat
void saveMemberDetails(const vector< MemberRecord >& memberDetails)
{
	fstream outFile("Members.dat", ios::in | ios::out | ios::binary);

	for (int i = 0; i < memberDetails.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&memberDetails[i]), sizeof(memberDetails[i]));
}

// output all reservations into the file Reservations.dat
void saveReservations(const vector< ReservationRecord >& reservations)
{
	fstream outFile("Reservations.dat", ios::in | ios::out | ios::binary);

	for (int i = 0; i < reservations.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&reservations[i]), sizeof(reservations[i]));
}