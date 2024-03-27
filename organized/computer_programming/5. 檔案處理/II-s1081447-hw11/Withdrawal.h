// Withdrawal.h
// Withdrawal class definition. Represents a withdrawal transaction.
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <vector> // class uses vector to store Account objects
using namespace std;
#include "Account.h" // Account class definition

class Withdrawal
{
public:
   Withdrawal( int userAccountNumber, vector< Account > &atmAccounts, int &atmRemainingBills );
   void execute(); // perform the withdrawal transaction
private:
   int accountNumber; // indicates account involved
   vector< Account > &accounts; // reference to the vector of the bank's Accounts
   int amount; // amount to withdraw
   int &remainingBills; // number of $20 bills remaining 

   // get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
   Account * getAccount( int accountNumber, vector< Account > &accounts ) const;

   // display a menu of withdrawal amounts and the option to cancel;
   // return the chosen amount or 0 if the user chooses to cancel
   int displayMenuOfAmounts() const;
}; // end class Withdrawal

Account* Withdrawal::getAccount(int accountNumber, vector< Account >& accounts) const
{
	int i = 0;
	for (; i < accounts.size(); i++)
		if (accounts[i].getAccountNumber() == accountNumber)
			break;
	return &accounts[i];
}

int Withdrawal::displayMenuOfAmounts() const
{
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
		if (getAccount(accountNumber, accounts)->getAvailableBalance() >= 20.0)
			return 20;
		break;
	case 2:
		if (getAccount(accountNumber, accounts)->getAvailableBalance() >= 40.0)
			return 40;
		break;
	case 3:
		if (getAccount(accountNumber, accounts)->getAvailableBalance() >= 60.0)
			return 60;
		break;
	case 4:
		if (getAccount(accountNumber, accounts)->getAvailableBalance() >= 100.0)
			return 100;
		break;
	case 5:
		if (getAccount(accountNumber, accounts)->getAvailableBalance() >= 200.0)
			return 200;
		break;
	case 6:
		return 0;
	}
	return 1;
}

void Withdrawal::execute()
{
	int withd = displayMenuOfAmounts();
	if (withd == 0)
		return;
	if (withd == 1) {
		cout << "戶頭裡的餘額不足，請先確認自己的存款";
		return;
	}
	getAccount(accountNumber, accounts)->debit(withd);
	cout << "\n請把現金領走，避免自己的權益喪失";
}

Withdrawal::Withdrawal(int userAccountNumber, vector< Account >& atmAccounts, int& atmRemainingBills)
	: accountNumber(userAccountNumber), accounts(atmAccounts), remainingBills(atmRemainingBills)
{
}

#endif // WITHDRAWAL_H