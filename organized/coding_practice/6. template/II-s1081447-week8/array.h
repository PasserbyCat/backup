
#include <iostream>
#include <string>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H
template <typename T>
class Array {
public:

   Array(int input);

   ~Array();

   void setValue(int index, T value);
   T getValue(int index);

   void setSize(int index);
   int getSize();

protected:

   int size;
   T* ArrayPtr;
};
#endif

 // ARRAY_H#pragma once
