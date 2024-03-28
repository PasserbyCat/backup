#ifndef qq_H
#define qq_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define MAXWORDLENGTH 255
struct dictionary {
	char word[MAXWORDLENGTH];
	unsigned int count;
};

void prepositionsload(vector< dictionary > & temp);

void man();
#endif
