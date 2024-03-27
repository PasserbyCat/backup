#include "hw10.h"

void login(vector< Account >& accountDetails);

int main()
{
	cout << "�A�n~�w����{!\n\n";
	vector<Account>accountDetails = {(1), (2)};
	login(accountDetails);
	cout << "\n�T�T~���´f�U";
	return 0;
}

void login(vector< Account >& accountDetails)
{
	int tempaccounnt, tempPIN, i;
	bool breaking = true;
	
	do {
		cout << "�п�J�A��account number (��J0�������) : ";
		cin >> tempaccounnt;
		if (!tempaccounnt)
			return;
		cout << "\n�п�J PIN: ";
		cin >> tempPIN;
		for (i = 0; i < accountDetails.size(); i++)
			if (accountDetails[i].valid(tempaccounnt, tempPIN)) {
				breaking = false;
				break;
			}
		if (breaking)
			cout << "\n�b���αK�X�O���~���A�бz�b��J�@���C\n\n";
	} while (breaking);

	while (true) {
		int choice;
		cout << "\n�D���:";
		cout << "\n1 - �d�ݾl�B";
		cout << "\n2 - ����";
		cout << "\n3 - �s��";
		cout << "\n4 - ���}";
		do {
			cout << "\n\n�п�J�z�����: ";
			choice = inputAnInteger(1, 4);
		} while (choice == -1);
		switch (choice) {
		case 1:
			accountDetails[i].balance();
			break;
		case 2:
			accountDetails[i].withdraw();
			break;
		case 3:
			accountDetails[i].deposit();
			break;
		case 4:
			cout << "\n���b���}�t��...";
			return;
		}
	}
}