#include "character.h"

character::character() {

	this->name = "";
	int stat[7] = { 5,5,5,5,5,5,5 };
	this->charStats = stats(stat);
	this->gold = 0;
	this->Inv = inventory();
	this->pos = posn();
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
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		std::cout << "Error opening a file" << std::endl;
		file.close();
		return;
	}

	file >> this->name;
	for (int i = 0; i < 7; i++) {
		file >> stat[i];
	}
	file >> alvl;
	file >> axp;
	file >> aSp;
	this->charStats.setStats(stat, alvl, axp, aSp);
	file >> this->gold;

	while (file >> check && (check == 'i' || check == 'w' || check == 'e')) {
		switch (check) {
		case 'i':
		{
			std::shared_ptr<Items> tempItem(new Items{});
			file >> tempString;
			tempItem->changeName(tempString);
			file >> tempNum;
			tempItem->changeVal(tempNum);
			this->Inv.invAdd(tempItem);
			break;
		}
		case 'w':
		{
			std::shared_ptr<weapon> tempWeapon(new weapon{"temp", 0, 0});
			file >> tempString;
			tempWeapon->changeName(tempString);
			file >> tempNum;
			tempWeapon->changeVal(tempNum);
			file >> tempNum;
			tempWeapon->setAtk(tempNum);
			Inv.invAdd(tempWeapon);
			break;
		}
		case 'e':
		{
			std::shared_ptr<equipment> tempEquipment(new equipment{ "temp", 0, 0 , temp});
			file >> tempString;
			tempEquipment->changeName(tempString);
			file >> tempNum;
			tempEquipment->changeVal(tempNum);
			file >> tempNum;
			tempEquipment->setSlot(tempNum);
			for (int i = 0; i < 7; i++) {
				file >> stat[i];
			}
			tempEquipment->setMods(stat);
			this->Inv.invAdd(tempEquipment);
			break;
		}
		default:
		{
			std::cout << "Oops, something went wrong!" << std::endl;
			//Do nothing
		}
		}
			
	}

	file >> tempNum;
	this->pos.setX(tempNum);
	file >> tempNum;
	this->pos.setY(tempNum);

	file.close();

	return;

}

void character::printCharacter() {
	std::cout << this->name << std::endl;
	this->charStats.printStats();
	std::cout << "Gold: " << this->gold << std::endl;
	this->Inv.printInventory();
	this->pos.printPosn();
	return;
}

void character::changeName(std::string newName) {
	this->name = newName;
	return;
}

void character::changeGold(int change) {
	this->gold += change;
	return;
}

void character::changeStats(stats newStats) {
	this->charStats = newStats;
	return;
}

void character::changeInventory(inventory newInv) {
	this->Inv = newInv;
	return;
}

void character::changePosition(posn newPos) {
	this->pos = newPos;
	return;
}

std::string character::getName() {
	return this->name;
}

int character::getGold() {
	return this->gold;
}

stats character::getStats() {
	return this->charStats;
}

inventory character::getInventory() {
	return this->Inv;
}

posn character::getPosition() {
	return pos;
}

void character::battle(character enemy) {
	int temp;
	int input;
	int damage;
	int enemyDamage;
	stats enemyStatTemp;
	while (this->charStats.getCurrentStats()[0] > 0 && enemy.getStats().getCurrentStats()[0] > 0) {
		//Reset
		damage = 0;
		enemyDamage = 0;
		//Display menu
		std::cout << "______________________" << std::endl;
		std::cout << "\\0/              >0< " << std::endl;
		std::cout << this->charStats.getTrueStats()[0] << "/" << this->charStats.getCurrentStats()[0];
		temp = 2;
		for (int i = this->charStats.getTrueStats()[0]; i >= 1; i/=10) {
			temp += 2;
		}
		for (int i = enemy.getStats().getCurrentStats()[0]; i >= 1; i /= 10) {
			temp += 2;
		}
		for (int i = 0; i < 22 - temp; i++) {
			std::cout << " ";
		}
		std::cout << enemy.getStats().getTrueStats()[0] << "/" << enemy.getStats().getCurrentStats()[0] << std::endl;
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
			damage = this->charStats.getCurrentStats()[2] - (enemy.getStats().getCurrentStats()[3] / 2);
			break;
		case 2:
			
			damage = (this->charStats.getCurrentStats()[4] * (this->charStats.getTrueStats()[1]/20)) - (enemy.getStats().getCurrentStats()[5] / 2);
			this->charStats.statUpdate(1, -1 * this->charStats.getTrueStats()[1] / 20);
			break;
		case 3:
			this->charStats.statUpdate(4, this->charStats.getCurrentStats()[4]);
			break;
		case 4:
			std::cout << "WIP! Try something else?" << std::endl;
			break;

		default:
			std::cout << "Invalid command, try again!" << std::endl;

		}

		//Enemy Action (WIP):
		if (enemy.getStats().getCurrentStats()[2] >= enemy.getStats().getCurrentStats()[4]) {
			enemyDamage = enemy.getStats().getCurrentStats()[2] - (this->charStats.getCurrentStats()[3] / 2);
		}
		else {
			enemyDamage = enemy.getStats().getCurrentStats()[4] - (this->charStats.getCurrentStats()[5] / 2);
		}

		std::cout << damage << " " << enemyDamage << std::endl;

		//Action Occurance (Add Speed tie!)
		//Win or tie in speed
		if (this->charStats.getCurrentStats()[6] >= enemy.getStats().getCurrentStats()[6]) {
			enemyStatTemp = enemy.getStats();
			enemyStatTemp.statUpdate(0, -1 * damage);
			enemy.changeStats(enemyStatTemp);
			if (enemy.getStats().getCurrentStats()[0] > 0) {
				//End of battle update
				return;
			}
			this->charStats.statUpdate(0, -1 * enemyDamage);
			if (this->charStats.getCurrentStats()[0] > 0) {
				//Game Over sequence
				return;
			}
		}
		//Lose in speed
		else if (this->charStats.getCurrentStats()[6] < enemy.getStats().getCurrentStats()[6]) {

			this->charStats.statUpdate(0, -1 * enemyDamage);
			if (this->charStats.getCurrentStats()[0] > 0) {
				//Game Over sequence
				return;
			}
			enemyStatTemp = enemy.getStats();
			enemyStatTemp.statUpdate(0, -1 * damage);
			enemy.changeStats(enemyStatTemp);
			if (enemy.getStats().getCurrentStats()[0] > 0) {
				//End of battle update
				this->postBattle(enemy);
				return;
			}

		}

	}
}

void character::postBattle(character enemy) {
	int chance;
	srand(time(NULL));
	//Add XP
	this->charStats.xpUpdate(enemy.getStats().getXp());
	this->charStats.checkLevel();
	//Add gold
	this->changeGold(enemy.getGold());
	//Add Items (WIP) Placeholder drop rate of 10%
	for (int i = 0; i < enemy.getInventory().getLen(); i++) {
		chance = rand() % 100 + 1;
		if (chance <= 10) {
			this->Inv.invAdd(enemy.getInventory().findItem(i));
		}
		else {
			//Do nothing
		}
	}
	return;
}

character::~character() {
	//Not much to do, most of the heavy lifting is done by the deconstructors of the other classes that are properties of character
}