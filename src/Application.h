#ifndef SUDOKU_APPLICATION_H
#define SUDOKU_APPLICATION_H

#include <map>
#include <string>
#include <random>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };	
	
	int getNumber(int min = 1, int max = 9)
	{
		std::uniform_int_distribution range(min, max);
		return range(mt);
	}
}

class Application
{
public:
	Application();

	void initializeGrid();
};

#endif
