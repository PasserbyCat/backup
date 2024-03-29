//week7-template practice
// The example of C++ Class
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

using namespace std;

template <typename T>
class Array {
   using size_type = int;
    public:
        Array(size_type s);
        ~Array();
        void setValue(size_type index, T value);
        T getValue(size_type index);
    private:
       size_type Size;
        T *ArrayPtr;
};

#endif // ARRAY_H

template <typename T>
Array< T >::Array(size_type s)
{
   ArrayPtr = new T[s]();
}

template <typename T>
Array< T >::~Array()
{
   delete[]ArrayPtr;
}

template <typename T>
void Array< T >::setValue(size_type index, T value)
{
   ArrayPtr[index] = value;
}

template <typename T>
T Array< T >::getValue(size_type index)
{
   return ArrayPtr[index];
}