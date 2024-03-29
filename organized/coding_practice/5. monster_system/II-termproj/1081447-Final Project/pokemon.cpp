//寶可夢的數據

#include "pokemon.h"
#include <sstream>
#include <fstream>

//把所有跟寶可夢有關的數據存進去
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

	loadAllelopathy();//讀pokemon的克制關係
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
		return 0;//例外處理
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
		return "error";//例外處理
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
}

//讀取屬性間的相生相剋
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
	if (getHP() > 0) {
		if (getHP() + 3 > getMaxHP()) {
			setHP(getMaxHP());
			std::cout << getName() << "已將生命至回復到最大值，無法超過上限。HP = " << getHP() << std::endl;
		}
		else {
			setHP(getHP() + 3);
			std::cout << getName() << "生命值回復3點。HP = " << getHP() << std::endl;
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害，並且造成額外" << burn << "點燃燒傷害。\n";
		}
		else {
			another->setHP(another->getHP() - burn - 1);
			std::cout << getName() << ":可惡。此次的攻擊只造成1點傷害，並且造成額外" << burn << "點燃燒傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊，此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊，此次反擊受到的傷害為" << counter << "點。\n";
		}
		lastHP = getHP();
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
}

int CounterAttack::getCounterAttack() { return (lastHP - getHP()) / 4; }//上次的生命減去現在剩餘的生命就是受到的傷害

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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了。\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害，並吸取了" << bonus << "點生命值。";
			setHP(getHP() + 2);
			std::cout << "同時也回復了" << bonus << "點生命值。\n";
		}
		else {
			another->setHP(another->getHP() - 1 - bonus);
			std::cout << getName() << "已對敵人造成" << 1 << "點傷害，並吸取了" << bonus << "點生命值。";
			setHP(getHP() + bonus);
			std::cout << "同時也回復了" << bonus << "點生命值。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
	if (rand() % 5 == 0) {
		std::cout << "運氣不錯!你成功觸發了doubleAttack。";
		if (another->getAbility() == 6)
			temp = rand() % 5;
		if (temp != 0) {
			int hurt = getAttack() * getAllelopathy(getIntType(), another->getIntType()) - another->getDefence();
			int counter = another->getCounterAttack() * getAllelopathy(another->getIntType(), getIntType());
			if (hurt > 0) {
				another->setHP(another->getHP() - hurt);
				std::cout << getName() << "成功對敵人造成" << hurt << "點傷害。\n";
			}
			else {
				another->setHP(another->getHP() - 1);
				std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
			}
			if (counter > 0) {
				setHP(getHP() - counter);
				std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
			}
		}
		else
			std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
	if (available) {
		std::cout << getName() << "使用了中毒技能。\n";
		if (another->getAbility() != 4)
			another->setNegative(8);
		else
			std::cout << another->getName() << "免疫中毒。\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
	if (available) {
		std::cout << getName() << "使用了麻痺技能。\n";
		if (another->getAbility() != 4)
			another->setNegative(9);
		else
			std::cout << another->getName() << "免疫麻痺。\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
	if (available) {
		std::cout << getName() << ":看我降低你的防禦力。\n";
		if (another->getAbility() != 4)
			another->setNegative(11);
		else
			std::cout << another->getName() << "施法無效。\n";
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
			std::cout << getName() << "已對敵人造成" << hurt << "點傷害。\n";
		}
		else {
			another->setHP(another->getHP() - 1);
			std::cout << another->getName() << "哈哈!不痛不癢。你此次的攻擊造成1點傷害。\n";
		}
		if (counter > 0) {
			setHP(getHP() - counter);
			std::cout << getName() << "遭到反擊。此次反擊受到的傷害為" << counter << "點。\n";
		}
	}
	else
		std::cout << getName() << ":糟糕了!攻擊被迴避了!\n";
	if (available) {
		std::cout << getName() << ":看我降低你的攻擊力。\n";
		if (another->getAbility() != 4)
			another->setNegative(12);
		else
			std::cout << another->getName() << "施法無效。\n";
		available = false;
	}
}

void Pokemon::effectNegative()
{
	for (int i = 0; i < negative.size(); i++) {
		if (negative[i].effectability == 8) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3)
				std::cout << getName() << "中毒了!還剩下" << negative[i].availableTime - 1 << "回合\n";
			if (negative[i].availableTime == 2 || negative[i].availableTime == 1) {
				std::cout << getName() << "中毒了!本回合損失2點生命值，還剩下" << negative[i].availableTime - 1 << "回合\n" ;
				HP -= 2;
			}
		}
		if (negative[i].effectability == 9) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "麻痺了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				speed -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "麻痺了!還剩下" << negative[i].availableTime - 1 << "回合\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "麻痺了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				speed += 2;//把原本扣除的值，加回去
			}
		}
		if (negative[i].effectability == 11) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "被降防禦了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				defence -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "被降防禦了!還剩下" << negative[i].availableTime - 1 << "回合\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "被降防禦了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				defence += 2;//把原本扣除的值，加回去
			}
		}
		if (negative[i].effectability == 12) {
			negative[i].availableTime--;
			if (negative[i].availableTime == 3) {
				std::cout << getName() << "被降攻擊了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				attack -= 2;
			}
			if (negative[i].availableTime == 2) {
				std::cout << getName() << "被降攻擊了!還剩下" << negative[i].availableTime - 1 << "回合\n";
			}
			if (negative[i].availableTime == 1) {
				std::cout << getName() << "被降攻擊了!還剩下" << negative[i].availableTime - 1 << "回合\n";
				attack += 2;//把原本扣除的值，加回去
			}
		}
	}
}
//負面的附加效果
void Pokemon::setNegative(int ability)
{
	if (getAbility() != 4) {
		negative.push_back(Negative());
		negative[negative.size() - 1].effectability = ability;
	}
}
