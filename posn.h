#pragma once
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
    ~posn();
};

