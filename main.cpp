/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include "zoo.hpp"
#include "inputValidation.hpp"

int main(){
   // initialize a new seed for generating random numbers with rand() later in
   // the program
   srand(time(0));
   cout << endl;
   // initialize variables for this program
   bool selection = true;   // used to determine when to execute the menu & program vs. quit the program
   bool gameStatus = true;  // used to determine whether the game should be active (repeat rounds) or end
   string programName = "Zoo Tycoon Game";

   while(selection == true){
      // repeatedly run the menu after completing the program (until the program is told to quit)
      menu(selection);

      if(selection == false){
         break;
      }

      Zoo zoo = Zoo();

		// prompt to continue playing or end the current game after each round (i.e., "day")
		while(gameStatus == true) {
         cout << "Hey! The game rounds have started!" << endl;
         // play a round ("day")
	      zoo.playRound(gameStatus);
         cout << endl << "Round #" << zoo.getTurn() << " remaining balance: " << zoo.getMoney() << endl;
         // give the user the option to play another round or quit the current game
         zoo.updateStatus(gameStatus);
		}
      zoo.freeMemory();
   }
   cout << endl;

   return 0;
}
