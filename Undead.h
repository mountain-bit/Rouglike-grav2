#pragma once
#include "Enemi.h"
class Undead :public Enemi
{
public:
	Undead(int level);
	~Undead();

	// Odziedziczono za poœrednictwem elementu Enemi



	// Odziedziczono za poœrednictwem elementu Enemi
	int maxHp() override;
	string toString() override;


	// Odziedziczono za poœrednictwem elementu Enemi

};

