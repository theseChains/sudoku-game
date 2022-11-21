#ifndef SUDOKU_GRID_SOLVER_H
#define SUDOKU_GRID_SOLVER_H

#include <tuple>

#include "../util.h"

class GridSolver
{
public:
	GridSolver() = default;
	GridSolver(const GridType& board);

	void solve();
	bool isUnique();

	GridType getSolution() const;

private:
	GridType m_grid{};
	GridType m_solution{};
	int m_numberOfSolutions{};
	bool isSafe(int row, int column, int num);
	bool backtrack(int row, int column);
};

#endif
