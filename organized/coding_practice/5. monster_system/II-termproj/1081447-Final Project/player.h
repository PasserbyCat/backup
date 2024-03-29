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
	int number = 0;//�B��]�]�̦��X��pokemon
	Pokemon* list[3];
	PokemonDatabase<Pokemon> &pokemonDatabase;//�ݭnpokemon���Ϥ��M���

	int win = 0;//�p��ӳ�
	int lose = 0;//�p��ѳ�
};

#endif // !PLAYER_H