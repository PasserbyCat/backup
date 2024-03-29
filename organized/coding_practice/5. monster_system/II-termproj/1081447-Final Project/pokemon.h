#ifndef POKEMON_H
#define POKEMON_H

#include "rlutil/rlutil.h"
#include <vector>
#include <iomanip>

struct Negative
{
	int availableTime = 4;
	int effectability;
};

class Pokemon
{
public:
	Pokemon(int number, std::string name, std::string type, 
		int HP, int maxHP, int attack, int defence, int speed, int ability);

	float getAllelopathy(int attackType, int defenceType);

	void setHP(int end);
	void setNegative(int ability);

	int getNumber() const;
	std::string getName() const;
	std::string getCharType() const;
	int getIntType() const;
	int getHP() const;
	int getMaxHP() const;
	int getAttack() const;
	int getDefence() const;
	int getSpeed() const;
	int getAbility() const;

	void effectNegative();

	virtual void reset() {};

	virtual void Attack(Pokemon* another);

	virtual int getCounterAttack() const;
private:
	int number;
	std::string name;
	int type = 0;
	int HP = 0;
	int maxHP = 0;
	int attack = 0;
	int defence = 0;
	int speed = 0;
	int ability = 0;

	std::vector<Negative>negative;//存取負面的附加效果

	float allelopathy[18][18];//存取pokemon間的克制關係
	void loadAllelopathy();
};

class Heal : public Pokemon 
{
private:

public:
	Heal(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class Burning : public Pokemon
{
private:

public:
	Burning(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class CounterAttack : public Pokemon
{
private:
	int lastHP = getMaxHP();
public:
	CounterAttack(Pokemon input) : Pokemon(input), lastHP(getMaxHP()) {}
	void Attack(Pokemon* another);
	int getCounterAttack();
	void reset() { lastHP = getMaxHP(); }
};

class Immunology : public Pokemon
{
private:

public:
	Immunology(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class LeechLife : public Pokemon
{
private:

public:
	LeechLife(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class Avoid : public Pokemon
{
private:

public:
	Avoid(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class DoubleAttack : public Pokemon
{
private:

public:
	DoubleAttack(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class Poison : public Pokemon
{
private:
	bool available = true;
public:
	Poison(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
	void reset() { available = true; }
};

class LowerSpeed : public Pokemon
{
private:
	bool available = true;
public:
	LowerSpeed(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
	void reset() { available = true; }
};

class RockSkin : public Pokemon
{
private:

public:
	RockSkin(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
};

class LowerDefence : public Pokemon
{
private:
	bool available = true;
public:
	LowerDefence(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
	void reset() { available = true; }
};

class LowerAttack : public Pokemon
{
private:
	bool available = true;
public:
	LowerAttack(Pokemon input) : Pokemon(input) {}
	void Attack(Pokemon* another);
	void reset() { available = true; }
};

#endif // !POKEMON_H