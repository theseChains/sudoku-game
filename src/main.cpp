#include <iostream>
#include <iomanip>
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

void printNumberRows(int currentRow)
{
	std::cout << currentRow + 1 << ' ';
	for (int boxColumn{ 0 }; boxColumn < 9; ++boxColumn)
	{
		if (boxColumn == 0 || boxColumn == 3 || boxColumn == 6)
		{
			// the numbers are to be inserted here
			std::cout << boldOn << "| " << boldOff << rnd::getNumber() << ' ';
		}
		else
		{
			std::cout << boldOff << "| " << rnd::getNumber() << ' ';
		}
	}
	std::cout << boldOn << "|\n";
}

void printGrid()
{
	printLettersAtTheTop();
	printTopLine();

	for (int row{ 0 }; row < 9; ++row)
	{
		printNumberRows(row);	
		printNonNumberRows(row);
	}
}

int main()
{	
	printGrid();

	return 0;
}
