#include "character.h"

character::character() {

	name = "";
	int stat[7] = { 5,5,5,5,5,5,5 };
	charStats = stats(stat);
	gold = 0;
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
			std::cout << "Oops, something went wrong!" << std::endl;
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

void character::changeName(std::string newName) {
	name = newName;
	return;
}

void character::changeGold(int change) {
	gold += change;
	return;
}

std::string character::getName() {
	return name;
}

int character::getGold() {
	return gold;
}

void character::battle(character enemy) {
	int temp;
	int input;
	int damage;
	int enemyDamage;
	while (charStats.getCurrentStats()[0] > 0 && enemy.charStats.getCurrentStats()[0] > 0) {
		//Reset
		damage = 0;
		enemyDamage = 0;
		//Display menu
		std::cout << "______________________" << std::endl;
		std::cout << "\\0/              >0< " << std::endl;
		std::cout << charStats.getTrueStats()[0] << "/" << charStats.getCurrentStats()[0];
		temp = 2;
		for (int i = charStats.getTrueStats()[0]; i >= 1; i / 10) {
			temp += 2;
		}
		for (int i = enemy.charStats.getCurrentStats()[0]; i >= 1; i / 10) {
			temp += 2;
		}
		for (int i = 0; i < 22 - temp; i++) {
			std::cout << " ";
		}
		std::cout << enemy.charStats.getTrueStats()[0] << "/" << enemy.charStats.getCurrentStats()[0] << std::endl;
		std::cout << "______________________" << std::endl << std::endl;

		std::cout << "|--------------------|" << std::endl;
		std::cout << "|Choose an Action!   |" << std::endl;
		std::cout << "|1. Physical Attack  |" << std::endl;
		std::cout << "|2. Special Attack   |" << std::endl;
		std::cout << "|3. Defend           |" << std::endl;
		std::cout << "|4. Use Item         |" << std::endl;
		std::cout << "|--------------------|" << std::endl;
		std::cin >> input;
		//Player Action (WIP):
		switch (input) {
		case 1:
			damage = charStats.getCurrentStats()[2] - (enemy.charStats.getCurrentStats()[3] / 2);
			break;
		case 2:
			
			damage = (charStats.getCurrentStats()[4] * (charStats.getTrueStats()[1]/20)) - (enemy.charStats.getCurrentStats()[5] / 2);
			charStats.statUpdate(1, -1 * charStats.getTrueStats()[1] / 20);
			break;
		case 3:
			charStats.statUpdate(4, charStats.getCurrentStats()[4]);
			break;
		case 4:
			std::cout << "WIP! Try something else?" << std::endl;
			break;

		default:
			std::cout << "Invalid command, try again!" << std::endl;

		}

		//Enemy Action (WIP):
		if (enemy.charStats.getCurrentStats()[2] >= enemy.charStats.getCurrentStats()[4]) {
			enemyDamage = enemy.charStats.getCurrentStats()[2] - (charStats.getCurrentStats()[3] / 2);
		}
		else {
			enemyDamage = enemy.charStats.getCurrentStats()[4] - (charStats.getCurrentStats()[5] / 2);
		}

		//Action Occurance (Add Speed tie!)
		//Win or tie in speed
		if (charStats.getCurrentStats()[6] >= enemy.charStats.getCurrentStats()[6]) {
			enemy.charStats.statUpdate(0, -1 * damage);
			if (enemy.charStats.getCurrentStats()[0] > 0) {
				//End of battle update
				return;
			}
			charStats.statUpdate(0, -1 * enemyDamage);
			if (charStats.getCurrentStats()[0] > 0) {
				//Game Over sequence
				return;
			}
		}
		//Lose in speed
		else if (charStats.getCurrentStats()[6] < enemy.charStats.getCurrentStats()[6]) {

			charStats.statUpdate(0, -1 * enemyDamage);
			if (charStats.getCurrentStats()[0] > 0) {
				//Game Over sequence
				return;
			}
			enemy.charStats.statUpdate(0, -1 * damage);
			if (enemy.charStats.getCurrentStats()[0] > 0) {
				//End of battle update
				return;
			}

		}

	}
}