/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Prototype of the Turtle class
*********************************************************************/

#include <iostream>
#include "Animal.hpp"

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle : public Animal
{ 
 	protected:


  	public:
  	Turtle();
    int getAge();
    int getCost();
    int getFeedCostMul();
    int getBabies();
    int getPayoff();
    void incAge();
    void setAge(int a);


};
#endif