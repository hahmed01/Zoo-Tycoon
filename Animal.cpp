/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementaion of the Animal class
*********************************************************************/


#include <iostream>
#include "Animal.hpp"


using namespace std;

Animal::Animal()
{
	payoff = 0;
}


int Animal::getAge()
{
	return age;
}

void Animal::incAge()
{
	age++;
}

int Animal::getPayoff()
{
    return payoff;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getFeedCostMul()
{
	return feedCostMul;
}

int Animal::getBabies()
{
    return newBabies;
}

Animal::~Animal()
{
	
}
