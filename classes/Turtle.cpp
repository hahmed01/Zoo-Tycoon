/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of the Turtle class, drived from Animal/
*********************************************************************/

#include <iostream>
#include "Animal.hpp"
#include "Turtle.hpp"

Turtle::Turtle()
{
	age = 0;
	cost = 100;
	payoff = 5;
	feedCostMul = 1;
	newBabies = 10;
}

int Turtle::getAge()
{
	return age;
}

void Turtle::incAge()
{
	age++;
}

int Turtle::getPayoff()
{
    return payoff;
}

int Turtle::getCost()
{
    return cost;
}

int Turtle::getFeedCostMul()
{
	return feedCostMul;
}

int Turtle::getBabies()
{
    return newBabies;
}

void Turtle::setAge(int a)
{
	age = a;
}

