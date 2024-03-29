// The definition of Class Point
#ifndef POLYNIMIAL_H
#define POLYNIMIAL_H
#include <iostream>
using namespace std;
class Polynomial {
   friend ostream& operator<<(ostream& out, const Polynomial& outPoint);
   friend istream& operator>>(istream& in, Polynomial& outPoint);

private:
   int* array;
   int size;
public:
   Polynomial(int x);
   Polynomial (const Polynomial &k);
   Polynomial operator+(Polynomial& rightPoint);
   Polynomial operator-(Polynomial& rightPoint);
};
#endif /* POLYNIMIAL_H */