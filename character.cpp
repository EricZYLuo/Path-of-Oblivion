#include "character.h"

character::character() {

	name = "";
	int stat[7] = { 5,5,5,5,5,5,5 };
	charStats = stats(stat);
	int gold = 0;
	Inv = inventory();
	pos = posn();
	return;
}

character::character(std::string fileName) {

	int axp;
	int alvl;
	int aSp;
	int stat[7];
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		std::cout << "Error opeing a file" << std::endl;
		file.close();
		return;
	}

	std::cin >> name;
	for (int i = 0; i < 7; i++) {
		std::cin >> stat[i];
	}
	std::cin >> alvl;
	std::cin >> axp;
	std::cin >> aSp;
	std::cin >> gold;

	



}