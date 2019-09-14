/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of the Zoo class
*********************************************************************/


#include <iostream>
#include <random>

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "helpers.hpp"


using std::cout;
using std::cin;
using std::endl;


/*********************************************************************
 ** Description: Zoo()
 Default contstructor, initialising the Zoo member variables 
 *********************************************************************/


Zoo::Zoo()
{
	tigers = nullptr;
	penguins = nullptr;
	turtles = nullptr;
	bank = 100000;
	numTigers = 0;
	numTurtles = 0;
	numPenguins = 0;
	tigerCapacity = 10;
	turtleCapacity = 10;
	penguinCapacity = 10;
	capacity = 10;
	day = 1;
}


/*********************************************************************
 ** Description: gameLoop()
 Overall game flow of zooTycoon
 *********************************************************************/


void Zoo::gameLoop()
{
	day++;
	int f, food, e, event;
	animalGrows(); //Animal. all animals increase Age
	getBank();
	cout << "Time to feed the animals..." << endl;
	f = feedTypeCalculator();
	food = f;
	e = feedTypeResult(food);
	event = e;
	randomEvent(event);
	calcProfit(); //Animal. Bonus calculation
	buyNewAdultAnimal();
	noMoney();
	keepPlaying();
}

/*********************************************************************
 ** Description: keepPlaying()
 Asks user if they want to keep playing
 *********************************************************************/

void Zoo::keepPlaying()
{
	int choice, c;
	std::string usrInput;
	cout << "Do you want to keep playing? 1 for Yes and 2 for No" << endl;
 	c = validateInput(usrInput); //validate input
 	choice = c;

	switch(choice)
	{
		case 1:
			cout << "Keep playing..." << endl;
			gameLoop(); //if yes, restart game loop
			break;

		case 2:
			cout << "Quit" << endl;
			deallocate(); //if not, quit and deallocate
			break;

	}
}


/*********************************************************************
 ** Description: getBank() and setBank()
 Bank is accumulator variable keeping track of how much money is in the bank,
 these are the getter and setter functions.
 *********************************************************************/


int Zoo::getBank()
{
	return bank;
}

void Zoo::setBank(int b)
{
	bank = b;
}


/*********************************************************************
 ** Description: getter and setter functions for each animal type, keeping 
 track of the accumulators for the respective animal types
 *********************************************************************/



int Zoo::getNumTigers()
{
	return numTigers;
}

int Zoo::getNumTurtles()
{
	return numTurtles;
}

int Zoo::getNumPenguins()
{
	return numPenguins;
}

void Zoo::setNumTurtles(int t)
{
	numTurtles = t;
}
void Zoo::setNumPenguins(int p)
{
	numPenguins = p;
}

void Zoo::setNumTigers(int n)
{
	numTigers = n;
}


/*********************************************************************
 ** Description: createAnimal()
 Create animals at the start of the game. Ask user how many of each animal
 they want, and then dynamically allocate that amount
 *********************************************************************/

void Zoo::createAnimal()
{
	std::string animalInput;
	int z, p, s;
	int penguinCost, turtleCost, tigerCost;
	int numPeng = 0;
	int numTurt = 0;
	int numTig = 0;

	cout << endl;
	cout << "Welcome to Zoo Tycoon!" << endl;
	cout << "Time to put some animals in your virtual zoo." << endl;
	cout << endl; 

	//validate and create penguins, calc cost
	cout << "Penguins: " << endl;
	numPeng = validateAnimalInput(animalInput);
	setNumPenguins(numPeng);
	p = getNumPenguins();
	penguins = new Penguin*[capacity];
	for (int i = 0; i < p; i++ )
	{
		penguins[i] = new Penguin;
	}

	z = penguins[0]->getCost();
	penguinCost = p * z; 


	//validate and create tutrles, calc cost
	cout << "Turtles: " << endl;
	numTurt = validateAnimalInput(animalInput);
	setNumTurtles(numTurt);
	int q, r;
	q = getNumTurtles();
	turtles = new Turtle*[capacity]; //initial capacity is 10 possible animals
	for (int i = 0; i < q; i++ ) 
	{
		turtles[i] = new Turtle;
	}
	r = turtles[0]->getCost();
	turtleCost = q * r;

	//validate and create tigers, calc cost
	cout << "Tigers: " << endl;
	numTig = validateAnimalInput(animalInput);
	setNumTigers(numTig);
	int n, m, t, c;
	n = getNumTigers();
	tigers = new Tiger*[capacity]; //initial capacity is 10 possible animals
	for (int i = 0; i < n; i++ ) 
	{
		tigers[i] = new Tiger;
	}
	c = tigers[0]->getCost();
	tigerCost = n * c;

	m = penguinCost + turtleCost + tigerCost; //calc total cost of buying animals
	t = getBank() - m;
	setBank(t); //update money available

	getNumAnimals();
	cout << "You spent $" << m << " on your animals." << endl;
	cout << "You've got $" << t << " in your bank now." <<endl;
	cout << endl; 

}


/*********************************************************************
 ** Description: feedTypeCalculator()
 Asks user what feed type they want to choose for today, and then sends them
 to respective feedType function
 *********************************************************************/

int Zoo::feedTypeCalculator()
{
	std::string foodInput;
	int c;
	c = pickFeedType(foodInput);
	//int choice = c;

	switch(c)
	{
		case 1:
		{
			//cout << "You chose Premium" << endl;
			calcFoodCostPremium();
			return 1;
			break;
		}

		case 2:
		{
			//cout << "You chose Cheap" << endl;
			calcFoodCostCheap();
			return 2;
			break;
		}

		case 3:
		{
			//cout << "You chose Generic" << endl;
			calcFoodCostGeneric();
			return 3;
			break; 
		}
	}
	cout << endl; 
}


/*********************************************************************
 ** Description: animalGrows()
 Animals grow by 1 day
 *********************************************************************/
void Zoo::animalGrows()
{
	for (int i = 0; i < numPenguins; i++ )
	{
		penguins[i]->incAge();
	}

	cout << "Your penguins grew by 1 day." << endl;

	for (int i = 0; i < numTurtles; i++ )
	{
		turtles[i]->incAge();
	}
	cout << "Your turtles grew by 1 day." << endl;


	for (int i = 0; i < numTigers; i++ )
	{
		tigers[i]->incAge();
	}

	cout << "Your tigers grew by 1 day." << endl;
	cout << "This is day " << day << "." << endl;
	cout << endl; 

}



/*********************************************************************
 ** Description: calFoodCostGeneric()
 If food type chosen is generic, this is what you pay
 *********************************************************************/


void Zoo::calcFoodCostGeneric()
{
	int b = 0; 
	int s = 0;
	int m = 0;
	int p = 0;
	int t = 0;
	int totalFoodCost = 0;

	p = penguins[0]->getFeedCostMul();
    for(int i = 0; i < numPenguins; i++)
    {
        totalFoodCost += baseFoodCost * p;
    }

    t = turtles[0]->getFeedCostMul();
    for(int i = 0; i < numTurtles; i++)
    {
        totalFoodCost += (baseFoodCost * t)/2;
    }

	m = tigers[0]->getFeedCostMul();
    for(int i = 0; i < numTigers; i++)
    {
        totalFoodCost += baseFoodCost * m;
    }

	b = getBank();
	s = b - totalFoodCost;
	setBank(s);

	cout << "The food cost $" << totalFoodCost << "." << endl;
	cout << "After feeding the animals, you have $" << s << " left in the bank." << endl;
	cout << endl; 
}



/*********************************************************************
 ** Description: calFoodCostPremium()
 If food type chosen is premium, this is what you pay
 *********************************************************************/


void Zoo::calcFoodCostPremium()
{	
	int b = 0; 
	int s = 0;
	int m = 0;
	int p = 0;
	int t = 0;	
	int totalFoodCost = 0;

	p = penguins[0]->getFeedCostMul();
    for(int i = 0; i < numPenguins; i++)
    {
        totalFoodCost += baseFoodCost * p;
    }


    t = turtles[0]->getFeedCostMul();
    for(int i = 0; i < numTurtles; i++)
    {
        totalFoodCost += (baseFoodCost * t)/2;
    }

	m = tigers[0]->getFeedCostMul();
    for(int i = 0; i < numTigers; i++)
    {
        totalFoodCost += baseFoodCost * m;
    }
    

    totalFoodCost = totalFoodCost * 2; //multiply total food cost by 2

	b = getBank();
	s = b - totalFoodCost;
	setBank(s);

	cout << "The food cost $" << totalFoodCost << "." << endl;
	cout << "After feeding the animals, you have $" << s << " left in the bank." << endl;
	cout << endl; 

}


/*********************************************************************
 ** Description: calFoodCostCheap()
 If food type chosen is cheap, this is what you pay
 *********************************************************************/


void Zoo::calcFoodCostCheap()
{	
	int b = 0; 
	int s = 0;
	int m = 0;
	int p = 0;
	int t = 0;	
	int totalFoodCost = 0;

	p = penguins[0]->getFeedCostMul();
    for(int i = 0; i < numPenguins; i++)
    {
        totalFoodCost += baseFoodCost * p;
    }

    t = turtles[0]->getFeedCostMul();
    for(int i = 0; i < numTurtles; i++)
    {
        totalFoodCost += (baseFoodCost * t)/2;
    }

	m = tigers[0]->getFeedCostMul();
    for(int i = 0; i < numTigers; i++)
    {
        totalFoodCost += baseFoodCost * m;
    }
    
    totalFoodCost = totalFoodCost / 2;   //divide total cast of food by 2

	b = getBank();
	s = b - totalFoodCost;
	setBank(s);

	cout << "The food cost $" << totalFoodCost << "." << endl;
	cout << "After feeding the animals, you have $" << s << " left in the bank." << endl;
	cout << endl; 
}


/*********************************************************************
 ** Description: calcPayoff()
 Calculates total playoff of all the animals, sendt it to calcProfit()
 to calculate for the day 
 *********************************************************************/


int Zoo::calcPayoff()
{
	int p, m, n;
	int moneyEarned = 0;

	p = penguins[0]->getPayoff();
    for(int i = 0; i < numPenguins; i++)
    {
        moneyEarned += p;
    }

	m = turtles[0]->getPayoff();
    for(int i = 0; i < numTurtles; i++)
    {
        moneyEarned += m;
    }

	n = tigers[0]->getPayoff();
    for(int i = 0; i < numTigers; i++)
    {
        moneyEarned += n;
    } 

    return moneyEarned;
}


/*********************************************************************
 ** Description: calcProfit()
 Calculates total profit of the day
 *********************************************************************/


void Zoo::calcProfit()
{

	int m, p, b, s;
	p = calcPayoff();

	cout << "You earned $" << p << " in profit today!" << endl;
	b = getBank();
	s = p + b;
	setBank(s);
	cout << "You now have $" << s << " in the bank." << endl;
	cout << endl; 

}


/*********************************************************************
 ** Description: feedTypeResult()
Sets probabiliy for random events to occur, based on feed type chosen
 *********************************************************************/


int Zoo::feedTypeResult(int feedChosen)
{
	int event, e1, e2;
	if (feedChosen == 1) //If feed type is premium, retun higher number (since animalDies is case 1 in randomEvent())
	{
		e1 = rand() % 3 + 1;
		e2 = rand() % 3 + 1;
		if (e1 > e2)
		{
			event = e1;
			return event;
		}
		else if (e2 > e1)
		{
			event = e2;
			return event;
		}
		else
		{
			event = e1;
		}
	}
	else if (feedChosen == 2) //If feed type is cheap, retun lower number (since animalDies is case 1 in randomEvent())
	{
		e1 = rand() % 2 + 1;
		e2 = rand() % 2 + 1;
		if (e1 < e2)
		{
			event = e1;
			return event;
		}
		else if (e2 < e1)
		{
			event = e2;
			return event;
		}
		else
		{
			event = e1;
		}
	}
	else 
	{
		if (feedChosen == 3) //random number
		event = rand() % 3 + 1;
		return event;
	}
}



/*********************************************************************
 ** Description: randomEvent(int event)
Random event happen occur, based on feed type chosen
 *********************************************************************/


void Zoo::randomEvent(int event)
{
	cout << "Something is about to happen..." << endl;
	switch(event)
	{
		case 1:
		{
			randomAnimalDies();
			break;
		}

		case 2:
		{
			randomBoom();
			break;
		}

		case 3:
		{
			pickRandomAnimalBaby();
			break;
		}
	}
}



/*********************************************************************
 ** Description: randomAnimalDies()
Random animal dies
 *********************************************************************/

void Zoo::randomAnimalDies()
{
	int n = 0;
	int num = 0;
	int animal = rand() % 3 + 1; //generate random number
	switch(animal)
	{
		case 1:
		{
			if (deadPenguins() == false) //check if there are any penguins left
			{
				n = getNumPenguins();
				num = n - 1;
				delete penguins[num];
		        setNumPenguins(num);

		        cout << "A penguin died." << endl;
		        cout << "You have " << numPenguins << " penguins left" <<endl;
	    	}
	    	else
	    	{
	    		randomAnimalDies();
	    	}
			break;
		}

		case 2:
		{
			if (deadTurtles() == false)
			{
				n = getNumTurtles();
				num = n - 1;
				delete turtles[num];
		        setNumTigers(num);
		        cout << "A turtle died." << endl;
		        cout << "You have " << numTurtles << " turtles left." <<endl;
	    	}
	    	else
	    	{
	    		randomAnimalDies();
	    	}
			break;
		}

		case 3:
		{
			if (deadTurtles() == false)
			{
				n = getNumTigers();
				num = n - 1;
				delete tigers[num];
		        setNumTigers(num);
		        cout << "A tiger died." << endl;
		        cout << "You have " << numTigers << " tigers left." <<endl;
			}
			else
			{
				randomAnimalDies();
			}
			break;
		}
	}

}



/*********************************************************************
 ** Description: getter and setter functiond to get the capacity of different
 animal capacities, for  use by expandArray()
 *********************************************************************/


int Zoo::getPenguinCapacity()
{
	return penguinCapacity;
}

int Zoo::getTurtleCapacity()
{
	return turtleCapacity;
}

int Zoo::getTigerCapacity()
{
	return tigerCapacity;
}

void Zoo::setTigerCapacity(int cap)
{
	tigerCapacity = cap;
}

void Zoo::setPenguinCapacity(int cap)
{
	penguinCapacity = cap;
}

void Zoo::setTurtleCapacity(int cap)
{
	turtleCapacity = cap;
}


/*********************************************************************
 ** Description: expandArray()
 Expand array depending on what animal might have a new object added to
 their array
 *********************************************************************/


void Zoo::expandArray(int animal)
{
	int n = 0;
	int p = 0;
	int t = 0;

	switch(animal)
	{
		case 1:
		{
			n = getNumPenguins();
			p = getPenguinCapacity();

			if (n > (p-7)) //penguins have 5 babies, so oncc there's less then 4 spaces left, expand array
			{
			    t = p * 2;
			    Penguin **temp = new Penguin*[t]; //create new temp array twice the size
			    for (int i = 0; i < n; i++)
			    {
			        temp[i] = penguins[i];  //copy penguin[i] into temp array
			    }
			    delete[] penguins; //delete old array
			    penguins = temp;

			    setPenguinCapacity(t);
			    cout << "Your Penguin aquarium expanded too!" << endl;
			}
			else
			{
				cout << "Your Penguin aquarium didn't expand" << endl;
			}
			break;
		}

		case 2:
		{
			n = getNumTurtles();
			p = getTurtleCapacity();

			if (n > (p-9)) //expand array if there'r less than 9 spots left for turtle objects
			{
		      	t = p * 2;

		      	Turtle **temp = new Turtle*[t]; //create new temp array twice the size
		      	for (int i = 0; i < n; i++)
		      	{
		        	temp[i] = turtles[i];  //copy turtles[i] into temp array
		      	}
		      	delete[] turtles; //delete old array
		      	turtles = temp;

		      	setTurtleCapacity(t);
		      	cout << "Your Turtle aquarium expanded too!" << endl;
			} 
			else
			{
				cout << "Your Turtle aquarium didn't expand." << endl;
			}
			break;
		}

		case 3: 
			{
				n = getNumTigers();
				p = getTigerCapacity();

				if (n > (p-3))
				{
				    t = p * 2;

				    Tiger **temp = new Tiger*[t]; //create new temp array, twice the size
				    for (int i = 0; i < n; i++)
				    {
				        temp[i] = tigers[i]; //copy turtles[i] into temp array
				    }
				    delete[] tigers; //delete old array
				    tigers = temp;

				    setTigerCapacity(t);
				    cout << "Your Tiger pen expanded too!" << endl;
				}
				else
				{
					cout << "Your Tiger pen didn't expand" << endl;
				}
				break;
			}
		}
}
	


/*********************************************************************
 ** Description: getNumAnimals()
 Gets how many of each animals are in the zoo
 *********************************************************************/


void Zoo::getNumAnimals()
{
	cout << "You have " << numPenguins << " penguins." << endl;
	cout << "You have " << numTurtles << " turtles." << endl;
	cout << "You have " << numTigers << " tigers." << endl;
	cout << endl;
}


/*********************************************************************
 ** Description: randomBoom()
From the random function, calculates bonus for every tiger
 *********************************************************************/


void Zoo::randomBoom()
{
	int bonus1 = 0;
	int bonus = 0;
	int numT = 0;
	int tigerProfit = 0;
	int b = 0;
	int t = 0;
	bonus1 = rand() % 500 + 1;

	while (bonus1 < 250) //redo bonus if it's less than $250
	{
		bonus1 = rand() % 500 + 1;
	}
	bonus = bonus1; 

	int p = getNumTigers();
	tigerProfit = p * bonus;
	b = getBank();
	t = b + tigerProfit;
	setBank(t); //Update bank

	cout << "You earned a $" << bonus << " bonus for each of your " << p << " tigers!" << endl;
	cout << "You have $" << bank << " in your bank." << endl;
}


/*********************************************************************
 ** Description: pickRandomAnimalBaby()
//From the random function
//Goes through every animal to see if they are old enough to have babies
 *********************************************************************/


int Zoo::pickRandomAnimalBaby()
{
	int animal = rand() % 3 + 1;
	switch(animal)
	{
		case 1: //penguins
		{
			if (isOldEnough(1) == 1)
			{
			 	randomBabyBorn(1);
			}
			else 
				{
					return (isOldEnough(animal) == 0);
				}
			break;
		}

		case 2: //tutles
		{
			if (isOldEnough(2) == 1)
			{
			 	randomBabyBorn(2);
			}
			else 
				{
					return (isOldEnough(animal) == 0);
				}			
			break;
		}

		case 3: //tigers
		{
			if (isOldEnough(3) == 1)
			{
			 	randomBabyBorn(3);
			}
			else 
				{
					return (isOldEnough(animal) == 0);
				}			
			break;
		}
	}

	if(isOldEnough(animal) == 0) //redo if false
	{
		if (isOldEnough(1))
		{
			randomBabyBorn(1);
		}
		else if (isOldEnough(2))
		{
			randomBabyBorn(2);
		}

		else if (isOldEnough(3) == 1) //else if
		{
			randomBabyBorn(3);
		}
		else
		{
			cout << endl;
		}
	}
}


/*********************************************************************
 ** Description: isOldEnough()
Checks if animal is old enough to have babies
 *********************************************************************/


bool Zoo::isOldEnough(int animal)
{
	switch(animal)
	{
		case 1:
			{
				for(int i = 0; i < numPenguins; i++)
			    {
	            	if(penguins[i]->getAge() >= 3)
	            	{
	                	return true;
	            	}
	            	else 
	            	{
	            		return false;
	            	}
	            }
				break;
			}

		case 2:
			{
			    for(int i = 0; i < numTurtles; i++)
			    {
	            	if(turtles[i]->getAge() >= 3)
	            	{
	                	return true;
	            	}
	            	else 
	            	{
	            		return false;
	            	}
	            }
				break;
			}

		case 3:
			{
			    for(int i = 0; i < numTigers; i++)
			    {
	            	if(tigers[i]->getAge() >= 3)
	            	{
	                	return true;
	            	}
	            	else 
	            	{
	            		return false;
	            	}
	            }
				break;
			}
	}
}


/*********************************************************************
 ** Description: randomAnimalBaby()
From randomEvent(), creates new baby animal and dynamically adds to array,
updates number of animals checks if array needs to expand 
 *********************************************************************/


void Zoo::randomBabyBorn(int animal)
{
	int n = 0;
	int num = 0;
	int b = 0;
	int nb = 0;
	int babies = 0;

	switch(animal)
	{
		case 1:
		{
			n = getNumPenguins();
			b = penguins[0]->getBabies(); //5 
			babies = b;

			cout << endl;
			for (int i = (n-1); i <= ((n-1) + babies); i++)
			{
				penguins[i] = new Penguin;
			}

			nb = n + b;

	        setNumPenguins(nb);
	        cout << "Penguins were born!" << endl;
	        expandArray(1); //check if need to expand array
	        cout << "You have " << numPenguins << " penguins" <<endl;
	        break;
        }

		case 2:
		{
			n = getNumTurtles();
			b = turtles[0]->getBabies(); //10 
			babies = b;

	       	expandArray(2); //check if need to expand array before adding turtles because they have a lot of babies

			for (int i = (n-1); i <= ((n-1) + babies); ++i)
			{
				turtles[i] = new Turtle;
			}
			nb = n + b;

	        setNumTurtles(nb);
	        cout << "Turtles were born!" << endl;
	        cout << "You have " << numTurtles << " turtles" <<endl;
			break;
		}

		case 3:
		{
			n = getNumTigers();
			num = n + 1;
			tigers[num-1] = new Tiger;
	        setNumTigers(num);
	        cout << "A penguin was born!" << endl;
	        expandArray(3);
	        cout << "You have " << numTigers << " tigers" <<endl;
	        break;
		}
	}
}

/*********************************************************************
 ** Description: bool functions checking if animals are dead, ie there's
 0 objects of that animal type left
 *********************************************************************/

bool Zoo::deadPenguins()
{
	if (getNumPenguins() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Zoo::deadTurtles()
{
	if (getNumTurtles() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Zoo::deadTigers()
{
	if (getNumTigers() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*bool Zoo::allDead()
{
	if (deadTurtles() == true && deadPenguins() == true && deadTigers() == true)
	{
		cout << "All your animals are dead :(" << endl; 
		cout << "You need to buy more in order to keep playing!" << endl;
		return true;
	}
	else 
	{
		return false;
	}
}
*/

/*********************************************************************
 ** Description: buyNewAdultAnimal()
 Validates if user wants to buy new adult animal, sends them to createAdultAnima()
 if they do want to 
 *********************************************************************/


void Zoo::buyNewAdultAnimal()
{
	std::string buyInput;
	std::string buyAnimalInput;
	int choice = buyNewAdultAnimalPrompt(buyInput);
	int chooseAnimal;


	switch (choice)
	{
        case 1:
        {
            cout << "Here are your options:" << endl;
            chooseAnimal = buyNewAdultAnimalType(buyAnimalInput);
            createAdultAnimal(chooseAnimal);
            break;
        }

        case 2:
        {
            cout << "Okay then, see you tomorrow!" << endl;
            keepPlaying();
            break;
        }
    }
}


/*********************************************************************
 ** Description: createsAdultAnimal()
 Dynamically creates new animal type objectm sets age to 3
 *********************************************************************/


void Zoo::createAdultAnimal(int chooseAnimal)
{
	int n = 0;
	int num = 0;
	int gB = 0;
	int sB = 0;
	int c = 0;	

	switch(chooseAnimal)
	{
		case 1:
		{
			n = getNumPenguins();
			num = n + 1;
	        expandArray(1); //check if need to expand array
			penguins[num-1] = new Penguin;
	        setNumPenguins(num);
	        gB = getBank();
	        sB = gB - 1000;
	        setBank(sB);
	        cout << "You bought a new adult penguin." << endl;
	        cout << "You have " << numPenguins << " penguins" <<endl;
	        cout << "You now have $" << sB << " in the bank." << endl;
	        penguins[num-1]->setAge(3);
			break;
		}
		case 2:
		{
			n = getNumTurtles();
			num = n + 1;
	        expandArray(2); //check if need to expand array
			turtles[num-1] = new Turtle;
	        setNumTurtles(num);
	        gB = getBank();
	        sB = gB - 100;
	        setBank(sB);
	        cout << "You bought a new adult turtle." << endl;
	        cout << "You have " << numTurtles << " turtles." <<endl;
	       	cout << "You now have $" << sB << " in the bank." << endl;
	        turtles[num-1]->setAge(3);
			break;
		}
		case 3:
		{
			n = getNumTigers();
			num = n + 1;
	        expandArray(3); //check if need to expand array
			tigers[num-1] = new Tiger;
	        setNumTigers(num);
	        gB = getBank();
	        sB = gB - 10000;
	        setBank(sB);
	        cout << "You bought a new adult tiger." << endl;
	        cout << "You have " << numTigers << " tigers." <<endl;
	       	cout << "You now have $" << sB << " in the bank." << endl;
	        tigers[num-1]->setAge(3);
	        break;
	    }

	}
}

void Zoo::noMoney()
{
	if (getBank() == 0)
	{
		cout << "You don't have anymore money, you have to quit" << endl;
	}
	else
	{
		cout << "You have enough money for the next game" << endl;
	}
}


/*********************************************************************
 ** Description: deallocate()
 Deallocates memory at the end of the game
 *********************************************************************/

void Zoo::deallocate()
{
	int n;
	n = getNumTigers();

	delete [] turtles;
	delete [] penguins;
	delete [] tigers; //tiger dies
}