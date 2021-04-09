#include "MapFiles.h"



//Tile Methods

tile::tile() {
    this->display = '#';
    this->pos = posn();
    this->encounterRate = 0;
    this->difficulty = 1;
    return;
}

tile::tile(char disp, posn position) {
    this->display = disp;
    this->pos = position;
    this->encounterRate = 50;
    this->difficulty = this->pos.getX() * this->pos.getY();
    return;
}

tile::tile(char disp, int x, int y) {
    this->display = disp;
    this->pos = posn(x, y);
    this->encounterRate = 50;
    this->difficulty = x * y;
    return;
}

void tile::changeDisp(char disp) {
    this->display = disp;
    return;
}

void tile::changePos(posn position) {
    this->pos = position;
    return;
}

void tile::changePos(int x, int y) {
    this->pos.setX(x);
    this->pos.setY(y);
    return;
}

void tile::changeRate(int change) {
    this->encounterRate = change;
    return;
}

void tile::changeDiff(int change) {
    this->difficulty = change;
    return;
}

char tile::getDisp() {
    return this->display;
}

posn tile::getPos() {
    return this->pos;
}

int tile::getRate() {
    return this->encounterRate;
}

int tile::getDiff() {
    return this->difficulty;
}

void tile::tileInteract(character player) {
    srand(time(NULL));
    int randNum = rand() % 100 + 1;
    if (randNum > this->encounterRate) {
        //No encounter occurs
        return;
    }
    else {
        
    }
}

tile::~tile() {
    //Nothing special again
}

//Map Methods

map::map(int len) {
    this->size = len;
    this->board = new tile * [this->size];
    for (int i = 0; i < this->size; i++) {
        this->board[i] = new tile[this->size];
        for (int j = 0; j < this->size; j++) {
            this->board[i][j].changeDisp('#');
            this->board[i][j].changePos(i, j);
        }
    }
}
void map::mapPrint() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (i == this->playerPos.getX() && j == this->playerPos.getY()) {
                std::cout << '@';
            }
            else {
                std::cout << this->board[i][j].getDisp();
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
        if (line.size() != this->size) {
            file.close();
            return;
        }
        for (int i = 0; i < line.size(); i++) {
            this->board[a][i].changeDisp(line[i]);
        }
        a++;
    }
    file.close();
    return;
}
void map::mapUpdate() {

    //Key check
    //A Press
    if (GetAsyncKeyState(0x41) != 0 && this->playerPos.getY() > 0) {
        this->playerPos.changeY(-1);
    }
    //D Key
    else if (GetAsyncKeyState(0x44) != 0 && this->playerPos.getY() < this->size - 1) {
        this->playerPos.changeY(1);
    }
    //W Key
    else if (GetAsyncKeyState(0x57) != 0 && this->playerPos.getX() > 0) {
        this->playerPos.changeX(-1);
    }
    //S Key
    else if (GetAsyncKeyState(0x53) != 0 && this->playerPos.getX() < this->size - 1) {
        this->playerPos.changeX(1);
    }

    else {
        //Do nothing
    }
    system("CLS");
    mapPrint();
}
void map::mapDestroy() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
    return;
}

map::~map() {
    //Clear the board
    for (int i = 0; i < this->size; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

