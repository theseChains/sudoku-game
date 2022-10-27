#include "GridSolver.h"

// i want to create a copy of the grid here since i only want to get the number of solutions
// not solve the grid itself, having a copy prevents modification of the original grid.
// the modification of the grid happens in the grid generator class
int GridSolver::solveGrid(GridType grid)
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
				int digitIndex{ digit - 1 };
				rowContains[row].set(digitIndex);
				columnContains[column].set(digitIndex);
				// compute which box we are in right now
				int box{ getBox(row, column) };
				boxContains[box].set(digitIndex);
			}
		}
	}

	solve(grid, 0, 0, rowContains, columnContains, boxContains);
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
