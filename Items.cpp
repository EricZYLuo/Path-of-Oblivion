#include "Items.h"

Items::Items() {
	this->name = "";
	this->value = 0;
	return;
}

Items::Items(std::string title, int val) {
	this->name = title;
	this->value = val;
	return;
}

void Items::printItem() {
	std::cout << "Item: " << name << std::endl;
	std::cout << "Value: " << value << std::endl;
	return;
}

void Items::changeName(std::string newName) {
	this->name = newName;
	return;
}

void Items::changeVal(int change) {
	this->value = change;
	return;
}

std::string Items::getName() {
	return this->name;
}

int Items::getValue() {
	return this->value;
}

Items::~Items() {
	//No special properties to remove
}

weapon::weapon(std::string title, int val, int attack): Items(title, val) {
	this->atk = attack;
	return;
}

void weapon::printItem() {
	std::cout << "Weapon: " << this->getName() << std::endl;
	std::cout << "Attack Power: " << this->atk << std::endl;
	std::cout << "Value: " << this->getValue() << std::endl;
	return;
}

void weapon::setAtk(int change) {
	this->atk = change;
	return;
}

void weapon::changeAtk(int change) {
	this->atk += change;
	return;
}

int weapon::getAtk() {
	return this->atk;
}

weapon::~weapon() {
	//Similarily, nothing special to remove
}

equipment::equipment(std::string title, int val, int slots, int changes[7]):Items(title, val) {

	this->slot = slots;
	for (int i = 0; i < 7; i++) {
		this->modifiers[i] = changes[i];
	}
	
	return;
}

void equipment::printItem() {
	std::cout << "Equipment: " << this->getName() << std::endl;
	std::cout << "Type: ";
	switch (this->slot) {
	
	case 0:
		std::cout << "Helmet" << std::endl;
		break;
	case 1:
		std::cout << "Chestplate" << std::endl;
		break;
	case 2:
		std::cout << "Leggings" << std::endl;
		break;
	case 3:
		std::cout << "Boots" << std::endl;
		break;
	default:
		std::cout << "Where does this even go?" << std::endl;
	
	}

	for (int i = 0; i < 7; i++) {
		if (this->modifiers[i] != 0) {
			std::cout << i << ": " << this->modifiers[i] << std::endl;
		}
	}


	std::cout << "Value: " << this->getValue() << std::endl;
	return;
}

void equipment::setSlot(int val) {
	this->slot = val;
	return;
}

void equipment::setMods(int change[7]) {
	for (int i = 0; i < 7; i++)
	{
		this->modifiers[i] = change[i];
	}
	return;
}

void equipment::changeMods(int change[7]) {
	for (int i = 0; i < 7; i++)
	{
		this->modifiers[i] += change[i];
	}
	return;
}

int equipment::getSlot() {
	return this->slot;
}

int* equipment::getMods() {
	return this->modifiers;
}

equipment::~equipment() {
	//Nothing special again to remove
}