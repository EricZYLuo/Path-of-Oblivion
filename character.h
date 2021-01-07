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

class stats {
	//Hp,Mp,atk,def,spA,spD,spe
	int bStats[7];
	int level;
	int xp;
	int skillPoints;

public:
	stats(int stat[7], int alevel, int axp, int sp);
	void checkLevel();
	void statUpdate(int key, int change);
	void xpUpdate(int change);
	void spUpdate(int change);
	int* getStats();
	int getLevel();
	int getXp();
	int getSP();

};

class character
{
	std::string name;
	stats charStats;
	//Inventory

};