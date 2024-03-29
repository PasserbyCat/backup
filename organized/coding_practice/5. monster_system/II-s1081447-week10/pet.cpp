#include "pet.h"

class pet::implement
{
public:
	implement(string input) { name = new string(input); }
	~implement() { delete name; }
	string *name;
};


pet::pet(string input)
{
	ptm = new implement(input);
}

pet::~pet()
{
	delete ptm;
}

string pet::makeSound()
{
	return "\0";
}

string pet::Name()
{
	return *ptm->name;
}


cat::cat(string input)
	:pet(input)
{
}

string cat::makeSound()
{
	return "miau";
}


dog::dog(string input)
	:pet(input)
{
}

string dog::makeSound()
{
	return "won";
}