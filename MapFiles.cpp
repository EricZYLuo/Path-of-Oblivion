#include "MapFiles.h"

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

//Tile Methods

tile::tile() {
    display = '#';
    pos = posn();
    return;
}

tile::tile(char disp, posn position) {
    display = disp;
    pos = position;
    return;
}

tile::tile(char disp, int x, int y) {
    display = disp;
    pos = posn(x, y);
    return;
}

void tile::changeDisp(char disp) {
    display = disp;
    return;
}

void tile::changePos(posn position) {
    pos = position;
    return;
}

void tile::changePos(int x, int y) {
    pos.setX(x);
    pos.setY(y);
    return;
}

char tile::getDisp() {
    return display;
}

posn tile::getPos() {
    return pos;
}

void tile::tileInteract(character player) {

}



//Map Methods

map::map(int len) {
    size = len;
    board = new tile * [size];
    for (int i = 0; i < size; i++) {
        board[i] = new tile[size];
        for (int j = 0; j < size; j++) {
            board[i][j].changeDisp('#');
            board[i][j].changePos(i, j);
        }
    }
}
void map::mapPrint() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == playerPos.getX() && j == playerPos.getY()) {
                std::cout << '@';
            }
            else {
                std::cout << board[i][j].getDisp();
            }
        }
        std::cout << std::endl;
    }
    return;
}
void map::mapFill(std::string fileName) {
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
            board[a][i].changeDisp(line[i]);
        }
        a++;
    }
    file.close();
    return;
}
void map::mapUpdate() {

    //Key check
    //A Press
    if (GetAsyncKeyState(0x41) != 0 && playerPos.getY() > 0) {
        playerPos.changeY(-1);
    }
    //D Key
    else if (GetAsyncKeyState(0x44) != 0 && playerPos.getY() < size - 1) {
        playerPos.changeY(1);
    }
    //W Key
    else if (GetAsyncKeyState(0x57) != 0 && playerPos.getX() > 0) {
        playerPos.changeX(-1);
    }
    //S Key
    else if (GetAsyncKeyState(0x53) != 0 && playerPos.getX() < size - 1) {
        playerPos.changeX(1);
    }

    else {
        //Do nothing
    }
    system("CLS");
    mapPrint();
}
void map::mapDestroy() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
    return;
}



