objects = main.o Animal.o Zoo.o Tiger.o Turtle.o Penguin.o helpers.o

all: zooTycoon

zooTycoon: $(objects)
	g++ $(objects) -o zooTycoon

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -std=c++11 -c Animal.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -std=c++11 -c Zoo.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -std=c++11 -c Tiger.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -std=c++11 -c Turtle.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -std=c++11 -c Penguin.cpp

helpers.o: helpers.cpp helpers.hpp
	g++ -std=c++11 -c helpers.cpp

clean:
	rm *.o zooTycoon