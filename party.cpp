#include <iostream>

using namespace std;

#include "person.h"
#include "party.h"
#include <string>

Party::Party() {

}

Party::~Party() {

}

Party::Party(string s) {
    name = s;
}

string Party::getName() {
    return name;
}

void Party::setName(string s) {
    name = s;
    string init = "X";
    initial = init[0];
}

char Party::getInitial() {
    return initial;
}

void Party::setInitial(char initial) {
    this->initial = initial;
}

int Party::getId() {
    return id;
}

void Party::setId(int id) {
    this->id = id;
}
