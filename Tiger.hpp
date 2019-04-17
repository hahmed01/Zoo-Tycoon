/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Prototpe of the Tiger class, drived from Animal/
*********************************************************************/


#include <iostream>
#include "Animal.hpp"

#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger : public Animal
{ 
    protected:

    public:
      Tiger();
      int getAge();
      int getCost();
      int getFeedCostMul();
      int getBabies();
      int getPayoff();
      void incAge();
      void setAge(int a);

};
#endif