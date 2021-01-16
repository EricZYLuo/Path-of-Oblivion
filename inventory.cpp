#include "inventory.h"


inventory::inventory() {
	length = 0;
	invList.clear();
	return;
}

inventory::inventory(int len, std::vector<Items> list) {
	length = len;
	for (int i = 0; i < length; i++) {
		invList.emplace_back(list[i]);
	}
	return;
}

void inventory::invAdd(Items item) {
	invList.emplace_back(item);
	return;
}

void inventory::invDel(int pos) {
	std::vector<Items> temp;
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (i = pos) {
			counter = 1;
		}
		else {
			temp[i - counter] = invList[i];
		}
	}
	invList.clear();
	temp.swap(invList);
	return;
}

void inventory::fullDel() {
	invList.clear();
	return;
}

int inventory::findPos(std::string name) {
	for (int i = 0; i < length; i++) {
		if (invList[i].getName() == name) {
			return i;
		}
		else {
			//Fall Through
		}
	}
	return -1;
}

Items inventory::findItem(int position) {
	return invList[position];
}

int inventory::getLen() {
	return length;
}
