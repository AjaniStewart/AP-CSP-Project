// AP Computer Science Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"

int main() //gonna set up and initiate the game
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	std::cout << "Enter your name: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Welcome, " << name << "\n";
	Player player(name);
	player.playGame(); 
	std::cin.get();

	return 0;
}