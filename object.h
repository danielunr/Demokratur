#ifndef OBJECT_H
#define OBJECT_H

#include "probability.h"

class object
{
private:
    long id;
    probability value;

public:
    object();
    ~object();
    long getId();
    void setId(long id);
    probability getProbability();
    void setProbability(probability value);

};

#endif // OBJECT_H
