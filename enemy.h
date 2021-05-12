#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#undef max
#include <vector>
#include <unistd.h>
#include <iomanip>

using namespace std;

class Enemy
{
    private:

    // General Description
    string name = "NoName";
    int enemyId;
    int tier = 0; // The tier will define the range of gold that the player will get, the xp and possible items.

    // Dynamic stats;
    int LP;
    int MP;

    // Other
    bool blocking = false;
    bool isBoss;

    public:

    /* ATTRIBUTES
    PD | MD | DE | MDE | LP | MP | SP | CD | LU
    */
    std::vector<int> attributes = { };

    // Change Stats
    Enemy();
    void setEnemy(string n, int r, bool B); // Set Name and tier
    void setLP(int l); // Change lp for combat
    void setMP(int m); // Change mp for combat

    // Return Values
    int getLP();
    int getMP();
    int getTier();
    string getName();

    // Display
    void displayLPBar();
    // void displayMPBar();
};

#endif