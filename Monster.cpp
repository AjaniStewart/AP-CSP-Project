#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>

void attackMonster(Monster &monster, Player &player);
void attackPlayer(Monster &monster, Player &player);

int Monster::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster Monster::getRandomMonster()
{
	return Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1)));
}

//Using a lookup table!
Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{   //name, symbol, health, damage, gold
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
	{"elder dragon", 'E',20,7,500},
	{"dwarf", 'd',6,2,30},
	{"giant", 'G', 20, 5, 300},
	{"troll", 'T', 10, 3, 50},
	{"spriggan", 'g', 2, 1, 10},
	{"vampire", 'v', 4, 2, 25},
	{"Dragonslayer Ornstein", 'O', 10, 7, 450},
	{"Knight Artorias", 'A', 10,5,200 },
};

void attackMonster(Monster &monster, Player &player)
{
	monster.reduceHealth(player.getDamage());
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
	std::cout << "The monster has " << monster.getHealth() << " health.\n";
}

void attackPlayer(Monster &monster, Player &player)
{
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
	std::cout << "You have " << player.getHealth() << " health.\n";
}

/*void Monster::adjustForLevel(Player &player)
{
	//make an appropriate curve for
	//HEALTH
	//DAMAGE
	//GOLD DROPPED
	//based on player level

	if (this->getName() == "Slime")
		return;

	int pLevel = player.getLevel();

}*/