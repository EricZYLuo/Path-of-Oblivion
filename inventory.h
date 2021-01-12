#pragma once
#include <cstdlib>
#include "Items.h"

class inventory {
	int length;
	Items* invList;
public:
	inventory();
	inventory(int len, Items* list);
	void invAdd(Items item);
	void invDel(int pos);
	void fullDel();
	int findPos(std::string name);
	Items findItem(int position);
	int getLen();
	
};

