#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <tuple>

#include "grid/GridNumberGenerator.h"
#include "grid/GridPrinter.h"

using grid_type = std::array<std::array<int, 9>, 9>;

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min = 1, int max = 9)
	{
		std::uniform_int_distribution range(min, max);
		return range(mt);
	}
}

void checkIfRowHasNumber(const grid_type& numbers, int currentRow, int numberToInsert,
		bool& changeTheNumber)
{
	for (int rowColumn{ 0 }; rowColumn < 9; ++rowColumn)
	{
		if (numbers[currentRow][rowColumn] == numberToInsert)
		{
			changeTheNumber = true;
			break;
		}
	}
}

void checkIfColumnHasNumber(const grid_type& numbers, int currentColumn, int numberToInsert,
		bool& changeTheNumber)
{
	for (int columnRow{ 0 }; columnRow < 9; ++columnRow)
	{
		if (numbers[columnRow][currentColumn] == numberToInsert)
		{
			changeTheNumber = true;
			break;
		}
	}
}

void checkIf3x3BoxHasNumber(const grid_type& numbers, int currentRow, int currentColumn,
		int numberToInsert, bool& changeTheNumber)
{
	int boxRowIndex{ currentRow / 3 };
	int boxColumnIndex{ currentColumn / 3 };
	for (int row{ boxRowIndex * 3 }; row < boxRowIndex * 3 + 3; ++row)
		{
		for (int column{ boxColumnIndex * 3 }; column < boxColumnIndex * 3 + 3; ++column)
		{
			if (numbers[row][column] == numberToInsert)
			{
				changeTheNumber = true;
				break;
			}
		}
	}
}

void generateNumbers(grid_type& numbers)
{
	// mode
	int numberOfClues{ 27 };
	std::cout << "number of clues generated: " << numberOfClues << '\n';
	// now we need to generate the positions randomly
	for (int cluePosition{ 0 }; cluePosition < numberOfClues; ++cluePosition)
	{
		auto position{ std::make_pair(rnd::getNumber(0, 8), rnd::getNumber(0, 8)) };

		// if the position already has a number, create a new position
		while (numbers[position.first][position.second])
		{
			position = std::make_pair(rnd::getNumber(0, 8), rnd::getNumber(0, 8));
		}

		// create a random number
		int numberToInsert{ rnd::getNumber() };

		// search for that number in the current row, column and 3x3 box
		while (true)
		{
			bool changeTheNumber{ false };

			checkIfRowHasNumber(numbers, position.first, numberToInsert, changeTheNumber);
			
			checkIfColumnHasNumber(numbers, position.second, numberToInsert, changeTheNumber);

			checkIf3x3BoxHasNumber(numbers,position.first, position.second, numberToInsert, changeTheNumber);

			if (changeTheNumber)
			{
				numberToInsert = rnd::getNumber();
			}
			else
			{
				break;
			}
		}
		numbers[position.first][position.second] = numberToInsert;
	}
}

// easy mode: 30 - 36 clues
// medium mode: 26 - 29 clues
// hard mode: 22 - 25 clues
// expert mode: 18 - 21 clues
// nightmare mode: 17 clues
//
// a better idea would be to fill the board entirely and then remove one number and run a 
// sudoku solver on that board. if more than one solution exists, try removing another number
// do this until you have reached the appropritate number of clues. we also want to remove 
// the numbers randmoly across the board to make it look nicer.

int main()
{	
	grid_type numbers{};
	generateNumbers(numbers);
	GridPrinter gridPrinter{ numbers };
	gridPrinter.printGrid();

	return 0;
}
