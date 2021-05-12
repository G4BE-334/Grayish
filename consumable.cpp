#include "consumable.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>

Consumable::Consumable()
{
    
}

Consumable::Consumable(string t, int e, bool d)
{
    typeC = t;
    effect = e;
    isDebuff = d;
}


