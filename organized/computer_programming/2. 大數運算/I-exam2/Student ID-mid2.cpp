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

const int numTestCases = 20;
const int arraySize = 200;

// HugeInt class definition
class HugeInt
{
public:
   // enable user to input a positive huge integer
   void input( istream &inFile );

   // output the specified huge integer
   void output( ostream &outFile );

   // returns true if and only if the specified huge integer is zero
   bool isZero();

   // return true if and only if current object == hugeInt2
   bool equal( HugeInt &hugeInt2 );

   // a recursive function that returns true if and only if
   // elems[ 0 .. last ] == hugeInt2.elems[ 0 .. last ]
   // provided that size == hugeInt2.size
   bool recursiveEqual( HugeInt &hugeInt2, int last );

   // return true if and only if current object < hugeInt2
   bool less( HugeInt &hugeInt2 );

   // a recursive function that returns true if and only if
   // elems[ 0 .. last ] < hugeInt2.elems[ 0 .. last ]
   // provided that size == hugeInt2.size
   bool recursiveLess( HugeInt &hugeInt2, int last );

   // request the current object to reduce its array to fit its size
   void shrink_to_fit();

   // sum = current object + adder
   void addition( HugeInt &adder, HugeInt &sum );

   // a recursive function that perform the carry operation
   // used in addition and multiplication
   int carrying( int last );

   // difference = current object - subtrahend
   // provided that the current object is greater than or equal to the subtrahend
   void subtraction( HugeInt &subtrahend, HugeInt &difference );

   // a recursive function that perform the borrow operation used in subtraction
   int borrowing( int last );

   // product = current object * multiplier
   void multiplication( HugeInt &multiplier, HugeInt &product );

   // quotient = current object / divisor; remainder = current object % divisor
   // provided that the divisor is not equal to 0
   void division( HugeInt &divisor, HugeInt &quotient, HugeInt &remainder );

   // left = current object; assignment
   void assign( HugeInt &left );

   // current object /= 10
   void divideByTen();

   void reset();

   int size = 1; // the number of digits of the integer; it can never be zero
   int *elems = new int[ 1 ]();  // used to store a nonnegative integer, one digit per element
}; // end class HugeInt


// enable user to input a positive huge integer
void HugeInt::input( istream &inFile )
{
   char numericString[ arraySize ];

   inFile >> numericString;

   size = strlen( numericString );
   delete[] elems;
   elems = new int[ size ];
   for( int i = 0; i < size; i++ )
      elems[ i ] = numericString[ size - i - 1 ] - '0';
} // end function input

// output the specified huge integer
void HugeInt::output( ostream &outFile )
{
   for( int i = size - 1; i >= 0; i-- )
      if( elems[ i ] < 10 )
         outFile << elems[ i ];
   outFile << endl;
} // end function output

// returns true if and only if the specified huge integer is zero
bool HugeInt::isZero()
{
   if( size == 1 && elems[ 0 ] == 0 )
      return true;
   return false;
}

// return true if and only if current object == hugeInt2
bool HugeInt::equal( HugeInt &hugeInt2 )
{
   if( size != hugeInt2.size )
      return false;

   return recursiveEqual( hugeInt2, size - 1 );
}

// a recursive function that returns true if and only if
// elems[ 0 .. last ] == hugeInt2.elems[ 0 .. last ]
// provided that size == hugeInt2.size
bool HugeInt::recursiveEqual( HugeInt &hugeInt2, int last )
{

}

// returns true if and only if current object < hugeInt2
bool HugeInt::less( HugeInt &hugeInt2 )
{
   if( size < hugeInt2.size )
      return true;
   if( size > hugeInt2.size )
      return false;

   return recursiveLess( hugeInt2, size - 1 );
}

// a recursive function that returns true if and only if
// elems[ 0 .. last ] < hugeInt2.elems[ 0 .. last ]
// provided that size == hugeInt2.size
bool HugeInt::recursiveLess( HugeInt &hugeInt2, int last )
{

}

// request the current object to reduce its array to fit its size
void HugeInt::shrink_to_fit()
{
   int *buffer = new int[ size ];
   for( int i = 0; i < size; i++ )
      buffer[ i ] = elems[ i ];
   delete [] elems;
   elems = buffer;
}

// sum = current object + adder
void HugeInt::addition( HugeInt &adder, HugeInt &sum )
{
   sum.size = ( size >= adder.size ) ? size + 1 : adder.size + 1;

   delete[] sum.elems;
   sum.elems = new int[ sum.size ]();

   for( int i = 0; i < size; i++ )
      sum.elems[ i ] = elems[ i ];

   for( int i = 0; i < adder.size; i++ )
      sum.elems[ i ] += adder.elems[ i ];

   // a recursive function that perform the carry operation
   sum.carrying( sum.size - 1 );

   if( sum.elems[ sum.size - 1 ] == 0 )
   {
      sum.size--;
      sum.shrink_to_fit();
   }
}

int HugeInt::carrying( int last )
{

}

// difference = current object - subtrahend
// provided that the current object is greater than or equal to the subtrahend
void HugeInt::subtraction( HugeInt &subtrahend, HugeInt &difference )
{
   if( equal( subtrahend ) )
      difference.reset();
   else
   {


      // a recursive function that perform the borrow operation
      difference.borrowing( difference.size - 1 );


   }
}

int HugeInt::borrowing( int last )
{

}

// product = current object * multiplier
void HugeInt::multiplication( HugeInt &multiplier, HugeInt &product )
{
   if( isZero() || multiplier.isZero() )
      product.reset();
   else
   {


      // a recursive function that perform the carry operation
      product.carrying( product.size - 1 );


   }
}

// quotient = current object / divisor; remainder = current object % divisor
// provided that the divisor is not equal to 0
void HugeInt::division( HugeInt &divisor, HugeInt &quotient, HugeInt &remainder )
{
   if( isZero() )        // current object == 0
   {
      quotient.reset();  // quotient == 0
      remainder.reset(); // remainder == 0
   }
   else if( less( divisor ) ) // current object < divisor
   {
      quotient.reset();       // quotient == 0
      assign( remainder );    // remainder = dividend
   }
   else if( equal( divisor ) ) // current object == divisor
   {
      quotient.reset();        // quotient == 0
      quotient.elems[ 0 ] = 1; // quotient == 1
      remainder.reset();       // remainder == 0
   }
   else
   {

   }
}

// left = current object; assignment
void HugeInt::assign( HugeInt &left )
{
   left.size = size;
   delete[] left.elems;
   left.elems = new int[ left.size ];
   for( int i = 0; i < left.size; i++ )
      left.elems[ i ] = elems[ i ];
}

// current object /= 10
void HugeInt::divideByTen()
{
   if( size == 1 )
      elems[ 0 ] = 0;
   else
   {
      for( int i = 1; i < size; i++ )
         elems[ i - 1 ] = elems[ i ];

      size--;
      elems[ size ] = 0;
      shrink_to_fit();
   }
}

void HugeInt::reset()
{
   size = 1;
   delete[] elems;
   elems = new int[ 1 ]();
}

void inputAll( HugeInt hugeInt1[], HugeInt hugeInt2[] )
{

}

// output the specified huge integer
void outputScreen( HugeInt hugeInt1[], HugeInt hugeInt2[],
                   HugeInt hugeInt3[], HugeInt hugeInt4[] )
{
   for( int i = 0; i < numTestCases; i++ )
   {
      hugeInt1[ i ].output( cout );
      hugeInt2[ i ].output( cout );
      hugeInt3[ i ].output( cout );
      hugeInt4[ i ].output( cout );
      cout << endl;
   }
}

// output the specified huge integer
void outputFile( HugeInt hugeInt1[], HugeInt hugeInt2[],
                 HugeInt hugeInt3[], HugeInt hugeInt4[] )
{

}

int main()
{
   system( "mode con cols=80" );

   HugeInt hugeInt1[ numTestCases ];
   HugeInt hugeInt2[ numTestCases ];
   HugeInt hugeInt3[ numTestCases ];
   HugeInt hugeInt4[ numTestCases ];

   inputAll( hugeInt1, hugeInt2 );

   for( int i = 0; i < numTestCases; i++ )
      hugeInt1[ i ].division( hugeInt2[ i ], hugeInt3[ i ], hugeInt4[ i ] );
      // hugeInt3 = hugeInt1 / hugeInt2; hugeInt4 = hugeInt1 % hugeInt2

   outputScreen( hugeInt1, hugeInt2, hugeInt3, hugeInt4 );
   outputFile( hugeInt1, hugeInt2, hugeInt3, hugeInt4 );

   for( int i = 0; i < numTestCases; i++ )
   {
      delete[] hugeInt1[ i ].elems;
      delete[] hugeInt2[ i ].elems;
      delete[] hugeInt3[ i ].elems;
      delete[] hugeInt4[ i ].elems;
   }

   system( "pause" );
}