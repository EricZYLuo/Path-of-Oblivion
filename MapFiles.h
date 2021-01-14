#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
#include <WinUser.h>
#include "character.h"

class posn {
    int x;
    int y;
public:
    posn();
    posn(int a, int b);
    void setX(int a);
    void setY(int a);
    void changeX(int a);
    void changeY(int a);
    int getX();
    int getY();
};

class tile {
    char display;
    posn pos;
    int encounterRate;
    int difficulty;
public:
    tile();
    tile(char disp, posn position);
    tile(char disp, int x, int y);
    void changeDisp(char disp);
    void changePos(posn position);
    void changePos(int x, int y);
    void changeRate(int change);
    void changeDiff(int change);
    char getDisp();
    posn getPos();
    int getRate();
    int getDiff();
    void tileInteract(character player);

};

class map {
    tile** board;
    int size;
    posn playerPos;
public:
    map(int len);
    void mapPrint();
    void mapFill(std::string fileName);
    void mapUpdate();
    void mapDestroy();


};