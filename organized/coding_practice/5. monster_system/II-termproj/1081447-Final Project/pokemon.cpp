//�_�i�ڪ��ƾ�

#include "pokemon.h"
#include <sstream>
#include <fstream>

//��Ҧ����_�i�ڦ������ƾڦs�i�h
Pokemon::Pokemon(int innumber, std::string inname, std::string intype,
	int inHP, int inmaxHP, int inattack, int indefence, int inspeed, int inability)
	: number(innumber), name(inname), HP(inHP), maxHP(inmaxHP),
	attack(inattack), defence(indefence), speed(inspeed), ability(inability)
{
	if (intype == "Normal")
		type = 0;
	if (intype == "Fire")
		type = 1;
	if (intype == "Water")
		type = 2;
	if (intype == "Electric")
		type = 3;
	if (intype == "Grass")
		type = 4;
	if (intype == "Poison")
		type = 7;
	if (intype == "Ground")
		type = 8;
	if (intype == "Flying")
		type = 9;
	if (intype == "Bug")
		type = 11;
	else type = 0;

	loadAllelopathy();//Ūpokemon���J�����Y
}

void Pokemon::setHP(int end) 
{ 
	try {
		if (end > maxHP)
			throw maxHP;
	}
	catch (const int newend) {
		std::cout << "Your HP cannot over than your naxHP.\n";
		HP = newend;
		return;
	}
	HP = end;
	return;
}//exception

int Pokemon::getNumber() const { return number; }
std::string Pokemon::getName() const { return name; }
int Pokemon::getHP() const
{
	if (HP > 0)
		return HP;
	else
		return 0;//�ҥ~�B�z
}
int Pokemon::getMaxHP() const { return maxHP; }
int Pokemon::getAttack() const { return attack; }
int Pokemon::getSpeed() const { return speed; }
int Pokemon::getAbility() const { return ability; }
int Pokemon::getCounterAttack() const { return 0; }
std::string Pokemon::getCharType() const {
	if (type == 0)
		return "Normal";
	if (type == 1)
		return "Fire";
	if (type == 2)
		return "Water";
	if (type == 3)
		return "Electric";
	if (type == 4)
		return "Grass";
	if (type == 7)
		return "Poison";
	if (type == 8)
		return "Ground";
	if (type == 9)
		return "Flying";
	if (type == 11)
		return "Bug";
	else
		return "error";//�ҥ~�B�z
}
int Pokemon::getIntType() const { return type; }
int Pokemon::getDefence() const { return defence; }

void Pokemon::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
}

//Ū���ݩʶ����ۥͬ۫g
void Pokemon::loadAllelopathy()
{
	std::stringstream use;
	std::string value;
	std::fstream inFile("assets/type.csv", std::ios::in);
	for (int i = 0; i < 18; i++)
		for (int j = 0; j < 18; j++) {
			getline(inFile, value, ',');
			use.str("");
			use.clear();
			use << value;
			use >> allelopathy[i][j];
		}
}

float Pokemon::getAllelopathy(int attackType, int defenceType) { return allelopathy[attackType][defenceType]; }

void Heal::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
	if (getHP() > 0) {
		if (getHP() + 3 > getMaxHP()) {
			setHP(getMaxHP());
			std::cout << getName() << "�w�N�ͩR�ܦ^�_��̤j�ȡA�L�k�W�L�W���CHP = " << getHP() << std::endl;
		}
		else {
			setHP(getHP() + 3);
			std::cout << getName() << "�ͩR�Ȧ^�_3�I�CHP = " << getHP() << std::endl;
		}
	}
}

void Burning::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int burn = rand() % 3 + 1;
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt - burn);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�A�åB�y���B�~" << burn << "�I�U�N�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - burn - 1);
			std::cout << getName() << ":�i�c�C�����������u�y��1�I�ˮ`�A�åB�y���B�~" << burn << "�I�U�N�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������A�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
}

void CounterAttack::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������A�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
		lastHP = getHP();
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
}

int CounterAttack::getCounterAttack() { return (lastHP - getHP()) / 4; }//�W�����ͩR��h�{�b�Ѿl���ͩR�N�O���쪺�ˮ`

void Immunology::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF�C\n";
}


void LeechLife::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		unsigned int bonus = rand() % 2 + 2;
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt - bonus);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�A�çl���F" << bonus << "�I�ͩR�ȡC";
			setHP(getHP() + 2);
			std::cout << "�P�ɤ]�^�_�F" << bonus << "�I�ͩR�ȡC\n";
		}
		else {
			another->setHP(another->getHP() - 1 - bonus);
			std::cout << getName() << "�w��ĤH�y��" << 1 << "�I�ˮ`�A�çl���F" << bonus << "�I�ͩR�ȡC";
			setHP(getHP() + bonus);
			std::cout << "�P�ɤ]�^�_�F" << bonus << "�I�ͩR�ȡC\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
}

void Avoid::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());

		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
}

void DoubleAttack::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
	if (rand() % 5 == 0) {
		std::cout << "�B�𤣿�!�A���\Ĳ�o�FdoubleAttack�C";
		if (another->getAbility() == 6)
			temp = rand() % 5;
		if (temp != 0) {
			int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
			int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
			if (hurt > 0) {
				another->setHP(another->getHP() - hurt);
				std::cout << getName() << "���\��ĤH�y��" << hurt << "�I�ˮ`�C\n";
			}
			else {
				another->setHP(another->getHP() - 1);
				std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
			}
			if (counter > 0) {
				setHP(getHP() - counter);
				std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
			}
		}
		else
			std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
	}
}

void Poison::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
	if (available) {
		std::cout << getName() << "�ϥΤF���r�ޯ�C\n";
		if (another->getAbility() != 4)
			another->setNegative(8);
		else
			std::cout << another->getName() << "�K�̤��r�C\n";
		available = false;
	}
}

void LowerSpeed::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
	if (available) {
		std::cout << getName() << "�ϥΤF�·��ޯ�C\n";
		if (another->getAbility() != 4)
			another->setNegative(9);
		else
			std::cout << another->getName() << "�K�̳·��C\n";
		available = false;
	}
}

void RockSkin::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF\n";
}

void LowerDefence::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
	if (available) {
		std::cout << getName() << ":�ݧڭ��C�A�����m�O�C\n";
		if (another->getAbility() != 4)
			another->setNegative(11);
		else
			std::cout << another->getName() << "�I�k�L�ġC\n";
		available = false;
	}
}

void LowerAttack::Attack(Pokemon* another)
{
	int temp = 6;
	if (another->getAbility() == 6)
		temp = rand() % 5;
	if (temp != 0) {
		int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
		int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
		if (hurt > 0) {
			another->setHP(another->getHP() - hurt);
			std::cout << getName() << "�w��ĤH�y��" << hurt << "�I�ˮ`�C\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "����!���h���o�C�A�����������y��1�I�ˮ`�C\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "�D������C�����������쪺�ˮ`��" << counter << "�I�C\n";
		}
	}
	else
		std::cout << getName() << ":�V�|�F!�����Q�j�פF!\n";
	if (available) {
		std::cout << getName() << ":�ݧڭ��C�A�������O�C\n";
		if (another->getAbility() != 4)
			another->setNegative(12);
		else
			std::cout << another->getName() << "�I�k�L�ġC\n";
		available = false;
	}
}

void Pokemon::effectNegative()
{
	for (int i = 0; i < negative.size(); i++) {
		if (negative[i].effectability == 8) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3)
				std::cout << getName() << "���r�F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
			if (negative[i].availableTime == 2 || negative[i].availableTime == 1) {
				std::cout << getName() << "���r�F!���^�X�l��2�I�ͩR�ȡA�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n" ;
				HP -= 2;
			}
		}
		if (negative[i].effectability == 9) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "�·��F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				speed -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "�·��F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "�·��F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				speed += 2;//��쥻�������ȡA�[�^�h
			}
		}
		if (negative[i].effectability == 11) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "�Q�����m�F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				defence -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "�Q�����m�F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "�Q�����m�F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				defence += 2;//��쥻�������ȡA�[�^�h
			}
		}
		if (negative[i].effectability == 12) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "�Q�������F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				attack -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "�Q�������F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "�Q�������F!�ٳѤU" << negative[i].availableTime - 1 << "�^�X\n";
				attack += 2;//��쥻�������ȡA�[�^�h
			}
		}
	}
}
//�t�������[�ĪG
void Pokemon::setNegative(int ability)
{
	if (getAbility() != 4) {
		negative.push_back(Negative());
		negative[negative.size() - 1].effectability = ability;
	}
}
