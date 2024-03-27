// Account.h
// Account class definition. Represents a bank account.
#ifndef ACCOUNT_H
#define ACCOUNT_H

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
   Account( int theAccountNumber, int thePIN, double theAvailableBalance,
            double theTotalBalance ); // constructor sets attributes
   bool validatePIN( int userPIN ) const; // is user-specified PIN correct?
   double getAvailableBalance() const; // returns available balance
   double getTotalBalance() const; // returns total balance
   void credit( double amount ); // adds an amount to the Account balance
   void debit( double amount ); // subtracts an amount from the Account balance
   int getAccountNumber() const; // returns account number
private:
   int accountNumber; // account number
   int pin; // PIN for authentication
   double availableBalance; // funds available for withdrawal
   double totalBalance; // funds available + funds waiting to clear
}; // end class Account

void Account::credit(double amount)
{
    totalBalance += amount;
}

void Account::debit(double amount)
{
    availableBalance -= amount;
    totalBalance -= amount;
}

Account::Account(int theAccountNumber, int thePIN, double theAvailableBalance, double theTotalBalance)
     : accountNumber(theAccountNumber),
       pin(thePIN),
       availableBalance(theAvailableBalance),
       totalBalance(theTotalBalance)
{
}

bool Account::validatePIN(int userPIN) const
{
    return pin == userPIN;
}

double Account::getAvailableBalance() const
{
    return availableBalance;
}

double Account::getTotalBalance() const
{
    return totalBalance;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}
#endif // ACCOUNT_H