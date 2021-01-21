#include "posn.h"

//Posn Methods
posn::posn() {
    x = 0;
    y = 0;
    return;
}

posn::posn(int a, int b) {
    x = a;
    y = b;
    return;
}

void posn::setX(int a) {
    x = a;
    return;
}

void posn::setY(int a) {
    y = a;
    return;
}

void posn::changeX(int a) {
    x += a;
    return;
}

void posn::changeY(int a) {
    y += a;
    return;
}

int posn::getX() {
    return x;
}

int posn::getY() {
    return y;
}