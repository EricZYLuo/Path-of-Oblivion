#pragma once
#include <cstdlib>
#include <vector>
#include <memory>
#include "Items.h"

class inventory {
	int length;
	std::vector<std::shared_ptr<Items>> invList;
public:
	inventory();
	inventory(int len, std::vector<std::shared_ptr<Items>> list);
	void printInventory();
	void invAdd(std::shared_ptr<Items> item);
	void invDel(int pos);
	void fullDel();
	int findPos(std::string name);
	std::shared_ptr<Items> findItem(int position);
	int getLen();
	~inventory();
	
};

