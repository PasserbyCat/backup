#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "array.h"

template< typename T >
class SortedArray : public Array< T >
{
public:

   SortedArray(int input);

   void addValue(T input);

   //bool big(T x, T y);
};
#endif
//#include "sortedarray.cpp"
