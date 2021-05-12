#include "shop.h"

Shop::Shop()
{
    slots = 45;
    store = new Item[slots];
    occupied[slots] = {false};
    
    Weapon basicSword(false, false, "sword");
    basicSword.setItem("Small Sword", 0, "equipment", 1);
    basicSword.setAttributes(1, 0, 0);
    basicSword.setTypeE("weapon");
    store[0] = basicSword;
    occupied[0] = true;

    Weapon shield(false, false, "shield");
    shield.setItem("Basic Shield", 0, "equipment", 2);
    basicSword.setTypeE("shield");
    store[1] = shield;
    occupied[1] = true;

    Armor basicArmor(1, 0, 1);
    basicArmor.setItem("Basic Armor", 0, "equipment", 0);
    basicArmor.setTypeE("armor");
    store[2] = basicArmor;
    occupied[2] = true;

    Weapon greatSword(true, true, "sword");
    greatSword.setItem("Great Sword", 1, "equipment", 1);
    greatSword.setAttributes(3, 0, 1);
    greatSword.setTypeE("weapon");
    store[3] = greatSword;
    occupied[3] = true;

    Weapon noviceMace(false, true, "mace");
    noviceMace.setItem("Novice Mace", 1, "equipment", 1);
    noviceMace.setAttributes(0, 3, 1);
    noviceMace.setTypeE("weapon");
    store[4] = noviceMace;
    occupied[4] = true;
    
    Weapon elementalRing(false, true, "ring");
    elementalRing.setItem("Elemental Ring", 1, "equipment", 1);
    elementalRing.setAttributes(1, 2, 2);
    elementalRing.setTypeE("weapon");
    store[5] = elementalRing;
    occupied[5] = true;

    Weapon muskyAxe(true, true, "ring");
    muskyAxe.setItem("Musky Axe", 1, "equipment", 1);
    muskyAxe.setAttributes(4, 0, 0);
    muskyAxe.setTypeE("weapon");    
    store[6] = muskyAxe;
    occupied[6] = true;

    Consumable potion("potion", 10, false);
    potion.setItem("Health Potion", 0, "consumable", 3);
    store[7] = potion;
    occupied[7] = true;
}

void Shop::setSlots(int s)
{
    slots = s;
}

void Shop::setStore(Item i)
{
    for (int j = 0; j < slots; j++) { if (occupied[j] == false) { store[j] = i; occupied[j] = true;} }
}

Item* Shop::getStore()
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
    for (int j = 0; j < slots; j++) { if (occupied[j] == true) {
        cout << j << "|| " << store[j].getName() << ": " << store[j].getPP() << " gold\t"; 
        }
        else {
            break;
        } 
    }
}