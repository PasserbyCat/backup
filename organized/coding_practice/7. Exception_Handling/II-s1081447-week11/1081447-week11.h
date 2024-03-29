//week11-Exception Handling (2 weeks)
#pragma once

#ifndef CHINESEYEAR_H
#define CHINESEYEAR_H

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

string allanimal[12] = { "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig" };

class ChineseYear
{
	friend ostream& operator<<(ostream& output, const ChineseYear& now)
	{
		output << now.animal << " " << now.year << "-" << now.year + 1;
		return output;
	}

public:
	class WrongGregorianYear : runtime_error {
	public :
		WrongGregorianYear()
			:runtime_error("Invalid Gregorian Year (must be >= 1900)") {}

		string what()
		{
			return "Invalid Gregorian Year (must be >= 1900)";
		}
	};
	class WrongChineseYear : runtime_error {
	public:
		WrongChineseYear()
			:runtime_error("Invalid Chinese Year") {}

		string what()
		{
			return "Invalid Chinese Year";
		}
	};

	ChineseYear() {}

	ChineseYear(string inputanimal)
	{
		for (int i = 0; i < 12; i++)
			if (inputanimal == allanimal[i])
				break;
			else if (i == 11)
				throw WrongChineseYear();

		int place = 0;
		for (int i = 11; i > -1; i--) {
			if (inputanimal == allanimal[i]) {
				break;
			}
			year--;
		}
		animal = inputanimal;
		year--;
	}

	ChineseYear(int inputyear)
	{
		if (inputyear < 1900)
			throw WrongGregorianYear();

		int place;
		place = inputyear - year;
		place += 1200;
		place %= 12;
		animal = allanimal[place];
		year = inputyear;
	}

	string getanimal() { return animal; }

	int getyear() { return year; }

	void setanimal(string input)
	{
		for (int i = 0; i < 12; i++)
			if (input == allanimal[i])
				break;
			else if (i == 11)
				throw;

		animal = input;
	}

	void setyear(int inputyear)
	{
		if (inputyear < 1900)
			throw;
		year = inputyear;
	}

	ChineseYear operator+=(int plus) {
		year += 1;

		int place = 0;
		for (int i = 0; animal != allanimal[i]; place++, i++) {};
		place += plus;
		place %= 12;
		animal = allanimal[place];
		return *this;
	}
private:
	string animal = { "Rat" };
	int year = 2020;
};

ChineseYear operator+(ChineseYear input, int plus) {
	input.setyear(input.getyear() + plus);

	int place = 0;
	for (int i = 0; input.getanimal() != allanimal[i]; place++, i++) {};
	place += plus;
	place %= 12;
	input.setanimal(allanimal[place]);
	
	return input;
}

ChineseYear operator+(int plus, ChineseYear input) {
	input.setyear(input.getyear() + plus);

	int place = 0;
	for (int i = 0; input.getanimal() != allanimal[i]; place++, i++) {};
	place += plus;
	place %= 12;
	input.setanimal(allanimal[place]);
	
	return input;
}
#endif