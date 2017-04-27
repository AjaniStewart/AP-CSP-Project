#pragma once

#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(std::string name, char symbol, int health, int damage, int gold)
		: m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
	{
	}

	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void addHealth(int value) { m_health += value; }
	void reduceHealth(int value) { m_health -= value; }
	bool isDead() { return (m_health <= 0); }
	void addGold(int value) { m_gold += value; }
	void reduceGold(int value) { m_gold -= value; }
};