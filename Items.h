#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

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

class Items
{
	std::string name;
	int value;

public:
	Items(std::string title, int val);
	void changeName(std::string newName);
	void changeVal(int change);
	std::string getName();
	int getValue();
};

class weapon:Items {
	int atk;
public:
	weapon(std::string title, int val, int atk);
	void changeAtk(int change);
	int getAtk();
};

class equipment :Items {
	int slot;
	int modifiers[7];
public:
	equipment(std::string title, int val, int slot, int changes[7]);
	void changeMods(int change[7]);
	int getSlot();
	int* getMods();
 };
