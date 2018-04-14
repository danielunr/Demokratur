#include <iostream>
#include "object.h"

using namespace std;

object::object() {

}

object::~object() {

}

long object::getId(){
    return id;
}

void object::setId(long id){
    this->id = id;
}

probability object::getProbability(){
    return value;
}

void object::setProbability(probability value){
    this->value = value;
}
