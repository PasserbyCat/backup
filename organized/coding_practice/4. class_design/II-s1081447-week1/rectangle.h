#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class rectangle
{
   public:
      rectangle();
      void setWidth(int ww);
      void setLength(int ll);
      int getWidth();
      int getLength();
      void setFillCharacter(char word);
      void draw();

   private:
      int width;
      int length;
      char fillCharacter;
};
#endif