// Compute the square root of a huge integer.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
#include <ctime>

// put a randomly generated positive integer into the array hugeInt
void random( int hugeInt[], int hugeIntSize );

// put the square root of hugeInt into the array sqrt
void squareRoot( int hugeInt[], int sqrt[], int hugeIntSize, int &sqrtSize );

// put the square of hugeInt into the array sq
void square( int hugeInt[], int sq[], int hugeIntSize, int &sqSize );

// if hugeInt1 < hugeInt2, retuen true; otherwise, return false
bool less( int hugeInt1[], int hugeInt2[], int size1, int size2 );

// print hugeInt and sqrt
void printResult( int hugeInt[], int sqrt[], int hugeIntSize, int sqrtSize );

// print the square of sqrt and the square of ( sqrt + 1 )
// if hugeInt is less than the square of sqrt, then print Error
// if hugeInt is not less than the square of ( sqrt + 1 ), then print Error
void verify( int hugeInt[], int sqrt[], int hugeIntSize, int sqrtSize );

// increment hugeInt by 1
void increment( int hugeInt[], int &hugeIntSize );

const int arraySize = 80;

int main()
{
//   srand( static_cast< int >( time(0) ) );

   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   int hugeIntSize = 70 + rand() % 10; // the number of digits of hugeInt
   int hugeInt[ arraySize ] = { 0 }; // a huge positive integer in the way that
                                     // hugeInt[0] is the units digit,
                                     // hugeInt[1] is the tens digit,
                                     // hugeInt[2] is the hundreds digit, ...,
                                     // hugeInt[ hugeIntSize - 1 ] is the most significant digit.

   random( hugeInt, hugeIntSize );

   int sqrt[ arraySize ] = { 0 }; // the square root of hugeInt
   int sqrtSize; // the number of digits of sqrt is sqrtSize

   // put the square root of hugeInt into the array sqrt
   squareRoot( hugeInt, sqrt, hugeIntSize, sqrtSize );

   printResult( hugeInt, sqrt, hugeIntSize, sqrtSize );// print hugeInt and sqrt

   // print the square of sqrt and the square of ( sqrt + 1 )
   // if hugeInt is less than the square of sqrt, then print Error
   // if hugeInt is not less than the square of ( sqrt + 1 ), then print Error
   verify( hugeInt, sqrt, hugeIntSize, sqrtSize );

   system( "pause" );
}

// put a randomly generated positive integer into the array hugeInt
void random( int hugeInt[], int hugeIntSize )
{
   for( int i = 0; i < hugeIntSize - 1; i++ )
      hugeInt[i] = rand() % 10;
   hugeInt[ hugeIntSize - 1 ] = 1 + rand() % 9;
}

// put the square root of hugeInt into the array sqrt
void squareRoot( int hugeInt[], int sqrt[], int hugeIntSize, int &sqrtSize )
{

}

// put the square of hugeInt into the array sq
void square( int hugeInt[], int sq[], int hugeIntSize, int &sqSize )
{

}

// if hugeInt1 < hugeInt2, retuen true; otherwise, return false
bool less( int hugeInt1[], int hugeInt2[], int size1, int size2 )
{

}

// print hugeInt and sqrt
void printResult( int hugeInt[], int sqrt[], int hugeIntSize, int sqrtSize )
{
   cout << "The square root of\n\n";
   for( int i = hugeIntSize - 1; i >= 0; i-- )
      cout << hugeInt[ i ];

   cout << "\n\nis\n\n";
   for( int i = sqrtSize - 1; i >= 0; i-- )
      cout << sqrt[ i ];
   cout << endl << endl;
}

// print the square of sqrt and the square of ( sqrt + 1 )
// if hugeInt is less than the square of sqrt, then print Error
// if hugeInt is not less than the square of ( sqrt + 1 ), then print Error
void verify( int hugeInt[], int sqrt[], int hugeIntSize, int sqrtSize )
{
   for( int i = hugeIntSize - 1; i >= 0; i-- )
      cout << "-";
   cout << endl << endl;

   int sq[ arraySize ] = { 0 };
   int sqSize = hugeIntSize;
   square( sqrt, sq, sqrtSize, sqSize );

   cout << "The square of\n\n";

   for( int i = sqrtSize - 1; i >= 0; i-- )
      cout << sqrt[ i ];

   cout << "\n\nis\n\n";

   for( int i = sqSize - 1; i >= 0; i-- )
      cout << sq[ i ];
   cout << endl << endl;

   if( less( hugeInt, sq, hugeIntSize, sqSize ) )
      cout << "Error!\n\n";


   int copy[ arraySize ] = {0};
   int copySize = sqrtSize;
   for( int i = sqrtSize - 1; i >= 0; i-- )
      copy[ i ] = sqrt[ i ];

   increment( copy, copySize );

   square( copy, sq, copySize, sqSize );

   cout << "\nThe square of\n\n";

   for( int i = copySize - 1; i >= 0; i-- )
      cout << copy[ i ];

   cout << "\n\nis\n\n";

   for( int i = sqSize - 1; i >= 0; i-- )
      cout << sq[ i ];
   cout << endl << endl;

   if( !less( hugeInt, sq, hugeIntSize, sqSize ) )
      cout << "Error!\n\n";
}

// increment hugeInt by 1
void increment( int hugeInt[], int &hugeIntSize )
{

}