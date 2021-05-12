#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class Consumable: public Item
{
    private:
    
    string typeC;
    int effect;
    bool isDebuff;
    
    public:
    Consumable();
    Consumable(string t, int e, bool d);
    
};

#endif