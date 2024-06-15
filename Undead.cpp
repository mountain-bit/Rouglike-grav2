#include "Undead.h"
#include "DataBase.h";

Undead::Undead(int level)
{
    id = level;
    idarchetype = 0;
    vitality = DATABASE.GetBaseEnemiVitalit(idarchetype);
    hp = maxHp();
    baseDng = DATABASE.GetBaseEnemiDng(idarchetype);
    baseArrmor = DATABASE.GetBaseEnemiArrmor(idarchetype);
    setAttacks();

}

Undead::~Undead()
{
}



int Undead::maxHp()
{
    return vitality*3*(1+id/10);
}

string Undead::toString()
{
    return "Nieumarly:\n Archetyp: " + to_string(idarchetype) + " \nlevel: " + to_string(id) + "\n hp : " + to_string(hp) + "\nvitality : " + to_string(vitality) + "\nbaseDng : " + to_string(baseDng) + "\nbaseArrmor : " + to_string(baseArrmor);

}

