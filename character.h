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
	void printCharacter();
	void changeName(std::string newName);
	void changeGold(int change);
	void changeStats(stats newStats);
	void changeInventory(inventory newInv);
	void changePosition(posn newPos);
	std::string getName();
	int getGold();
	stats getStats();
	inventory getInventory();
	posn getPosition();
	~character();
};

