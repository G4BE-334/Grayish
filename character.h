#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#undef max
#include <vector>
#include <unistd.h>
#include <iomanip>

#include "charclass.h"
#include "inventory.h"
#include "weapon.h"
#include "consumable.h"
#include "armor.h"


using namespace std;

class Character
{
    private:
    /* ATTRIBUTES
    PD | MD | DE | MDE | LP | MP | SP | CD | LU
    */

    // General Description
    string name = "NoName";
    int side; // 1: Left 2: Right

    // General Stats
    int gold;
    int XP;
    int lvl;



    // Dynamic stats;
    int LP;
    int MP;

    // Other
    bool blocking = false;
    bool secondHand = false; // Have second hand weapon?
    bool twoHand = false; // Have a twohanded weapon?
    int combatAtt[9];

    public:
    // Items and related
    Equipment equipments[3];

    // Weapon allW[7];
    // Armor allA[6];
    Inventory inventory;

    // Weapon weapons[2];
    // Armor armor;

    CharClass cClass; // 1: Knight 2: Sorcerer 3: Swordmage 4: Druid
    std::vector<int> attributes = { };

    // Change Stats
    Character();
    void setPlayer(string n, CharClass c, int s); // Set Name, Class, and Side
    void setAttribute(int index, int value); // Change attribute at index by value
    void setLP(int l); // Change lp for combat
    void setMP(int m); // Change mp for combat
    void setGold(int g); // Change cash for transactions
    void lvlUp(); // Upgrade lvl
    void setXP(int xp); // Change xp


    // Return Values
    std::vector<int> getAttributes();
    int getLP();
    int getMP();
    int getGold();
    int getLvl();
    int getXP();
    int* getCombatAtt();


    // Display
    void displayChar(); // Display Name, Lvl, LP, MP, Class, and XP
    void displayLPBar(); // Display LP Bar
    void displayMPBar(); // Display MP Bar
    void displayAttributes(); // Display Attributes
    void displayInv(); // Display Inventory
    void displayEquipped(); // Display Equipped items
    void displayEquipments(); // Display equipments

    // Other
    void addEquipment(Equipment e); // Add equipment to inventory
    void addConsumable(Consumable c); // Add consumable to inventory
    void block(); // Block attack
    void setEquipment(Equipment& e);
    void setCombatAtt(Weapon w);
    void setCombatAtt(Armor a);
    void canEquip(int a, Equipment e);

    // void setAllW(Weapon w);
    // void setAllA(Armor a);
    // void setWeapon(Weapon w);
    // void setArmor(Armor a);

};

#endif