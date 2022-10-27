#ifndef SUDOKU_GRID_SOLVER_H
#define SUDOKU_GRID_SOLVER_H

#include "../util.h"

#include <bitset>
#include <tuple>

class GridSolver
{
public:
	int solveGrid(GridType grid);
	bool solve(GridType& grid, const int rowStart, const int columnStart,
			std::array<std::bitset<9>, 9>& rowContains,
			std::array<std::bitset<9>, 9>& columnContains,
			std::array<std::bitset<9>, 9>& boxContains);

private:
	int getBox(int row, int column);
	int getNextRow(int row, int column);
	int getNextColumn(int column);
	std::pair<int, int> nextEmptyPosition(GridType& grid, int row, int column);
};

#endif
