// Deposit.h
// Deposit class definition. Represents a deposit transaction.
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <vector> // class uses vector to store Account objects
using namespace std;
#include "Account.h" // Account class definition

class Deposit
{
public:
   Deposit( int userAccountNumber, vector< Account > &atmAccounts );
   void execute(); // perform the deposit transaction
private:
   int accountNumber; // indicates account involved
   vector< Account > &accounts; // reference to the vector of the bank's Accounts
   double amount; // amount to deposit

   // get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
   Account * getAccount( int accountNumber, vector< Account > &accounts ); 
   double promptForDepositAmount() const; // prompt user to enter a deposit amount in cents 
}; // end class Deposit

Account* Deposit::getAccount(int accountNumber, vector< Account >& accounts)
{
    int i = 0;
    for (; i < accounts.size(); i++)
        if (accounts[i].getAccountNumber() == accountNumber)
            break;
    return &accounts[i];
}

double Deposit::promptForDepositAmount() const
{
    cout << "enter a deposit amount in cents ";
    double temp;
    cin >> temp;
    return temp / 100;
}

void Deposit::execute()
{
    double save = promptForDepositAmount();
    cout << "\n請將$" << fixed << setprecision(2) << save << "放入信封並投入機器";
    cout << "\n\n已經收到您的信封";
    cout << "\n注意: 在我們核對金額之前，您的有效存款不會馬上增加";
    getAccount(accountNumber, accounts)->credit(save);
}

Deposit::Deposit(int userAccountNumber, vector< Account >& atmAccounts)
    : accountNumber(userAccountNumber), accounts(atmAccounts)
{
}

#endif // DEPOSIT_H