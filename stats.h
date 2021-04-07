#pragma once
class stats
{
private:
	//Hp,Mp,atk,def,spA,spD,spe
	int bStats[7];
	int trueStats[7];
	int level;
	int xp;
	int skillPoints;

public:
	stats();
	stats(int stat[7]);
	stats(int stat[7], int alevel, int axp, int sp);
	void setStats(int stat[7], int alevel, int axp, int sp);
	void checkLevel();
	void statUpdate(int key, int change);
	void trueStatUpdate(int key, int change);
	void xpUpdate(int change);
	void spUpdate(int change);
	int* getTrueStats();
	int* getCurrentStats();
	int getLevel();
	int getXp();
	int getSP();
};

