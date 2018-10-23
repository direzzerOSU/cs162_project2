/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

class Animal {
protected:
	int age = 1;	// baby until 3 days old; if age >= 3 days, then the animal is an adult
	int cost;
	int numBabies;
	int baseFoodCost = 10;		// using a fixed amount of $10/animal/day
	int payoff;
public:
	Animal();
   virtual int getPurchaseCost();
   virtual int getFoodCost();
   virtual int getPayoff();
   float feedAnimals(int);
   virtual std::string getType();
   void setAge(int);
   int getAge();
   void updateAge();
};

class Tiger : public Animal {
public:
	Tiger() : Animal() {
		age = 1; // (default)
		cost = 10000;
		numBabies = 1;
		baseFoodCost *= 5;	// 5x the base food cost
		payoff = cost * 0.2;		// 20% of (purchase) cost is returned per day (not counting bonus)
	}
   int getPurchaseCost();
   int getFoodCost();
   int getPayoff();
   std::string getType();
};

class Penguin : public Animal {
public:
	Penguin() : Animal() {
		age = 1; // (default)
		cost = 1000;
		numBabies = 5;
		baseFoodCost = baseFoodCost; // (default)
		payoff = cost * 0.1;		// 10% of (purchase) cost is returned per day (not counting bonus)
	}
   int getPurchaseCost();
   int getFoodCost();
   int getPayoff();
   std::string getType();
};

class Turtle : public Animal {
public:
	Turtle() : Animal() {
		age = 1; // (default)
		cost = 100;
		numBabies = 10;
		baseFoodCost *= 0.5;		// 50% of purchase cost (per day)
		payoff = cost * 0.05;		// 5% of the (purchase) cost, which is returned per day
	}
   int getPurchaseCost();
   int getFoodCost();
   int getPayoff();
   std::string getType();
};

#endif
