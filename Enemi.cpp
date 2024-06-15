#include "Enemi.h"

Enemi::Enemi()
{
}

Enemi::Enemi(int id, int hp, int baseDng, int BaseArrmor) :Character(id, hp, vitality, baseDng, BaseArrmor)
{
}

Enemi::~Enemi()
{
	delete[]attacksNames;
	delete[]attacksChance;
	delete[]attacksMulty;
}

void Enemi::setAttacks()
{
	attacksCount = DATABASE.GetAttackEnemiCount(this->idarchetype,this->id);
	attacksNames = new string[attacksCount];
	attacksChance = new double[attacksCount];
	attacksMulty = new double[attacksCount];
	for (int i = 0; i < attacksCount; i++) {
		attacksNames[i] = DATABASE.GetAttackEnemiNames(this->idarchetype, this->id,i);
		attacksChance[i] = DATABASE.GetAttackEnemiChance(this->idarchetype, this->id, i);
		attacksMulty[i] = DATABASE.GetAttackEnemiMulti(this->idarchetype, this->id, i);
	}
	name = DATABASE.GetNamesEnemi(this->idarchetype, this->id);
	cout << name;
}

int Enemi::atack(int i)
{
	srand(time(NULL));
	double n = (double)(rand() % 100 + 1) / 100;
	if (n <= attacksChance[i])
		return baseDng * attacksMulty[i];
	else
		return 0;
}

int Enemi::getArchetype()
{
	return idarchetype;
}

string Enemi::getAttackName(int i)
{
	return attacksNames[i];
}

int Enemi::getAttackCount()
{
	return attacksCount;
}

string Enemi::getName()
{
	return name;
}
