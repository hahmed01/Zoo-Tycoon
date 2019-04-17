/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of the Penguin class, drived from Animal/
*********************************************************************/


#include <iostream>
#include "Animal.hpp"

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin : public Animal
{ 
  	protected:

  	public:
  	Penguin();
    int getAge();
    void setAge(int a);
    int getCost();
    int getFeedCostMul();
    int getBabies();
    int getPayoff();
    void incAge();



};
#endif