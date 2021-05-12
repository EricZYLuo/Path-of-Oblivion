#pragma once
#include <cstdlib>
#include <vector>
#include "Items.h"

class inventory {
	int length;
	std::vector<Items> invList;
public:
	inventory();
	inventory(int len, std::vector<Items> list);
	void printInventory();
	void invAdd(Items item);
	void invDel(int pos);
	void fullDel();
	int findPos(std::string name);
	Items findItem(int position);
	int getLen();
	~inventory();
	
};

