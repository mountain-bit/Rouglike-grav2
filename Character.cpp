#include "Character.h"

Character::Character()
	:id(0), vitality(0), hp(0), baseDng(0), baseArrmor(0) {}

Character::Character(int id, int hp, int vitality, int baseDng, int baseArrmor) :id(id), vitality(vitality), hp(hp), baseDng(baseDng), baseArrmor(baseArrmor) {}
string Character::toString()
{
	return "Character:\nid: "+to_string(id)+"\n hp: "+ to_string(hp)+"\nvitality: "+ to_string(vitality)+"\nbaseDng: "+ to_string(baseDng)+"\nbaseArrmor: "+ to_string(baseArrmor);
}
Character::~Character()
{
}
double Character::getArrmor()
{
	return log10(baseArrmor+100)/log10(1000)-0.5;
}
int Character::getId()
{
	return id;
}
int Character::getBaseDng()
{
	return baseDng;
}
int Character::getBaseArrmor()
{
	return baseArrmor;
}
bool Character::isDead()
{
	return hp<=0;
}
int Character::getHp()
{
	return hp;
}
int Character::takenDng(int dng)
{
	if (dng == 0)
		return 0;
	int pom = hp;
	hp -= ceil((dng * (1 - getArrmor())));
	return pom - hp;

}
void Character::setHp(int newHp)
{
	hp = newHp;
}
void Character::plusVitality(int plus)
{
	vitality += plus;
}
void Character::plusBaseDng(int plus)
{
	baseDng += plus;
}
void Character::plusBaseArrmor(int plus)
{
	baseArrmor += plus;
}


