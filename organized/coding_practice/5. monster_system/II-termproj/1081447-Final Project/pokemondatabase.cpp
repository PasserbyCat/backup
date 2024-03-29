#include "pokemondatabase.h"
#include <fstream>
#include <iostream>
#include <sstream>

template <typename T>
PokemonDatabase<T>::PokemonDatabase()
{
	loadPokemon();//Ū�Ҧ���pokemon
	loadPicture();//Ū�Ҧ�pokemon���Ϥ�
}

template <typename T>
T PokemonDatabase<T>::getData(int i) { return data[i]; }//�^�ǲ�i��pokemon���ƾ�

template <typename T>
void PokemonDatabase<T>::loadPicture()
{
	picture.resize(32);
	std::string value;
	for (int i = 1; i < 10; i++) {
		std::fstream inFile("assets/icons/color/00" + std::to_string(i) + ".txt", std::ios::in);
		while (getline(inFile, value, '\n')) {
			picture[i - 1].push_back(value);
		}
	}
	//������ӱ��p�AŪ�Ϥ���
	for (int i = 10; i < 33; i++) {
		std::fstream inFile("assets/icons/color/0" + std::to_string(i) + ".txt", std::ios::in);
		while (getline(inFile, value, '\n')) {
			picture[i - 1].push_back(value);
		}
	}
}

template <typename T>
void PokemonDatabase<T>::outPicture(int i, int x, int y)
{
	for (int j = 0; j < picture[i].size(); j++, y++) {
		gotoxy(x, y);//�����X����m
		std::cout << picture[i][j];
	}//��X�Ϥ�
}

//Ū���Ҧ����_�i�ڸ��(�u��constructor�Ψ�A�]�u�ݭnŪ�@��)
template <typename T>
void PokemonDatabase<T>::loadPokemon()
{
    std::fstream inFile("assets/pokemons.csv", std::ios::in);
	int number;
	std::string name;
	std::string type;
	int HP;
	int attack;
	int defence;
	int speed;
	int ability;

	int i = -1;

	std::stringstream first, second;//�Ψ��૬�A�A�]��csv�ɸ̦�int�Mstring
	std::string value;
	while (getline(inFile, value, '\n')) {
		first.str("");
		first.clear();
		first << value;//�s���
		while (getline(first, value, ',')) {
			second.str("");
			second.clear();
			i++;
			if (i % 8 == 0) {
				second << value;
				second >> number;
			}
			else if (i % 8 == 1) {
				second << value;
				second >> name;
			}
			else if (i % 8 == 2) {
				second << value;
				second >> type;
			}
			else if (i % 8 == 3) {
				second << value;
				second >> HP;
			}
			else if (i % 8 == 4) {
				second << value;
				second >> attack;
			}
			else if (i % 8 == 5) {
				second << value;
				second >> defence;
			}
			else if (i % 8 == 6) {
				second << value;
				second >> speed;
			}
			else if (i % 8 == 7) {
				second << value;
				second >> ability;
				if (ability == 10)
					defence += 2;
			}
		}
		data.push_back(Pokemon(number, name, type, HP, HP, attack, defence, speed, ability));//�Q��constructor�N��Ʀs�iprivate
	}
	inFile.close();
}

template class PokemonDatabase<Pokemon>;