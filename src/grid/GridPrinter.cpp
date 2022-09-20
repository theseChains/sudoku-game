#include "GridPrinter.h"

GridPrinter::GridPrinter(const grid_type& numbers) : m_numbers{ numbers }
{}

void GridPrinter::printGrid()
{
	printLettersAtTheTop();
	printTopGridLine();

	for (int row{ 0 }; row < 9; ++row)
	{
		printNumberRows(row);
		printNonNumberRows(row);
	}
}

std::ostream& boldOn(std::ostream& out)
{
	out << "\e[36;1m";

	return out;
}

std::ostream& boldOff(std::ostream& out)
{
	out << "\e[0m";

	return out;
}

void GridPrinter::printLettersAtTheTop()
{
	std::cout << "  ";
	for (char lineLetter{ 'A' }; lineLetter < 'J'; ++lineLetter)
	{
		std::cout << std::setw(3) << lineLetter << ' ';
	}
	std::cout << '\n';
}

void GridPrinter::printTopGridLine()
{
	std::cout << "  ";
	for (int topLineIndex{ 0 }; topLineIndex < 9; ++topLineIndex)
	{
		std::cout << boldOn << "+---";
	}
	std::cout << "+\n" << boldOff;
}

void GridPrinter::printNonNumberRows(int currentRow)
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

void GridPrinter::printNumberRows(int currentRow)
{
	std::cout << currentRow + 1 << ' ';
	for (int column{ 0 }; column < 9; ++column)
	{
		bool empty{ m_numbers[currentRow][column] == 0 };
		if (column == 0 || column == 3 || column == 6)
		{
			if (empty)
			{
				std::cout << boldOn << "|   ";
			}
			else
			{
				std::cout << boldOn << "| " << boldOff << m_numbers[currentRow][column] << ' ';
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
				std::cout << boldOff << "| " << m_numbers[currentRow][column] << ' ';
			}
		}
	}
	std::cout << boldOn << "|\n";
}
