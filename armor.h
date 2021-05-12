#ifndef ARMOR_H
#define ARMOR_H

#include"equipment.h"
#include <vector>

class Armor : public Equipment 
{
    private:
    // int weight;
    
    public:
    vector<int> attributes = { };
    Armor();
    Armor(int d, int md, int lp);
};

#endif
