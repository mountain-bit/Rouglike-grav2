#include "Warrior.h"

Warrior::Warrior()
{
    id = 0;
    vitality = DATABASE.GetBaseVitality(id);
    hp = maxHp();
    baseDng = DATABASE.GetBaseDng(id);
    baseArrmor = DATABASE.GetBaseArrmor(id);
    shield = DATABASE.GetSpecialAbility(id);
}

Warrior::~Warrior()
{
}

int Warrior::atack(double chance, double dngMulti)
{
    srand(time(NULL));
    double i =(double) (rand() % 100 + 1) / 100;
    if (i <= chance)
        return baseDng * dngMulti;
    else
        return 0;
}

int Warrior::takenDng(int dng)
{
    srand(time(NULL));
    int pom = hp;
    double i = (double)(rand() % 100 + 1);
    if (i <= shield) {
       
        hp -= ceil((dng * (1 - getArrmor())) * 0.1);
        return pom-hp;
    }
    else {
        hp -= ceil((dng*(1-getArrmor())));
        return pom - hp;
    }
}

int Warrior::maxHp()
{
    return vitality*5;
}

string Warrior::toString()
{
    return "Wojownik:\nid: " + to_string(id) + "\n hp: " + to_string(hp) + "\nvitality: " + to_string(vitality) + "\nbaseDng: " + to_string(baseDng) + "\nbaseArrmor: " + to_string(baseArrmor)+"\ntarcza: "+ to_string(shield);

}


void Warrior::cure(int level)
{
    hp =hp + maxHp_level(level)*0.1;
    if (hp > maxHp_level(level))hp = maxHp_level(level);
}

