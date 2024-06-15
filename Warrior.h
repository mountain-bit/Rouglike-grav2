#pragma once
#include "Protagonist.h"
#include<random>
#include<time.h>
#include "DataBase.h";
class Warrior : public Protagonist
{
private:
	double shield;
public:

	Warrior();
	~Warrior();
	// Odziedziczono za poœrednictwem elementu Protagonist
	int atack(double chance, double dngMulti) override;

	int takenDng(int dng) override;

	int maxHp() override;
	string virtual toString();
	void cure(int level);

	// Odziedziczono za poœrednictwem elementu Protagonist


};

