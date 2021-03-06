#include "stats.h"

stats::stats() {
	for (int i = 0; i < 7; i++) {
		this->trueStats[i] = 5;
		this->bStats[i] = 5;
	}
	this->level = 1;
	this->xp = 0;
	this->skillPoints = 0;
	return;
}

stats::stats(int stat[7]) {
	for (int i = 0; i < 7; i++) {
		this->trueStats[i] = stat[i];
		this->bStats[i] = stat[i];
	}
	this->level = 1;
	this->xp = 0;
	this->skillPoints = 0;
	return;
}
stats::stats(int stat[7], int alevel, int axp, int sp) {
	for (int i = 0; i < 7; i++) {
		this->trueStats[i] = stat[i];
		this->bStats[i] = stat[i];
	}
	this->level = alevel;
	this->xp = axp;
	this->skillPoints = sp;
	return;
}

void stats::printStats() {
	std::cout << "Stats: ";
	for (int i = 0; i < 7; i++) {
		std::cout << bStats[i] << "/" << trueStats[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Xp: " << xp << std::endl;
	std::cout << "Skill Points: " << skillPoints << std::endl;
	return;
}

void stats::setStats(int stat[7], int alevel, int axp, int sp) {
	for (int i = 0; i < 7; i++) {
		this->trueStats[i] = stat[i];
		this->bStats[i] = stat[i];
	}
	this->level = alevel;
	this->xp = axp;
	this->skillPoints = sp;
	return;
}

void stats::checkLevel() {
	double threshold = 100;
	for (int i = 1; i < this->level; i++) {
		threshold *= 1.05;
	}
	int thresh = threshold;
	if (this->xp >= thresh) {
		this->xp -= thresh;
		this->skillPoints += this->level;
		this->level++;
		checkLevel();
	}
	return;
}
void stats::statUpdate(int key, int change) {
	this->bStats[key] += change;
	return;
}
void stats::trueStatUpdate(int key, int change) {
	this->trueStats[key] += change;
	this->bStats[key] += change;
	return;
}
void stats::xpUpdate(int change) {
	this->xp += change;
	return;
}
void stats::spUpdate(int change) {
	this->skillPoints += change;
	return;
}
int* stats::getTrueStats() {
	int* temp = new int[7];
	for (int i = 0; i < 7; i++) {
		temp[i] = this->trueStats[i];
	}
	return temp;
}

int* stats::getCurrentStats() {
	int* temp = new int[7];
	for (int i = 0; i < 7; i++) {
		temp[i] = this->bStats[i];
	}
	return temp;
}

int stats::getLevel() {
	return this->level;
}
int stats::getXp() {
	return this->xp;
}
int stats::getSP() {
	return this->skillPoints;
}

stats::~stats() {
	//Nothing cool about stats to delete
}