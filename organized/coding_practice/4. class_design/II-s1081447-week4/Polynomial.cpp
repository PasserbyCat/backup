//Operator overloading (3 weeks)
#include "Polynomial.h"

Polynomial::Polynomial(int x = 0)
{
   array = new int[x]();
   size = x;
}

Polynomial::Polynomial(const Polynomial &k)
{
   array = new int[k.size]();
   for (int i = 0; i < k.size; i++) {
      array[i] = k.array[i];
   }
   size = k.size;
}

istream& operator>>(istream& in, Polynomial& outPoint)
{
   for (int i = 0; i < outPoint.size; i++) {
      in >> outPoint.array[i];
   }
   return in;
}

ostream& operator<<(ostream& out, const Polynomial& outPoint)
{
   for (int i = 0; i < outPoint.size; i++) {
      out << outPoint.array[i] << " * X^" << i;
      if (i == outPoint.size - 1) {
         out << endl;
      }
      else {
         out << " + ";
      }
   }
   return out;
}

Polynomial Polynomial::operator+(Polynomial& rightPoint)
{
   
   if (size > rightPoint.size) {
      Polynomial news(size);
      for (int i = 0; i < rightPoint.size; i++) {
         news.array[i] = array[i] + rightPoint.array[i];
      }
      for (int i = rightPoint.size; i < size; i++) {
         news.array[i] = array[i];
      }
      return news;
   }
   else {
      Polynomial news(rightPoint.size);
      for (int i = 0; i < size; i++) {
         news.array[i] = rightPoint.array[i] + array[i];
      }
      for (int i = size; i < rightPoint.size; i++) {
         news.array[i] = rightPoint.array[i];
      }
      return news;
   }
}

Polynomial Polynomial::operator-(Polynomial& rightPoint)
{
   if (size > rightPoint.size) {
      Polynomial news(size);
      for (int i = 0; i < rightPoint.size; i++) {
         news.array[i] = array[i] - rightPoint.array[i];
      }
      for (int i = rightPoint.size; i < size; i++) {
         news.array[i] = array[i];
      }
      return news;
   }
   else {
      Polynomial news(rightPoint.size);
      for (int i = 0; i < size; i++) {
         news.array[i] = array[i] - rightPoint.array[i];
      }
      for (int i = size; i < rightPoint.size; i++) {
         news.array[i] = -rightPoint.array[i];
      }
      return news;
   }
}