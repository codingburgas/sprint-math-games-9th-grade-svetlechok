// main project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"
int main()
{

	int choice;
		std::cout << "0. Quit" << std::endl << "1. Start a wordle game" << std::endl << "2. Start math problems game " << std::endl;




		do
		{

			std::cin >> choice;

			switch (choice)
			{
			case 0:
				std::cout << "Goodbye" << std::endl;
				return 0;

			case 1:
				wordleGame();
				break;

			case 2:
				mathProblems();
				break;

			default:
				std::cout << "Incorrect answer. Choose again..." << std::endl;
				break;

			}
			std::cout << "0. Quit" << std::endl << "1. Play again" << std::endl << "2.Play math problems game " << std::endl;
		} while (choice != 0);
	

}


