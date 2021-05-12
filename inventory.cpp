#include "inventory.h"

Inventory::Inventory()
{
    equipments = new Equipment[slots];
    consumables = new Consumable[slots];
}

void Inventory::setEquipments(Equipment e)
{
    for (int j = 0; j < slots; j ++) {
        if (occupied[j] == false)  {
            equipments[j] = e;
            occupied[j] = true;
            equipments[j].setQtt();
        }
        else if (equipments[j].getName() == e.getName()) {
            equipments[j].setQtt();
        }
        break;
    }
}

void Inventory::setConsumables(Consumable c)
{
    for (int j = 0; j < slots; j ++) {
        if (occupied[j] == false)  {
            consumables[j] = c;
            occupied[j] = true;
            consumables[j].setQtt();
        }
        else if (consumables[j].getName() == c.getName()) {
            consumables[j].setQtt();
        }
        break;
    }
}

void Inventory::setSlots(int s)
{
    slots = s;
}

void Inventory::displayItems()
{
    cout << endl << endl;
    for (int i = 0; i < slots; i++)
    {
        if (occupied[i] == true && equipments[i].getName() != "nothing")
        {
            cout << equipments[i].getName() << ": " << equipments[i].getQtt() << "\t";
        }
    }
    for (int i = 0; i < slots; i++)
    {
        if (occupied[i] == true && consumables[i].getName() != "nothing")
        {
            cout << consumables[i].getName() << ": " << consumables[i].getQtt() << "\t";
        }
    }}

Equipment* Inventory::getEquipments()
{
    return equipments;
}

Consumable* Inventory::getConsumables()
{
    return consumables;
}

int Inventory::getSlots()
{
    return slots;
}

bool* Inventory::getOccupied()
{
    return occupied;
}

int Inventory::getOccSlots()
{
    int counter = 0; 
    for (int i=0 ; i < slots ; i++) {
        if (occupied[i] == true) {counter++;}
    }
    occSlots = counter;
    return occSlots;

}