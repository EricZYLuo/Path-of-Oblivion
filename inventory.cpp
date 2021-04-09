#include "inventory.h"


inventory::inventory() {
	this->length = 0;
	this->invList.clear();
	return;
}

inventory::inventory(int len, std::vector<Items> list) {
	this->length = len;
	for (int i = 0; i < this->length; i++) {
		this->invList.emplace_back(list[i]);
	}
	return;
}

void inventory::invAdd(Items item) {
	this->invList.emplace_back(item);
	this->length++;
	return;
}

void inventory::invDel(int pos) {
	std::vector<Items> temp;
	int counter = 0;
	for (int i = 0; i < this->length; i++) {
		if (i = pos) {
			counter = 1;
		}
		else {
			temp[i - counter] = this->invList[i];
		}
	}
	this->invList.clear();
	temp.swap(invList);
	this->length--;
	return;
}

void inventory::fullDel() {
	this->invList.clear();
	this->length = 0;
	return;
}

int inventory::findPos(std::string name) {
	for (int i = 0; i < this->length; i++) {
		if (this->invList[i].getName() == name) {
			return i;
		}
		else {
			//Fall Through
		}
	}
	return -1;
}

Items inventory::findItem(int position) {
	return this->invList[position];
}

int inventory::getLen() {
	return this->length;
}

inventory::~inventory() {
	this->invList.clear();
}
