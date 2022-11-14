/* ------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Afnan Elhamshari
 * KUID: 2894852
 * Email Address: afnan.elhamshari@ku.edu
 * Assignment: EECS-169 Homework04
 * Description: HangMan Game
 * Date: 11/12/2016
 *
 ---------------------------------------------------------- */
#include "hangman.h"
#include "GameDriver.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string intialWord = " ";
	if (argc == 2)
	{
		string filename = argv[1];
    	GameDriver driver(filename);
		driver.run();
	}
	else
	{
		cout << "Invalid number of arguments. Minimum of two required.\n";
	}

	return 0;
}
