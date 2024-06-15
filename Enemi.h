#pragma once
#include "Character.h"
#include "DataBase.h"
class Enemi :public Character
{
protected:
	int idarchetype;
	string* attacksNames;
	double* attacksChance;
	double* attacksMulty;
	int attacksCount;
	string name;
public:
	Enemi();
	Enemi(int id, int hp, int baseDng, int BaseArrmor);
	~Enemi();
	void setAttacks();
	int virtual atack(int i);
	
	int virtual maxHp()= 0;
	int virtual getArchetype();
	string virtual getAttackName(int i);
	int virtual getAttackCount();
	string getName();
};

