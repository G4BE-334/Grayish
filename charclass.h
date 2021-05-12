#ifndef CHARCLASS_H
#define CHARCLASS_H
#include <string>
#include <iostream>

using namespace std;

class CharClass
{
    private:

    // General Description
    string name = "NoName";
    string* skills;
    int CCId;



    public:

    // Change Stats
    CharClass();
    void setChar(string n, string *sk);
    void setLSkills(int s);
    void setCCId(int n);

    // Dynamic Stats
    string learnedSkills[5] = {" "};

    // Return values
    string getName();
    int getCCId();

};

#endif
