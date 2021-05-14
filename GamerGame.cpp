// GamerGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

//Classes

#include "MapFiles.h"
#include "character.h"

//Standalone Functions


//Main

int main()
{

    character* player = new character{"characterStats.txt"};
    character* enemy = new character{ };
    enemy->changeName("Enemy");
    /*
    map worldMap(10);
    //worldMap.mapPrint();
    //worldMap.mapFill("map1.txt");
    //worldMap.mapPrint();
    do {
        worldMap.mapUpdate();
        //vkey = GetAsyncKeyState(0x44);
        //worldMap.playerMove(vkey);
        //worldMap.mapPrint();
        //std::cout << vkey << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    } while (true);
    worldMap.mapDestroy();
    */
    //player->battle(*enemy);
    player->printCharacter();
    enemy->printCharacter();

    
    //std::cout << name << std::endl;
    delete enemy;
    delete player;

}

