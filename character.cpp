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
	int tempNum;
	int stat[7];
	int temp[7] = { 0 };
	char check;
	std::string tempString;
	Items tempItem;
	weapon tempWeapon("temp", 0, 0);
	equipment tempEquipment("temp", 0, 0, temp);
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
	charStats.setStats(stat, alvl, axp, aSp);
	std::cin >> gold;
	
	while (std::cin >> check && (check == 'i' || check == 'w' || check == 'e')) {
		switch (check) {
		case 'i':
			std::cin >> tempString;
			tempItem.changeName(tempString);
			std::cin >> tempNum;
			tempItem.changeVal(tempNum);
			Inv.invAdd(tempItem);
			break;
		case 'w':
			std::cin >> tempString;
			tempWeapon.changeName(tempString);
			std::cin >> tempNum;
			tempWeapon.changeVal(tempNum);
			std::cin >> tempNum;
			tempWeapon.setAtk(tempNum);
			Inv.invAdd(tempWeapon);
			break;
		case 'e':
			std::cin >> tempString;
			tempEquipment.changeName(tempString);
			std::cin >> tempNum;
			tempEquipment.changeVal(tempNum);
			std::cin >> tempNum;
			tempEquipment.setSlot(tempNum);
			for (int i = 0; i < 7; i++) {
				std::cin >> stat[i];
			}
			tempEquipment.setMods(stat);
			Inv.invAdd(tempEquipment);
			break;
		default:
			//Do nothing
		}
			
	}

	std::cin >> tempNum;
	pos.setX(tempNum);
	std::cin >> tempNum;
	pos.setY(tempNum);

	file.close();
	return;

}