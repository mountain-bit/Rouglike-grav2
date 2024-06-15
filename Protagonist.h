#pragma once
#include "Character.h"
#include "DataBase.h";
class Protagonist :public Character
{
public:
	Protagonist();
	Protagonist(int id, int hp, int baseDng, int BaseArrmor);
	~Protagonist();

	int virtual atack(double chance, double dngMulti) = 0;
	int virtual maxHp() = 0;
	int virtual maxHp_level(int level);
	void virtual cure(int level);
};

