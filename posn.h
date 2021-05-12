#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

class posn {
    int x;
    int y;
public:
    posn();
    posn(int a, int b);
    void printPosn();
    void setX(int a);
    void setY(int a);
    void changeX(int a);
    void changeY(int a);
    int getX();
    int getY();
    ~posn();
};

