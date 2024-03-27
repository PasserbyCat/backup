// BalanceInquiry.h
// BalanceInquiry class definition. Represents a balance inquiry.
#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H

#include <vector> // class uses vector to store Account objects
using namespace std;
#include "Account.h" // Account class definition

class BalanceInquiry
{
public:
   BalanceInquiry( int userAccountNumber, vector< Account > &atmAccounts ); // constructor
   void execute(); // perform the balance inquiry transaction
private:
   int accountNumber; // indicates account involved
   vector< Account > &accounts; // reference to the vector of the bank's Accounts
   int realaccountplace;

   // get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
   Account * getAccount( int accountNumber, vector< Account > &accounts ); 
}; // end class BalanceInquiry

Account* BalanceInquiry::getAccount(int accountNumber, vector< Account >& accounts)
{
    int i = 0;
    for (; i < accounts.size(); i++)
        if (accounts[i].getAccountNumber() == accountNumber)
            break;
    return &accounts[i];
}

void BalanceInquiry::execute()
{
    cout << "\n您的存款";
    cout << "\n - 有效存款: " << setw(10) << "$" << fixed << setprecision(2) << getAccount(accountNumber, accounts)->getAvailableBalance();
    cout << "\n - 存款總金額: " << setw(8) << "$" << fixed << setprecision(2) << getAccount(accountNumber, accounts)->getTotalBalance() << endl;
}

BalanceInquiry::BalanceInquiry(int userAccountNumber, vector< Account >& atmAccounts)
    :accountNumber(userAccountNumber), accounts(atmAccounts)
{
}

#endif // BALANCE_INQUIRY_H