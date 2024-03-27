#include "hw10.h"

void login(vector< Account >& accountDetails);

int main()
{
	cout << "你好~歡迎光臨!\n\n";
	vector<Account>accountDetails = {(1), (2)};
	login(accountDetails);
	cout << "\n掰掰~謝謝惠顧";
	return 0;
}

void login(vector< Account >& accountDetails)
{
	int tempaccounnt, tempPIN, i;
	bool breaking = true;
	
	do {
		cout << "請輸入你的account number (輸入0結束交易) : ";
		cin >> tempaccounnt;
		if (!tempaccounnt)
			return;
		cout << "\n請輸入 PIN: ";
		cin >> tempPIN;
		for (i = 0; i < accountDetails.size(); i++)
			if (accountDetails[i].valid(tempaccounnt, tempPIN)) {
				breaking = false;
				break;
			}
		if (breaking)
			cout << "\n帳號或密碼是錯誤的，請您在輸入一次。\n\n";
	} while (breaking);

	while (true) {
		int choice;
		cout << "\n主選單:";
		cout << "\n1 - 查看餘額";
		cout << "\n2 - 提款";
		cout << "\n3 - 存款";
		cout << "\n4 - 離開";
		do {
			cout << "\n\n請輸入您的選擇: ";
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
			cout << "\n正在離開系統...";
			return;
		}
	}
}