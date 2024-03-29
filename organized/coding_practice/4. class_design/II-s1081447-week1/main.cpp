//Classes(1 week)

#include <iostream>
#include "rectangle.h"

int main(int argc, const char* argv[])
{
   rectangle size;
   int ll, ww;
   char word;

   cout << "Please input a word.\n";
   cin >> word;
   size.setFillCharacter(word);

   cout << "Please input your length.\n";
   cin >> ll;
   size.setLength(ll);

   cout << "Please input your width.\n";
   cin >> ww;
   size.setWidth(ww);

   if (size.getWidth() < 20 && size.getLength() < 20 && size.getLength() > 0 && size.getWidth() > 0) {
      size.draw();
   }
}