#pragma once
#include "Enemi.h"
class Undead :public Enemi
{
public:
	Undead(int level);
	~Undead();

	// Odziedziczono za pośrednictwem elementu Enemi



	// Odziedziczono za pośrednictwem elementu Enemi
	int maxHp() override;
	string toString() override;


	// Odziedziczono za pośrednictwem elementu Enemi

};

