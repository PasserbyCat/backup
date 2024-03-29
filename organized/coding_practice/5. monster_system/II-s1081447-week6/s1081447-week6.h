#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Monster {
    private:
        int HP;
        int MaxHP;
        int Attack;
        int Defense;
    public:
        Monster(int hp, int mxhp, int atk, int def):HP(hp),MaxHP(mxhp),Attack(atk),Defense(def){}
        void setHP(int hp){ HP = hp; }
        int getHP() const { return HP; }
        int getMaxHP() const { return MaxHP; }
        int getAttack() const { return Attack; }
        int getDefense() const { return Defense; }
        void showStats(){
            std::cout << std::setw(10) << "Monster(" << std::setw(3) << getHP() << " / " << std::setw(3) << getMaxHP() << " )" << std::endl; 
        }
        void attack(Monster &m){
            m.setHP(m.getHP() - (getAttack() - m.getDefense()));
        }
};

class Dragon : public Monster {
   private:
      float rate;
   public:
      Dragon(float input) : Monster(1000, 1000, 70, 20), rate(input){};
      void attack(Monster& another);
      void showStats();
};

class Unicorn : public Monster {
   private:
      bool rate[4] = {};
   public:
      Unicorn() : Monster(1000, 1000, 70, 20) {
         int x = rand() % 4;
         rate[x] = true;
      };
      void attack(Monster& another);
      void showStats();
};

void Dragon::attack(Monster& another)
{
   int x = rand() % 11 * rate;
   another.setHP(another.getHP() - getAttack() + another.getDefense() - x);
}

void Unicorn::attack(Monster& another)
{
   int x = rand() % 4;

   if (rate[x])
      another.setHP(another.getHP() - getAttack() + another.getDefense() - getAttack());
   else
      another.setHP(another.getHP() - getAttack() + another.getDefense());
}

void Dragon::showStats()
{
   cout << "\nDragon : HP-> " << getHP() << " MaxHP-> " << getMaxHP() << endl << endl;
}

void Unicorn::showStats()
{
   cout << "\nUnicorn : HP-> " << getHP() << " MaxHP-> " << getMaxHP() << endl << endl;
}
#endif // MONSTER_H
