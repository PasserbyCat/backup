#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace::std;

// reads in a C++ program from a cpp file, and put it to the array program
void load(char(*program)[100], int& numLines);

// deletes the comment beginning with "//" from sourceLine if any
void delComment(char sourceLine[]);

// deletes all string constants from sourceLine
void delStrConsts(char sourceLine[]);

// deletes all character constants from sourceLine
void delCharConsts(char sourceLine[]);

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers);

// stores all non-keyword strings in the array identifiers into a text file
void store(char(*identifiers)[32], int numIdentifiers);

// returns true if and only if str is a C++ keyword
bool keyword(char str[]);

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(char(*identifiers)[32], int pos);

const char keywords[][20] = { "auto", "break", "case", "char", "const",
								"continue", "default", "define","do", "double",
								"else", "enum", "extern", "float", "for",
								"goto", "if", "int", "long", "register",
								"return", "short", "signed", "sizeof",
								"static", "struct", "switch", "typedef",
								"union", "unsigned", "void", "volatile",
								"while", "bool", "catch", "class",
								"const_cast", "delete", "dynamic_cast",
								"explicit", "false", "friend", "inline",
								"mutable", "namespace", "new", "operator",
								"private", "protected", "public",
								"reinterpret_cast", "static_cast", "template",
								"this", "throw", "true", "try", "typeid",
								"typename", "using", "virtual", "include" };

int main()
{
	char(*program)[100] = new char[500][100]();
	int numLines = 0;

	// reads in a C++ program from a cpp file, and put it to the array program
	load(program, numLines);

	char(*identifiers)[32] = new char[500][32]();
	int numIdentifiers = 0;

	for (int i = 0; i < numLines; i++)
	{
		delComment(program[i]); // deletes the comment beginning with "//" from program[ i ]
		delStrConsts(program[i]); // deletes all string constants from program[ i ]
		delCharConsts(program[i]); // deletes all character constants from program[ i ]

		if (strcmp(program[i], "") != 0)
			extractIdentifiers(program[i], identifiers, numIdentifiers);
		// extracts all identifiers from program[ i ], and put them into the array identifiers
	}

	// stores all non-keyword strings in the array identifiers into a text file
	store(identifiers, numIdentifiers);

	delete[] program;

	delete[] identifiers;

	system("pause");
}

// reads in a C++ program from a cpp file, and put it to the array program
void load(char(*program)[100], int& numLines)
{
	ifstream inFile("test.cpp", ios::in);
	//�}�ɻPŪ��
	while (!inFile.eof())
	{
		inFile.getline(program[numLines], 100);
		numLines++;
	}
	inFile.close();
}

// deletes the comment beginning with "//" from sourceLine if any
void delComment(char* sourceLine)
{
	//�����׽u�����ѡA�����ɪŦr��
	for (int i = 0; i < 99; i++)
		if (sourceLine[i] == 47 && sourceLine[i + 1] == 47)
			sourceLine[i] = 0;
}

// deletes all string constants from sourceLine
void delStrConsts(char sourceLine[])
{
	int length = 0;
	//�p���Ӥ޸���������
	for (int i = 0; i < 99; i++)
	{
		if (sourceLine[i] == 34)
		{
			//�p���Ӥ޸���������
			for (int j = i + 1; sourceLine[j] != 34; length++, j++);
			//����
			for (; i < 100; i++)
				sourceLine[i] = sourceLine[i + length + 2];
		}
	}
}

// deletes all character constants from sourceLine
void delCharConsts(char sourceLine[])
{
	//�r�Ŭ��@�Ӧr��
	for (int i = 0; i < 98; i++)
		if (sourceLine[i] == 39 && sourceLine[i + 2] == 39)
			for (int j = i; j < 98; j++)
				sourceLine[j] = sourceLine[j + 3];
	//�r�Ŭ���Ӧr�ɡA��:'\"'
	for (int i = 0; i < 97; i++)
		if (sourceLine[i] == 39 && sourceLine[i + 3] == 39)
			for (int j = i; j < 97; j++)
				sourceLine[j] = sourceLine[j + 4];
}

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers)
{
	for (int i = 0; sourceLine[i] != 0; i++)
		//�Ĥ@�Ӧr�Ť��i��O�Ʀr
		if ((sourceLine[i] == 95) || (sourceLine[i] >= 65 && sourceLine[i] <= 90) || (sourceLine[i] >= 97 && sourceLine[i] <= 122))
		{
			identifiers[numIdentifiers][0] = sourceLine[i];
			i++;
			//�x�s�Ѿl�r��
			for (int j = 1; (sourceLine[i] >= 48 && sourceLine[i] <= 57) || (sourceLine[i] >= 65 && sourceLine[i] <= 90) || (sourceLine[i] >= 97 && sourceLine[i] <= 122) || (sourceLine[i] == 95); i++, j++)
				identifiers[numIdentifiers][j] = sourceLine[i];
			numIdentifiers++;
		}
}

// stores all non-keyword strings in the array identifiers into a text file
void store(char(*identifiers)[32], int numIdentifiers)
{
	//�ư�keyword
	for (int i = 0; i < numIdentifiers; i++)
		if (keyword(identifiers[i]))
			identifiers[i][0] = '\0';
	//�ư��w��X���r��
	for (int i = 0; i < numIdentifiers; i++)
		if (duplicate(identifiers, i))
			identifiers[i][0] = '\0';
	//����
	ofstream outFile;
	outFile.open("answer.txt");
	//��X
	for (int i = 0; i < numIdentifiers; i++)
		if (identifiers[i][0] != '\0')
			outFile << identifiers[i] << endl;
	outFile.close();
}

// returns true if and only if str is a C++ keyword
bool keyword(char str[])
{
	bool key = false;
	for (int i = 0; i < 62; i++)
		if (!strcmp(str, keywords[i]))
		{
			key = true;
			break;
		}
	return key;
}

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(char(*identifiers)[32], int pos)
{
	bool same = false;
	for (int i = 0; i < pos; i++)
		if (!strcmp(identifiers[pos], identifiers[i]))
		{
			same = true;
			break;
		}
	return same;
}