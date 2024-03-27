#pragma once

#ifndef HW10_H
#define HW10_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

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

class Account
{
public:
	Account(int input = 0)
	{
		if (input == 1) {
			accountNumber = 12345;
			PIN = 54321;
			availableBalance = 1000.0;
			totalBalance = 1200.0;
		}
		else if (input == 2) {
			accountNumber = 98765;
			PIN = 56789;
			availableBalance = 200.0;
			totalBalance = 200.0;
		}
	}
	bool valid(int inputAccount, int inputPIN)
	{
		for (int i = 0; i < 2; i++)
			if (inputAccount == accountNumber && inputPIN == PIN)
				return true;

		return false;
	}
	void balance() {
		cout << "\n您的存款";
		cout << "\n - 有效存款: " << setw(10) << "$" << fixed << setprecision(2) << availableBalance;
		cout << "\n - 存款總金額: " << setw(8) << "$" << fixed << setprecision(2) << totalBalance << endl;
	}
	void withdraw() {
			int choice;

			cout << "\n提款選項:";
			cout << "\n1 - $20";
			cout << "\n2 - $40";
			cout << "\n3 - $60";
			cout << "\n4 - $100";
			cout << "\n5 - $200";
			cout << "\n6 - 取消該次交易";

			do {
				cout << "\n\n請輸入您的選擇: ";
				choice = inputAnInteger(1, 6);
			} while (choice == -1);

			switch (choice) {
			case 1:
				if (availableBalance >= 20) {
					availableBalance -= 20;
					totalBalance -= 20;
					cout << "\n請把現金領走，避免自己的權益喪失";
				}
				else
					cout << "戶頭裡的餘額不足，請先確認自己的存款";
				break;
			case 2:
				if (availableBalance >= 40) {
					availableBalance -= 40;
					totalBalance -= 40;
					cout << "\n請把現金領走，避免自己的權益喪失";
				}
				else
					cout << "戶頭裡的餘額不足，請先確認自己的存款";
				break;
			case 3:
				if (availableBalance >= 60) {
					availableBalance -= 60;
					totalBalance -= 60;
					cout << "\n請把現金領走，避免自己的權益喪失";
				}
				else
					cout << "戶頭裡的餘額不足，請先確認自己的存款";
				break;
			case 4:
				if (availableBalance >= 100) {
					availableBalance -= 100;
					totalBalance -= 100;
					cout << "\n請把現金領走，避免自己的權益喪失";
				}
				else
					cout << "戶頭裡的餘額不足，請先確認自己的存款";
				break;
			case 5:
				if (availableBalance >= 200) {
					availableBalance -= 200;
					totalBalance -= 200;
					cout << "\n請把現金領走，避免自己的權益喪失";
				}
				else
					cout << "戶頭裡的餘額不足，請先確認自己的存款";
				break;
			case 6:
				return;
			}
	}
	void deposit() {
		float save;
		cout << "\n請輸入您要存幾分錢->(輸入0取消): ";
		cin >> save;
		save /= 100;
		cout << "\n請將$" << fixed << setprecision(2) << save << "放入信封並投入機器";
		cout << "\n\n已經收到您的信封";
		cout << "\n注意: 在我們核對金額之前，您的有效存款不會馬上增加";
		totalBalance += save;
	}
private:
	int accountNumber = 0;
	int PIN = 0;
	float availableBalance = 0;
	float totalBalance = 0;
};



#endif
