/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Protoypes of the helper functions.
*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <string>

  int validateAnimalInput(std::string userInput); //validates user's choice for loaded or unloaded die
  int pickFeedType(std::string foodInput);
	int validateInput(std::string usrInput);
	int buyNewAdultAnimalType(std::string buyAnimalInput);
	int buyNewAdultAnimalPrompt(std::string buyInput);




  bool containChar(std::string usrInput); //checks if there is a letter character in input
  bool withinRange(int userInput); //checks if the input is within range

#endif
