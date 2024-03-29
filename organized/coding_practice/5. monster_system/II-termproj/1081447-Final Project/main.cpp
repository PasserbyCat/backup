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
				yzumap.met();//下次加載地圖重新印一張
				player.fight(&NPC[i]);//和NPC對決
				i++;
				if (player.getWin() > 6) {//總勝場數大於6時結算
					system("cls");
					for (int m = 0; m < 10; m++)
						std::cout << "通關成功!\n你在與" << player.getWin() + player.getLose() << "位NPC的對戰中獲得" << player.getWin() << "勝" << player.getLose() << "敗\n";
					return 0;
				}
				if (player.getLose() > 5) {//總勝場數大於5時，遊戲不可能通關，直接結算
					system("cls");
					for (int m = 0; m < 10; m++)
						std::cout << "通關失敗!\n你在與" << player.getWin() + player.getLose() << "位NPC的對戰中獲得" << player.getWin() << "勝" << player.getLose() << "敗\n";
					return 0;
				}
			}
			
			else if (yzumap.getplace() == ' ' || yzumap.getplace() == '~' || yzumap.getplace() == ';') {
				if (rand() % 10 == 0) {//10%的機率遇到pokemon
					yzumap.met();//下次加載地圖重新印一張
					player.catchPokemon(yzumap.getplace());//將目前的位置丟入捕捉的地方
				}
			}
		}
	}
}

//製作12個npc
std::vector <Player> builtNPC(PokemonDatabase<Pokemon>* pokemonDatabase)
{
	std::vector <Player> NPC;
	for (int i = 0; i < 12; i++) {
		NPC.push_back(Player("NPC" + std::to_string(i), *pokemonDatabase));//按照算續創造12個
		for (int j = 0; j < 3; j++) {
			int base = rand() % 32;//利用隨機亂數把pokemon塞進npc的包包裡
			NPC[i].polynophism(pokemonDatabase->getData(base), j);
		}
	}
	return NPC;
}