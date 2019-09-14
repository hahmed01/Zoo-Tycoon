/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Prototypes of the Zoo class
*********************************************************************/


#include <iostream>
#include "Animal.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{ 
  protected:
    Tiger **tigers;
    Penguin **penguins;
    Turtle **turtles;

    int numTigers;
    int numPenguins;
    int numTurtles;

    int capacity;

    int feedType;
    const int baseFoodCost = 20; //base food cost is 20$
    int tigerCapacity;
    int turtleCapacity;
    int penguinCapacity;
    int day;






    int bank;
    //void expand();


  public:
    Zoo();
    void gameLoop();
    void keepPlaying();
    //int pickFeedType();
    int feedTypeResult(int);
    int feedTypeCalculator();

    void randomEvent(int);
    void getNumAnimals(); 
    int getNumTigers();

    int getNumTurtles();

    int getNumPenguins();
    void setNumTurtles(int t);
    void setNumPenguins(int p);

    void createAnimal();
    void animalGrows();
    void randomAnimalDies();
    void randomBabyBorn(int);

    void noMoney();


    void deallocate();
    void setNumTigers(int n);
    void calcFoodCostPremium();
    void calcFoodCostCheap();
    void calcFoodCostGeneric();

    bool deadPenguins();


    bool deadTurtles();

    bool deadTigers();

    int pickRandomAnimalBaby();

    bool isOldEnough(int);
    bool allDead();

    void calcFoodCost();
    int calcPayoff();
    void calcProfit();
    void getFoodCost();
    void getPayoff();
    void randomBoom();

    int getBank();
    void setBank(int);

    void expandArray(int);
    void buyNewAdultAnimal();
    void createAdultAnimal(int);

int getPenguinCapacity();

int getTurtleCapacity();

int getTigerCapacity();

void setTigerCapacity(int cap);

void setPenguinCapacity(int cap);

void setTurtleCapacity(int cap);


    //void incAge();

};
#endif