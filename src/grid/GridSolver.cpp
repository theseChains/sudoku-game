#include "GridSolver.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>

GridSolver::GridSolver(const GridType& board)
{
	m_numberOfSolutions = 0;
	m_grid = board;
}

void GridSolver::solve()
{
	backtrack(0, 0);
}

bool GridSolver::backtrack(int row, int column)
{
	// end of board, return true
	if (row == 8 && column == 9)
	{
		++m_numberOfSolutions;
		m_solution = m_grid;
		return true;
	}

	// reached end of row, go to next
	if (column == 9)
	{
		column = 0;
		++row;
	}

	// position already has value, go to next
	if (m_grid[row][column] > 0)
	{
		return backtrack(row, column + 1);
	}

	// create array with random numbers instead of normal loop
	// used for generating unique puzzles
	std::array<int, 9> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::mt19937 mt{ std::random_device{}() };
	std::ranges::shuffle(numbers, mt);

	int index{ 0 };
	for (auto number : numbers)
	{
		// check if its safe to place number
		if (isSafe(row, column, number))
		{
			m_grid[row][column] = number;

			// this doesn't work
			if (backtrack(row, column + 1) && m_numberOfSolutions > 1)
			{
				return true;
			}
		}
	}

	// number was wrong, reset
	m_grid[row][column] = 0;
	return false;
}

bool GridSolver::isSafe(int row, int column, int number)
{
	// check in the same row
	for (int i{ 0 }; i < 9; ++i)
	{
		if (m_grid[row][i] == number)
			return false;
	}

	// check in the same column
	for (int i{ 0 }; i < 9; ++i)
	{
		if (m_grid[i][column] == number)
			return false;
	}

	// check in the same box
	int boxRow{ row / 3 * 3 };
	int boxColumn{ column / 3 * 3 };
	for (int i{ boxRow }; i < boxRow + 3; ++i)
	{
		for (int j{ boxColumn }; j < boxColumn + 3; ++j)
		{
			if (m_grid[i][j] == number)
				return false;
		}
	}

	return true;
}

bool GridSolver::isUnique()
{
	return m_numberOfSolutions == 1;
}

GridType GridSolver::getSolution() const
{
	return m_solution;
}
