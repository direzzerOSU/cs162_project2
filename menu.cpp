/*********************************************************************
** Program name: War Game with Dice
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description:
*********************************************************************/

#include "menu.hpp"

void menu(bool& result){
   // introduction
   string program_name = "Zoo Tycoon Game";
   cout << "Hello! Welcome to Ryan's " << program_name << " Program:" << endl;

   // user input to start the program or quit
   cout << "Please select an option from below:" << endl;
   cout << "   a. Start " << program_name << endl;
   cout << "   b. Quit" << endl << endl;
   char selection = ' ';
   cout << "Selection: ";
   cin >> selection;
   cout << endl;

   // input validation until the user selects a valid option
   while(tolower(selection) != 'a' && tolower(selection) != 'b'){
      cout << "Uh oh... That's not a valid option. Please try again." << endl;
      cout << "Selection: ";
      cin >> selection;
   }

   if(tolower(selection == 'a')){
      result = true;
   }
   else{
      cout << "Ending program..." << endl;
      result = false;
   }
}
