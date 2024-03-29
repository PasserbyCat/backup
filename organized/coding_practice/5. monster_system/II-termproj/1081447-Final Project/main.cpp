#include "rlutil\rlutil.h"
#include "map.h"
#include "player.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>

std::vector <Player> builtNPC(PokemonDatabase<Pokemon>* thePokemonDatabase);

int main()
{
	Map yzumap;
	PokemonDatabase<Pokemon> thePokemonDatabase;
	Player player("player", thePokemonDatabase);
	std::vector <Player> NPC;
	NPC = builtNPC(&thePokemonDatabase);
	srand(time(NULL));

	int i = 0;

	while (true) {
		if (yzumap.move()) {
			if (yzumap.getplace() == '#') {
				yzumap.met();//�U���[���a�ϭ��s�L�@�i
				player.fight(&NPC[i]);//�MNPC��M
				i++;
				if (player.getWin() > 6) {//�`�ӳ��Ƥj��6�ɵ���
					system("cls");
					for (int m = 0; m < 10; m++)
						std::cout << "�q�����\!\n�A�b�P" << player.getWin() + player.getLose() << "��NPC����Ԥ���o" << player.getWin() << "��" << player.getLose() << "��\n";
					return 0;
				}
				if (player.getLose() > 5) {//�`�ӳ��Ƥj��5�ɡA�C�����i��q���A��������
					system("cls");
					for (int m = 0; m < 10; m++)
						std::cout << "�q������!\n�A�b�P" << player.getWin() + player.getLose() << "��NPC����Ԥ���o" << player.getWin() << "��" << player.getLose() << "��\n";
					return 0;
				}
			}
			
			else if (yzumap.getplace() == ' ' || yzumap.getplace() == '~' || yzumap.getplace() == ';') {
				if (rand() % 10 == 0) {//10%�����v�J��pokemon
					yzumap.met();//�U���[���a�ϭ��s�L�@�i
					player.catchPokemon(yzumap.getplace());//�N�ثe����m��J�������a��
				}
			}
		}
	}
}

//�s�@12��npc
std::vector <Player> builtNPC(PokemonDatabase<Pokemon>* pokemonDatabase)
{
	std::vector <Player> NPC;
	for (int i = 0; i < 12; i++) {
		NPC.push_back(Player("NPC" + std::to_string(i), *pokemonDatabase));//���Ӻ���гy12��
		for (int j = 0; j < 3; j++) {
			int base = rand() % 32;//�Q���H���üƧ�pokemon��inpc���]�]��
			NPC[i].polynophism(pokemonDatabase->getData(base), j);
		}
	}
	return NPC;
}