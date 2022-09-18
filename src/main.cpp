#include <iostream>
#include <iomanip>

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

void createThreeByThreeGrid()
{
	std::cout << "  ";
	for (char letterLineIndex{ 'A' }; letterLineIndex < 'J'; ++letterLineIndex)
	{
		std::cout << std::setw(3) << letterLineIndex << ' ';
	}
	std::cout << '\n';
	
	std::cout << "  ";
	for (int topLineIndex{ 0 }; topLineIndex < 9; ++topLineIndex)
	{
		std::cout << boldOn << "+---";
	}
	std::cout << "+\n" << boldOff;

	for (int row{ 0 }; row < 9; ++row)
	{
		std::cout << row + 1 << ' ';
		for (int boxColumn{ 0 }; boxColumn < 9; ++boxColumn)
		{
			if (boxColumn == 0 || boxColumn == 3 || boxColumn == 6)
			{
				std::cout << boldOn << "|   ";
			}
			else
			{
				std::cout << boldOff << "|   ";
			}
		}
		
		std::cout << boldOn << "|\n";
		
		std::cout << "  ";
		for (int lineColumn{ 0 }; lineColumn < 9; ++lineColumn)
		{
			if (row == 2 || row == 5 || row == 8)
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
}

int main()
{	
	createThreeByThreeGrid();

	return 0;
}
