#include <iostream>
#include "rectangle.h"

rectangle::rectangle()
   : width(1),
      length(1)
{

}

void rectangle::setWidth(int ww)
{
   while (ww > 20 || ww < 1) {
      cout << "Your input is illegal.\nPlease input again.\n";
      cin >> ww;
   }
   width = ww;
}

void rectangle::setLength(int ll)
{
   while (ll > 20 || ll < 1) {
      cout << "Your input is illegal.\nPlease input again.\n";
      cin >> ll;
   }
   length = ll;
}

int rectangle::getWidth()
{
   return width;
}

int rectangle::getLength()
{
   return length;
}

void rectangle::setFillCharacter(char word)
{
   fillCharacter = word;
}

void rectangle::draw()
{
   for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
         if (i == 0 || j == 0 || i == length - 1 || j == width - 1)
            cout << fillCharacter;
         else {
            cout << " ";
         }
      }
      cout << endl;
   }
}
