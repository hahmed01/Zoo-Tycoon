# Zoo-Tycoon
Interactive virtual zoo, written in C++. Tiger, penguin and turtule are inherited classes from Animal. The Animal class has private variables that determine the age, cost of buying, cost of feeding, payoff and number of babies that animal can have. The Zoo class contains a dynamic array of every animal, and the control flow of the game. The game begins with the player buying one of two of each animal. Every turn is a day. The following events happen in a day:
1. The user feeds the animals
2. A random event occurs. An animal dies (dynamic array may be resized) OR there's a boom in zoo attendance (increased profit) OR baby animals are born (dynamic array may be resized). 
3. The profit of the day is calculated. The player has the option to buy an adult animal.

### Instructions for running
Compile using:
```
make
```
Run using
```
zooTycoon
```
