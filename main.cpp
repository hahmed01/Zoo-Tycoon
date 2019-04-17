/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of main
*********************************************************************/



#include <iostream>
#include <random>

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{

	Zoo play;

	play.createAnimal();
	play.gameLoop();


}