#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "stats.h"
#include "inventory.h"
#include "Items.h"
#include "posn.h"

class character
{
private:
	std::string name;
	stats charStats;
	int gold;
	inventory Inv;
	posn pos;
	//Private Helper Functions
	void postBattle(character enemy);

public:
	character();
	character(std::string fileName);
	void battle(character enemy);
	void changeName(std::string newName);
	void changeGold(int change);
	std::string getName();
	int getGold();
	~character();
};

