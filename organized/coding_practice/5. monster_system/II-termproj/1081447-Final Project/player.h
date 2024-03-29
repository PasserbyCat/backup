#ifndef PLAYER_H
#define PLAYER_H

#include "pokemondatabase.h"

class Player
{
public:
	Player(std::string inname, PokemonDatabase<Pokemon> &thePokemonDatabase);
	std::string getName();
	Pokemon* getCurrentPokemon();
	void showAlivePokemons(int x = 1, int y = 1);
	void catchPokemon(char place);
	void fight(Player* another);

	void polynophism(Pokemon input, int where);

	int getWin() { return win; }
	int getLose() { return lose; }
private:
	bool fightTest(Player* npc);

	std::string name = "player";
	int number = 0;//運算包包裡有幾隻pokemon
	Pokemon* list[3];
	PokemonDatabase<Pokemon> &pokemonDatabase;//需要pokemon的圖片和資料

	int win = 0;//計算勝場
	int lose = 0;//計算敗場
};

#endif // !PLAYER_H