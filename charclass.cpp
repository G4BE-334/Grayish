#include "charclass.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>

CharClass::CharClass()
{
    
}

void CharClass::setChar(string n, string* sk)
{
    name = n;
    skills = sk;
}

void CharClass::setLSkills(int s)
{
    if (s <= 5) {
        for (int i = 0; i <= s; i++) {
            learnedSkills[i] = skills[i]; 
        }
    }        
}

void CharClass::setCCId(int n) {
    CCId = n;
}

int CharClass::getCCId() {
    return CCId;
}

string CharClass::getName()
{
    return name;
}

