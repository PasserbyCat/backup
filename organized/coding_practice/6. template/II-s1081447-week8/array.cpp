#include "array.h"

template <typename T>
Array< T >::Array(int input)
{
   ArrayPtr = new T[input]();
   size = input;
}

template <typename T>
Array< T >::~Array() { delete[]ArrayPtr; }

template <typename T>
void Array< T >::setValue(int index, T value) { ArrayPtr[index] = value; }

template <typename T>
T Array< T >::getValue(int index) { return ArrayPtr[index]; }

template <typename T>
void Array< T >::setSize(int index) { size = index; }

template <typename T>
int Array< T >::getSize() { return size; }

template class Array<int>;
template class Array<float>;
template class Array<string>;