#pragma once
#include "Enemi.h"
class Undead :public Enemi
{
public:
	Undead(int level);
	~Undead();

	// Odziedziczono za po�rednictwem elementu Enemi



	// Odziedziczono za po�rednictwem elementu Enemi
	int maxHp() override;
	string toString() override;


	// Odziedziczono za po�rednictwem elementu Enemi

};

