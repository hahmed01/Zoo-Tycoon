/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of the Penguin class, drived from Animal/
*********************************************************************/


#include <iostream>
#include "Animal.hpp"
#include "Penguin.hpp"

Penguin::Penguin()
{
	age = 0;
	cost = 1000;
	payoff = 100;
	feedCostMul = 1;
	newBabies = 5;
}

int Penguin::getAge()
{
	return age;
}

void Penguin::incAge()
{
	age++;
}

int Penguin::getPayoff()
{
    return payoff;
}

int Penguin::getCost()
{
    return cost;
}

int Penguin::getFeedCostMul()
{
	return feedCostMul;
}

int Penguin::getBabies()
{
    return newBabies;
}

void Penguin::setAge(int a)
{
	age = a;
}
