#include "GridNumberGenerator.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>

void GridNumberGenerator::generateNumbers(int numberOfClues)
{
	struct Cell
	{
		int row{};
		int column{};
		int value{};
	};


	std::cout << "solving\n";
	m_solver.solve();
	m_grid = m_solver.getSolution();
	std::cout << "solved\n";

	std::array<Cell, 81> cells{};
	int count{ 0 };
	for (int i{ 0 }; i < 9; ++i)
	{
		for (int j{ 0 }; j < 9; ++j)
		{
			cells[count].row = i;
			cells[count].column = j;
			cells[count].value = m_grid[i][j];
			++count;
		}
	}

	// shuffle array randomly to remove positions:
	std::mt19937 mt{ std::random_device{}() };
	std::ranges::shuffle(cells, mt);

	int numberOfUnknowns{ 81 - numberOfClues };
	std::cout << "generating\n";
	for (int index{ 0 }; const auto& cell : cells)
	{
		m_grid[cell.row][cell.column] = 0;
		m_solver = GridSolver{ m_grid };
		m_solver.solve();
		if (!m_solver.isUnique())
		{
			// removal of value does not produce unique solution, put the value back
			m_grid[cell.row][cell.column] = cell.value;
		}
		else
		{
			--numberOfUnknowns;
		}
		std::cout << "numberOfUnknowns: " << numberOfUnknowns << '\n';
		std::cout << "index: " << index << '\n';
		if (index == numberOfUnknowns)
		{
			break;
		}
	}
}

GridType GridNumberGenerator::getGrid() const
{
	return m_grid;
}
