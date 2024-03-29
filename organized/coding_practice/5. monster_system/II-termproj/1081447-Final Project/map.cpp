#include "map.h"
#include <fstream>
//real		y - 2, x - 1

char Map::getplace()
{
	return map[y - 2][x - 1];//���@��e����m
}

Map::Map()
{
	std::fstream makingmap("assets/yzumap.txt", std::ios::in);

	for (unsigned int i = 0; i < 31; i++)
		std::getline(makingmap, map[i]);//��map����Ū�i��
}

void Map::met() { first = true; }//�ΨӧP�_��U������������S���a��

bool Map::move()
{
	if (!first) {
		rlutil::setColor(15);
		gotoxy(1, 1);
		std::cout << "You should be able to move the '@' character with WASD keys." << std::endl;
		std::cout << "Turn count: " << cnt << std::endl;
	}

	if (first) {
		system("cls");
		first = false;
		rlutil::setColor(15);
		gotoxy(1, 1);
		std::cout << "You should be able to move the '@' character with WASD keys." << std::endl;
		std::cout << "Turn count: " << cnt << std::endl;
		for (unsigned int i = 1; i < 31; i++) {
			for (unsigned int j = 0; j < map[i].size(); j++) {
				rlutil::setColor(0);
				if (map[i][j] != ' ')
					rlutil::setBackgroundColor(15);
				if (map[i][j] == '#')
					rlutil::setBackgroundColor(14);
				else if (map[i][j] == '!')
					rlutil::setBackgroundColor(6);
				else if (map[i][j] == ';')
					rlutil::setBackgroundColor(2);
				else if (map[i][j] == '~')
					rlutil::setBackgroundColor(3);
				else if (map[i][j] == '*')
					rlutil::setBackgroundColor(12);
				//�N�a�ϬV��ÿ�X
				std::cout << map[i][j];
				rlutil::resetColor();
			}
			if (i != 30)
				std::cout << std::endl;
		}
		rlutil::setColor(15);
		rlutil::locate(x, y); std::cout << '@'; // Output player
	}

	while (true) {
		if (kbhit()) {
			int k = rlutil::getkey(); // Get character
			gotoxy(x, y);
			rlutil::setColor(0);
			if (map[y - 2][x - 1] == '#') {
				rlutil::setBackgroundColor(14);
				map[y - 2][x - 1] = 'X';//�C�@�ӹD�]�u��D�Ԥ@��
			}
			else if (map[y - 2][x - 1] == '!')
				rlutil::setBackgroundColor(6);
			else if (map[y - 2][x - 1] == ';')
				rlutil::setBackgroundColor(2);
			else if (map[y - 2][x - 1] == '~')
				rlutil::setBackgroundColor(3);
			else if (map[y - 2][x - 1] == '*')
				rlutil::setBackgroundColor(12);

			std::cout << map[y - 2][x - 1];
			rlutil::resetColor();
			//�N�ۤv�W������m�]�^�쥻���ϥ�
			if (moveavailable(k)) {
				cnt++;
				rlutil::setColor(15);
				gotoxy(x, y); std::cout << '@'; // Output player
				return true;
			}
			else {
				rlutil::setColor(15);
				gotoxy(x, y); std::cout << '@'; // Output player
				return false;
			}
			//��ۤv�s����m�g�i�a��
			std::cout.flush();
		}
	}
}

//�P�_�q��L�o�쪺���ʬO�_�X�k
bool Map::moveavailable(char k)
{
	if (k == 'a') {
		--x;
		if (map[y - 2][x - 1] == '!' || map[y - 2][x - 1] == '1' || map[y - 2][x - 1] == '2' || map[y - 2][x - 1] == '3' || map[y - 2][x - 1] == '*'
			|| map[y - 2][x - 1] == '5' || map[y - 2][x - 1] == '6' || map[y - 2][x - 1] == '7' || map[y - 2][x - 1] == '8' || map[y - 2][x - 1] == '9'
			|| map[y - 2][x - 1] == 'A' || map[y - 2][x - 1] == 'B' || map[y - 2][x - 1] == 'C' || map[y - 2][x - 1] == 'D' || map[y - 2][x - 1] == 'X') {
			++x;
			return false;
		}
		return true;
	}
	else if (k == 'd') {
		++x;
		if (map[y - 2][x - 1] == '!' || map[y - 2][x - 1] == '1' || map[y - 2][x - 1] == '2' || map[y - 2][x - 1] == '3' || map[y - 2][x - 1] == '*'
			|| map[y - 2][x - 1] == '5' || map[y - 2][x - 1] == '6' || map[y - 2][x - 1] == '7' || map[y - 2][x - 1] == '8' || map[y - 2][x - 1] == '9'
			|| map[y - 2][x - 1] == 'A' || map[y - 2][x - 1] == 'B' || map[y - 2][x - 1] == 'C' || map[y - 2][x - 1] == 'D' || map[y - 2][x - 1] == 'X') {
			--x;
			return false;
		}
		return true;
	}
	else if (k == 'w') {
		--y;
		if (map[y - 2][x - 1] == '!' || map[y - 2][x - 1] == '1' || map[y - 2][x - 1] == '2' || map[y - 2][x - 1] == '3' || map[y - 2][x - 1] == '*'
			|| map[y - 2][x - 1] == '5' || map[y - 2][x - 1] == '6' || map[y - 2][x - 1] == '7' || map[y - 2][x - 1] == '8' || map[y - 2][x - 1] == '9'
			|| map[y - 2][x - 1] == 'A' || map[y - 2][x - 1] == 'B' || map[y - 2][x - 1] == 'C' || map[y - 2][x - 1] == 'D' || map[y - 2][x - 1] == 'X') {
			++y;
			return false;
		}
		return true;
	}
	else if (k == 's') {
		++y;
		if (map[y - 2][x - 1] == '!' || map[y - 2][x - 1] == '1' || map[y - 2][x - 1] == '2' || map[y - 2][x - 1] == '3' || map[y - 2][x - 1] == '*'
			|| map[y - 2][x - 1] == '5' || map[y - 2][x - 1] == '6' || map[y - 2][x - 1] == '7' || map[y - 2][x - 1] == '8' || map[y - 2][x - 1] == '9'
			|| map[y - 2][x - 1] == 'A' || map[y - 2][x - 1] == 'B' || map[y - 2][x - 1] == 'C' || map[y - 2][x - 1] == 'D' || map[y - 2][x - 1] == 'X') {
			--y;
			return false;
		}
		return true;
	}
	else
		return false;
}