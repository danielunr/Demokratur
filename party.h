#ifndef PARTY_H
#define PARTY_H

#include"party.h"
#include <string>

using namespace std;

class Party {
private:
    char initial;
    string name;
    int id;
public:
    Party();
    ~Party();
    Party(string name);
    string getName();
    void setName(string name);
    char getInitial();
    void setInitial(char initial);
    int getId();
    void setId(int id);
};

#endif // PARTY_H
