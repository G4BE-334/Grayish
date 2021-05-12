#include "enemy.h"


Enemy::Enemy()
{
    enemyId++;
}

void Enemy::setEnemy(string n, int r, bool B) 
{
    name = n;
    tier = r;
    isBoss = B;
    
    switch(r) {
        case 0:
            attributes = {2, 0, 1, 0, 10, 0, 2, 0, 0};
            break;
    }
    LP = attributes[4];
    MP = attributes[5];
}

void Enemy::setLP(int l)
{
    LP += l; 
}

void Enemy::setMP(int m)
{
    MP += m;
}

int Enemy::getLP()
{
    return LP;
}

int Enemy::getMP()
{
    return MP;
}

int Enemy::getTier()
{
    return tier;
}

string Enemy::getName()
{
    return name;
}

void Enemy::displayLPBar()
{
    int LPBar;
    LPBar = (LP*1.00)/attributes[4];
    cout << setw(60) << name << " <<";
    for (int i = 0; i < LPBar * 10; i++) { cout << "|"; }
    for (int i = 0; i < 9 - LPBar * 10; i++) { cout << " "; }
    cout << ">> " << LP << "LP" << endl;;

}
