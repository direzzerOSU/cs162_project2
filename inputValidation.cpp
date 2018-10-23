/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 14, 2018
** Description: Implements an input validation function, which is used
   when receiving various user-specified attribute values.
*********************************************************************/

// include the function's header with its function prototype
#include "inputValidation.hpp"

// prompts the user to re-enter the intended attribute's value (for an int value)
void intValidation(int& value){
   while(cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // see the header file for a reference citation (1)
      cout << "You have entered the wrong type of input. \n   Please enter an integer: ";
      cin >> value;
      cout << endl;
   }
}

// prompts the user to re-enter the intended attribute's value (for a char value)
void charValidation(char& value){
   while(cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // see the header file for a reference citation (1)
      cout << "You have entered the wrong type of input. \n   Please enter a character: ";
      cin >> value;
      cout << endl;
   }
}
