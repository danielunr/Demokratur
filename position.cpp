#include "position.h"

using namespace std;

position::position()
{
}

position::position(int x, int y){
 this->x = x;
 this->y = y;
}

int position::getX(){
    return x;
}

void position::setX(int x){
    this->x = x;
}

int position::getY(){
    return y;
}

void position::setY(int y){
    this->y = y;
}

bool position::equal(position pos){
    return (this->x == pos.getX() && this->y == pos.getY());
}

position::~position(){

}
