/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Protoype = of the Animal class
*********************************************************************/


#include <iostream>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{ 
  protected:
  	int age; //member variables to be inherited
  	int payoff; 
  	int cost;
  	int newBabies;
  	int feedCostMul;

  public:
  	Animal();
  	virtual int getAge(); //virtual functions to be overridden
  	virtual int getCost();
  	virtual int getFeedCostMul();
  	virtual int getBabies();
  	virtual int getPayoff();
  	virtual void incAge();
	virtual ~Animal();
};
#endif