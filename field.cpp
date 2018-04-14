#include <iostream>
#include "field.h"
#include "object.h"

#include <QtDebug>

using namespace std;

field::field()
{    
    this->pixmap = QPixmap(60,60);
    this->color = QColor(Qt::lightGray);
}

field::~field() {

}

field* field::einfuegen(field *anker, object wert)
{
    //TODO Pointer private + getter, setter
    field *tmpAnker = anker;
    if (anker == nullptr)
    {
        QMessageLogger(__FILE__, __LINE__, 0).debug() << "anker == nullptr";
        anker = new field();
        anker->lNeighbour = nullptr;
        anker->rNeighbour = nullptr;
    }
    else
    {
         QMessageLogger(__FILE__, __LINE__, 0).debug() << "anker != nullptr";
        while (anker->rNeighbour != nullptr){
            anker = anker->rNeighbour;
        }
        if (anker->rNeighbour == nullptr)
        {
            anker->rNeighbour = new field();
            anker->rNeighbour->lNeighbour = anker;
            anker->rNeighbour->rNeighbour = nullptr;
            anker = tmpAnker;
        }
    }
    return anker;
}

void field::ausgeben(field *anker)
{
    if (anker == nullptr)
    {
        cout << "Leere Liste." << endl;
    }
    else
    {
        if (anker->rNeighbour != nullptr)
        {
            //cout << anker->obj.getPartei().getName() << endl;
            ausgeben(anker->rNeighbour);
        }
        else
        {
            //cout << anker->obj.getPartei().getName() << endl;
        }
    }
}

int field::length(field *anker)
{
    field *tmpAnker = anker;
    int length = 0;
    if (anker != nullptr)
    {
        do{
            length++;
            anker = anker->rNeighbour;
        } while (anker->rNeighbour != nullptr);
    }
    anker = tmpAnker;
    return length;
}

field* field::findElementById(field *anker, long id)
{
    field *tmpAnker = anker;
    if (tmpAnker != nullptr)
    {
        do{
            if (tmpAnker->getObject().getId() == id) {
                return tmpAnker;
            }
            if (tmpAnker->rNeighbour->getObject().getId() == id){
                return tmpAnker->rNeighbour;
            }
            tmpAnker = tmpAnker->rNeighbour;
        } while (tmpAnker->rNeighbour != nullptr);
    }
    return nullptr;
}

field* field::findElementByPos(field *anker, position pos)
{
    field *tmpAnker = anker;
    if (tmpAnker != nullptr)
    {
        do{
            //TODO equal method?
            if (tmpAnker->getPosition().equal(pos)) {
                return tmpAnker;
            }
            if (tmpAnker->rNeighbour->getPosition().equal(pos)){
                return tmpAnker->rNeighbour;
            }
            tmpAnker = tmpAnker->rNeighbour;
        } while (tmpAnker->rNeighbour != nullptr);
    }
    return nullptr;
}

position field::getPosition(){
    return location;
}
void field::setPosition(position location){
    this->location = location;
}

position field::getQLocation(){
    return Qlocation;
}

void field::setQLocation(position qlocation){
    this->Qlocation = qlocation;
}

object field::getObject(){
    return obj;
}
void field::setObject(object obj){
    this->obj = obj;
}

QPixmap field::getQPixmap(){
    return pixmap;
}

void field::setQPixmap(QPixmap pixmap){
    this->pixmap = pixmap;
}

QColor field::getQcolor(){
    return color;
}

void field::setQColor(QColor color){
    this->color = color;
}

field *field::getInstance(){

    if(this->instance == nullptr){
        this->instance = new field();
        QMessageLogger(__FILE__, __LINE__, 0).debug() << "1 field::getInstance instance" << this->instance;
    }
    return this->instance;
}

