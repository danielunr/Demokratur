#ifndef TALK_H
#define TALK_H

#include"contact.h"
#include"math.h"
#include"villager.h"


class Talk : public Contact {
private:
    Villager v1;
    Villager v2;
    Villager *vPointer1;
    Villager *vPointer2;
public:
    Talk();
    ~Talk();
    Talk(Villager v1, Villager v2);
    Villager getV1();
    Villager getV2();
    void setV1(Villager v1);
    void setV2(Villager v2);
    bool compare();
    Party argue();
};

#endif // TALK_H
