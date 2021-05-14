#include "inventory.h"


inventory::inventory() {
	this->length = 0;
	this->invList.clear();
	return;
}

inventory::inventory(int len, std::vector<std::shared_ptr<Items>> list) {
	this->length = len;
	for (int i = 0; i < this->length; i++) {
		this->invList.emplace_back(list[i]);
	}
	return;
}

void inventory::printInventory() {
	std::cout << "Inventory:" << std::endl;
	std::shared_ptr<Items> tempItem;
	for (int i = 0; i < this->length; i++) {
		tempItem = this->invList.at(i);
		tempItem->printItem();
	}
	return;
}

void inventory::invAdd(std::shared_ptr<Items> item) {
	this->invList.emplace_back(item);
	this->length++;
	return;
}

void inventory::invDel(int pos) {
	std::vector<std::shared_ptr<Items>> temp;
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
		if (this->invList[i]->getName() == name) {
			return i;
		}
		else {
			//Fall Through
		}
	}
	return -1;
}

std::shared_ptr<Items> inventory::findItem(int position) {
	return this->invList.at(position);
}

int inventory::getLen() {
	return this->length;
}

inventory::~inventory() {
	for (int i = length - 1; i >= 0; i--) {
		invList.pop_back();
	}
	this->invList.clear();
}
