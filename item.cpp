#include "item.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>

Item::Item()
{

}

Item::~Item()
{
    
}

void Item::setItem(string n, int t, string ty, int s)
{
    name = n;
    tier = t;
    type = ty;
    slot = s;

    switch(tier) {
        case 0:
            purchasePrice = 100;
            salePrice = 0;
            break;
        case 1:
            purchasePrice = 300;
            salePrice = 150;
            break;
        case 2:
            purchasePrice = 600;
            salePrice = 250;
            break;
    }
}

void Item::setQtt()
{
    quantity++;
}

void Item::setQttN()
{
    quantity--;
}

int Item::getTier()
{
    return tier;
}

int Item::getPP()
{
    return purchasePrice;
}

int Item::getSP()
{
    return salePrice;
}

string Item::getName()
{
    return name;
}

string Item::getType()
{
    return type;
}

int Item::getQtt()
{
    return quantity;
}

int Item::getSlot(){
    return slot;
}
