#include "weapon.h"


Weapon::Weapon()
{
    
}

Weapon::Weapon(bool th, bool cs, string t)
{
    isTwoHand = th;
    isCSpecific = cs;
    typeW = t;
}

void Weapon::setAttributes(int pd, int md, int cd)
{
    attributes = {pd, md, cd};
}

void Weapon::setWeapon(bool th, bool cs, string t)
{
    isTwoHand = th;
    isCSpecific = cs;
    typeW = t;
}

bool Weapon::getIsTwoH()
{
    return isTwoHand;
}

bool Weapon::getIsCSPecific()
{
    return isCSpecific;
}

string Weapon::getTypeW()
{
    return typeW;
}