/* ---------------------------------
 *
 * File Name: hangman.cpp
 * Author: Afnan Elhamshari
 * KUID: 2894852
 * Email Address: afnan.elhamshari@ku.edu
 * Homework Assignment Number: Homework 04
 * Description: Definition of the hangman Class
 * Last Changed: 11/16/2016
----------------------------------- */
#include "hangman.h"
#include <string>
#include <iostream>
using namespace std;

//Preconditions: The user provide a secret word
Hangman::Hangman(string Intial)
{
	disguisedWordSize = Intial.length();
	for (int i=0; i<disguisedWordSize; i++)
	{
		Intial[i] = tolower(Intial[i]);
	}
	secretWord = Intial;
	disguisedWord = new char [disguisedWordSize];

	for (int i = 0; i < disguisedWordSize; i = i + 1)
	{
		if (secretWord[i] == ' ')
		{
			disguisedWord[i] = secretWord [i];
		}
		else
		{
			disguisedWord[i] = '?';
		}
	}
	guessCount = 0;
	missesCount = 0;
	WordGuess = true;
	Found = false;
	MAX_MISSES_ALLOWED = 7;
	missedMarkers = new char [MAX_MISSES_ALLOWED];
	for (int i = 0; i < MAX_MISSES_ALLOWED; i = i + 1)
	{
		missedMarkers[i] = 'O';
	}
}
//Postconditions: All of the private members are intialized and ready to be used in the other methods.

//Precondition: The program is finished.
Hangman::~Hangman()
{
        delete [] disguisedWord;
        delete [] missedMarkers;
		disguisedWord = nullptr;
		missedMarkers = nullptr;
}
//Postconditions: All arrays in private members are deleted.

//Preconditions: The user the user either found the secret word or out of misses.
bool Hangman::isGameOver()
{
	if (isFound() || Found)
	{
		return true;
	}
	if ( missesCount >= MAX_MISSES_ALLOWED)
	{
		return true;
	}
	return false;
}
//Postcondition: If true a set of the game will be over, if not the game will go on.

//Precondition: The user finds the secret word.
bool Hangman::isFound()
{
	if (Found)
	{
		return(true);
	}
	for (int i = 0; i < disguisedWordSize; i = i + 1)
	{
		if (disguisedWord[i] == '?')
		{
			return false;
		}
	}
	return true;
}
//postcondition: The set of the game ends .

//precondition: guessCount is intialized.
int Hangman::getGuessCount()
{
	return guessCount;
}
//postcondition: guessCount is returned to be used.

//precondition: The user provides a character guess.
bool Hangman::guessCharacter(char c)
{
	guessCount = guessCount + 1;
	int guess = 0;
	for (int i = 0; i < disguisedWordSize; i = i + 1)
	{
		if (secretWord[i] == c)
		{
			disguisedWord [i] = c;
			guess = guess + 1;
		}
	}
	if (guess !=0)
	{
		return true;
	}
	else
	{
		missesCount = missesCount + 1;
	}
	return false;
}
//Postconditions: The guesses count increases by one.
//                If it hits the array will be updated.
//                If it misses the missesCount will increase by one.

//Preconditions: The array of the secret word is intialized.
string Hangman::getDisguisedWord()
{
  string mystring (disguisedWord, disguisedWordSize);
	return mystring;
}
//Postcondition: The array is converted into a string and returned.

//Precondition: missesCount is intialized.
int Hangman::getMissesCount()
{
	return missesCount;
}
//Postcondition: missesCount is returned to be used.

//Precondition: The array of the missed marker is intialized.
string Hangman::getMissedMarker()
{
	for (int i = 0; i < missesCount && i < MAX_MISSES_ALLOWED ; i = i + 1)
	{
		missedMarkers[i] = 'X';
	}
  string markers (missedMarkers, MAX_MISSES_ALLOWED);
	return markers;
}
//Postcondition: The array of missedmarker is updated converted into string and returned.

//Precondition: The user provides a whole word with the same size as the secret word.
//              Word guesses are allowed
bool Hangman::guessWord(string word)
{
	guessCount += 1;
	if (word != secretWord)
	{
		WordGuess = false;
	}
	else{
		Found = true;
	}
	return Found;
}
//Postcondition: If true the set of the game will end.
//               If false the user cannot guess any whole words again.


//Precondition: The user provides a whole word with the same size as the secret word.
bool Hangman::areWordGuessesAllowed()
{
	return WordGuess;
}
// PostCondition: If true the word guess will be checked and no more guesses are allowed.

string Hangman::getSecretword()
{
	return(secretWord);
}
