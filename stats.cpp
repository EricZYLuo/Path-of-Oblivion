#include "stats.h"

stats::stats() {
	for (int i = 0; i < 7; i++) {
		trueStats[i] = 5;
		bStats[i] = 5;
	}
	level = 1;
	xp = 0;
	skillPoints = 0;
	return;
}

stats::stats(int stat[7]) {
	for (int i = 0; i < 7; i++) {
		trueStats[i] = stat[i];
		bStats[i] = stat[i];
	}
	level = 1;
	xp = 0;
	skillPoints = 0;
	return;
}
stats::stats(int stat[7], int alevel, int axp, int sp) {
	for (int i = 0; i < 7; i++) {
		trueStats[i] = stat[i];
		bStats[i] = stat[i];
	}
	level = alevel;
	xp = axp;
	skillPoints = sp;
	return;
}

void stats::setStats(int stat[7], int alevel, int axp, int sp) {
	for (int i = 0; i < 7; i++) {
		trueStats[i] = stat[i];
		bStats[i] = stat[i];
	}
	level = alevel;
	xp = axp;
	skillPoints = sp;
	return;
}

void stats::checkLevel() {
	double threshold = 100;
	for (int i = 1; i < level; i++) {
		threshold *= 1.05;
	}
	int thresh = threshold;
	if (xp >= thresh) {
		xp -= thresh;
		skillPoints += level;
		level++;
		checkLevel();
	}
	return;
}
void stats::statUpdate(int key, int change) {
	bStats[key] += change;
}
void stats::trueStatUpdate(int key, int change) {
	trueStats[key] += change;
}
void stats::xpUpdate(int change) {
	xp += change;
	return;
}
void stats::spUpdate(int change) {
	skillPoints += change;
	return;
}
int* stats::getTrueStats() {
	int* temp = new int[7];
	for (int i = 0; i < 7; i++) {
		temp[i] = trueStats[i];
	}
	return temp;
}

int* stats::getCurrentStats() {
	int* temp = new int[7];
	for (int i = 0; i < 7; i++) {
		temp[i] = bStats[i];
	}
	return temp;
}

int stats::getLevel() {
	return level;
}
int stats::getXp() {
	return xp;
}
int stats::getSP() {
	return skillPoints;
}