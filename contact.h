#pragma once

using namespace std;

#include "player.h"

class Contact
{
protected:
    player p1;
    player p2;
public:
    Contact();
    ~Contact();
    Contact(player p1, player p2);
    player getP1();
    player getP2();
    void setP1(player p1);
    void setP2(player p2);
    int getId();
    void setId(int id);

};
