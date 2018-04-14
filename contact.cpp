#include <iostream>
#include "contact.h"
#include "player.h"

using namespace std;

Contact::Contact() {

}

Contact::~Contact() {

}

Contact::Contact(player p1, player p2) {
    this->p1 = p1;
    this->p2 = p2;
}

player Contact::getP1() {
    return p1;
}

void Contact::setP1(player p) {
    p1 = p;
}

player Contact::getP2() {
    return p2;
}

void Contact::setP2(player p) {
    p2 = p;
}
