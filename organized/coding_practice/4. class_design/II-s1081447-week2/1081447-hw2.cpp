//Classes: A Deeper Look (2 weeks)

#include <iostream>
#include "person.h"

// constructor
person::person(char const* nm, int ae)
{
   name = new char[7]();
   for (int i = 0; i < strlen(nm); i++) {
      name[i] = nm[i];
   }
   age = ae;
}

// copy constructor
person::person(person& m)
{
   name = new char[strlen(m.name) + 1]();
   for (int i = 0; i < strlen(m.name); i++) {
      name[i] = m.name[i];
   }

   age = m.age;
}

// destructor
person::~person()
{
   delete[]name;
}

// assignment operator
person& person::operator=(person& m)
{
   name = new char[strlen(m.name) + 1]();
   for (int i = 0; i < strlen(m.name); i++) {
      name[i] = m.name[i];
   }
   age = m.age;
   return *this;
}

// member functions
void person::setName(char const* nm) 
{
   if (strlen(nm) > strlen(name)) {
      delete[]name;
      name = new char[strlen(nm) + 1]();
   }
   for (int i = 0; i < strlen(nm); i++) {
      name[i] = nm[i];
   }
}

void person::setAge(int ae)
{
   age = ae;
}

string person::getName()
{
   return name;
}

int person::getAge()
{
   return age;
}