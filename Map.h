#pragma once
#include<iostream>;
#include<random>;
#include<time.h>;
#include "Enemis.h";
using namespace std;
class Map
{
	string nameLocation[10];
	int LocationCount;
	int enemiCount;
public:

	Map();
	~Map();

	string GetNameLocation(int i);
	void SetEnemiCount();
	Enemi* GiveEnemi();
	void nextLocation();
	int GetLocationCount();
	int GetEnemiCount();
	string toString();
};

