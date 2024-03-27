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
	while (1) {//�N�C�Ӧr�����O���X�A�Φ��@�զr��
		if (choice == '\n')
			break;
		temp.resize(temp.size() + 1);
		temp[temp.size() - 1] = choice;
		cin.get(choice);//�� cin>> �|������ '\n'
	}

	for (int i = 0; i < temp.size(); i++)
		number += (temp[i] - '0') * pow(10, (temp.size() - i - 1));//��X�L��int��

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
		cout << "\n�z���s��";
		cout << "\n - ���Ħs��: " << setw(10) << "$" << fixed << setprecision(2) << availableBalance;
		cout << "\n - �s���`���B: " << setw(8) << "$" << fixed << setprecision(2) << totalBalance << endl;
	}
	void withdraw() {
			int choice;

			cout << "\n���ڿﶵ:";
			cout << "\n1 - $20";
			cout << "\n2 - $40";
			cout << "\n3 - $60";
			cout << "\n4 - $100";
			cout << "\n5 - $200";
			cout << "\n6 - �����Ӧ����";

			do {
				cout << "\n\n�п�J�z�����: ";
				choice = inputAnInteger(1, 6);
			} while (choice == -1);

			switch (choice) {
			case 1:
				if (availableBalance >= 20) {
					availableBalance -= 20;
					totalBalance -= 20;
					cout << "\n�Ч�{���⨫�A�קK�ۤv���v�q�ॢ";
				}
				else
					cout << "���Y�̪��l�B�����A�Х��T�{�ۤv���s��";
				break;
			case 2:
				if (availableBalance >= 40) {
					availableBalance -= 40;
					totalBalance -= 40;
					cout << "\n�Ч�{���⨫�A�קK�ۤv���v�q�ॢ";
				}
				else
					cout << "���Y�̪��l�B�����A�Х��T�{�ۤv���s��";
				break;
			case 3:
				if (availableBalance >= 60) {
					availableBalance -= 60;
					totalBalance -= 60;
					cout << "\n�Ч�{���⨫�A�קK�ۤv���v�q�ॢ";
				}
				else
					cout << "���Y�̪��l�B�����A�Х��T�{�ۤv���s��";
				break;
			case 4:
				if (availableBalance >= 100) {
					availableBalance -= 100;
					totalBalance -= 100;
					cout << "\n�Ч�{���⨫�A�קK�ۤv���v�q�ॢ";
				}
				else
					cout << "���Y�̪��l�B�����A�Х��T�{�ۤv���s��";
				break;
			case 5:
				if (availableBalance >= 200) {
					availableBalance -= 200;
					totalBalance -= 200;
					cout << "\n�Ч�{���⨫�A�קK�ۤv���v�q�ॢ";
				}
				else
					cout << "���Y�̪��l�B�����A�Х��T�{�ۤv���s��";
				break;
			case 6:
				return;
			}
	}
	void deposit() {
		float save;
		cout << "\n�п�J�z�n�s�X����->(��J0����): ";
		cin >> save;
		save /= 100;
		cout << "\n�бN$" << fixed << setprecision(2) << save << "��J�H�ʨç�J����";
		cout << "\n\n�w�g����z���H��";
		cout << "\n�`�N: �b�ڭֹ̮���B���e�A�z�����Ħs�ڤ��|���W�W�[";
		totalBalance += save;
	}
private:
	int accountNumber = 0;
	int PIN = 0;
	float availableBalance = 0;
	float totalBalance = 0;
};



#endif
