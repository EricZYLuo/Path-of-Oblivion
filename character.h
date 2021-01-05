#pragma once

class stats {
	//Hp,Mp,atk,def,spA,spD,spe
	int bStats[7];
	int level;
	int xp;

public:
	stats(int stat[7], int alevel, int axp);
	void checkLevel();
	void statUpdate(int key, int change);
	void xpUpdate(int change);
	int* getStats();
	int getLevel();
	int getXp();

};

class character
{



};