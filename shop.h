#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <iostream>

#include "weapon.h"
#include "armor.h"
#include "consumable.h"

using namespace std;

class Shop
{
    private:
    int slots;
    Item* store[45];
    int occSlots;

    public:
    bool occupied[];

    // Change Stats
    Shop();
    void setSlots(int s);
    void setStore(Item* i);
    
    Item** getStore();
    int getOccSlots();

    void displayStore();
};

#endif