#pragma once
#include "PlayerClass.h"
#include "Player.h"
#include "Enemis.h"
#include "Map.h"
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "DataBase.h"
#include <sstream>

using namespace std;
class GraphicEngine 
{
	Player* P;
	Enemi* E;
	Map* M;
	int stan;
	int animationTime;
	bool log = true;
	//0-start
	//1-wybór postaci
	//2-podró¿ (animacja)
	//3-walka
	//31-atakuje gracz (bool czy trafia)
	//32-atakuje wróg -||-
	//4 - wróg umiera (bool)
	//41 - zyskane skarby
	//5-koniec podró¿y
	//6-ulepszanie
	// wróæ do punktu 2 
	//7-nie ¿yjesz

	//kolory
	enum kolory {
		cyjan = 11,
		zielony = 10,
		czerwonu = 12,
		niebieski = 9,
		szary = 8,
		bialy = 7,
		zolty = 14,
		czarny_czerony = 192,
		czerwony_czerwony = 76,
		zielony_ciemnozielony = 42,
		zolty_zoelony = 46,
		bialy_czerwony = 71
	};

	//--------------------------------------------------------------------------------
	//zewsja pierwsz - zostawiona ¿eby test dzia³¹³ 
	//--------------------------------------------------------------------------------

	void ShowGame_separator();
	void ShowGame_choice(string s);
	
	void ShowGame_Characters();
	
	void ShowGame_hello();
	void ShowGame_title();
	void ShowGame_travelEnd();
	void ShowGame_playerDie();
	void ShowGame_map(int x=0);
	void ShowGame_Fight(bool who,bool t,int i, int obr=0);
	void ShowGame_EnemiDie();
	void ShowGame_prize(int gold, int exp);
public:
	GraphicEngine();
	void SetPlayer(Player *p);
	void SetEnemi(Enemi* e);
	void SetMap(Map* m);
	int choise(string* tab, int n);



	
	//trzeba dodaæ wyœwietlanie statystyk
	void showGame(int s);//0,5,4,2,7  --- skoñczone (chyba)
	int showGame(int s,string *tab, int n);//1,3,6   ------skoñczone (chyba)
	
	void showGame(int s,bool who,bool t,int obr);//31,32  -----skoñczone(chyba)
	void showGame(int s, int exp,int gold);//41   ------ skoñczone (chyba)
	


	//--------------------------------------------------------------------------------
	//zewsja druga
	//--------------------------------------------------------------------------------

protected:
	int size = 60;


	void Show_map();
	void Show_heroAndEnemi();
	void Show_stats();
	void Show_separator();
public:
	void Show_start();
	int  Show_choice(string* t, int n, int stan, string komunikat, int inne=0,string inneS="");
	void Anamacja(int stan, int klatka =-1, string info = "");
	void Show_info(int stan, string info);

};
extern GraphicEngine GE;


