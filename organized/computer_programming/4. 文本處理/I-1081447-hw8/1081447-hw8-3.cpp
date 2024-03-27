#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace::std;

// reads in a C++ program from a cpp file, and put it to the vector program
void load(vector< string >& program);

// deletes the comment beginning with "//" from sourceLine if any
void delComment(string& sourceLine);

// deletes all string constants from sourceLine
void delStrConsts(string& sourceLine);

// deletes all character constants from sourceLine
void delCharConsts(string& sourceLine);

// deletes the first identifier from sourceLine, and returns it
string delFirstIdentifier(string& sourceLine);

// stores all non-keyword strings in the vector identifiers into a text file
void store(vector< string >& identifiers);

// return true if and only if "str" is a C++ keyword
bool keyword(string str);

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(vector< string >& identifiers, int pos);

const string keywords[] = { "auto", "break", "case", "char", "const",
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
	vector< string > program;

	// reads in a C++ program from a cpp file, and put it to the vector program
	load(program);

	vector< string > identifiers;
	string firstIdentifier;
	string null;

	for (unsigned int i = 0; i < program.size(); i++)
	{
		delComment(program[i]); // deletes the comment beginning with "//" from program[ i ]
		delStrConsts(program[i]); // deletes all string constants from program[ i ]
		delCharConsts(program[i]); // deletes all character constants from program[ i ]

		// extracts all identifiers from program[ i ], and put them into the vector identifiers
		while ((firstIdentifier = delFirstIdentifier(program[i])) != null)
			identifiers.push_back(firstIdentifier);
	}

	// stores all non-keyword strings in the vector identifiers into a text file
	store(identifiers);

	system("pause");
}

// reads in a C++ program from a cpp file, and put it to the vector program
void load(vector< string >& program)
{
	ifstream inFile("test.cpp", ios::in);
	//�}�ɻPŪ��
	program.resize(0);
	while (!inFile.eof())
	{
		program.resize(program.size() + 1);
		getline(inFile, program[program.size() - 1]);
		
	}
	inFile.close();
}

// deletes the comment beginning with "//" from sourceLine if any
void delComment(string& sourceLine)
{
	//�����׽u�����ѡA�����ɪŦr��
	for (int i = 0; i < sourceLine.size(); i++)
		if (sourceLine[i] == 47 && sourceLine[i + 1] == 47)
			sourceLine[i] = 0;
}

// deletes all string constants from sourceLine
void delStrConsts(string& sourceLine)
{
	int length = 2;
	//�p���Ӥ޸���������
	for (int i = 0; i < sourceLine.size(); i++)
	{
		if (sourceLine[i] == 34)
		{
			//�p���Ӥ޸���������
			for (int j = i + 1; sourceLine[j] != 34; length++, j++);
			sourceLine.erase(i, length);
			length = 2;
		}
	}
}

// deletes all character constants from sourceLine
void delCharConsts(string& sourceLine)
{
	//�r�Ŭ��@�Ӧr��
	for (int i = 0; i < sourceLine.size(); i++)
		if (sourceLine[i] == 39 && sourceLine[i + 2] == 39)
			for (int j = i; j < sourceLine.size(); j++)
				sourceLine[j] = sourceLine[j + 3];
	//�r�Ŭ���Ӧr�ɡA��:'\"'
	for (int i = 0; i < sourceLine.size(); i++)
		if (sourceLine[i] == 39 && sourceLine[i + 3] == 39)
			for (int j = i; j < sourceLine.size(); j++)
				sourceLine[j] = sourceLine[j + 4];
}

// deletes the first identifier from sourceLine, and returns it
string delFirstIdentifier(string& sourceLine)
{
	string identifiers;
	int length = 1;
	for (int i = 0; sourceLine[i] != 0; i++)
		//�Ĥ@�Ӧr�Ť��i��O�Ʀr
		if ((sourceLine[i] == 95) || (sourceLine[i] >= 65 && sourceLine[i] <= 90) || (sourceLine[i] >= 97 && sourceLine[i] <= 122))
		{
			int j = i;
			identifiers += sourceLine[i];
			i++;
			//�x�s�Ѿl�r��
			for (; (sourceLine[i] >= 48 && sourceLine[i] <= 57) || (sourceLine[i] >= 65 && sourceLine[i] <= 90) || (sourceLine[i] >= 97 && sourceLine[i] <= 122) || (sourceLine[i] == 95); i++, length++)
				identifiers += sourceLine[i];
			sourceLine.erase(j, length);
			return identifiers;
		}
	return identifiers;
}

// stores all non-keyword strings in the vector identifiers into a text file
void store(vector< string >& identifiers)
{
	//�ư�keyword
	for (int i = 0; i < identifiers.size(); i++)
		if (keyword(identifiers[i]))
			identifiers[i][0] = '\0';
	//�ư��w��X���r��
	for (int i = 0; i < identifiers.size(); i++)
		if (duplicate(identifiers, i))
			identifiers[i][0] = '\0';
	//����
	ofstream outFile;
	outFile.open("answer.txt");
	//��X
	for (int i = 0; i < identifiers.size(); i++)
		if (identifiers[i][0] != '\0')
			outFile << identifiers[i] << endl;
	outFile.close();
}

// return true if and only if "str" is a C++ keyword
bool keyword(string str)
{
	bool key = false;
	for (int i = 0; i < 62; i++)
		if (str == keywords[i])
		{
			key = true;
			break;
		}
	return key;
}

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(vector< string >& identifiers, int pos)
{
	bool same = false;
	for (int i = 0; i < pos; i++)
		if (identifiers[pos] == identifiers[i])
		{
			same = true;
			break;
		}
	return same;
}