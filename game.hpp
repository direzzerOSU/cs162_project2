/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "zoo.hpp"
#include "inputValidation.hpp"

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<map>
// ctime & cstdlib are used for generating random numbers
#include<ctime>
#include<cstdlib>

class Zoo {
private:
	int money = 100000;
   int animalCapacity = 10;
   int animalCount = 0;
	Animal* animals = new Animal[animalCapacity];		// start with 3 animals; 1 or 2 per type of animal
	int turn = 1;
public:
	Zoo();
	void playRound(bool&);
	std::string charToAnimal(char);
   int selectFood();   // used to select an int, which corresponds to a type of feed; use the int in another function to feed animals & pay (update bank's money $ balance)
	void randomEvent();
   void sickness();
   void attendanceBoom();
   void babyBorn();
   void updateStatus(bool&);
   void checkAnimalCapacity();
   bool startingAnimalQuantity(int array);
   int inputToArray(char option);
   void freeMemory();
   void erase(int); 
   bool moneyRemaining();
   int getMoney();
   int getTurn();
};
#endif
