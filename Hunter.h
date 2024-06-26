#pragma once
#include "Protagonist.h"

class Hunter :public Protagonist
{
private:
	double dodge;
public:
	Hunter();
	~Hunter();

	// Odziedziczono za pośrednictwem elementu Protagonist
	int atack(double chance, double dngMulti) override;
	int takenDng(int dng) override;
	int maxHp() override;
	string virtual toString();
	void cure(int level);

	// Odziedziczono za pośrednictwem elementu Protagonist
};

