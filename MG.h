#pragma once
#include "PlayerClass.h";
#include "Player.h";
#include "Map.h";
#include "GraphicEngine.h";
#include "DataBase.h";
class MG
{
	Player* P;
	Map* M;
	bool logs;
public:
	MG();
	void game();
	void game_test();
	void log(string s);
	~MG();
};

