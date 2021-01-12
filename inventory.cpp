#include "inventory.h"


inventory::inventory() {
	length = 0;
	invList = NULL;
}

inventory::inventory(int len, Items* list) {
	length = len;
	invList = new Items[length];
	for (int i = 0; i < length; i++) {
		invList[i] = list[i];
	}
}

void inventory::invAdd(Items item) {
	Items* temp = new Items[length + 1];
	for (int i = 0; i < length; i++) {
		temp[i] = invList[i];
	}
	temp[length] = item;
	delete[] invList;
	invList = new Items[length + 1];
	length++;
	for (int i = 0; i < length; i++) {
		invList[i] = temp[i];
	}
	delete[] temp;

}

void inventory::invDel(int pos) {
	Items* temp = new Items[length - 1];
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (i = pos) {
			counter = 1;
		}
		else {
			temp[i - counter] = invList[i];
		}
	}
	delete[] invList;
	length--;
	invList = new Items[length];
	for (int i = 0; i < length; i++) {
		invList[i] = temp[i];
	}
	delete[] temp;

}

void inventory::fullDel() {
	delete[] invList;
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
