#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include <vector>
using std::vector;

const unsigned int numTestCases = 22;
const unsigned int arraySize = 200;

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, vector< int > &hugeInt1, vector< int > &hugeInt2,
                                vector< int > &hugeInt3, vector< int > &hugeInt4 );

// enable user to input a positive huge integer
void input( istream &inFile, vector< int > &hugeInt );

// outputs hugeInt[ hugeInt.size() - 1 .. 0 ]
void output( ostream &outFile, vector< int > &hugeInt );

// a recursive function that outputs hugeInt[ last .. 0 ]
void recursiveOutput( ostream &outFile, vector< int > &hugeInt, int last );

// returns true if and only if the specified huge integer is zero
bool isZero( vector< int > &hugeInt );

// return true if and only if hugeInt1 == hugeInt2
bool equal( vector< int > &hugeInt1, vector< int > &hugeInt2 );

// a recursive function that returns true if and only if
// hugeInt1[ 0 .. last ] == hugeInt2[ 0 .. last ]
// provided that hugeInt1.size() == hugeInt2.size()
bool recursiveEqual( vector< int > &hugeInt1, vector< int > &hugeInt2, int last );

// return true if and only if hugeInt1 < hugeInt2
bool less( vector< int > &hugeInt1, vector< int > &hugeInt2 );

// a recursive function that returns true if and only if
// hugeInt1[ 0 .. last ] < hugeInt2[ 0 .. last ]
// provided that hugeInt1.size() == hugeInt2.size()
bool recursiveLess( vector< int > &hugeInt1, vector< int > &hugeInt2, int last );

// sum = addend + adder
void addition( vector< int > &addend, vector< int > &adder, vector< int > &sum );

// difference = minuend - subtrahend
// provided that the minuend is greater than or equal to the subtrahend
void subtraction( vector< int > &minuend, vector< int > &subtrahend, vector< int > &difference );

// product = multiplicand * multiplier
void multiplication( vector< int > &multiplicand, vector< int > &multiplier, vector< int > &product );

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that the divisor is not equal to 0
void division( vector< int > &dividend, vector< int > &divisor, vector< int > &quotient, vector< int > &remainder );

// hugeInt /= 10
void divideByTen( vector< int > &hugeInt );

void reset( vector< int > &hugeInt );

int main()
{
   system( "mode con cols=122" );

   ifstream inFile( "Test cases.txt", ios::in );

   // exit program if ifstream could not open file
   if( !inFile )
   {
      cout << "File could not be opened" << endl;
      system( "pause" );
      exit( 1 );
   }

   ofstream outFile( "Result.txt", ios::out );

   // exit program if ofstream could not open file
   if( !outFile )
   {
      cout << "File could not be opened" << endl;
      system( "pause" );
      exit( 1 );
   }

   vector< int > hugeInt1;
   vector< int > hugeInt2;
   vector< int > hugeInt3;
   vector< int > hugeInt4;

   for( int i = 0; i < numTestCases; i++ )
   {
      input( inFile, hugeInt1 );
      input( inFile, hugeInt2 );
      perform( cout, hugeInt1, hugeInt2, hugeInt3, hugeInt4 );
      perform( outFile, hugeInt1, hugeInt2, hugeInt3, hugeInt4 );
      reset( hugeInt1 );
      reset( hugeInt2 );
   }

   inFile.close();
   outFile.close();

   system( "pause" );
}

// perform addition, subtraction, multiplication and division
void perform( ostream &outFile, vector< int > &hugeInt1, vector< int > &hugeInt2,
                                vector< int > &hugeInt3, vector< int > &hugeInt4 )
{
   output( outFile, hugeInt1 );
   output( outFile, hugeInt2 );

   addition( hugeInt1, hugeInt2, hugeInt3 ); // hugeInt3 = hugeInt1 + hugeInt2
   output( outFile, hugeInt3 );

   if( less( hugeInt1, hugeInt2 ) )
   {
      outFile << '-';
      subtraction( hugeInt2, hugeInt1, hugeInt3 ); // hugeInt3 = hugeInt2 - hugeInt1
      output( outFile, hugeInt3 );
   }
   else
   {
      subtraction( hugeInt1, hugeInt2, hugeInt3 ); // hugeInt3 = hugeInt1 - hugeInt2
      output( outFile, hugeInt3 );
   }

   multiplication( hugeInt1, hugeInt2, hugeInt3 ); // hugeInt3 = hugeInt1 * hugeInt2
   output( outFile, hugeInt3 );

   if( isZero( hugeInt2 ) )
   {
      outFile << "DivideByZero!\n";
      outFile << "DivideByZero!\n";
   }
   else
   {
      // hugeInt3 = hugeInt1 / hugeInt2; // hugeInt4 = hugeInt1 % hugeInt2
      division( hugeInt1, hugeInt2, hugeInt3, hugeInt4 );
      output( outFile, hugeInt3 );
      output( outFile, hugeInt4 );
   }

   outFile << endl;
}

// enable user to input a positive huge integer
void input( istream &inFile, vector< int > &hugeInt )
{
   char numericString[ arraySize ];

   inFile >> numericString;

   hugeInt.resize( strlen( numericString ) );
   for( unsigned int i = 0; i < hugeInt.size(); i++ )
      hugeInt[ hugeInt.size() - i - 1 ] = numericString[ i ] - '0';
}

// outputs hugeInt[ hugeInt.size() - 1 .. 0 ]
void output( ostream &outFile, vector< int > &hugeInt )
{
   recursiveOutput( outFile, hugeInt, hugeInt.size() - 1 );
   outFile << endl;
}

// a recursive function that outputs hugeInt[ last .. 0 ]
void recursiveOutput( ostream &outFile, vector< int > &hugeInt, int last )
{

}

// returns true if and only if the specified huge integer is zero
bool isZero( vector< int > &hugeInt )
{
   for( unsigned int i = 0; i < hugeInt.size(); i++ )
      if( hugeInt[ i ] != 0 )
         return false;
   return true;
}

// return true if and only if hugeInt1 == hugeInt2
bool equal( vector< int > &hugeInt1, vector< int > &hugeInt2 )
{
   if( hugeInt1.size() != hugeInt2.size() )
      return false;

   return recursiveEqual( hugeInt1, hugeInt2, hugeInt1.size() - 1 );
}

// a recursive function that returns true if and only if
// hugeInt1[ 0 .. last ] == hugeInt2[ 0 .. last ]
// provided that hugeInt1.size() == hugeInt2.size()
bool recursiveEqual( vector< int > &hugeInt1, vector< int > &hugeInt2, int last )
{

}

// returns true if and only if hugeInt1 < hugeInt2
bool less( vector< int > &hugeInt1, vector< int > &hugeInt2 )
{
   if( hugeInt1.size() < hugeInt2.size() )
      return true;
   if( hugeInt1.size() > hugeInt2.size() )
      return false;

   return recursiveLess( hugeInt1, hugeInt2, hugeInt1.size() - 1 );
}

// a recursive function that returns true if and only if
// hugeInt1[ 0 .. last ] < hugeInt2[ 0 .. last ]
// provided that hugeInt1.size() == hugeInt2.size()
bool recursiveLess( vector< int > &hugeInt1, vector< int > &hugeInt2, int last )
{

}

// sum = addend + adder
void addition( vector< int > &addend, vector< int > &adder, vector< int > &sum )
{
   sum.resize( ( addend.size() >= adder.size() ) ? addend.size() + 1 : adder.size() + 1 );

   for( unsigned int i = 0; i < addend.size(); i++ )
      sum[ i ] = addend[ i ];

   for( unsigned int i = addend.size(); i < sum.size(); i++ )
      sum[ i ] = 0;

   for( unsigned int i = 0; i < adder.size(); i++ )
      sum[ i ] += adder[ i ];

   for( unsigned int i = 0; i < sum.size() - 1; i++ )
      if( sum[ i ] > 9 ) // determine whether to carry a 1
      {
         sum[ i ] -= 10; // reduce to 0-9
         sum[ i + 1 ]++;
      }

   if( sum[ sum.size() - 1 ] == 0 )
      sum.pop_back();
}

// difference = minuend - subtrahend
// provided that the minuend is greater than or equal to the subtrahend
void subtraction( vector< int > &minuend, vector< int > &subtrahend, vector< int > &difference )
{

}

// product = multiplicand * multiplier
void multiplication( vector< int > &multiplicand, vector< int > &multiplier, vector< int > &product )
{

}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that the divisor is not equal to 0
void division( vector< int > &dividend, vector< int > &divisor, vector< int > &quotient, vector< int > &remainder )
{
   if( isZero( dividend ) )
   {
      reset( quotient );
      reset( remainder );
      return;
   }

}

// hugeInt /= 10
void divideByTen( vector< int > &hugeInt )
{
   if( hugeInt.size() == 1 )
      hugeInt[ 0 ] = 0;
   else
   {
      for( unsigned int i = 1; i < hugeInt.size(); i++ )
         hugeInt[ i - 1 ] = hugeInt[ i ];
      hugeInt[ hugeInt.size() - 1 ] = 0;
      hugeInt.pop_back();
   }
}

void reset( vector< int > &hugeInt )
{
   hugeInt.resize( 1 );
   hugeInt[ 0 ] = 0;
}