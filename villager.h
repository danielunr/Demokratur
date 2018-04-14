#ifndef VILLAGER_H
#define VILLAGER_H

#include"party.h"
#include "player.h"

class Villager: public player {
private:
    Party party;
public:
    Villager();
    ~Villager();
    Villager(Party party);
    Villager(long id);
    Party getParty();
    void setParty(Party p);
};
#endif // VILLAGER_H
