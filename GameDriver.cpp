/* -------------------------------------------
 *
 * File Name: GameDriver.cpp
 * Author: Afnan Elhamshari
 * KUID: 2894852
 * Email: afnan.elhamshari@ku.edu
 * Homework Assignment Number: Homework 04
 * Discription: definition of GameDriver Class
 * Last Changed: 11/16/2016
--------------------------------------------- */
#include "GameDriver.h"
#include "hangman.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

GameDriver::GameDriver(string file)
{
	wordFile = file;
	srand(time(NULL));
	readFile();
}

GameDriver::~GameDriver()
{
	delete [] wordList;
}

void GameDriver::readFile()
{
	ifstream infile;
	infile.open(wordFile);
	infile >> wordList_size;
	wordList = new string [wordList_size];
	for (int i=0; i<wordList_size;i++)
	{
		infile >> wordList[i];
	}
}

string GameDriver::chooseword()
{
	return (wordList[rand()%wordList_size]);
}

void GameDriver::run()
{
	do
	{
		word_to_be_guessed = chooseword();
		Hangman* H = new Hangman(word_to_be_guessed);
		interaction(H);
		delete H;
	}while(playagain());

}

void GameDriver::interaction(Hangman* G)
{	
	char guess = '0';
	string word = "0";
	do
	{
		cout << "\nGuess this: ";
		cout << G->getDisguisedWord() <<endl;
		cout << "Guesses so far: " << G->getGuessCount() << endl;
		cout << "Misses: " << G->getMissedMarker() << endl;
		cout << "Enter your guess character: ";
		getline (cin, word);
		if (word.length() > 1)
		{
			//guesses the whole word
			if (G->getDisguisedWord().length() == word.length())
			{
				if (G->areWordGuessesAllowed())
				{
					if (!(G->guessWord(word)))
					{
						cout << word << " is not the secret word. you can't guess words any more.\n";
					}
					else{
						break;
					}
				}
				else
				{
					cout << "Sorry, you aren't allowed to make any more guesses.\n";
				}
			}
			else
			{
				cout << "The length of the guess and the secret word don't match.\n";
				cout << "The length of the secret word is " << G->getDisguisedWord().length() << " Your guess length is " << word.length() << ".\n";
			}
		}
		else
		{
			guess = word[0];
			if (G->guessCharacter(guess))
			{
				cout << guess << " is in the secret word!\n";
			}
			else
			{
				cout << guess << " is not in the secret word. Death draws closer.\n";
			}
		}
	}while (!(G->isGameOver()));
	if (G->isFound())
	{
		cout << "\nCongratulations! you guessed the secret word: " << word_to_be_guessed << " in " << G->getGuessCount() << " guesses!\n";
	}
	else
	{
		cout << "\nGame Over!\n";
		cout << "You died. The Secret word was " << G->getSecretword() <<"\nNext time, guess as if your life depends on it.\n";
	}
}

bool GameDriver::playagain()
{
	char again;
	do
	{
		cout << "\nDo you want to play again? (y/n):\n";
		cin >> again;
		cin.ignore (1, '\n');
		again = tolower(again);
	}while (again != 'y' && again != 'n');
	if (again == 'y')
	{
		return true;
	}
	cout << "\nThanks for playing Hangman!\n";
	return false;
}