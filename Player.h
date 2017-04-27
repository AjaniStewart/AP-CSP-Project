#pragma once

#include "Creature.h"
#include "Monster.h"

class Monster;

class Player : public Creature
{
private:
	int m_level = 1;
	int m_potions = 1;
	int m_maxHealth;
	int m_totalGold = 0;
public:
	Player(std::string name)
		: Creature(name, '@', 10, 1, 0)
		//Player has custom name, @ symbol, has 10 health to start, does 1 dmg and has no gold
	{
		m_maxHealth = m_health;
	}

	int getLevel() { return m_level; }
	void levelUp() { ++m_level; ++m_damage; ++m_maxHealth; }
	bool hasWon() { return (m_level == 20); }
	void playGame(); //main game loop
	bool fightMonster(Monster &monster);
	void usePotion();
	friend void vendor(Player &player);
	int getPotions() { return m_potions; }
	void addTGold(int value) { m_totalGold += value; }
	int getTGold() { return m_totalGold; }
};