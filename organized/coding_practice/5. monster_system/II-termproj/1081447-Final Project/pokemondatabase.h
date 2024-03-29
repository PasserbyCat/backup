//將所有的寶可夢資料讀出來並儲存

#ifndef POKEMONDATABASE_H
#define POKEMONDATABASE_H

#include "pokemon.h"
#include <vector>

template <typename T>
class PokemonDatabase
{
public:
	PokemonDatabase();
	
	T getData(int i);

	void outPicture(int i, int x = 1, int y = 1);
private:
	std::vector<T> data;

	std::vector<std::vector<std::string>> picture;

	void loadPokemon();
	
	void loadPicture();
};

#endif // !POKEMONDATABASE_H
