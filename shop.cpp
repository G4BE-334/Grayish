#include "shop.h"

Shop::Shop()
{
    slots = 45;
    occupied[slots] = {false};
    for (int i = 0; i < slots; i++)
    {
        store[i] = new Item;
    }
}

void Shop::setSlots(int s)
{
    slots = s;
}

void Shop::setStore(Item* i)
{
    for (int j = 0; j < slots; j++) { if (occupied[j] == false) { store[j] = i; occupied[j] = true; break;} }
}

Item** Shop::getStore()
{
    return store;
}

int Shop::getOccSlots()
{
    for (int i=0 ; i < slots ; i++) {
        if (occupied[i] == false) {occSlots = i+1; break;}
    }
    return occSlots;

}

void Shop::displayStore()
{
    for (int j = 0; j < slots; j++) {
        if (store[j]) { 
            if (occupied[j] == true && store[j]->getName() != "nothing") {
            cout << j << "|| " << store[j]->getName() << ": " << store[j]->getPP() << " gold\t"; 
            }
            else {
                break;
            }
        } 
    }
}