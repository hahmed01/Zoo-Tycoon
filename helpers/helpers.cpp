
/*********************************************************************
** Program name: Zoo Tycoon
** Author: Haya Ahmed
** Date: October 21, 2018
** Description: Implementation of the helper functions.
*********************************************************************/

#include <iostream>
#include <string>
#include "helpers.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;

/*********************************************************************
 ** Description: validateAnimalInput()
 Validates number of animals to be made
 *********************************************************************/

int validateAnimalInput(std::string animalInput)
{
    cout << "Enter an integer of how many you want" << endl;
    cout << "1. One of this animal" << endl;
    cout << "2. Two of this animal" << endl;
    cout << endl;
    getline(cin, animalInput);
    int chooseOption;
    chooseOption = atoi(animalInput.c_str());


    while (containChar(animalInput) || (chooseOption != 1 && chooseOption != 2))
        {
            cout << "Invalid input. Please enter integer 1 or 2" << endl;
            getline(cin, animalInput);
            chooseOption = atoi(animalInput.c_str());
        }

    switch(chooseOption)
    {
        case 1:
        {
            cout << "You bought one" << endl;
            cout << endl;
			return 1;
            break;
        }
        case 2: 
        {
            cout << "You bought two." << endl;
            cout << endl;
            return 2;
            break;
        }
    }
}

/*********************************************************************
 ** Description: buyNewAdultPomp()
 Validates if user wants to buy new animal
 *********************************************************************/


int buyNewAdultAnimalPrompt(std::string buyInput)
{

    cout << "Would you like to buy a new adult animal?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    getline(cin, buyInput);
    int chooseOption;
    chooseOption = atoi(buyInput.c_str());


    while (containChar(buyInput) || (chooseOption != 1 && chooseOption != 2))
        {
            cout << "Invalid input. Please enter integer 1 or 2" << endl;
            getline(cin, buyInput);
            chooseOption = atoi(buyInput.c_str());
        }

    switch(chooseOption)
    {
        case 1:
        {
            cout << "Which animal do you want to buy?" << endl;
            cout << endl;
            return 1;
            break;
        }
        case 2: 
        {
            cout << "See you tomorrow!" << endl;
            cout << endl;
            return 2;
            break;
        }
    }

}


/*********************************************************************
 ** Description: buyNewAnimalType()
 Validates type of animal to be made
 *********************************************************************/


int buyNewAdultAnimalType(std::string buyAnimalInput)
{
    cout << "1. A Penguin for $1000" << endl;
    cout << "2. A Turtle for $100" << endl;
    cout << "3. A Tiger for $10000" << endl;


    getline(cin, buyAnimalInput);
    int chooseOption = atoi(buyAnimalInput.c_str());



    while (containChar(buyAnimalInput) || (chooseOption != 1 && chooseOption != 2 && chooseOption != 3))
        {
            cout << "Invalid input. Please enter integer 1 or 2" << endl;
            getline(cin, buyAnimalInput);
            chooseOption = atoi(buyAnimalInput.c_str());
        }

    switch(chooseOption)
    {
        case 1:
        {
            cout << "You bought one Penguin" << endl;
            return 1;
            break;
        }
        case 2: 
        {
            cout << "You bought one Turtle." << endl;
            return 2;
            break;
        }
        case 3:
        {
            cout << "You bought one Tiger" << endl;
            return 3;
            break;
        }
    }

}


/*********************************************************************
 ** Description: pickfeedType()
 Validates tupe of feed chosen
 *********************************************************************/


int pickFeedType(std::string foodInput)
{
    cout << "You get to choose between three different feed types." << endl;
    cout << "Pick Premium, and your animals are half as likely to die BUT the food costs twice as much." << endl;
    cout << "Pick Cheap, and the cost of food is half as expensive, but your animals are twice as likely to die." << endl;
    cout << "Pick Generic, and you pay the standard food cost and your animals have the same chance of dying as they normally would." << endl;
    cout << "1. Premium" << endl;
    cout << "2. Cheap" << endl;
    cout << "3. Generic" << endl;
    getline(cin, foodInput);
    int chooseOption = atoi(foodInput.c_str());


    while (containChar(foodInput) || (chooseOption != 1 && chooseOption != 2 && chooseOption != 3))
        {
            cout << "Invalid input. Please enter integer 1 or 2 or 3." << endl;
            getline(cin, foodInput);
            chooseOption = atoi(foodInput.c_str());
        }

    switch(chooseOption)
    {
        case 1:
        {
            cout << "You chose Premium" << endl;
            return 1;
            break;
        }

        case 2:
        {
            cout << "You chose Cheap" << endl;
            return 2;
            break;
        }

        case 3:
        {
            cout << "You chose Generic" << endl;
            return 3;
            break; 
        }
    }
    cout << endl; 
}

/*********************************************************************
 ** Description: validateInput()
 ** This function asks the user for an integer value  and validates the 
 input (making sure it is an integer). It repeatedly asks
 the user for valid input until the user enters valid input. It returns
 the validated input.
 *********************************************************************/

int validateInput(std::string usrInput)
{
    getline(cin, usrInput);
    int userInput = atoi(usrInput.c_str());

    while (containChar(usrInput) || (userInput != 1 && userInput != 2))
    {
            cout << "Invalid input. Please enter a valid integer." << endl;
            getline(cin, usrInput);
            userInput = atoi(usrInput.c_str());
    }
    
    switch(userInput)
    {
        case 1:
        {
            return 1;
            break;
        }
        case 2: 
        {
            return 2;
            break;
        }
    }
}

/*********************************************************************
 ** Description: containChar()
 ** This boolean function takes a string as an an inout and iterated it to
 see if it has an alphabet character. Using this, validateInput() only accepts
 numeric values.
 *********************************************************************/

bool containChar(std::string usrInput)
{
    for (int i = 0; i < usrInput.length(); i++)
    {
        if(isalpha(usrInput[i]))
        {
            return true;
        }
    }
}

/*********************************************************************
 ** Description: withinRange()
 ** This boolean function takes an integer and tests if it is within range,
 ensuring that the value passed through validateInput() is within range and
 a positive number.
 *********************************************************************/

bool withinRange(int userInput)
{

    if (userInput > 0 && userInput < 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}