#include "Map.h"

Map::Map()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int r = rand() % DATABASE.GetNamesLocationCount();
		nameLocation[i] = DATABASE.GetNameLocation(r);
	}
	LocationCount = 0;

}

Map::~Map()
{
}

string Map::GetNameLocation(int i) {
	if (i >= 0 && i<10)
		return nameLocation[i];
	return " ";
}

void Map::SetEnemiCount()
{
	srand(time(NULL));
	enemiCount = rand() % 5 + 2;
}

Enemi* Map::GiveEnemi()
{
	enemiCount--;
	srand(time(NULL));
	int r = (int)(rand() % DATABASE.GetNamesArchetypeEnemCount());
	int l  = (int)(rand() % DATABASE.GetNamesEnemiCount(r));
	Enemi* em;
	switch (r)
	{
	case 0:

		em = new Undead(l);
		break;
	case 1:
		em = new Spider(l);
		break;

	default:
		em = new Undead(l);
		break;
	}
	
	return em;
}

void Map::nextLocation()
{
	LocationCount++;
	if (LocationCount >= 10) {
		enemiCount = 0;

	}
	else {
		SetEnemiCount();
	}
}

int Map::GetLocationCount()
{
	return LocationCount;
}

int Map::GetEnemiCount()
{
	return enemiCount;
}

string Map::toString()
{
	string n = "";
	for (int i = 0; i < 10; i++) {
		if (LocationCount == i) { n += "!!!"; n += to_string(this->GetEnemiCount()); };
		n += nameLocation[i] + "\t";
	}
	n += "\n";
	return n;
}
