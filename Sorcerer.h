#pragma once
#include "Protagonist.h"
#include "DataBase.h";
class Sorcerer :public Protagonist
{
private:
	int special;
public:
	Sorcerer();
	~Sorcerer();
	// Odziedziczono za poœrednictwem elementu Protagonist
	virtual int atack(double chance, double dngMulti) override;
	virtual int maxHp() override;
	string virtual toString();
	void cure(int level);

	// Odziedziczono za poœrednictwem elementu Protagonist

	// Odziedziczono za poœrednictwem elementu Protagonist
};

