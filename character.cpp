#include "character.h"

stats::stats(int stat[7], int alevel, int axp) {
	for (int i = 0; i < 7; i++) {
		bStats[i] = stat[i];
	}
	level = alevel;
	xp = axp;
	return;
}
void stats::checkLevel() {
	double threshold = 100;
	for (int i = 1; i < level; i++) {
		threshold *= 1.05;
	}
	if (xp >= threshold) {
		xp -= int(threshold);
		level++;
		//StatUpdate();
	}
	return;
}

void stats::statUpdate(int key, int change) {
	bStats[key] += change;
	return;
}