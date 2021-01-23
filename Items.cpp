#include "Items.h"

Items::Items() {
	name = "";
	value = 0;
	return;
}

Items::Items(std::string title, int val) {
	name = title;
	value = val;
	return;
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
	return;
}

void weapon::setAtk(int change) {
	atk = change;
	return;
}

void weapon::changeAtk(int change) {
	atk += change;
	return;
}

int weapon::getAtk() {
	return atk;
}

equipment::equipment(std::string title, int val, int slots, int changes[7]) {

	slot = slots;
	for (int i = 0; i < 7; i++) {
		modifiers[i] = changes[i];
	}
	Items(title, val);
	return;
}

void equipment::setSlot(int val) {
	slot = val;
	return;
}

void equipment::setMods(int change[7]) {
	for (int i = 0; i < 7; i++)
	{
		modifiers[i] = change[i];
	}
	return;
}

void equipment::changeMods(int change[7]) {
	for (int i = 0; i < 7; i++)
	{
		modifiers[i] += change[i];
	}
	return;
}

int equipment::getSlot() {
	return slot;
}

int* equipment::getMods() {
	return modifiers;
}

