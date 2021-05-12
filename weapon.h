#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <vector>

#include "equipment.h"

using namespace std;

class Weapon: public Equipment
{
    private:
    
    bool isTwoHand;
    bool isCSpecific;
    string typeW = "nothing";
    
    public:
    vector<int> attributes = {};
    Weapon();
    Weapon(bool th, bool cs, string t);
    void setAttributes(int pd, int md, int cd);
    void setWeapon(bool th, bool cs, string t);
    
    string getTypeW();
    bool getIsTwoH();
    bool getIsCSPecific();
};

#endif