#ifndef PLAYER_H
#define PLAYER_H

#include "field.h"

class player : public object
{
protected:
    long id;
public:
    player();
    long getId();
    void setId(long id);
};

#endif // PLAYER_H
