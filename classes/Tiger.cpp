/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementaion of the Tiger class, drived from Animal/
*********************************************************************/
#include <iostream>
#include "Animal.hpp"
#include "Tiger.hpp"


Tiger::Tiger()
{
	age = 0;
	cost = 10000;
	payoff = 2000;
	feedCostMul = 5;
	newBabies = 1;
}

int Tiger::getAge()
{
	return age;
}

void Tiger::incAge()
{
	age++;
}

int Tiger::getPayoff()
{
    return payoff;
}

int Tiger::getCost()
{
    return cost;
}

int Tiger::getFeedCostMul()
{
	return feedCostMul;
}

int Tiger::getBabies()
{
    return newBabies;
}

void Tiger::setAge(int a)
{
	age = a;
}




