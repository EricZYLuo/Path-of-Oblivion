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

	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		std::cout << "Error opeing a file" << std::endl;
		file.close();
		return;
	}


}