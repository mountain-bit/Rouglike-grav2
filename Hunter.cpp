#include "Hunter.h"

Hunter::~Hunter()
{
}

Hunter::Hunter() {
    id = 1;
    vitality = DATABASE.GetBaseVitality(id);
    hp = maxHp();
    baseDng = DATABASE.GetBaseDng(id);
    baseArrmor = DATABASE.GetBaseArrmor(id);
    dodge = DATABASE.GetSpecialAbility(id);
}

int Hunter::atack(double chance, double dngMulti)
{

    srand(time(NULL));
    double i = (double)(rand() % 100 + 1) / 100;
    if (i <= chance)
        return baseDng * dngMulti;
    else
        return 0;
}

int Hunter::takenDng(int dng)
{

    srand(time(NULL));
    int pom = hp;
    double i = (double)(rand() % 100);
    if (i <= dodge) {
        return 0;
    }
    else {
        hp -= ceil((dng * (1 - getArrmor())));
        return pom-hp;
    }
}

int Hunter::maxHp()
{
    return vitality*3;
}

string Hunter::toString()
{
    return "£owca:\nid: " + to_string(id) + "\n hp: " + to_string(hp) + "\nvitality: " + to_string(vitality) + "\nbaseDng: " + to_string(baseDng) + "\nbaseArrmor: " + to_string(baseArrmor) + "\nunik: " + to_string(dodge);

}

void Hunter::cure(int level)
{
    hp = hp + maxHp_level(level) * 0.8;
    if (hp > maxHp_level(level))hp = maxHp_level(level);
}
