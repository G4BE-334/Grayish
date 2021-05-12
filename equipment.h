#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class Equipment: public Item
{
    private:
    
    string typeE;
    bool isEquipped;

    public:
    Equipment();
    string getTypeE();
    void setTypeE(string t);
    bool getIsEquipped();
    void setEquipped();
    
};

#endif