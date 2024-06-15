#include "Protagonist.h"

Protagonist::Protagonist():Character()
{
}

Protagonist::Protagonist(int id, int hp, int baseDng, int BaseArrmor):Character(id,hp,vitality,baseDng,BaseArrmor)
{
}

Protagonist::~Protagonist()
{
}

int Protagonist::maxHp_level(int level)
{
    return (int)((double)maxHp()) * pow(DATABASE.GetMultiLevelHp(id), level);
}

void Protagonist::cure(int level)
{
    hp = maxHp_level(level);
}

