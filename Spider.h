#pragma once
#include "Enemi.h"
#include "DataBase.h"
class Spider :public Enemi
{
public:
	Spider(int level);
	~Spider();
	// Odziedziczono za pośrednictwem elementu Enemi
	int maxHp() override;
	string toString() override;
};

