#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

class inventory {

};

class Items
{
	std::string name;
	int value;

public:
	Items(std::string title, int val);
	std::string getName();
	int getValue();
};

class weapon:Items {
	int atk;

};

