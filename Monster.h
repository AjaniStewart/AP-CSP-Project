#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include "Creature.h"
#include "Player.h"

class Player;

class Monster : public Creature
{
	//needed for lookup table
public:
	enum Type
	{
		//add more monsters
		DRAGON,
		ORC,
		SLIME,
		ELDER_DRAGON,
		DWARF,
		GIANT,
		TROLL,
		SPRIGGAN,
		VAMPIRE,
		DRAGONSLAYER_ORNSTEIN,
		KNIGHT_ARTORIAS,
		MAX_TYPES
	};

	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES]; //static so it gets defined once

	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
			monsterData[type].damage, monsterData[type].gold)
	{
	}

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max);
	static Monster getRandomMonster();
	//void adjustForLevel(Player &player); //WORK IN PROGRESS

};
