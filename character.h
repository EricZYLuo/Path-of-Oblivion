#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "stats.h"
#include "inventory.h"
#include "Items.h"
#include "MapFiles.h"

class character
{
	std::string name;
	stats charStats;
	int gold;
	inventory Inv;
	posn playerPos;

public:
	character();
	character(std::string fileName);
	void battle(character enemy);
	void changeName(std::string newName);
	void setStats(stats newStats);
	void singleStatsChange(int key, int change);
};

