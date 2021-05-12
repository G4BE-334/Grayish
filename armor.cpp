#include "armor.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>

Armor::Armor()
{

}

Armor::Armor(int d, int md, int lp)
{
    attributes = {d, md, lp};
}
