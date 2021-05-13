#include "character.h"

Weapon nothing;

Character::Character()
{
    gold = 100;
    XP = 0;
    lvl = 0;

}

void Character::setPlayer(string n, CharClass c, int s)
{
    name = n;
    cClass = c;
    side = s;

    switch(cClass.getCCId()) {
            // PD | MD | DE | MDE | LP | MP | SP | CD | LU
        case 1:
            attributes = {5, 0, 16, 2, 25, 0, 6, 16, 0};
            break;
        case 2:
            attributes = {2, 4, 6, 10, 20, 15, 4, 16, 0};
            break;
        case 3:
            attributes = {3, 3, 8, 8, 25, 10, 5, 18, 1};
            break;
        case 4:
            attributes = {4, 0, 16, 16, 160, 5, 16, 1, 16};
            break;
    }
    LP = attributes[4];
    MP = attributes[5];
    for (int i = 0; i < 9; i ++) {
        combatAtt[i] = attributes[i];
    }
}

void Character::setAttribute(int index, int value)
{
    if (index == 4 or index == 5 or index == 7 or index == 16){
        attributes[index] = attributes[index] + 16*value;
    }
    else {
        attributes[index]++;
    }
}

void Character::setLP(int l)
{
    LP += l;
}

void Character::setMP(int m)
{
    MP += m;
}

void Character::setGold(int g)
{
    if (g > 0) {
        cout << "You received " << g << " gold!" << flush << endl;
    }
    else {
        cout << "You lost " << g << " gold!" << flush << endl;
    }
    gold += g;
    usleep(3000000);
}

void Character::lvlUp()
{
    lvl++;
    int AP = 5;
    cout << "You leveled up!\n" << "Your new level is " << lvl << "\nSelect where you want to spend your Ability Points(AP)" << endl;
    getchar();
    int apAct, apSpend = 0;
    while (AP > 0) {
        cout << "You have " << AP << " AP left to spend" << endl << endl;
        cout << "0|| Physical Damage: " << attributes[0] << "  1|| Magical Damage: " << attributes[1] << "  2|| Defense: " << attributes[2] << "  3|| Magical Defense: " << attributes[3] << "  4|| Life Points: " << attributes[4] << "  5|| Magic Points: " << attributes[5] << "  6|| Speed: " << attributes[6] << "  7|| Critical Damage: " << attributes[7] << "  8|| Luck: " << attributes[8] << flush << endl;
        cin >> apAct;
        system("cls");
        cout << "How many AP do you want to spend on this attribute?" << endl;
        cin >> apSpend;
        if (apSpend <= AP) {
            setAttribute(apAct, apSpend);
            AP -= apSpend;
            cout << "Nicely done!" << endl;
            getchar();
            cin.get();
            system("cls");
        }
        else {
            cout << "Sorry, you do not have enough AP for that" << endl;
            getchar();
            cin.get();
            system("cls");
        }

    }
    LP = attributes[4];
    MP = attributes[5];
    for (int i = 0; i < 9; i ++) {
        combatAtt[i] = attributes[i];
    }    
    cClass.setLSkills(lvl);
    cout << "You have learned " << cClass.learnedSkills[lvl-1] << " and " << cClass.learnedSkills[lvl] << endl;
    getchar();
    system("cls");
}

void Character::setXP(int xp)
{
    XP += xp;
}

vector<int> Character::getAttributes()
{
    return attributes;
}

int Character::getLP()
{
    return LP;
}

int Character::getMP()
{
    return MP;
}

int Character::getGold()
{
    return gold;
}

int Character::getXP()
{
    return XP;
}

int Character::getLvl()
{
    return lvl;
}

int* Character::getCombatAtt() 
{
    return combatAtt;
}

void Character::displayChar()
{
    cout << setw(16) << name << setw(16) << cClass.getName() << setw(16) << " Level: " << lvl << setw(16) << " LP: " <<LP<<"/"<<attributes[4] << setw(16) << " MP: " << MP<<"/"<<attributes[5] << setw(16) << " XP: " <<XP<<"/"<<250 + 250*lvl<<endl;
}

void Character::displayLPBar()
{
    int LPBar;
    LPBar = (LP*1.00)/attributes[4];
    cout << setw(16) << name << " <<";
    for (int i = 0; i < LPBar * 10; i++) { cout << "|"; }
    for (int i = 0; i < 9 - LPBar * 10; i++) { cout << " "; }
    cout << ">> " << LP << "LP";

}

void Character::displayMPBar()
{
    int MPBar;
    if (attributes[5] != 0) {
        MPBar = (MP*1.00)/attributes[5];
        cout << setw(12) << " <<";
        for (int i = 0; i < MPBar * 10; i++) { cout << "|"; }
        for (int i = 0; i < 9 - MPBar * 10; i++) { cout << " "; }
        cout << ">> " << MP << "MP" << endl;
    }
}

void Character::displayAttributes()
{
    for (auto i = attributes.begin(); i != attributes.end(); ++i)
        cout << *i << " ";
}

void Character::block() { blocking = true; }

void Character::addEquipment(Equipment* e)
{
    inventory.setEquipments(e);
}

void Character::addConsumable(Consumable c)
{
    inventory.setConsumables(c);
}

// void Character::setAllA(Armor a)
// {
//     for (int i = 0; i < 6; i ++)
//     { 
//         if (allA[i].getName() == "nothing")
//         {
//             allA[i] = a;
//             break;
//         } 
//     }
// }

// void Character::setAllW(Weapon w)
// {
//     for (int i = 0; i < 7; i ++)
//     { 
//         if (allW[i].getName() == "nothing")
//         {
//             allW[i] = w;
//             break;
//         } 
//     }
// }

void Character::setCombatAtt(Weapon w)
{
    if (w.getTypeE() == "weapon") {
        combatAtt[0] = attributes[0] + w.attributes[0];
        combatAtt[1] = attributes[1] + w.attributes[1];
        combatAtt[7] = attributes[7] + w.attributes[2];
    }
    else {

    }
}

void Character::setCombatAtt(Armor a)
{
    combatAtt[2] = attributes[2] + a.attributes[0];
    combatAtt[3] = attributes[3] + a.attributes[1];
    combatAtt[4] = attributes[4] + a.attributes[2];
}

void Character::setEquipment(Equipment* e)
{
    if (e->getTypeE() == "armor") {
        Armor &a = dynamic_cast<Armor&>(*e);
        equipments[0] = a;
        setCombatAtt(a);
    }
    else if (e->getTypeE() == "weapon")
    {
        Weapon &w = dynamic_cast<Weapon&>(*e);
        if (w.getIsTwoH() == true) {
            cout << "This is a two handed weapon. Equipping it will occupy both hand slots" << flush << endl;
            usleep(1500000);
            cout << "Would you like to equip it?" << endl;
            string answer;
            while (answer != "Y" and answer != "y" and answer != "N" and answer != "n") {
                cout << "Y|| Yes\t N|| No" << endl;
                cin >> answer;
            }
            if (answer == "Y" or answer == "y") {
                w.setEquipped();
                equipments[1].setEquipped(); 
                equipments[1] = w;
                equipments[2] = nothing;
                setCombatAtt(w);
                twoHand = true;
            }
        }
        else {
            w.setEquipped();
            equipments[1].setEquipped();
            equipments[1] = w;
            setCombatAtt(w);
            twoHand = false;
        }
    }
    else {
        Weapon &w = dynamic_cast<Weapon&>(*e);
        if (twoHand)
        {
            cout <<+ "Sorry, you cannot equip this shield because you are holding a two handed weapon." << endl;     
        }
        else {
            w.setEquipped();
            equipments[2].setEquipped();
            equipments[2] = w;
            setCombatAtt(w);
        }
    }
}

// void Character::setWeapon(Weapon w)
// {
//     if (w.getTypeW() == "shield") { 
//         if (weapons[0].getIsTwoH() == true) {
//             cout <<+ "Sorry, you cannot equip this shield because you are holding a two handed weapon." << endl;     
//         }
//         else {
//             w.setEquipped();
//             weapons[1].setEquipped();
//             weapons[1] = w;
//         }
//     }

//     else if (w.getIsTwoH() == true) {
//         cout << "This is a two handed weapon. Equipping it will remove weapons equipped in both hands." << flush << endl;
//         usleep(1500000);
//         cout << "Would you like to equip it?" << endl;
//         string answer;
//         while (answer != "Y" and answer != "y" and answer != "N" and answer != "n") {
//             cout << "Y|| Yes\t N|| No" << endl;
//             cin >> answer;
//         }
//         if (answer == "Y" or answer == "y") {
//             w.setEquipped();
//             weapons[0].setEquipped(); 
//             weapons[0] = w;
//             weapons[1] = nothing;
//             cout << "You equipped " << w.getName() << endl;
//             getchar();
//             cin.get();
//         }
//         system("cls");
//     }
//     else {
//         cout << "You equipped " << w.getName() << endl;
//         w.setEquipped();
//         weapons[0].setEquipped();
//         weapons[0] = w;
//     }
//     system("cls");
// }

// void Character::setArmor(Armor a)
// {
//     a.setEquipped();
//     armor.setEquipped();
//     armor = a;
// }

void Character::displayEquipments() {
    for (int i = 0; i < inventory.getOccSlots(); i++) {
        if (inventory.getOccupied()[i]) {
            if (inventory.getEquipments()[i]->getName() != "nothing") {
                cout << i << "|| " << inventory.getEquipments()[i]->getName() << " \t ";
            }
        }
    }
}


void Character::displayInv()
{
    inventory.displayItems();
}

void Character::displayEquipped()
{
    if (side == 1) {
        if (twoHand) {
            cout << "1|| ARMOR: " << equipments[0].getName() << " \t 2|| LEFT HAND: " << equipments[1].getName() << " \t 3|| RIGHT HAND: " << equipments[1].getName() << " \t 4|| BACK " << endl; 
        }
        else {
            cout << "1|| ARMOR: " << equipments[0].getName() << " \t 2|| LEFT HAND: " << equipments[1].getName() << " \t 3|| RIGHT HAND: " << equipments[2].getName() << " \t 4|| BACK " << endl; 
        }
    }
    else {
        if (twoHand) {
            cout << "1|| ARMOR: " << equipments[0].getName() << " \t 2|| RIGHT HAND: " << equipments[1].getName() << " \t 3|| LEFT HAND: " << equipments[1].getName() << " \t 4|| BACK " << endl; 
        }
        else {
            cout << "1|| ARMOR: " << equipments[0].getName() << " \t 2|| RIGHT HAND: " << equipments[1].getName() << " \t 3|| LEFT HAND: " << equipments[2].getName() << " \t 4|| BACK " <<  endl; 
        }
    }
}

void Character::canEquip(int a, Equipment* e)
{
    if (a == e->getSlot()) {
        setEquipment(e);
        }
    else {
        cout << "Sorry, you cannot equip this equipment in this slot " << endl;
        getchar();
        cin.get();
        return;
    }
}
