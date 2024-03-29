#pragma once
#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class implement;

class pet 
{
public:
	pet(string);
	~pet();
	string Name();
	virtual string makeSound();
private:
	class implement;
	implement* ptm;
};

class cat : public pet
{
public:
	cat(string);
	string makeSound();
};

class dog : public pet
{
public:
	dog(string);
	string makeSound();
};

#endif