#include <iostream>
#include <sstream>
#include "person.h"

using namespace std;

Person::Person(){

}


Person::~Person(){

}

Person::Person(long id){
    this->id = id;
}

long Person::getId() {
    return id;
}

void Person::setId(long id) {
    this->id = id;
}

