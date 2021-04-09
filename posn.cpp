#include "posn.h"

//Posn Methods
posn::posn() {
    this->x = 0;
    this->y = 0;
    return;
}

posn::posn(int a, int b) {
    this->x = a;
    this->y = b;
    return;
}

void posn::setX(int a) {
    this->x = a;
    return;
}

void posn::setY(int a) {
    this->y = a;
    return;
}

void posn::changeX(int a) {
    this->x += a;
    return;
}

void posn::changeY(int a) {
    this->y += a;
    return;
}

int posn::getX() {
    return this->x;
}

int posn::getY() {
    return this->y;
}

posn::~posn() {
    //Nothing cool
}