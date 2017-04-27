#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

void attackMonster(Monster &monster, Player &player);
void attackPlayer(Monster &monster, Player &player);

bool Player::fightMonster(Monster &monster) //a single encounter
{
	while (true)
	{
		if (this->isDead())
		{
			break;//return this->isDead();
			//game over noob
		}
		std::cout << "You have " << this->getHealth() << " health and " << this->getPotions() << " potion(s).\n";
		std::cout << "(R)un or (F)ight or (U)se potion: ";
		char choice;
		std::cin >> choice;
		if (choice == 'F' || choice == 'f')
		{
			attackMonster(monster, *this);
			if (monster.isDead())
			{
				this->levelUp();
				this->addGold(monster.getGold());
				this->addTGold(monster.getGold());
				std::cout << "You killed the " << monster.getName() << " .\n";
				std::cout << "You are now level " << this->getLevel() << " .\n";
				std::cout << "You found " << monster.getGold() << " gold.\n";
				std::cout << "You have " << this->getGold() << " gold.\n";
				break;//return this->isDead();
			}
			else
			{
				attackPlayer(monster, *this);
			}
		}
		else if (choice == 'R' || choice == 'r')
		{
			if (Monster::getRandomNumber(0, 9) < 6) //55% chance to escape
			{
				std::cout << "You successfully fled.\n";
				break;// return this->isDead();
			}
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, *this);
			}
		}
		else if (choice == 'U' || choice == 'u')
		{
			this->usePotion();
			attackPlayer(monster, *this);
		}
	}
	return this->isDead();
}

void Player::playGame() //main game loop
{
	while (true)
	{
		if (this->hasWon())
		{
			std::cout << "Somehow, by the grace of god, you managed to dodge the op dragons and reached level 20.\n";
			std::cout << "You also accumulated " << this->getTGold() << " gold.\n";
			std::cout << "I don't know how long you have tried but you did it buddy.\n";
			std::cout << "Congrats. You won.\n";
			return;
		}

		if (this->getLevel() % 5 == 0) //fix pls
			vendor(*this);


		Monster monster = Monster::getRandomMonster();
		std::cout << "You have encountered a " << monster.getName() << ". (" << monster.getSymbol() << ") .\n";
		if (this->fightMonster(monster))
		{
			std::cout << "You died at level " << this->getLevel() << " and with " << this->getTGold() << " gold.\n";
			std::cout << "Too bad you can't take it with you!\n";
			return;
		}
	}
}

void Player::usePotion()
{
	if (m_potions > 0)
	{
		m_health += 5;
		if (m_health > m_maxHealth)
			m_health = m_maxHealth; //to stop the cheeky early game strats
		--m_potions;
	}
	else
		std::cout << "No potions.\n";
}

void vendor(Player &player)
{
		std::cout << "I am a potion vendor.\n";
		std::cout << "Potions cost 50 coins each.\n";
		std::cout << "And they restore 5 health.\n";
		std::cout << "I've only got 5 potions though.\n";
		std::cout << "Would you like to buy one? (Y/N): ";
		char choice;
		while (true)
		{
			std::cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				std::cout << "OK, how many do you want?\n";
				int amount;

				while (true)
				{
					std::cin >> amount;
					if (!amount)
					{
						std::cout << "You're wasting my time.\n";
						return;
					}
					else if (amount < 0 || amount > 5)
						std::cout << "Enter a valid number, peasant.\n";

					else if (amount * 50 > player.getGold())
						std::cout << "You can't afford that amount, mate. Enter a valid amount.\n";
					
					else
						break; //leave the loop if they enter a valid number
				}

				std::cout << "This might save your life, traveller.\n";
				player.m_potions += amount;
				player.reduceGold(amount * 50);
				return;
			}
		}
}