#include<iostream>
#include <random>
#include"header.h"

void numberGame()
{
	std::random_device rn;
	std::mt19937 numGen(rn());
	std::uniform_int_distribution<> range(1, 100);

	int number = range(numGen);
	std::cout << "Welcome to our game! The computer has picked a number between 1 and 100, and your challenge is to guess it. You have 8 attempts. Good luck" << std::endl;

	int guess;
	bool guessed = true;

	for (int attempt = 8; attempt > 0;)
	{
		std::cout << " " << std::endl;
		std::cout << "Attempts left: " << attempt << std::endl;
		std::cout << "Enter number between 1 and 100" << std::endl;
		std::cin >> guess;
		
		while (guessed = true)
		{
			if (guess >= 1 && guess <= 100)
			{
				if (guess == number)
				{
					std::cout << "Correct answer! The number is " << number << std::endl;
					return;
				}
				else if (guess > number)
				{
					std::cout << "The number is lower. Try again." << std::endl;
					attempt--;
					break;
				}
				else if (guess < number)
				{
					std::cout << "The number is higher. Try again." << std::endl;
					attempt--;
					break;
				}
			}
			else
			{
				std::cout << "Incorrect answer. Try again" << std::endl;
				break;
			}
			

		}
		
	}

}
