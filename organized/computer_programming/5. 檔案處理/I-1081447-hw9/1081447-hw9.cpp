#include <iostream>
#include <fstream>
#include <vector>
using namespace::std;

struct MemberRecord
{
	char IDNumber[12];   // account number
	char password[24];   // password
	char name[8];        // name
};

// input memberDetails from the file Members.dat
void loadMemberDetails(vector< MemberRecord >& memberDetails);

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end);

// login
void login(const vector< MemberRecord >& memberDetails);

// there exists a member with specified IDNumber and password
bool valid(char IDNumber[], char password[],
	const vector< MemberRecord >& memberDetails);

// add a new member
void registration(vector< MemberRecord >& memberDetails);

// return true if IDNumber is a legal ID number
bool legalID(char IDNumber[]);

// return true if IDNumber belongs to memberDetails
bool existingID(char IDNumber[], const vector< MemberRecord >& memberDetails);

// output all memberDetails into the file Members.dat
void saveMemberDetails(const vector< MemberRecord >& memberDetails);

int main()
{
	vector< MemberRecord > memberDetails = {}; // member details for all members
	int numMembers = 0;                     // number of members

	loadMemberDetails(memberDetails);

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
			login(memberDetails);
			break;

		case 2:
			registration(memberDetails);
			break;

		case 3:
			saveMemberDetails(memberDetails);
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

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end)
{
	char choice;
	vector<char>recog;
	cin >> choice;
	while (1)
	{
		//當cin.get讀到\n時，代表已經做出選擇了
		if (choice == '\n')
			break;
		recog.resize(recog.size() + 1);
		recog[recog.size()-1] = choice;
		cin.get(choice);
	}
	//temp.size必須是1，才是正確的輸入；且必須是數字
	if (recog[0] >= begin + '0' && recog[0] <= end + '0' && recog.size() == 1)
		return recog[0] - '0';
	else
		return -1;
}

// input memberDetails from the file Members.dat
void loadMemberDetails(vector< MemberRecord >& memberDetails)
{
	fstream inFile("Members.dat", ios::in | ios::app | ios::binary);
	//使用numLine是上課時聽到的
	inFile.seekg(0, ios::end);
	int numLine = inFile.tellg() / sizeof(memberDetails);
	inFile.seekg(0, ios::beg);
	for (int i = 0; i < numLine; i++)
	{
		memberDetails.resize(numLine);
		inFile.read(reinterpret_cast<char*>(&memberDetails[i]), sizeof(memberDetails[i]));
	}
}

// input memberDetails from the file Members.dat
void login(const vector< MemberRecord >& memberDetails)
{
	MemberRecord log;
	//第一次必須進去，使用do while
	do
	{
		cout << "Input your ID Number: ";
		cin >> log.IDNumber;
		cout << "Enter your password: ";
		cin >> log.password;
		if (!valid(log.IDNumber, log.password, memberDetails))
			cout << "\nInvalid account number or password. Please try again." << endl << endl;
	} while (!valid(log.IDNumber, log.password, memberDetails));//直到帳號密碼皆正確
}

// return true if IDNumber is a legal ID number
void registration(vector< MemberRecord >& memberDetails)
{
	MemberRecord regis;
	cout << "Input your ID Number: ";
	cin >> regis.IDNumber;
	cout << endl;
	if (legalID(regis.IDNumber))
	{
		if (existingID(regis.IDNumber, memberDetails))
			cout << "You are already a member!" << endl << endl;
		else
		{
			cout << "Input your Name: ";
			cin >> regis.name;
			cout << endl;
			cout << "Choose a password: ";
			cin >> regis.password;
			cout << endl;
			cout << "Registration Completed!" << endl;
			cout << endl;
			memberDetails.resize(memberDetails.size() + 1);
			memberDetails[memberDetails.size() - 1] = regis;
		}
	}
	else
		cout << "The ID number " << regis.IDNumber << " is illegal." << endl << endl;
}

// output all memberDetails into the file Members.dat
void saveMemberDetails(const vector< MemberRecord >& memberDetails)
{
	fstream outFile("Members.dat", ios::in | ios::out | ios::binary);
	for (int i = 0; i < memberDetails.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&memberDetails[i]), sizeof(memberDetails[i]));
}

// there exists a member with specified IDNumber and password
bool valid(char IDNumber[], char password[], const vector< MemberRecord >& memberDetails)
{
	for (int i = 0; i < memberDetails.size(); i++)
	{
		//使用strcmp比較帳號與密碼是否一樣
		if (strcmp(IDNumber, memberDetails[i].IDNumber) == 0 && strcmp(password, memberDetails[i].password) == 0)
			return true;
	}
	return false;
}

// return true if IDNumber is a legal ID number
bool legalID(char IDNumber[])
{
	char count[12];
	if (IDNumber[10] != '\0')
		return false;

	strcpy_s(count, IDNumber);

	if (count[0] >= 65 && count[0] <= 72 || count[0] == 87) // A-H,W
		count[0] -= 55;
	else if (count[0] >= 74 && count[0] <= 78) // J-N
		count[0] -= 56;
	else if (count[0] >= 80 && count[0] <= 86 || count[0] == 90) // P-V,Z
		count[0] -= 57;
	else if (count[0] == 88 || count[0] == 89) // X-Y
		count[0] -= 58;
	else if (count[0] == 73) // I
		count[0] -= 39;
	else if (count[0] == 79) // O
		count[0] -= 44;
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
	{
		if (strcmp(IDNumber, memberDetails[i].IDNumber) == 0)
			return true;
	}
	return false;
}