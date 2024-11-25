#include <iostream>
#include "header.h"
#include <random>
#include <string>

void mathProblems()
{
	std::random_device rd;
	std::mt19937 mathGen(rd());
	std::uniform_int_distribution<> range(1, 10);

	int score = 0;
	std::cout << "Welcome to our game where you will have to solve math problems!" << std::endl;
	std::cout << "You have to solve 10 math problems. For each solved problem you get 1 point." << std::endl;
	std::cout << "To achieve an excellent score you must have at least 8 points. If you have less than 6 points you lose" << std::endl;
	std::cout << "Are you ready? Let's get started" << std::endl;

     
	for(int i = 1; i <= 10; ++i)
	{
	
		int num1 = range(mathGen);
		int num2 = range(mathGen);
		char actions[] = { '+', '-', '*' };
		std::uniform_int_distribution<> a_range(0, 2);
		char operation = actions[a_range(mathGen)];

		int correctAnswer = 0;
		switch (operation)
		{
		case '+' :
			correctAnswer = num1 + num2;
			break;
		case '-' :
			correctAnswer = num1 - num2;
			break;
		case '*' :
			correctAnswer = num1 * num2;
			break;
		}
		std::cout << "Problem " << i << ": " << num1 << " " << operation << " " << num2 << " = ?" << std::endl;
		int answer;
		std::cout << "Your answer is: ";
		std::cin >> answer;

		if (answer == correctAnswer)
		{
			std::cout << "Correct!" << std::endl;
			++score;
		}
		else
		{
			std::cout << "Incorrect. The answer is: " << correctAnswer << std::endl;
		}

	}
	std::cout << "Game over!" << std::endl;
	std::cout << "Your result is: " << score << " points" << std::endl;

	if (score >= 8)
	{
		std::cout << "Excellent performance!" << std::endl;
	}
	else if (score >= 6)
	{
		std::cout << "You did well!" << std::endl;
	}
	else
	{
		std::cout << "You lost. Try again!" << std::endl;
	}
	return;
}