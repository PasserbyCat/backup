#pragma once
#include "sortedarray.h"

template <typename T>
bool big(T x, T y) { return (x > y) ? true : false; }

template<> bool big(const string x, const string y)
{
   return (x[0] > y[0]) ? true : false; ;
}

template< typename T >
SortedArray< T >::SortedArray(int input) : Array< T >(input) {}

template< typename T >
void SortedArray< T >::addValue(T input)
{
   T temp;
   for (int i = 0; i < this->getSize(); i++) {
      if (big(input, this->getValue(i))) {
         temp = this->getValue(i);
         this->setValue(i, input);
         input = temp;
      }
   }
}

//template <typename T>
//bool SortedArray< T >::big(T x, T y) { return (x > y) ? true : false; }

template class SortedArray<int>;
template class SortedArray<float>;
template class SortedArray<string>;
//template<> bool SortedArray<const char*>::big(const char* x, const char* y)
//{
//   return strcmp(x, y) > 0 ? true : false;
//}

