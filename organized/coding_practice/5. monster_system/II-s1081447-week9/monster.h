#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Monster {
private:
	int HP;
	int MaxHP;
	int Attack;
	int Defense;
public:
	Monster(int hp = 0, int mxhp = 0, int atk = 0, int def = 0) :HP(hp), MaxHP(mxhp), Attack(atk), Defense(def) {}
	void setHP(int hp) { HP = hp; }
	int getHP() const { return HP; }
	int getMaxHP() const { return MaxHP; }
	int getAttack() const { return Attack; }
	int getDefense() const { return Defense; }

	virtual void showStats() { cout << setw(10) << "Monster(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl; }

	virtual void attack(Monster* another) 
	{
		another->setHP(another->getHP() - (getAttack() - another->getDefense()));
		setHP(getHP() - another->getCounterAttack());

		showStats();
		another->showStats();
	}

	virtual int getCounterAttack() { return 0; }
};

class Dragon : public Monster {
private:
	float rate;
public:
	Dragon(float input) : Monster(100, 100, 40, 0), rate(input) {};

	void attack(Monster* another)
	{
		int x = rand() % 11 * rate;
		another->setHP(another->getHP() - getAttack() + another->getDefense() - x);
		setHP(getHP() - another->getCounterAttack());

		showStats();
		another->showStats();
	}

	void showStats() { cout << setw(10) << "Dragon(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl; }
};

class Unicorn : public Monster {
private:
	bool rate[4] = {};
public:
	Unicorn() : Monster(100, 100, 30, 0)
	{
		int x = rand() % 4;
		rate[x] = true;
	}

	void attack(Monster* another)
	{
		int x = rand() % 4;

		if (rate[x])
			another->setHP(another->getHP() - getAttack() + another->getDefense() - getAttack());
		else
			another->setHP(another->getHP() - getAttack() + another->getDefense());

		setHP(getHP() - another->getCounterAttack());

		showStats();
		another->showStats();
	}

	void showStats() { cout << setw(10) << "Unicorn(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl; }
};

class Hedgehog : public Monster {
private:

public:
	Hedgehog() : Monster(100, 100, 32, 0) {}
	int getCounterAttack() { return 8; }

	void showStats() { cout << setw(10) << "Hedgehog(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl; }
};

class Player {
private:
	string name;
	Monster* list[3];
public:
	Player(string input) {
		name = input;
		for (int i = 0; i < 3; i++) {
			if (rand() % 3 == 0) {
				Dragon* tmpdra = new Dragon(0.6);
				list[i] = tmpdra;
			}
			else if (rand() % 3 == 1) {
				Unicorn* tmpuni = new Unicorn();
				list[i] = tmpuni;
			}
			else {
				Hedgehog* tmphed = new Hedgehog();
				list[i] = tmphed;
			}
		}
	}

	string getName() { return name; }

	Monster* getCurrentMonster() {
		for (int i = 0; i < 3; i++)
			if (list[i]->getHP() > 0)
				return list[i];

		return nullptr;
	}

	void showAliveMonsters() {
		cout << endl << getName() << endl;
		int i = 0;
		for (; i < 3; i++)
			if (list[i]->getHP() > 0)
				list[i]->showStats();
	}

	bool win(Player &another)
	{
		if (!another.getCurrentMonster()) {
			cout << endl << getName() << "\t\twin";
			return 1;
		}
		if (!getCurrentMonster()) {
			cout << endl << another.getName() << "\t\twin";
			return 1;
		}
		return 0;
	}
};


#endif // MONSTER_H