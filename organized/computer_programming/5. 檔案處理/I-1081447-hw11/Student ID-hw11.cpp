#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace::std;

char foods[ 14 ][ 48 ] = { "",
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

int price[ 14 ] = { 0, 220, 176, 216, 200, 200, 432, 225,
                       225, 200, 200, 225, 250, 225 };

struct Date
{
   int year;
   int month;
   int day;
};

struct Account
{
   char email[ 40 ]; // used as the account number
   char password[ 20 ];
   char name[ 12 ];
   char address[ 80 ];
   char phone[ 12 ];
   int cart[ 14 ]; // Cart[i] is the quantity of food #i in the shopping cart
};

struct Order
{
   char orderNumber[ 12 ];
   char email[ 40 ];
   Date deliveryDate;
   Date arrivalDate;
   int quantity[ 14 ]; // quantity[i] is the quantity of food #i in the order
};

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

// add a new account to the file Accounts.dat
void registration( vector< Account > &accountDetails );

// return true if email belongs to accountDetails
bool exists( char email[], const vector< Account > &accountDetails );

// save all elements in accountDetails to the file Accounts.dat
void saveAllAccounts( const vector< Account > &accountDetails );

// login and call shopping
void login( vector< Account > &accountDetails );

// load all accounts details from the file Accounts.dat
void loadAccountDetails( vector< Account > &accountDetails );

// return true if there exists an account with specified email and password; and
// put the account with specified email and password into account
bool valid( char email[], char password[], Account &account,
            const vector< Account > &accountDetails );

// add chosen Foods to the shopping cart
void shopping( Account &account );

// return true if the shopping cart is empty
bool emptyCart( const Account &account );

// display the shopping cart in account
bool displayCart( const Account &account );

// append account in the file Accounts.dat
void saveAccount( const Account &account );

// update the shopping cart in account
void updateCart( Account &account );

// generate a Bill and reset account.cart
void check( Account &account );

// compute the current date
void compCurrentDate( Date &currentDate );

// open the file Orders.txt and call displayOrderDetails twice
void createOrder( const Account &account, const Order &order );

// write an order to Orders.txt or display it on the output window depending on os
void displayOrderDetails( ostream &os, const Account &account, const Order &order );

int main()
{
   vector< Account > accountDetails; // account details for all accounts

   cout << "Welcome to DintaiFung Shopping Mall!\n";
   srand( static_cast< int >( time( 0 ) ) );

   int choice;

   while( true )
   {
      cout << "\n1 - Registration\n";
      cout << "2 - Login\n";
      cout << "3 - End\n";

      do cout << "\nEnter your choice (1~3): ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      cout << endl;

      switch( choice )
      {
      case 1:
         registration( accountDetails );
         break;

      case 2:
         login( accountDetails );
         break;

      case 3:
         cout << "Thank you! Goodbye!\n\n";
         system( "pause" );
         return 0;
      }
   }

   system( "pause" );
}