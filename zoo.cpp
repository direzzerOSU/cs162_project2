/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#include "zoo.hpp"
#include "inputValidation.hpp"

Animal::Animal() {
	age = 0;		
}

// virtual only function
int Animal::getPurchaseCost() {
   return 0;
}

// virtual only function
int Animal::getFoodCost() {
   return 0;
}

// return the purchase cost for each animal
int Tiger::getPurchaseCost() {
   return cost;
}

int Penguin::getPurchaseCost() {
   return cost;
}

int Turtle::getPurchaseCost() {
   return cost;
}

// return the recurring (daily) food cost of each animal
int Tiger::getFoodCost() {
   return baseFoodCost;
}

int Penguin::getFoodCost() {
   return baseFoodCost;
}

int Turtle::getFoodCost() {
   return baseFoodCost;
}

std::string Animal::getType() {
   return "N/A - This is a generic animal";
}

std::string Tiger::getType() {
   return "Tiger";
}

std::string Penguin::getType() {
   return "Penguin";
}

std::string Turtle::getType() {
   return "Turtle";
}

int Animal::getAge() {
   return age;
}

void Animal::updateAge() {
   age += 1;
}

// feeds the animals (all derived classes [animal types/breeds] are treated the
// same; as shown by using the base class with this function's implementation
float Animal::feedAnimals(int input) {
   int food = 0;     // represents the cost of the day's food

   // cheap food
   if(input == 1) {
      food = static_cast<float>(baseFoodCost)/2.0;
      
   }
   // generic food
   else if(input == 2) {
      // behaves normally
      
      food = static_cast<float>(baseFoodCost);
   }
   // premium food
   else if(input == 3) {
      food = static_cast<float>(baseFoodCost)*2.0;
   }
   return food;
}

// updates an animal's age (in days)
void Animal::setAge(int x) {
   age = x;
}

// virtual function; animal (with no type) will not return a payoff
int Animal::getPayoff() {
   return 0;
}

// return the payoff/revenue from each animal type
int Tiger::getPayoff() {
   return payoff;
}
int Penguin::getPayoff() {
   return payoff;
}
int Turtle::getPayoff() {
   return payoff;
}
