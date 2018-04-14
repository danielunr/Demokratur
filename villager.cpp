#include <iostream>

using namespace std;

#include "party.h"
#include "villager.h"
#include <string>

Villager::Villager() {

}

Villager::~Villager(){

}

Villager::Villager(Party p) {
    party = p;
}

Villager::Villager(long id){
    this->id = id;
}

Party Villager::getParty() {
    return party;
}

void Villager::setParty(Party p) {
    party = p;
}
