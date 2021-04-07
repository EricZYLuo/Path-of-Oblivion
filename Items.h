#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

class Items
{
private:
	std::string name;
	int value;

public:
	Items();
	Items(std::string title, int val);
	void changeName(std::string newName);
	void changeVal(int change);
	std::string getName();
	int getValue();
};

class weapon:public Items {
	int atk;
public:
	weapon(std::string title, int val, int attack);
	void setAtk(int change);
	void changeAtk(int change);
	int getAtk();
};

class equipment :public Items {
	int slot;
	int modifiers[7];
public:
	equipment(std::string title, int val, int slots, int changes[7]);
	void setSlot(int val);
	void setMods(int change[7]);
	void changeMods(int change[7]);
	int getSlot();
	int* getMods();
 };
