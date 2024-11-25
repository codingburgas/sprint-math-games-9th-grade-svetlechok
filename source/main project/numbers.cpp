#include<iostream>
#include <random>
#include"header.h"

void numberGame()
{
	std::random_device rn;
	std::mt19937 numGen(rn());
	std::uniform_int_distribution<> range(1, 100);

	int number = range(numGen);
}
