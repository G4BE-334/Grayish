#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#undef max
#include <vector>

#include "equipment.h"
#include "consumable.h"

using namespace std;

class Inventory
{
    private:
    int slots = 15;
    Equipment* equipments[15];
    Consumable* consumables;
    int occSlots;
    bool occupied[30] = {false};

    public:

    // Change Stats
    Inventory();
    void setSlots(int s);
    void setEquipments(Equipment* e);
    void setConsumables(Consumable e);

    void displayItems();

    Equipment& getEquipments(int i);
    Equipment** getEquipments();
    Consumable* getConsumables();
    int getSlots();
    bool* getOccupied();
    int getOccSlots();
};

#endif