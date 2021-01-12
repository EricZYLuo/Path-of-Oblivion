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

public:
    int x;
    int y;

    posn() {
        x = 0;
        y = 0;
    }
    posn(int a, int b) {
        x = a;
        y = b;
    }
};

class tile {

public:
    char display;
    posn pos;

    void tileInteract(character player) {

    }

};

class map {

public:
    tile** board;
    int size;
    posn playerPos;

    map(int len) {
        size = len;
        board = new tile * [size];
        for (int i = 0; i < size; i++) {
            board[i] = new tile[size];
            for (int j = 0; j < size; j++) {
                board[i][j].display = '#';
                board[i][j].pos.x = i;
                board[i][j].pos.y = j;
            }
        }
    }
    void mapPrint() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == playerPos.x && j == playerPos.y) {
                    std::cout << '@';
                }
                else {
                    std::cout << board[i][j].display;
                }
            }
            std::cout << std::endl;
        }
        return;
    }
    void mapFill(std::string fileName) {
        int a = 0;
        std::ifstream file;
        file.open(fileName);
        if (file.fail()) {
            std::cout << "Error opeing a file" << std::endl;
            file.close();
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.size() != size) {
                file.close();
                return;
            }
            for (int i = 0; i < line.size(); i++) {
                board[a][i].display = line[i];
            }
            a++;
        }
        file.close();
        return;
    }
    void mapUpdate() {

        //Key check
        //A Press
        if (GetAsyncKeyState(0x41) != 0 && playerPos.y > 0) {
            playerPos.y--;
        }
        //D Key
        else if (GetAsyncKeyState(0x44) != 0 && playerPos.y < size - 1) {
            playerPos.y++;
        }
        //W Key
        else if (GetAsyncKeyState(0x57) != 0 && playerPos.x > 0) {
            playerPos.x--;
        }
        //S Key
        else if (GetAsyncKeyState(0x53) != 0 && playerPos.x < size - 1) {
            playerPos.x++;
        }

        else {
            //Do nothing
        }
        system("CLS");
        mapPrint();
    }
    void mapDestroy() {
        for (int i = 0; i < size; i++) {
            delete[] board[i];
        }
        delete[] board;
        return;
    }



};