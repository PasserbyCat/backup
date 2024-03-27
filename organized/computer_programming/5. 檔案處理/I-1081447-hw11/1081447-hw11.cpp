#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace::std;

char foods[14][48] = { "",
						   "Pork XiaoLongBao (12)",
						   "Steamed Vegetable and Ground Pork Dumplings (8)",
						   "Steamed Shrimp and Pork Dumplings (8)",
						   "Steamed Fish Dumplings (8)",
						   "Steamed Vegetarian Mushroom Dumplings (8)",
						   "Steamed Shrimp and Pork Shao Mai (12)",
						   "Pork Buns (5)",
						   "Vegetable and Ground Pork Buns (5)",
						   "Red Bean Buns (5)",
						   "Sesame Buns (5)",
						   "Taro Buns (5)",
						   "Vegetarian Mushroom Buns (5)",
						   "Golden Lava Buns (5)" };

int price[14] = { 0, 220, 176, 216, 200, 200, 432, 225,
					   225, 200, 200, 225, 250, 225 };

struct Date
{
	int year;
	int month;
	int day;
};

struct Account
{
	char email[40]; // used as the account number
	char password[20];
	char name[12];
	char address[80];
	char phone[12];
	int cart[14]; // Cart[i] is the quantity of food #i in the shopping cart
};

struct Order
{
	char orderNumber[12];
	char email[40];
	Date deliveryDate;
	Date arrivalDate;
	int quantity[14]; // quantity[i] is the quantity of food #i in the order
};

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end);

// add a new account to the file Accounts.dat
void registration(vector< Account >& accountDetails);

// return true if email belongs to accountDetails
bool exists(char email[], const vector< Account >& accountDetails);

// save all elements in accountDetails to the file Accounts.dat
void saveAllAccounts(const vector< Account >& accountDetails);

// login and call shopping
void login(vector< Account >& accountDetails);

// load all accounts details from the file Accounts.dat
void loadAccountDetails(vector< Account >& accountDetails);

// return true if there exists an account with specified email and password; and
// put the account with specified email and password into account
bool valid(char email[], char password[], Account& account,
	const vector< Account >& accountDetails);

// add chosen Foods to the shopping cart
void shopping(Account& account);

// return true if the shopping cart is empty
bool emptyCart(const Account& account);

// display the shopping cart in account
bool displayCart(const Account& account);

// append account in the file Accounts.dat
void saveAccount(const Account& account);

// update the shopping cart in account
void updateCart(Account& account);

// generate a Bill and reset account.cart
void check(Account& account);

// compute the current date
void compCurrentDate(Date& currentDate);

// open the file Orders.txt and call displayOrderDetails twice
void createOrder(const Account& account, const Order& order);

// write an order to Orders.txt or display it on the output window depending on os
void displayOrderDetails(ostream& os, const Account& account, const Order& order);

int main()
{
	vector< Account > accountDetails; // account details for all accounts

	cout << "Welcome to DintaiFung Shopping Mall!\n";
	srand(static_cast<int>(time(0)));

	int choice;

	while (true)
	{
		cout << "\n1 - Registration\n";
		cout << "2 - Login\n";
		cout << "3 - End\n";

		do cout << "\nEnter your choice (1~3): ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice)
		{
		case 1:
			registration(accountDetails);
			break;

		case 2:
			login(accountDetails);
			break;

		case 3:
			cout << "Thank you! Goodbye!\n\n";
			system("pause");
			return 0;
		}
	}

	system("pause");
}

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end)
{
	char choice;
	vector< char >temp;
	int number = 0;

	cin >> choice;
	while (1) {//將每個字元分別取出，形成一組字串
		if (choice == '\n')
			break;
		temp.resize(temp.size() + 1);
		temp[temp.size() - 1] = choice;
		cin.get(choice);//用 cin>> 會取不到 '\n'
	}

	for (int i = 0; i < temp.size(); i++)
		number += (temp[i] - '0') * pow(10, (temp.size() - i - 1));//算出他的int值

	if (number >= begin && number <= end)
		return number;
	else
		return -1;
}

// add a new account to the file Accounts.dat
void registration(vector< Account >& accountDetails)
{
	Account temp;

	for (int i = 0; i < 14; i++)
		temp.cart[i] = 0;//先初始化

	accountDetails.resize(accountDetails.size() + 1);//新增一格，準備擺新註冊者的資訊

	cout << "Email address (Account number): ";
	cin >> temp.email;
	if (!exists(temp.email, accountDetails)) {
		cout << "Password: ";
		cin >> temp.password;
		cout << "Name: ";
		cin >> temp.name;
		cout << "Shipping address: ";
		cin >> temp.address;
		cout << "Contact phone number: ";
		cin >> temp.phone;

		accountDetails[accountDetails.size() - 1] = temp;

		cout << "\nRegistration Completed!" << endl;
	}
	else
		cout << "\nYou are already a member!" << endl;
	
	saveAllAccounts(accountDetails);
}

// return true if email belongs to accountDetails
bool exists(char email[], const vector< Account >& accountDetails)
{
	for (int i = 0; i < accountDetails.size(); i++)
		if (strcmp(email, accountDetails[i].email) == 0)
			return true;
	return false;
}

// save all elements in accountDetails to the file Accounts.dat
void saveAllAccounts(const vector< Account >& accountDetails)
{
	ofstream outFile("Accounts.dat", ios::out || ios::binary);
	for (int i = 0; i < accountDetails.size(); i++)
		outFile.write(reinterpret_cast<const char*>(&accountDetails[i]), sizeof(accountDetails[i]));
	outFile.close();
}

// login and call shopping
void login(vector< Account >& accountDetails)
{
	loadAccountDetails(accountDetails);

	Account temp;

	do {
		cout << "Email address (0 to end): ";
		cin >> temp.email;
		if (strcmp(temp.email, "0") == 0)
			return;
		cout << "Enter your password: ";
		cin >> temp.password;
		if (!valid(temp.email, temp.password, temp, accountDetails))
			cout << "\nInvalid account number or password. Please try again." << endl << endl;
	} while (!valid(temp.email, temp.password, temp, accountDetails));

	cout << endl;
	shopping(temp);
}

// load all accounts details from the file Accounts.dat
void loadAccountDetails(vector< Account >& accountDetails)
{
	ifstream inFile("Accounts.dat", ios::in | ios::binary);
	if (!inFile) {
		ofstream outFile("Accounts.dat", ios::out | ios::binary);
		outFile.close();
	}
	else {
		inFile.seekg(0, ios::end);
		int numLine = inFile.tellg() / sizeof(Account);
		inFile.seekg(0, ios::beg);
		for (int i = 0; i < numLine; i++) {
			accountDetails.resize(numLine);
			inFile.read(reinterpret_cast<char*>(&accountDetails[i]), sizeof(accountDetails[i]));
		}
	}
	inFile.close();
}

// return true if there exists an account with specified email and password; and
// put the account with specified email and password into account
bool valid(char email[], char password[], Account& account, const vector< Account >& accountDetails)
{
	for (int i = 0; i < accountDetails.size(); i++)
		if (strcmp(email, accountDetails[i].email) == 0 && strcmp(password, accountDetails[i].password) == 0) {
			account = accountDetails[i];
			return true;
		}
	return false;
}

// add chosen Foods to the shopping cart
void shopping(Account& account)
{
	int choice = 0;
	int space[14] = { 0,32,6,16,27,12,16,40,19,36,38,40,25,33 };
	int number;

	while(choice != 3) {
		for (int i = 1; i < 14; i++)
			cout << setw(2) << i << ". " << foods[i] << setw(space[i]) << price[i] << endl;

		if (!emptyCart(account)) {//看購物車是否有東西 
			cout << setw(2) << 14 << ". " << "View your shopping cart" << endl;

			do cout << "\nEnter your choice (0 to logout): ";
			while ((choice = inputAnInteger(0, 14)) == -1);

			if (choice == 0)
				return;

			if (choice == 14)
				displayCart(account);//展示購物車
			else {
				do {//下訂單
					cout << "\nEnter the quantity: ";
					cin >> number;
				} while (number <= 0);
				account.cart[choice] = number;

				displayCart(account);//展示購物車
			}
		}
		else
		{
			do cout << "\nEnter your choice (0 to logout): " ;
			while ((choice = inputAnInteger(0, 13)) == -1);

			if (choice == 0)
				return;
			do {//下訂單
				cout << "\nEnter the quantity: " ;
				cin >> number;
			} while (number <= 0);
			account.cart[choice] = number;

			displayCart(account);//展示購物車
		}

		saveAccount(account);

		do {
			cout << "\n1. Continue Shopping\n";
			cout << "2. Update Cart\n";
			cout << "3. Check\n";

			do cout << "\nEnter your choice (1~3): ";
			while ((choice = inputAnInteger(1, 3)) == -1);
			cout << endl;

			switch (choice) {
			case 1:
				break;

			case 2:
				updateCart(account);
				break;

			case 3:
				check(account);
				break;
			}
		} while (choice ==2);
	}
}

// return true if the shopping cart is empty
bool emptyCart(const Account& account)
{
	for (int i = 0; i < 14; i++)
		if (account.cart[i] != 0)
			return false;
	return true;
}

// display the shopping cart in account
bool displayCart(const Account& account)
{
	cout << "\nYour Shopping Cart Contents: " << endl;
	int total = 0;
	cout << "\nCode" << setw(53) << "Item  " << "Price  " << "Quantity  " << "Subtotal  " << endl;
	for (int i = 1; i < 14; i++)
		if (account.cart[i] != 0) {
			cout << setw(4) << i << setw(51) << foods[i] << setw(7) << price[i] << setw(10) << account.cart[i] << setw(10) << price[i] * account.cart[i] << endl;
			total += price[i] * account.cart[i];//將總金額計算
		}

	cout << "\nTotal Cost: " << total << endl;
	return true;
}

// append account in the file Accounts.dat
void saveAccount(const Account& account)
{
	vector< Account > temp;
	int place = 0;
	fstream File("Accounts.dat", ios::in |ios::app| ios::binary);

	File.seekg(ios::end);
	int numLine = File.tellg() / sizeof(Account);
	File.seekg(0, ios::beg);

	for (int i = 0; i < numLine; i++) {//把資料讀出來
		temp.resize(numLine);
		File.read(reinterpret_cast<char*>(&temp[i]), sizeof(temp[i]));
	}

	for (int i = 0; i < numLine; i++)//找到訂單的account位置
		if (strcmp(temp[i].email, account.email) == 0) {
			place = i;
			break;
		}

	File.seekg(place * sizeof(Account), ios::beg);
	File.write(reinterpret_cast<const char*>(&account), sizeof(account));//將他寫入
}

// update the shopping cart in account
void updateCart(Account& account)
{
	int choice;

	do {//選擇要修改的項目
		do cout << "\nEnter the product code: " ;
		while ((choice = inputAnInteger(1, 13)) == -1);
	} while (account.cart[choice] == 0);

	int number = 0;

	do {//修改訂單資料
		cout << "\nEnter the quantity: " ;
		cin >> number;
	} while (number < 0);
	account.cart[choice] = number;

	displayCart(account);//展示購物車
}

// generate a Bill and reset account.cart
void check(Account& account)
{
	Order order;
	int num = time(0);

	cout << "Enter arrival date" << endl;
	cout << "year: ";
	cin >> order.arrivalDate.year;
	cout << "month: ";
	cin >> order.arrivalDate.month;
	cout << "day: ";
	cin >> order.arrivalDate.day;

	compCurrentDate(order.deliveryDate);
	strcpy_s(order.email, account.email);

	for (int i = 0; i < 11; i++) {
		srand(i + num);
		if (i == 0)
			order.orderNumber[i] = rand() % 26 + 'A';
		else if (i == 10)
			order.orderNumber[i] = '\0';
		else
			order.orderNumber[i] = rand() % 10 + '0';
	}//隨機產生訂單編號

	for (int i = 0; i < 14; i++)
		order.quantity[i] = account.cart[i];

	createOrder(account, order);
}

// compute the current date
void compCurrentDate(Date& currentDate)
{
	tm timeN;
	time_t rawTime = time(0);
	localtime_s(&timeN, &rawTime);
	currentDate.year = timeN.tm_year + 1900;
	currentDate.month = timeN.tm_mon + 1;
	currentDate.day = timeN.tm_mday;
}

// open the file Orders.txt and call displayOrderDetails twice
void createOrder(const Account& account, const Order& order)
{
	fstream orderFile1("Order.txt", ios::out||ios::app);
	if (!orderFile1) {
		ofstream orderFile2("Order.txt", ios::out||ios::app);
		displayOrderDetails(orderFile2, account, order);
		orderFile2.close();
	}
	else
		displayOrderDetails(orderFile1, account, order);
	orderFile1.close();
}

// write an order to Orders.txt or display it on the output window depending on os
void displayOrderDetails(ostream& os, const Account& account, const Order& order)
{
	os.write(reinterpret_cast<const char*>(&order), sizeof(order));

	cout << "Order number: " << order.orderNumber << endl;
	cout << "Delivery Date: " << order.deliveryDate.year <<'/'<<order.deliveryDate.month<<'/'<<order.deliveryDate.day<< endl;
	cout << "Arrival Date: " << order.arrivalDate.year << '/' << order.arrivalDate.month << '/' << order.arrivalDate.day << endl;
	cout << "Recipient: " << account.name << endl;
	cout << "Contact Phone Number: " << account.phone << endl;
	cout << "Shipping address: " << account.address << endl;
	cout << "Shopping details :" << endl;
	
	int total = 0;
	cout << "\nCode" << setw(53) << "Item  " << "Price  " << "Quantity  " << "Subtotal  " << endl;
	for (int i = 1; i < 14; i++)//加總金額
		if (order.quantity[i] != 0) {
			cout << setw(4) << i << setw(51) << foods[i] << setw(7) << price[i] << setw(10) << account.cart[i] << setw(10) << price[i] * account.cart[i] << endl;
			total += price[i] * order.quantity[i];
		}

	cout << "\nTotal Cost: " << total << endl;
	cout << "\nAn order has been created." << endl;
}