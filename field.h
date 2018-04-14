#ifndef FIELD_H
#define FIELD_H

#include "object.h"
#include "position.h"

#include <QPixmap>
#include <QColor>

using namespace std;

class field
{
private:
    field * instance = nullptr;

    position location;
    object obj;

    QPixmap pixmap;
    position Qlocation;
    QColor color;

public:
    field * lNeighbour;
    field * rNeighbour;
    field * above;
    field * below;
    field * rightOf;
    field * leftOf;

    field();
    ~field();

    field* einfuegen(field *anker, object wert);
    void ausgeben(field *anker);
    int length(field *anker);
    field* findElementById(field *anker, long id);
    static field* findElementByPos(field *anker, position pos);
    field* getInstance();    

   // field* getLNeighbour();
    //void setLNeighbour(field* lNeighbour);

    QPixmap getQPixmap();
    void setQPixmap(QPixmap pixmap);

    position getPosition();
    void setPosition(position location);

    position getQLocation();
    void setQLocation(position qlocation);

    QColor getQcolor();
    void setQColor(QColor color);

    object getObject();
    void setObject(object obj);
};

#endif // FIELD_H

