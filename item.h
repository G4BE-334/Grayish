#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

using namespace std;

class Item
{
    private:

    // General Description
    string name = "nothing";
    int quantity = 0;
    string type;
    // string description;
    int tier; // The tier will define the range of gold that the player will get, the xp and possible items.
    int purchasePrice;
    int salePrice;
    int slot;

    public:

    // Change Stats
    Item();
    virtual ~Item();
    void setItem(string n, int t, string ty, int s);
    void setQtt();
    void setQttN();

    // Return Values
    // int getItemId();
    int getTier();
    int getPP();
    int getSP();
    int getQtt();
    int getSlot();

    string getName();
    string getType();
    // string getDescription();

};

#endif