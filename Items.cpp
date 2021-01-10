#include "Items.h"

Items::Items() {
	name = "";
	value = 0;
}

Items::Items(std::string title, int val) {
	name = title;
	value = val;
}

void Items::changeName(std::string newName) {
	name = newName;
	return;
}

void Items::changeVal(int change) {
	value = change;
	return;
}

std::string Items::getName() {
	return name;
}

int Items::getValue() {
	return value;
}

weapon::weapon(std::string title, int val, int attack) {
	atk = attack;
	Items(title, val);
}

void weapon::changeAtk(int change) {
	atk += change;
}

int weapon::getAtk() {
	return atk;
}

equipment::equipment(std::string title, int val, int slots, int changes[7]) {
	slot = slots;
	for (int i = 0; i < 7; i++) {
		modifiers[i] = changes[i];
	}
}

void equipment::changeMods(int change[7]) {
	for (int i = 0; i < 7; i++)
	{
		modifiers[i] += change[i];
	}
}

int equipment::getSlot() {
	return slot;
}

int* equipment::getMods() {
	return modifiers;
}

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