/* ------------------------------------------------------------
 *
 * File Name: GameDriver.h
 * Author: Afnan Elhamshari
 * KUID: 2894852
 * Email Address: afnan.elhamshari@ku.edu
 * Assignment: EECS-169 Homework04
 * Description: declaring GameDriver class
 * Date: 11/12/2016
 *
 ---------------------------------------------------------- */
#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include "hangman.h"

class GameDriver
{
	private:
		//current word to be guessed
		string word_to_be_guessed;
		//File that contains all the possible words in the game, this file has the length of the array as
		//the first row
		string wordFile;
		//Size of the words array
		int wordList_size;
		//an array that contains all the words in the file
		string* wordList;

	public:
		GameDriver(string file);
		~GameDriver();
		//Runs an instance of Hangman
		void run();
		//Displays all the updates with in a hangman game
		void interaction(Hangman* G);
		//Reads the contents of the words file into the array
		void readFile();
		//Randomly chooses the current word to guess
		string chooseword();
		//Gives the option of running another hangman instance
		bool playagain();

};
#endif
