#include "GridSolver.h"
#include <iostream>
// i want to create a copy of the grid here since i only want to get the number of solutions
// not solve the grid itself, having a copy prevents modification of the original grid.
// the modification of the grid happens in the grid generator class
bool GridSolver::solveGrid(GridType grid)
{
	// keep track of what numbers are already used for each row, column and 3x3 box:
	std::array<std::bitset<9>, 9> rowContains{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::array<std::bitset<9>, 9> columnContains{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::array<std::bitset<9>, 9> boxContains{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// loop over the board to mark up all of the integers that were already given to us
	for (int row{ 0 }; row < 9; ++row)
	{
		for (int column{ 0 }; column < 9; ++column)
		{
			int digit{ grid[row][column] };
			if (digit != 0)
			{
				std::cout << "digit " << digit << " is at row " << row << " column " << column << '\n';
				int digitIndex{ digit - 1 };
				rowContains[row].set(digitIndex);
				columnContains[column].set(digitIndex);
				// compute which box we are in right now
				int box{ getBox(row, column) };
				boxContains[box].set(digitIndex);
			}
		}
	}

	return solve(grid, 0, 0, rowContains, columnContains, boxContains);
}

bool GridSolver::solve(GridType& grid, const int rowStart, const int columnStart,
		std::array<std::bitset<9>, 9>& rowContains,
		std::array<std::bitset<9>, 9>& columnContains,
		std::array<std::bitset<9>, 9>& boxContains)
{
	// find a position that we can fill in:
	auto [row, column]{ nextEmptyPosition(grid, rowStart, columnStart) };

	// end of board
	if (row == 9)
	{
		return true;
	}

	// compute which numbers have already been used in the current row, column or box
	const int box{ getBox(row, column) };
	const std::bitset<9> contains{ rowContains[row] | columnContains[column] | boxContains[box] };

	if (contains.all())
	{
		return false;
	}

	// loop over all digits
	for (int digitIndex{ 0 }; digitIndex < 9; ++digitIndex)
	{
		if (!contains[digitIndex])
		{
			grid[row][column] = digitIndex + 1;
			rowContains[row].set(digitIndex);
			columnContains[column].set(digitIndex);
			boxContains[box].set(digitIndex);

			if (solve(grid, row, column, rowContains, columnContains, boxContains))
			{
				return true;
			}

			rowContains[row].reset(digitIndex);
			columnContains[column].reset(digitIndex);
			boxContains[box].reset(digitIndex);
		}
	}

	grid[row][column] = 0;
	return false;
}

int GridSolver::getBox(int row, int column)
{
	return (row / 3) * 3 + column / 3;
}

int GridSolver::getNextRow(int row, int column)
{
	return row + (column + 1) / 9;
}

int GridSolver::getNextColumn(int column)
{
	return (column + 1) % 9;
}

std::pair<int, int> GridSolver::nextEmptyPosition(GridType& grid, int row, int column)
{
	while (row != 9)
	{
		if (grid[row][column] == 0)
		{
			return { row, column };
		}

		row = getNextRow(row, column);
		column = getNextColumn(column);
	}

	// off the board
	return { 9, 0 };
}
