/*
This is the main file of my fantasy fighting game
My game is called Grayish and it is a turn based game where combat will take place with text based actions
The game is about taking a side and being radical by defending your side
it is a satire of how our world is so polarized today
I hope you enjoy

I state that this is my own work
*/

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <memory>


#include "character.h"
#include "enemy.h"
#include "inventory.h"
#include "shop.h"


using namespace std;

Character player;
CharClass cClass;
Shop shop;

Equipment nothingE;
Consumable nothingC;

void combat(Enemy e);

void menu();

void shopping() {
    Weapon basicSword(false, false, "sword");
    basicSword.setItem("Small Sword", 0, "equipment", 1);
    basicSword.setAttributes(1, 0, 0);
    basicSword.setTypeE("weapon");
    shop.setStore(&basicSword);

    Weapon shield(false, false, "shield");
    shield.setItem("Basic Shield", 0, "equipment", 2);
    basicSword.setTypeE("shield");
    shop.setStore(&shield);

    Armor basicArmor(1, 0, 1);
    basicArmor.setItem("Basic Armor", 0, "equipment", 0);
    basicArmor.setTypeE("armor");
    shop.setStore(&basicArmor);

    Weapon greatSword(true, true, "sword");
    greatSword.setItem("Great Sword", 1, "equipment", 1);
    greatSword.setAttributes(3, 0, 1);
    greatSword.setTypeE("weapon");
    shop.setStore(&greatSword);

    Weapon noviceMace(false, true, "mace");
    noviceMace.setItem("Novice Mace", 1, "equipment", 1);
    noviceMace.setAttributes(0, 3, 1);
    noviceMace.setTypeE("weapon");
    shop.setStore(&noviceMace);
    
    Weapon elementalRing(false, true, "ring");
    elementalRing.setItem("Elemental Ring", 1, "equipment", 1);
    elementalRing.setAttributes(1, 2, 2);
    elementalRing.setTypeE("weapon");
    shop.setStore(&elementalRing);

    Weapon muskyAxe(true, true, "ring");
    muskyAxe.setItem("Musky Axe", 1, "equipment", 1);
    muskyAxe.setAttributes(4, 0, 0);
    muskyAxe.setTypeE("weapon");    
    shop.setStore(&muskyAxe);

    Consumable potion("potion", 10, false);
    potion.setItem("Health Potion", 0, "consumable", 3);
    shop.setStore(&potion);

    int storeAction = 0;
    while (storeAction < 1 || storeAction > 3 ) {
        cout << "1|| BUY \t 2|| SELL \t 3|| BACK" << endl;
        cin >> storeAction;
    }
    if (storeAction == 1) {
        int buyAction = -1;
        int OS = shop.getOccSlots();
        while (buyAction < 0 || buyAction > OS) {
            shop.displayStore();
            cout << endl;
            cin >> buyAction;
        }
        cout << "You currently have " << player.getGold() << " gold. Would you like to buy " << shop.getStore()[buyAction]->getName() << " for " << shop.getStore()[buyAction]->getPP() << "?" << endl;
        string answer;
        while (answer != "Y" and answer != "y" and answer != "N" and answer != "n") {
            cout << "Y|| Yes\t N|| No" << endl;
            cin >> answer;
        }
        if (answer == "Y" || answer == "y") {
            if (player.getGold() < shop.getStore()[buyAction]->getPP()) {
                cout << "Sorry you can't buy this item because you're broke." << endl;
                getchar();
                cin.get();
                system("cls");
                shopping();
            }
            else {
                player.setGold(-shop.getStore()[buyAction]->getPP());
                if (shop.getStore()[buyAction]->getType() == "equipment") {
                    Equipment* equipment = dynamic_cast<Equipment*>(shop.getStore()[buyAction]);
                    player.addEquipment(equipment);
                }
                else if (shop.getStore()[buyAction]->getType() == "consumable") {
                    Consumable* consumable = dynamic_cast<Consumable*>(shop.getStore()[buyAction]);
                    player.addConsumable(*consumable);
                }
                cout << "You obtained " << shop.getStore()[buyAction]->getName() << endl;
                getchar();
                cin.get();
                shopping();
            }
        }
        else {
            shopping();
        }
    }
    else if (storeAction == 2){
        int sellAction;
        int type = 0;
        player.displayInv();
        cout << endl;
        cin >> sellAction;
        if (player.inventory.getEquipments()[sellAction]->getName() != "nothing") {
            cout << "You currently have " << player.inventory.getEquipments()[sellAction]->getQtt() << " " << player.inventory.getEquipments()[sellAction]->getName() << ". Do you want to sell a unity for " << player.inventory.getEquipments()[sellAction]->getSP() <<  " gold?" << endl;
            type = 1;
        }
        else if (player.inventory.getConsumables()[sellAction].getName() != "nothing") {
            cout << "You currently have " << player.inventory.getConsumables()[sellAction].getQtt() << " " << player.inventory.getConsumables()[sellAction].getName() << ". Do you want to sell a unity for " << player.inventory.getConsumables()[sellAction].getSP() <<  " gold?" << endl;
            type = 2;
        }
        else {
            cout << "There's no item with that number. Please select a item again" << endl;
            getchar();
            cin.get();
            shopping();
        } 
        string answer;
        while (answer != "Y" and answer != "y" and answer != "N" and answer != "n") {
            cout << "Y|| Yes\t N|| No" << endl;
            cin >> answer;
        }
        if (answer == "Y" || answer == "y") {
            if (type = 1) {
                player.setGold(player.inventory.getEquipments()[sellAction]->getSP());
                player.inventory.getEquipments()[sellAction]->setQttN();
                if (player.inventory.getEquipments()[sellAction]->getQtt() == 0) {
                    player.inventory.getEquipments()[sellAction] = &nothingE;
                }
            }
            else {
                player.setGold(player.inventory.getConsumables()[sellAction].getSP());
                player.inventory.getConsumables()[sellAction].setQttN();
                if (player.inventory.getConsumables()[sellAction].getQtt() == 0) {
                    player.inventory.getConsumables()[sellAction] = nothingC;
                }
            }
            player.inventory.getOccupied()[sellAction] = false;
        }
        getchar();
        cin.get();
        system("cls");
        shopping();
    }
    else if (storeAction == 3){
        system("cls");
        menu();
    }
}

void equipment() {
    int equip = 0;
    while (equip < 1 || equip > 4) { 
        player.displayEquipped();
        cin >> equip;
    }
    switch(equip)
    {
        case 1:
        {
            int equip1 = -1;
            while (equip1 < 0 || equip1 > player.inventory.getOccSlots()-1) {
                player.displayEquipments();
                cout << endl;
                cin >> equip1;
            }
            if(player.inventory.getEquipments()[equip1]->getName() == player.equipments[0].getName()) {
                cout << "This armor is already equipped" << endl;
                getchar();
                cin.get();
                system("cls");
            }
            else {
                player.canEquip(equip-1, player.inventory.getEquipments()[equip1]);
            }
            equipment();
            break;
        }
        case 2:
        {
            int equip2 = -1;
            while (equip2 < 0 || equip2 > player.inventory.getOccSlots()-1) {
                player.displayEquipments();
                cout << endl;
                cin >> equip2;
            }
            if(player.inventory.getEquipments()[equip2]->getName() == player.equipments[1].getName()) {
                cout << "This weapon is already equipped" << endl;
                getchar();
                cin.get();
                system("cls");
            }
            else {
                player.canEquip(equip-1, player.inventory.getEquipments()[equip2]);
            }
            equipment();
            break;
        }
        case 3:
        {
            int equip3 = -1;
            while (equip3 < 0 || equip3 > player.inventory.getOccSlots()-1) {
                player.displayEquipments();
                cout << endl;
                cin >> equip3;
            }
            if(player.inventory.getEquipments()[equip3]->getName() == player.equipments[1].getName()) {
                cout << "This weapon is already equipped" << endl;
                getchar();
                cin.get();
                system("cls");
                equipment();
            }
            else {
                player.canEquip(equip-1, player.inventory.getEquipments()[equip3]);
            }
            equipment();
            break;
        }
        case 4:
        {
            menu();
        }
    }
    getchar();
    cin.get();
    system("cls");
    menu();
}

void menu() {
    int menuAct = 0;
    cout << endl << endl;
    player.displayChar();

    cout << endl << endl << endl << setw(40) << " \t \t 1|| Inventory    2|| Shop    3|| Equipment    4|| Train    5|| Quests    6||Save    7||Quit" << flush << endl;

    cin >> menuAct;

    switch(menuAct)
    {
        case 1:
            player.displayInv();
            getchar();
            cin.get();
            system("cls");
            menu();
        case 2:
            shopping();
        case 3:
            equipment();
    }
}

// Function to skip tutorial and go directly to the main menu
// By default the character will be a knight and left side 
void skipTutorial()
{
    string cName = "Knight";
    string skills[] = {"Flash Hit", "Hit Strike","Sword of Discernment", "Swallow's Wing", "Starbust Stream"};
    cClass.setChar(cName, skills);
    cClass.setCCId(1);

    player.setPlayer("tester", cClass, 2);
    
    Weapon basicSword(false, false, "sword");
    basicSword.setItem("Small Sword", 0, "equipment", 1);
    basicSword.setAttributes(1, 0, 0);
    basicSword.setTypeE("weapon");

    Armor basicArmor(1, 0, 1);
    basicArmor.setItem("Basic Armor", 0, "equipment", 0);
    basicArmor.setTypeE("armor");

    Consumable potion("potion", 10, false);
    potion.setItem("Health Potion", 0, "consumable", 3);
    for (int i = 0; i < 9; i ++) { potion.setQtt(); }

    player.addEquipment(&basicSword);
    player.addEquipment(&basicArmor);
    player.addConsumable(potion);

    player.setEquipment(&basicSword);
    player.setEquipment(&basicArmor);

    Weapon spcWeapon;
    spcWeapon.setWeapon(true, true, "sword");
    spcWeapon.setItem("Great Sword", 1, "equipment", 1);
    spcWeapon.setAttributes(3, 0, 1);
    spcWeapon.setTypeE("weapon");
    player.addEquipment(&spcWeapon);
    cout << "Obtained Great Sword" << flush << endl;
    player.setEquipment(&spcWeapon);

    player.lvlUp();

    menu();
}

void tutorial() {
    Enemy civilian;
    civilian.setEnemy("civilian", 0, false);

    Weapon basicSword(false, false, "sword");
    basicSword.setItem("Small Sword", 0, "equipment", 1);
    basicSword.setAttributes(1, 0, 0);
    basicSword.setTypeE("weapon");

    Armor basicArmor(1, 0, 1);
    basicArmor.setItem("Basic Armor", 0, "equipment", 0);
    basicArmor.setTypeE("armor");

    Consumable potion("potion", 10, false);
    potion.setItem("Health Potion", 0, "consumable", 3);
    for (int i = 0; i < 9; i ++) { potion.setQtt(); }

    player.addEquipment(&basicSword);
    player.addEquipment(&basicArmor);
    player.addConsumable(potion);

    player.setEquipment(&basicSword);
    player.setEquipment(&basicArmor);

    combat(civilian);

    player.lvlUp();

    Weapon spcWeapon;

    switch(player.cClass.getCCId()) {
        case 1: {
            spcWeapon.setWeapon(true, true, "sword");
            spcWeapon.setItem("Great Sword", 1, "equipment", 1);
            spcWeapon.setAttributes(3, 0, 1);
            spcWeapon.setTypeE("weapon");
            player.addEquipment(&spcWeapon);
            cout << "Obtained Great Sword" << flush << endl;
            break;
        }
        case 2: {
            spcWeapon.setWeapon(false, true, "mace");
            spcWeapon.setItem("Novice Mace", 1, "equipment", 1);
            spcWeapon.setAttributes(0, 3, 1);
            spcWeapon.setTypeE("weapon");
            player.addEquipment(&spcWeapon);
            cout << "Obtained Novice Mace" << flush << endl;
            break;
        }
        case 3: { 
            spcWeapon.setWeapon(false, true, "ring");
            spcWeapon.setItem("Elemental Ring", 1, "equipment", 2);
            spcWeapon.setAttributes(1, 2, 2);
            spcWeapon.setTypeE("weapon");
            player.addEquipment(&spcWeapon);
            cout << "Obtained Elemental Ring" << flush << endl;
            break;
        }
        case 4: {
            spcWeapon.setWeapon(true, true, "ring");
            spcWeapon.setItem("Musky Axe", 1, "equipment", 1);
            spcWeapon.setAttributes(4, 0, 0);
            spcWeapon.setTypeE("weapon");
            player.addEquipment(&spcWeapon);
            cout << "Obtained Musky Axe" << flush << endl;
            break;
        }
    }
    usleep(3000000);
    system("cls");

    string answer;
    while (answer != "Y" and answer != "y" and answer != "N" and answer != "n") {
        cout << "Do you want to equip it?\n\n";
        cout << "Y|| Yes\t N|| No" << endl;
        cin >> answer;

        if (answer == "Y" or answer == "y") { 
            player.setEquipment(&spcWeapon);
        }

        system("cls");
    }
}

void combat(Enemy e) {
    bool heavy = false;

    if (e.getTier() == 0) {
        while (e.getLP() > 0) {
            player.displayLPBar();
            e.displayLPBar();
            player.displayMPBar();


            int damage;
            int criticDmg;

            int combatAction = 0;

            while (combatAction < 1 or combatAction > 4)
            {
                if (heavy) {
                    cout << "Heavy Attack is charged" << flush << endl;
                    getchar();
                    system("cls");
                    cout << "You used Heavy Attack!" << flush << endl;
                    usleep(2000000);
                    system("cls");
                    damage = player.attributes[0]*2 + (player.getCombatAtt()[0]-player.attributes[0]) - e.attributes[2];
                    criticDmg = rand() % 100 + 1;
                    if (criticDmg <= player.attributes[7]) { damage = damage * 2; }
                    cout << e.getName() << " lost " << damage << " life points!" << flush << endl;
                    usleep(1000000);
                    system("cls");
                    e.setLP(-damage);
                    heavy = false;
                    break;
                }
                cout << "\n\n\n" << setw(80) << "1|| Attack    2|| Skill    3|| Block    4||Flee" << endl;
                cin >> combatAction;
                system("cls");
                if (combatAction == 2 and player.getLvl() == 0) {
                    cout << "You haven't learned any skill yet" << endl;
                    getchar();
                    cin.get();
                    system("cls");
                    combatAction = 0;
                }
            }
            switch(combatAction) {
                case 1:
                {
                    int attackAction = 0;
                    while (attackAction != 1 and attackAction != 2) {
                        cout << "\n\n\n" << setw(80) << "1|| Basic Attack    2|| Heavy Attack" << endl;
                        cin >> attackAction;
                        system("cls");
                    }
                    if (attackAction == 1) {
                        cout << " You used Basic Attack " << flush << endl;
                        usleep(1000000);
                        int damage;
                        damage = player.getCombatAtt()[0] - e.attributes[2];
                        criticDmg = rand() % 100 + 1;
                        if (criticDmg <= player.attributes[7]) { damage = damage * 2;}
                        cout << e.getName() << " lost " << damage << " life points!" << flush << endl;
                        usleep(1000000);
                        e.setLP(-damage);
                    }
                    else {
                        cout << " Charging Heavy Attack " << endl;
                        getchar();
                        cin.get();
                        system("cls");
                        heavy = true;
                    }
                    break;
                }
                case 2:
                {
                    int skill = 0;
                    while (skill != 1 and skill != 2) {
                        cout << "\n\n\n" << setw(50) << "1|| " << cClass.learnedSkills[0] << "    2|| " << cClass.learnedSkills[1] << endl;
                        cin >> skill;
                        system("cls");
                    }
                    cout << "You used skill" << cClass.learnedSkills[skill+1] << flush << endl;

                    damage = (rand() % player.attributes[0] /* + itemDamage */ * 2) - e.attributes[2];
                    if (damage < 0) { damage = 0; }
                    criticDmg = rand() % 100 + 1;
                    if (criticDmg <= player.attributes[7]) { damage = damage * 2;}
                    cout << e.getName() << " lost " << damage << " life points!" << flush << endl;
                    usleep(1000000);
                    e.setLP(-damage);
                    break;
                }
                case 3:
                {
                    player.block();
                    cout << "You are blocking\nDefense is increased!" << flush << endl;
                    usleep(1000000);
                    break;
                }
                case 4:
                {
                    cout << "THERE IS NO MERCY!" << flush << endl;
                    usleep(1000000);
                    break;
                }
                system("cls");
            }

            if (e.getLP() <= 0) {
                cout << e.getName() << ": ";
                for (int i = 0; i < 10; i ++) { cout << "A" << flush; usleep(300000); }
                cout << endl << "Cough Cough" << flush;
                usleep(550000);
                for (int i = 0; i < 3; i++) { cout <<"."<<flush; usleep(550000); }
                cout << "Please tell my kids I love them" << endl;
                getchar();
                cout << "You killed the " << e.getName() << endl;
                getchar();
                system("cls");
                break;
            }

            cout << e.getName() << ": AAAARRGHHHHH\n WHAT ARE YOU DOING DUDE???" << flush << endl;
            usleep(2000000);
            system("cls");
            cout << e.getName() << " tried to run away" << flush << endl;
            usleep(2000000);
            system("cls");
        }
    }
}


int main() {

    cout << "WELCOME TO GRAYISH" << flush << endl;
    usleep(2500000);
    system("cls");

    cout << "This is a text based game, throughout the game you will have to take actions based on the options displayed on the screen" << endl << endl;
    cout << "You will select an option by typing a button that will be shown in the message and pressing ENTER" << endl;
    cout << "When there is no option you just have to press ENTER" << endl;
    cout << "For example: " << endl << endl;

    string answer;
    while (answer != "Y" and answer != "y" and answer != "N" and answer != "n" and answer != "skip") {
        cout << "Would you like to play the game? " << endl;
        cout << "Y|| Yes\t N|| No" << endl;
        cin >> answer;
        system("cls");
    }
    if (answer == "N" and answer == "n")
    {
        system("cls");
        cout << "Well" << flush;
        usleep(550000);
        cout << "." << flush;
        usleep(550000);
        cout << "." << flush;
        usleep(550000);
        cout << "." << flush << endl;
        usleep(600000);
        system("cls");
        cout << "This is awkward " << flush << endl;
        usleep(800000);
        cout << "Thanks for your attention" << flush << endl;
        usleep(800000);
        cout << "I guess" << flush << endl;
        usleep(800000);
        system("cls");
        usleep(800000);
        cout << "Goodbye" << endl;
        usleep(800000);
        system("cls");
        return 0;
    }
    else if (answer == "skip") {
        skipTutorial();
    }
    system("cls");

    cout << "Not bad!" << endl;
    getchar();
    cin.get();
    system("cls");

    cout << "Now that you know how to play a text based game... Please enter the name of your character: " << endl;
    string charName;
    cin >> charName;
    system("cls");

    cout << "Please select the class of your character:" << endl;
    int charClass = 0;
    while (charClass < 1 or charClass > 4) {
        cout << "1|| Knight\t2|| Sorcerer\t3|| Swordmage\t4|| Druid" << endl;
        cin >> charClass;
        system("cls");
    }
    string cName;
    if (charClass == 1) {
        cName = "Knight";
        string skills[] = {"Flash Hit", "Hit Strike","Sword of Discernment", "Swallow's Wing", "Starbust Stream"};
        cClass.setChar(cName, skills);
    }
    else if (charClass == 2) {
        cName = "Sorcerer";
        string skills[] = {"Fire Ball", "Storm","Critical Surge", "Solar Beam", "Discharge"};
        cClass.setChar(cName, skills);
    }
    else if (charClass == 3) {
        cName = "Swordmage";
        string skills[] = {"Burn", "Freeze", "Lightning", "Whirlwind", "Elemental Outburst"};
        cClass.setChar(cName, skills);
    }
    else {
        cName = "Druid";
        string skills[] = {"Stomp", "Terra Strike","Bestial Wrath", "Skull Bash", "Nature's Calling"};
        cClass.setChar(cName, skills);
    }
    cout << "Welcome to our world, " << cName <<" "<< charName << endl;
    cClass.setCCId(charClass);
    getchar();
    cin.get();
    system("cls");

    cout << "You will have to pick a side to fight for... What side do you want to join???" << endl;
    cout << "Think carefully about it..." << endl;
    getchar();
    cout << "It actually does not really matter which side you pick" << endl;
    cout << "Just know that each side hate the other " << endl;
    getchar();
    system("cls");

    int charSide;
    while (charSide != 1 and charSide != 2) {
        cout << "1|| LEFT\t2|| RIGHT" << endl;
        cin >> charSide;
        system("cls");
    }
    player.setPlayer(charName, cClass, charSide);
    cout << "In this adventure you will have to destroy all enemies from the opposition" << endl;
    cout << "There is no MERCY!" << endl;
    getchar();
    cin.get();
    system("cls");

    cout << "There is a civilian from the other side looking at you" << endl;
    getchar();
    cout<< "He seems harmless, but you know what you gotta do" << flush;
    usleep(1500000);
    cout << "." << flush;
    usleep(700000);
    cout << "." << flush;
    usleep(700000);
    cout << "." << flush << endl;
    usleep(1000000);
    system("cls");
    int noMercy;
    while (noMercy != 1) {
        cout << "1|| Fight\t2|| Mercy" << endl;
        cin >> noMercy;
        if (noMercy == 2) {
            cout << "THERE IS NO MERCY!" << flush << endl;
            getchar();
            cin.get();
            system("cls");
        }
        system("cls");
    }

    cout << "You entered combat" << endl;
    cout << "Just like before, you will have to select options, but now to fight" << endl << endl;
    getchar();
    system("cls");
    cout << "Your life and mana will be shown on the left side of the console" << endl << "Your enemy's will be shown on the right side" << endl;
    getchar();
    system("cls");

    tutorial();

    cout << "You unlocked the menu! Congratulations." << endl;
    getchar();
    system("cls");

    menu();
}


