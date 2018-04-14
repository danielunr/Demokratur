#include <iostream>
#include "villager.h"
#include "talk.h"
#include "party.h"
#include "math.h"

using namespace std;

Talk::Talk() {

}

Talk::~Talk() {

}

Talk::Talk(Villager v1, Villager v2) {
    this->v1 = v1;
    this->v2 = v2;
}

Villager Talk::getV1() {
    return v1;
}

void Talk::setV1(Villager v1) {
    this->v1 = v1;
}

Villager Talk::getV2() {
    return v2;
}

void Talk::setV2(Villager v2) {
    this->v2 = v2;
}

bool Talk::compare(){
    bool r = false;
    if (v1.getParty().getName() == v2.getParty().getName())
        r = true;
    return r;
}

Party Talk::argue(){
    int epiphany = rand() % 2 + 0;
    return (epiphany) ? v2.getParty() : v1.getParty();
}
