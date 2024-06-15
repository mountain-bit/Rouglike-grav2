#pragma once
#include "PlayerClass.h";
class Player
{
	//ostalanie wszystkiego bêdzie obs³ugiwa³ MG mnije wiêcej tak ¿e gracz przychodzi do sto³y i to MG ogarnia wszystko
	Protagonist* protagonist;
	int gold;
	int exp;
	int level;
	int toNextLevel;
	string name;

	string *attacksNames;
	double* attacksChance;
	double* attacksMulty;
	int attacksCount;

	int PowerUpVitality;
	int PowerUpDng;
	int PowerUpArrmor;

public:
	Player()
	{
		gold = 0;
		exp = 0;
		level = 0;
		toNextLevel = 3000;
		protagonist = new Warrior();
		PowerUpVitality = DATABASE.GetPowerUpVitality(
		);
		PowerUpDng = DATABASE.GetPowerUpDng();
		PowerUpArrmor = DATABASE.GetPowerUpArrmor();
	}
	~Player();

	Protagonist* getProtagonist();
	void SetProtagonist(Protagonist* p);

	int GetGold() const { return gold; }
	int GetExp() const { return exp; }
	int GetLevel() const { return level; }
	int GetToNextLevel() const { return toNextLevel; }

	void SetGold(int newGold);
	void SetGoldPlus(int plus);
	void SetExp(int newExp);
	void SetExpPlus(int plus);
	void SetLevel(int newLevel);
	void levleUp();
	void SetToNextLevel(int newToNextLevel);
	void SetToNextLevel();
	bool LevelUpAlready();
	string toString();
	int getAttackCount();
	string* getattacksNames();
	double* getattacksChance();
	double* getattacksMulty();

	string getattacksNames(int i);
	double getattacksChance(int i);
	double getattacksMulty(int i);

	int getPowerUpVitality();
	int getPowerUpDng();
	int getPowerUpArrmor();

	void plusArrmor();
	void plusVitality();
	void plusDmg();

	string GetName();
};

