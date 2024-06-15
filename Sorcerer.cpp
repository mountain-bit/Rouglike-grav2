#include "Sorcerer.h"

Sorcerer::~Sorcerer()
{
}

Sorcerer::Sorcerer() {
    id = 2;
    vitality = DATABASE.GetBaseVitality(id);
    hp = maxHp();
    baseDng = DATABASE.GetBaseDng(id);
    baseArrmor = DATABASE.GetBaseArrmor(id);
    special = 0;
}
int Sorcerer::atack(double chance, double dngMulti)
{
    special++;
    if (special < 4) {
        srand(time(NULL));
        double i = (double)(rand() % 100 + 1) / 100;
        if (i <= chance)
            return baseDng * dngMulti;
        else
            return 0;
        return 0;
    }
    else {
        special = 0;
        return baseDng * dngMulti * 5;
    }
}

int Sorcerer::maxHp()
{
    return vitality*2;
}

string Sorcerer::toString()
{
    return "Czarownik:\nid: " + to_string(id) + "\n hp: " + to_string(hp) + "\nvitality: " + to_string(vitality) + "\nbaseDng: " + to_string(baseDng) + "\nbaseArrmor: " + to_string(baseArrmor);

}

void Sorcerer::cure(int level)
{
    
        hp = hp + maxHp_level(level) * 0.8;
        if (hp > maxHp_level(level))hp = maxHp_level(level);
    
}

