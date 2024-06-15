#pragma once
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Character
{
protected:
	int id;
	int hp;
	int vitality;
	int baseDng;
	int baseArrmor;

public:
	Character();
	Character(int id, int hp, int vitality, int baseDng, int baseArrmor);
	string virtual toString();
	~Character();
	double virtual getArrmor();
	int virtual getId();
	int virtual getBaseDng();
	int virtual getBaseArrmor();
	bool virtual isDead();
	int virtual getHp();
	int virtual takenDng(int dng);
	void virtual setHp(int newHp);
	void virtual plusVitality(int plus);
	void virtual plusBaseDng(int plus);
	void virtual plusBaseArrmor(int plus);
};

