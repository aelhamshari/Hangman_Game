Hangman: main.o hangman.o GameDriver.o
	g++ -std=c++11 -g -Wall main.o hangman.o GameDriver.o -o Hangman

main.o: main.cpp hangman.h GameDriver.h
	g++ -std=c++11 -g -Wall -c main.cpp

GameDriver.o: GameDriver.h GameDriver.cpp hangman.h hangman.cpp 
	g++ -std=c++11 -g -Wall -c GameDriver.cpp 
hangman.o: hangman.h hangman.cpp
	g++ -std=c++11 -g -Wall -c hangman.cpp 

clean: 
	rm *.o Hangman
