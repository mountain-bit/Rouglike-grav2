#include "Player.h"

Player::~Player()
{
	delete protagonist;
	delete[]attacksNames;
	delete[]attacksChance ;
	delete[]attacksMulty;
}

Protagonist* Player::getProtagonist()
{
	return protagonist;
}

void Player::SetProtagonist(Protagonist* p)
{
	if (protagonist != nullptr)
		delete protagonist;
	protagonist = p;
	
	attacksCount = DATABASE.GetAttackCount(p->getId());
	attacksNames = new string[attacksCount];
	attacksChance = new double[attacksCount];
	attacksMulty = new double[attacksCount];
	for (int i = 0; i < attacksCount; i++) {
		
		attacksChance[i] = DATABASE.GetAttackChance(p->getId(), i);
		attacksMulty[i] = DATABASE.GetAttackMulti(p->getId(), i);

		attacksNames[i] = DATABASE.GetAttackNames(p->getId(), i) +"    "+to_string((int)(attacksChance[i] * 100)) + "%";
	}


	protagonist->plusVitality(PowerUpVitality);
	protagonist->plusBaseDng(PowerUpDng);
	protagonist->plusBaseArrmor(PowerUpArrmor);
	name = DATABASE.GetCharacterName(p->getId());
}

void Player::SetGold(int newGold) { gold = newGold; }

void Player::SetGoldPlus(int plus)
{
	gold += plus;
}

void Player::SetExp(int newExp) { exp = newExp; }

void Player::SetExpPlus(int plus)
{
	exp += plus;
}

void Player::SetLevel(int newLevel) { level = newLevel; }

void Player::levleUp()
{
	level++;
	exp -= toNextLevel;
	SetToNextLevel();
	getProtagonist()->cure(level);

}

inline void Player::SetToNextLevel(int newToNextLevel) { toNextLevel = newToNextLevel; }

void Player::SetToNextLevel()
{
	toNextLevel = toNextLevel * log10(15+level);
}

bool Player::LevelUpAlready()
{
	if (exp >= toNextLevel)
		return true;
	else
		return false;
}

string Player::toString()
{
	return "Gracz: gold = "+to_string(gold)+" exp = "+to_string(exp)+" level = "+to_string(level)+" nextLevel = "+to_string(toNextLevel)+" protagonista = "+protagonist->toString()+"\n";
}

int Player::getAttackCount()
{
	return attacksCount;
}

string* Player::getattacksNames()
{
	return attacksNames;
}

double* Player::getattacksChance()
{
	return attacksChance;
}

double* Player::getattacksMulty()
{
	return attacksMulty;
}

string Player::getattacksNames(int i)
{
	return attacksNames[i];
}

double Player::getattacksChance(int i)
{
	return attacksChance[i];
}

double Player::getattacksMulty(int i)
{
	return attacksMulty[i];
}

int Player::getPowerUpVitality()
{
	return PowerUpVitality;
}

int Player::getPowerUpDng()
{
	return PowerUpDng;
}

int Player::getPowerUpArrmor()
{
	return PowerUpArrmor;
}

void Player::plusArrmor()
{
	PowerUpArrmor += 10;
	protagonist->plusBaseArrmor(10);
}

void Player::plusVitality()
{
	PowerUpVitality += 5;
	protagonist->plusVitality(5);
}

void Player::plusDmg()
{
	PowerUpDng += 1;
	protagonist->plusBaseDng(1);
}

string Player::GetName()
{
	return name;
}
