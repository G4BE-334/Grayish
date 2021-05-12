#include "equipment.h"


Equipment::Equipment()
{
    bool isEquipped = false;
}

string Equipment::getTypeE()
{
    return typeE;
}

void Equipment::setTypeE(string t)
{
    typeE = t;
}

bool Equipment::getIsEquipped()
{
    return isEquipped;
}

void Equipment::setEquipped()
{
    if (isEquipped == false) { isEquipped = true; }
    else if (isEquipped == true) { isEquipped = false; }
}
