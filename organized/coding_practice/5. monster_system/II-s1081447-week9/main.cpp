//week9-Polymorphism Practice
#include "monster.h"

using namespace std;

int main(int argc, const char* argv[])
{
	srand(time(NULL));

	Player player1("left");
	Player player2("right");

	int round = 0;
	while (true) {
		cout << "Round " << ++round << endl;

		bool who = rand() % 2;

		if (who) {
			player1.getCurrentMonster()->attack(player2.getCurrentMonster());
			if (player1.win(player2))
				break;
		}

		player2.getCurrentMonster()->attack(player1.getCurrentMonster());
		if (player1.win(player2))
			break;

		if (!who) {
			player1.getCurrentMonster()->attack(player2.getCurrentMonster());
			if (player1.win(player2))
				break;
		}

		player1.showAliveMonsters();
		player2.showAliveMonsters();
		system("pause");
		system("cls");//�N��ܵ����M��
		srand(time(NULL));//�ϥήɶ��ü�
	}
	system("pause");
}