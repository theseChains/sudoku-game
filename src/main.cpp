#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <tuple>

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

std::ostream& boldOn(std::ostream& outputStream)
{
	outputStream << "\e[36;1m";

	return outputStream;
}


std::ostream& boldOff(std::ostream& outputStream)
{
	outputStream << "\e[0m";

	return outputStream;
}

void printLettersAtTheTop()
{
	std::cout << "  ";
	for (char letterLineIndex{ 'A' }; letterLineIndex < 'J'; ++letterLineIndex)
	{
		std::cout << std::setw(3) << letterLineIndex << ' ';
	}
	std::cout << '\n';
}

void printTopLine()
{
	std::cout << "  ";
	for (int topLineIndex{ 0 }; topLineIndex < 9; ++topLineIndex)
	{
		std::cout << boldOn << "+---";
	}
	std::cout << "+\n" << boldOff;
}

void printNonNumberRows(int currentRow)
{
	std::cout << "  ";
	for (int lineColumn{ 0 }; lineColumn < 9; ++lineColumn)
	{
		if (currentRow == 2 || currentRow == 5 || currentRow == 8)
		{
			std::cout << boldOn << "+---";
		}
		else if (lineColumn == 0 || lineColumn == 3 || lineColumn == 6)
		{
			std::cout << boldOn << '+' << boldOff << "---"; 
		}
		else
		{
			std::cout << boldOff << "+---";
		}
	}
	std::cout << boldOn << "+\n" << boldOff;
}

void printNumberRows(int currentRow, const grid_type& numbers)
{
	std::cout << currentRow + 1 << ' ';
	for (int boxColumn{ 0 }; boxColumn < 9; ++boxColumn)
	{
		bool empty{ numbers[currentRow][boxColumn] == 0 };
		if (boxColumn == 0 || boxColumn == 3 || boxColumn == 6)
		{
			// the numbers are to be inserted here
			if (empty)
			{
				std::cout << boldOn << "|   ";
			}
			else
			{
				std::cout << boldOn << "| " << boldOff << numbers[currentRow][boxColumn] << ' ';
			}
		}
		else
		{
			if (empty)
			{
				std::cout << boldOff << "|   ";	
			}
			else
			{
				std::cout << boldOff << "| " << numbers[currentRow][boxColumn] << ' ';
			}
		}
	}
	std::cout << boldOn << "|\n";
}

void printGrid(const grid_type& numbers)
{
	printLettersAtTheTop();
	printTopLine();

	for (int row{ 0 }; row < 9; ++row)
	{
		printNumberRows(row, numbers);	
		printNonNumberRows(row);
	}
}

void generateNumbers(grid_type& numbers)
{
	// easy mode
	int numberOfClues{ rnd::getNumber(27, 32) };
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
		// assign a random number once the position was found
		numbers[position.first][position.second] = rnd::getNumber();
	}
}

// i think i'm just going to use a 2d vector to put and manipulate numbers on the grid
//

int main()
{	
	grid_type numbers{};
	generateNumbers(numbers);
	printGrid(numbers);

	return 0;
}
