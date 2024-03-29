#include "pokemondatabase.h"
#include <fstream>
#include <iostream>
#include <sstream>

template <typename T>
PokemonDatabase<T>::PokemonDatabase()
{
	loadPokemon();//讀所有的pokemon
	loadPicture();//讀所有pokemon的圖片
}

template <typename T>
T PokemonDatabase<T>::getData(int i) { return data[i]; }//回傳第i筆pokemon的數據

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
	//分為兩個情況，讀圖片檔
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
		gotoxy(x, y);//控制輸出的位置
		std::cout << picture[i][j];
	}//輸出圖片
}

//讀取所有的寶可夢資料(只有constructor用到，也只需要讀一次)
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

	std::stringstream first, second;//用來轉型態，因為csv檔裡有int和string
	std::string value;
	while (getline(inFile, value, '\n')) {
		first.str("");
		first.clear();
		first << value;//存資料
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
		data.push_back(Pokemon(number, name, type, HP, HP, attack, defence, speed, ability));//利用constructor將資料存進private
	}
	inFile.close();
}

template class PokemonDatabase<Pokemon>;