#include "player.h"

Player::Player(std::string inname, PokemonDatabase<Pokemon>& thePokemonDatabase)
	: pokemonDatabase(thePokemonDatabase)
{
	name = inname;
}

Pokemon* Player::getCurrentPokemon() {
	for (int i = 0; i < number; i++)
		if (list[i]->getHP() > 0)
			return list[i];

	return nullptr;
}

void Player::showAlivePokemons(int x, int y) {
	gotoxy(x, y); std::cout << getName();
	for (int i = 0; i < number; i++) {
		gotoxy(x, y + i + 1);
		if (list[i] == nullptr)//���ШS�����D����pokemon�ɡA�N��]�]�w�g�ŤF
			break;
		std::cout << "NO. " << i + 1 << "  " << list[i]->getName() << "( " << list[i]->getHP() << " / " << list[i]->getMaxHP() << " )";
	}
}

std::string Player::getName() { return name; }

void Player::catchPokemon(char place)
{
	int base, run = 0, i = 0;
	//�N�Ŧa�B��a�B������O�y�z
	if (place == ' ') {
		int temp = rand() % 160;
		for (; i < 32; i++) {
			run += 5;
			if (run > temp) {
				base = i;
				break;
			}
		}
	}
	else if (place == '~') {
		int temp = rand() % 166;//���t�X�{���v�W�[40%
		for (; i < 32; i++) {
			if (i > 5 && i < 9)
				run += 7;
			else
				run += 5;
			if (run > temp) {
				base = i;
				break;
			}
		}
	}
	else if (place == ';') {
		int temp = rand() % 166;//���X�u���v�W�[40%
		for (; i < 32; i++) {
			if (i < 3)
				run += 7;
			else
				run += 5;
			if (run > temp) {
				base = i;
				break;
			}
		}
	}

	system("cls");
	pokemonDatabase.outPicture(base);
	gotoxy(60, 9); std::cout << "Name: " << pokemonDatabase.getData(base).getName();
	gotoxy(60, 10); std::cout << "Type: " << pokemonDatabase.getData(base).getCharType();
	gotoxy(60, 11); std::cout << "HP: " << pokemonDatabase.getData(base).getHP();
	gotoxy(60, 12); std::cout << "Attack: " << pokemonDatabase.getData(base).getAttack();
	gotoxy(60, 13); std::cout << "Defence: " << pokemonDatabase.getData(base).getDefence();	
	gotoxy(60, 14); std::cout << "Speed: " << pokemonDatabase.getData(base).getSpeed();
	showAlivePokemons(1, 25);

	std::cout << "\nCatch or Not? (C/N)\n";
	char k;
	while (1) {
		k = getch();
		if (k == 'C' || k == 'c' || k == 'N' || k == 'n')
			break;
	}

	if (k == 'C' || k == 'c') {
		if (rand() % 2 == 1) {
			if (number == 3) {//�I�]�������p
				std::cout << "�Ч�@��Pokemon�q�I�]�̥�X(use number to choose)" << std::endl;
				int where;
				while (1) {
					std::cin >> where;
					if (where > 0 && where < 4)
						break;
				}
				number--;
				polynophism(pokemonDatabase.getData(base), where - 1);
			}
			else //�I�]�٨S�������p
				polynophism(pokemonDatabase.getData(base), number);
			std::cout << "Congratulation! \n";
		}
		else //��������
			std::cout << "Sorry. You can't catch it. \n";
		showAlivePokemons(1, 30);
	}
	system("pause>>nul");
}

bool Player::fightTest(Player* npc)
{
	if (!getCurrentPokemon()) {
		lose++;
		std::cout << "\n\n�u�O�O�H�ˤߡA�z��F!" << std::endl;
		system("pause>>nul");
		for (int i = 0; i < 3; i++) {
			list[i]->setHP(list[i]->getMaxHP());//��԰������A��ͩR�Ȧ^��
			if (list[i]->getAbility() == 3 || list[i]->getAbility() == 8 || list[i]->getAbility() == 9 || list[i]->getAbility() == 11 || list[i]->getAbility() == 12 )
				list[i]->reset();//�N�ޯ�^�_�A��԰�����������
		}
		return true;
	}
	else if (!npc->getCurrentPokemon()) {
		win++;
		std::cout << "\n\n�O�H���Ī������A�zĹ�F!" << std::endl;
		system("pause>>nul");
		for (int i = 0; i < 3; i++) {
			list[i]->setHP(list[i]->getMaxHP());//��԰������A��ͩR�Ȧ^��
			if (list[i]->getAbility() == 3 || list[i]->getAbility() == 8 || list[i]->getAbility() == 9 || list[i]->getAbility() == 11 || list[i]->getAbility() == 12)
				list[i]->reset();//�N�ޯ�^�_�A��԰�����������
		}
		return true;
	}
	return false;
}

void Player::fight(Player* npc)
{
	system("cls");
	//rlutil::msleep(500);
	if (fightTest(npc))
		return;
	while(1) {
		gotoxy(1, 35);
		//���speed�ӨM�w�֥���֫��
		if (getCurrentPokemon()->getSpeed() >= npc->getCurrentPokemon()->getSpeed()) {
				getCurrentPokemon()->Attack(npc->getCurrentPokemon());
			if (fightTest(npc))
				return;
			npc->getCurrentPokemon()->Attack(getCurrentPokemon());
		}
		else {
			npc->getCurrentPokemon()->Attack(getCurrentPokemon());
			if (fightTest(npc))
				return;
			getCurrentPokemon()->Attack(npc->getCurrentPokemon());
		}
		if (fightTest(npc))
			return;
		//������誺�t�����A
		getCurrentPokemon()->effectNegative();
		npc->getCurrentPokemon()->effectNegative();
		if (fightTest(npc))
			return;
		//��������e���ݩ�
		pokemonDatabase.outPicture(getCurrentPokemon()->getNumber() - 1);
		gotoxy(1, 25); std::cout << "Name: " << getCurrentPokemon()->getName();
		gotoxy(1, 26); std::cout << "Type: " << getCurrentPokemon()->getCharType();
		gotoxy(1, 27); std::cout << "HP: " << getCurrentPokemon()->getHP();
		gotoxy(1, 28); std::cout << "Attack: " << getCurrentPokemon()->getAttack();
		gotoxy(1, 29); std::cout << "Defence: " << getCurrentPokemon()->getDefence();
		gotoxy(1, 30); std::cout << "Speed: " << getCurrentPokemon()->getSpeed();
		showAlivePokemons(1, 31);

		pokemonDatabase.outPicture(npc->getCurrentPokemon()->getNumber() - 1, 51, 1);
		gotoxy(51, 25); std::cout << "Name: " << npc->getCurrentPokemon()->getName();
		gotoxy(51, 26); std::cout << "Type: " << npc->getCurrentPokemon()->getCharType();
		gotoxy(51, 27); std::cout << "HP: " << npc->getCurrentPokemon()->getHP();
		gotoxy(51, 28); std::cout << "Attack: " << npc->getCurrentPokemon()->getAttack();
		gotoxy(51, 29); std::cout << "Defence: " << npc->getCurrentPokemon()->getDefence();
		gotoxy(51, 30); std::cout << "Speed: " << npc->getCurrentPokemon()->getSpeed();
		npc->showAlivePokemons(51, 31);
		system("pause>>nul");
		system("cls");
	}
}

void Player::polynophism(Pokemon input, int where)
{
	//�N�U�د�O���d���s���h��
	if (input.getAbility() == 0) {
		list[where] = new Pokemon(input);
	}
	if (input.getAbility() == 1) {
		list[where] = new Heal(input);
	}
	if (input.getAbility() == 2) {
		list[where] = new Burning(input);
	}
	if (input.getAbility() == 3) {
		list[where] = new CounterAttack(input);
	}
	if (input.getAbility() == 4) {
		list[where] = new Immunology(input);
	}
	if (input.getAbility() == 5) {
		list[where] = new LeechLife(input);
	}
	if (input.getAbility() == 6) {
		list[where] = new Avoid(input);
	}
	if (input.getAbility() == 7) {
		list[where] = new DoubleAttack(input);
	}
	if (input.getAbility() == 8) {
		list[where] = new Poison(input);
	}
	if (input.getAbility() == 9) {
		list[where] = new LowerSpeed(input);
	}
	if (input.getAbility() == 10) {
		list[where] = new RockSkin(input);
	}
	if (input.getAbility() == 11) {
		list[where] = new LowerDefence(input);
	}
	if (input.getAbility() == 12) {
		list[where] = new LowerAttack(input);
	}
	number++;
}