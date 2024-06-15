#include "Spider.h"

Spider::Spider(int level)
{
    id = level;
    idarchetype = 1;
    vitality = DATABASE.GetBaseEnemiVitalit(idarchetype);
    hp = maxHp();
    baseDng = DATABASE.GetBaseEnemiDng(idarchetype);
    baseArrmor = DATABASE.GetBaseEnemiArrmor(idarchetype);
    setAttacks();
}

Spider::~Spider()
{
}


int Spider::maxHp()
{
    return vitality * 2 * (1 + id / 8);
}

string Spider::toString()
{
    return "Pajak:\n Archetyp: "+to_string(idarchetype)+" \nlevel: " + to_string(id) + "\n hp : " + to_string(hp) + "\nvitality : " + to_string(vitality) + "\nbaseDng : " + to_string(baseDng) + "\nbaseArrmor : " + to_string(baseArrmor);

}
