/* ------------------------------------------------------------
 *
 * File Name: hangman.h
 * Author: Afnan Elhamshari
 * KUID: 2894852
 * Email Address: afnan.elhamshari@ku.edu
 * Assignment: EECS-169 Homework04
 * Description: declaring Hangman class
 * Date: 11/12/2016
 *
 ---------------------------------------------------------- */
#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
using namespace std;

class Hangman
{
	private:
		//The secret word to be guessed
		string secretWord;
		//Displays the updated word with ? where the letters have not been
		//guissed yet
		char* disguisedWord;
		//The size of the guessed word
		int disguisedWordSize;
		//Tracks the number of total guesses
		int guessCount;
		//Tracks the number of missed guesses
		int missesCount;
		//The number of maximum allowed misses
		int MAX_MISSES_ALLOWED;
		//An array that shows you the total misses as X, and allowed misses as O
		char* missedMarkers;
		//Tracks if wordGuesses are allowed
		bool WordGuess;
		//Tracks if the secret word is found
		bool Found;
	public:
		Hangman(string Intial);
		~Hangman();
		//Returns if the guessed character is in the word
		bool guessCharacter(char c);
		//Returns if the game is over, either the word is found or
		//the user consumed all of their allowed misses
		bool isGameOver();
		//Returns if the word is found
		bool isFound();
		//Returns the Disguised word
		string getDisguisedWord();
		//Returns the number of guesses
		int getGuessCount();
		//Returns the number of missed guesses
		int getMissesCount();
		//Returns the array with the Xs and Os representing the misses
		string getMissedMarker();
		//Returns if guessWord is allowed
		bool areWordGuessesAllowed();
		//Returns if the guessed word matches the secret word
		bool guessWord(string word);
		//Returns the secret word
		string getSecretword();
};
#endif
