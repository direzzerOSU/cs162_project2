/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#include "game.hpp"
#include "zoo.hpp"   // already in game.hpp, but including to reflect its use
#include "inputValidation.hpp"

Zoo::Zoo() {
	// money is already initialized
		// update initial $ balance, if desired...
	// money = 0;
	
	cout << "Congratulations on founding a new zoo!\nLet's start by adopting your first three animals." << endl << endl;
	cout << "Please choose the animal's corresponding letter that you'd like to adopt." << endl;
	cout << "Available animals: " << endl;

	cout << "	a. Tiger" << endl;
	cout << "	b. Penguin" << endl;
	cout << "	c. Turtle" << endl << endl;

	char selection;	// used for the player to select his/her zoo's starting animals
	char verification = 'n';
   // array elements mirror the user (char) selection order of the user input choices (a, b, c)
   // startingAnimals[0] == Tiger; startingAnimals[1] == Penguin; startingAnimals[2] == Turtle
   int startingAnimals[3] = {0, 0, 0};    // tracks the quantity of adoptions for each animal breed
   bool qtyCheck = true;  // used to determine if the qty of an animal type is unacceptable; true will trigger the loop to break because the animal would exceed its adoption max
   int arrayElement;

	// user input to select the zoo's starting 3 animals
   //for(int n=0; n<3; n++) {
   
   // ensure that the user adopts 1-2 of each animal type at the very beginning
   while((startingAnimals[0] != 1 && startingAnimals[0] != 2) || (startingAnimals[1] != 1 && startingAnimals[1] != 2) || (startingAnimals[2] != 1 && startingAnimals[2] != 2)) {
		selection = ' ';
		verification = 'n';
      qtyCheck = true;
      // to keep track of the number of animals of each type; to limit the
      // starting quantity to 1-2
		while((tolower(selection) != 'a' && tolower(selection) != 'b' && tolower(selection) != 'c') || tolower(verification) == 'n') {
			cout << "Animal " << animalCount+1 << ": ";
			cin >> selection;

			charValidation(selection);

         arrayElement = inputToArray(tolower(selection));
         qtyCheck = startingAnimalQuantity(startingAnimals[arrayElement]);
			
         cout << endl;

			while((tolower(selection) != 'a' && tolower(selection) != 'b' && tolower(selection) != 'c') || qtyCheck == false) {
            if(tolower(selection) != 'a' && tolower(selection) != 'b' && tolower(selection) != 'c') {
			   	cout << endl <<  "Uh oh... You didn't select a valid option. Please try again..." << endl;
            }
            else if(qtyCheck == false) {
               cout << "Uh oh... You can adopt up to a maximum of 2 animals for each type when beginning the game. \nPlease select another animal..." << endl;
            }
				cout << "Animal " << animalCount+1 <<  ": ";
				cin >> selection;

				charValidation(selection);
   
            arrayElement = inputToArray(tolower(selection));
            qtyCheck = startingAnimalQuantity(startingAnimals[arrayElement]);
			}

			cout << "You have chosen: " << charToAnimal(tolower(selection)) << endl;
			cout << "Is this correct? (Y/N): ";
			cin >> verification;

			charValidation(verification);
			cout << endl;

			while(tolower(verification) != 'y' && tolower(verification) != 'n') {
				cout << "Whoops! It looks like you didn't give a proper answer (Y/N)." << endl;
				cout << "Please try again: ";
				cin >> verification;

				charValidation(verification);
			}
		}

      // adopt a tiger
		if(tolower(selection) == 'a') {
			cout << "Congratulations! You've adopted a " << charToAnimal(tolower(selection)) << "!" << endl;
         Tiger* tigerTemp = new Tiger();
         checkAnimalCapacity();
         animals[animalCount] = *tigerTemp;
         money -= tigerTemp->getPurchaseCost();
         startingAnimals[0] += 1;
         delete tigerTemp;
         animalCount += 1;
		}

      // adopt a penguin
		else if(tolower(selection) == 'b') {
			cout << "Congratulations! You've adopted a " << charToAnimal(tolower(selection)) << "!" << endl;			
         Penguin* penguinTemp = new Penguin();
         checkAnimalCapacity();
         animals[animalCount] = *penguinTemp;
         money -= penguinTemp->getPurchaseCost();
         startingAnimals[1] += 1;
         delete penguinTemp;      
         animalCount += 1;         
		}

      // adopt a turtle
		else if(tolower(selection) == 'c') {
			cout << "Congratulations! You've adopted a " << charToAnimal(tolower(selection)) << "!" << endl;
         Turtle* turtleTemp = new Turtle();
         checkAnimalCapacity();
         animals[animalCount] = *turtleTemp;	
         money -= turtleTemp->getPurchaseCost();
         startingAnimals[2] += 1;
         delete turtleTemp;
         animalCount += 1;         
		}

      // used for the notification of a "bug"; this scenario shouldn't occur if
      // inputValidation is successful
		else {
			cout << "Uh oh... There's a bug with validating the user's selection of the zoo's starting animals!" << endl;
			cout << "charValidation(selection) didn't validate the input to equal: 'a', 'b', or 'c'." << endl;
		}
      cout << "Money: " << getMoney() << endl;
		cout << endl;
	}
}

// plays a round (1 day) within the game
void Zoo::playRound(bool& identifier) {
   // select the animals' food
   int food = selectFood();

   // increase the age of each animal by 1 & feed each animal
   for(int n=0; n<animalCount; n++) {
//      cout << "Initial age: " << animals[n].getAge() << endl;
      animals[n].updateAge();
//      cout << "Updated age: " << animals[n].getAge() << endl;
      money -= animals[n].feedAnimals(food);
      money += animals[n].getPayoff();
   }
   cout << "Do you want to buy an adult animal?: " << endl;
   char input = 'z';
   cout << "   a. Yes" << endl;
   cout << "   b. No" << endl << endl;

   // input validation when deciding whether or not to buy an adult male
   while(tolower(input) != 'a' && tolower(input) != 'b') {
      cin >> input;
      charValidation(input);
      if(tolower(input) != 'a' && tolower(input) != 'b') {
         cout << "Incorrect option... Please try again: ..." << endl;
      }
   }

   // buy an adult animal
   cout << "What animal would you like to buy?" << endl;
  	cout << "	a. Tiger" << endl;
	cout << "	b. Penguin" << endl;
	cout << "	c. Turtle" << endl << endl;

   char animal = 'z';
   // input validation when deciding on the animal type to buy
   while(tolower(animal) != 'a' && tolower(animal) != 'b' && tolower(animal) != 'c') {
      cin >> animal;
      charValidation(animal);
      if(tolower(animal) != 'a' && tolower(animal) != 'b' && tolower(animal) != 'c') {
         cout << "Incorrect option... Please try again..." << endl;
      }
   }

   // buy a Tiger
   if(tolower(animal) == 'a') {
      Tiger* TigerTemp = new Tiger();
      checkAnimalCapacity();
      animals[animalCount] = *TigerTemp;
      money -= TigerTemp->getPurchaseCost();
      delete TigerTemp;
      animalCount += 1;
   }
   // buy a Penguin
   else if(tolower(animal) == 'b') {
      Penguin* PenguinTemp = new Penguin();
      checkAnimalCapacity();
      animals[animalCount] = *PenguinTemp;
      money -= PenguinTemp->getPurchaseCost();
      delete PenguinTemp;
      animalCount += 1;
   }
   // buy a Turtle
   else if(tolower(animal) == 'c') {
      Turtle* TurtleTemp = new Turtle();
      checkAnimalCapacity();
      animals[animalCount] = *TurtleTemp;
      money -= TurtleTemp->getPurchaseCost();
      delete TurtleTemp;
      animalCount += 1;
   }

   // set animal's age to 3 (to become an adult)
   animals[animalCount].setAge(3);
 //  cout << "animals[animalCount].setAge(3): " << animals[animalCount].getAge() << endl;

   // you ran out of money $$
   if(moneyRemaining() == false) {
      identifier = false;
   }
   else if(moneyRemaining() == true) {
      identifier = true;
   }
   else {
      cout << "[ERROR] The moneyRemaining() function didn't behave as expected..." << endl;
      identifier = false;
   }
}

std::string Zoo::charToAnimal(char selection){
	std::map<char, std::string> letter;

	letter['a'] = "Tiger";
	letter['b'] = "Penguin";
	letter['c'] = "Turtle";

	return letter[selection];
}

void Zoo::updateStatus(bool& status) {
   cout << "Round complete. Please indicate what you would like to do: " << endl;
   cout << "   a. Play another round" << endl;
   cout << "   b. Quit game" << endl;

   char input;

   cout << "Selection: ";
   cin >> input;

   charValidation(input);

   if(tolower(input) == 'a') {
      status = true;
   }
   else if(tolower(input) == 'b') {
      status = false;
   }
}

void Zoo::checkAnimalCapacity(){
   // if the Zoo's animal capacity (array) needs to be increased
   if((animalCount + 3) == animalCapacity) {
      int startingCapacity = animalCapacity;
      animalCapacity *= 2;
      Animal* tempArray = new Animal[animalCapacity];

      // copy the original array values to the temporary array (doesn't go
      // through the entire array because we only need to copy the number of
      // elements as the total number of animals in the Zoo
      for(int n=0; n<startingCapacity; n++) {
         tempArray[n] = animals[n];
      }

      // delete the old array since the data has already been copied over
      delete[] animals;

      // point the object's member variable to the new array (memory)
      animals = tempArray;
   }

   else {
      // do nothing
   }
}

int Zoo::inputToArray(char option) {
   // a = Tiger; b = Penguin; c = Turtle

   // map a character value (user selection from the menu) to a the
   // corresponding array element/position
   std::map<char, int> animal;
   animal['a'] = 0;
   animal['b'] = 1;
   animal['c'] = 2;

   return animal[option];
}

bool Zoo::startingAnimalQuantity(int array) {
   // if the animal count(s) has reached the max (2 animals of a type), then
   // the user cannot adopt another of that type
   if(array >= 2) {
      cout << "Uh oh! You must adopt either 1 or 2 animals of each type to begin the game..." << endl;
      return false;
   }
   
   // if a false return isn't triggered, all animals are okay
   return true;
}

// randomly generate an event to a random animal
void Zoo::randomEvent() {
   // num corresponds to the random event that will be triggered
   int num = rand() % 4;

   // sickness occurs
   if(num == 0) {
      sickness();
   }
   // attendance boom
   else if(num == 1) {
      attendanceBoom();
   }
   else if(num == 2) {
      babyBorn();
   }
   else if(num == 3) {
      // nothing happens
   }
   else {
      cout << "There's a bug in your program when generating a random event..." << endl;
   }
}

// one animal dies
void Zoo::sickness() {
   // num is the position of the animal that will experience the random event
   int num = rand() % animalCount;
   cout << "A sickness comes over animal #" << num << ", which is one of your " << animals[num].getType() << "s!" << endl;
   cout << "Your animal passed away from the sickness..." << endl;
   erase(num);
}

// random bonus for the day, $250 - 500/tiger & gain bonus payoff for each
// tiger to the total payoff of the day as a reward
void Zoo::attendanceBoom() {
   std::string breed = "";
   int count = 0;
   int bonus = 0;
   // generate the random bonus per tiger
   // random bonus of $250 - 500 per tiger in the zoo (for the day)      
   while(bonus<250 || bonus>500) {
      bonus = rand() % 501;
   }

   // quantify the total bonus based on the quantity of tigers
   for(int t=0; t<animalCount; t++) {
      breed = animals[t].getType();

      if(breed == "Tiger") {
         count += 1;
      }
   }
   // add the total bonus to the bank
   money += bonus * count;
}


// a baby is born from a random animal that is >3 days old
void Zoo::babyBorn() {
   // num is the position of the animal that will experience the random event
   int num = rand() % animalCount;
   animals[num].getType();
   
   // have a baby if the animal is old enough
   if(animals[num].getAge() >= 3) {
      // check the zoo's animal capacity & increase if required
      checkAnimalCapacity();
      // create a new animal (baby) of the same type as the parent
      if(animals[num].getType() == "Tiger") {
         cout << "Congratulations! You've adopted a " << animals[num].getType() << "!" << endl;
         Tiger* tigerTemp = new Tiger();
         animals[animalCount] = *tigerTemp;
         money -= tigerTemp->getPurchaseCost();
         delete tigerTemp;
         animalCount += 1;
      }
      else if(animals[num].getType() == "Penguin") {
         cout << "Congratulations! You've adopted a " << animals[num].getType() << "!" << endl;
         Penguin* penguinTemp = new Penguin();
         animals[animalCount] = *penguinTemp;
         money -= penguinTemp->getPurchaseCost();
         delete penguinTemp;
         animalCount += 1;
      }
      else if(animals[num].getType() == "Turtle") {
         cout << "Congratulations! You've adopted a " << animals[num].getType() << "!" << endl;
         Turtle* turtleTemp = new Turtle();
         animals[animalCount] = *turtleTemp;
         money -= turtleTemp->getPurchaseCost();
         delete turtleTemp;
         animalCount += 1;
      }
      // too young to have a baby
      else {
         // do nothing...
      }
   }
}

// delete an element within the array
void Zoo::erase(int n) {
   // moves all elements "up" one position; since the [i+1] position was just
   // moved to position [i], assign the [i+1] position a value of nullptr
   // (nothing should be at the [i+1] position
   for(int i=n; i<animalCount; i++) {
      animals[i] = animals[i+1];
      animals[i+1] = animals[i+2];
   }
}

void Zoo::freeMemory() {
   delete[] animals;
}

// interactive function for the user to select his/her animals' food (cheap, generic, premium)
int Zoo::selectFood() {
   cout << "Which type of food do you want to feed your animals this round?" << endl;
   cout << "   1. Cheap" << endl;
   cout << "   2. Generic" << endl;
   cout << "   3. Premium" << endl;

   // variable that represents the user's food selection
   int input;

   // ensure the user inputs a valid menu option & validate an int is entered
   while(input != 1 && input != 2 && input != 3) {
      cin >> input;
      intValidation(input);
      if(input != 1 && input != 2 && input != 3) {
         cout << "You didn't select a valid choice... Please try again." << endl;
      }
   }

   return input;
}

bool Zoo::moneyRemaining() {
   if(money <= 0) {
      return false;
   }
   else if(money > 0) {
      return true;
   }
   else{
      return false;  // there's a bug
   }
}

int Zoo::getMoney() {
   return money;
}

int Zoo::getTurn() {
   return turn;
}
