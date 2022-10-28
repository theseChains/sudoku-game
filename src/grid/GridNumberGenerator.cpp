#include "GridNumberGenerator.h"
#include <iostream>

GridType GridNumberGenerator::generateNumbers(int numberOfClues)
{
	// generate a full valid board
	for (int gridIndex{ 0 }; gridIndex < 81; ++gridIndex)
	{
		m_row = gridIndex / 9;
		m_column = gridIndex % 9;

		m_numberToInsert = rnd::getNumber();
		checkForNumberChange();

		m_grid[m_row][m_column] = m_numberToInsert;

		while (!m_solver.solveGrid(m_grid))
		{
			m_numberToInsert = rnd::getNumber();
			checkForNumberChange();

			m_grid[m_row][m_column] = m_numberToInsert;
		}
	}

	// remove numbers at random positions until the proper amount of clues is reached
	int amountOfNumbersToRemove{ 81 - numberOfClues };
	for (int index{ 0 }; index < amountOfNumbersToRemove; ++index)
	{
		auto [row, column]{ std::make_pair(index / 9, index % 9) };

		int previousValue{ m_grid[row][column] };
		m_grid[row][column] = 0;

		// check if the grid still has a solution
		while (!m_solver.solveGrid(m_grid))
		{
			m_grid[row][column] = previousValue;
			std::tie(row, column) = std::make_pair(rnd::getNumber(0, 8), rnd::getNumber(0, 8));

			previousValue = m_grid[row][column];
			m_grid[row][column] = 0;
		}
	}

	return m_grid;
}

void GridNumberGenerator::checkForNumberChange()
{
	while (true)
	{
		m_changeTheNumber = false;

		checkIfRowHasNumber();
		checkIfColumnHasNumber();
		checkIf3x3BoxHasNumber();

		if (m_changeTheNumber)
		{
			m_numberToInsert = rnd::getNumber();
		}
		else
		{
			break;
		}
	}
}

void GridNumberGenerator::checkIfRowHasNumber()
{
	for (int currentColumn{ 0 }; currentColumn < 9; ++currentColumn)
	{
		if (m_grid[m_row][currentColumn] == m_numberToInsert)
		{
			m_changeTheNumber = true;
			break;
		}
	}
}

void GridNumberGenerator::checkIfColumnHasNumber()
{
	for (int currentRow{ 0 }; currentRow < 9; ++currentRow)
	{
		if (m_grid[currentRow][m_column] == m_numberToInsert)
		{
			m_changeTheNumber = true;
			break;
		}
	}
}

void GridNumberGenerator::checkIf3x3BoxHasNumber()
{
	int boxRowIndex{ m_row / 3 };
	int boxColumnIndex{ m_column / 3 };

	int currentGridRow{ boxRowIndex * 3 };
	int currentGridColumn{ boxColumnIndex * 3 };

	for (int row{ currentGridRow }; row < currentGridRow + 3; ++row)
	{
		for (int column{ currentGridColumn }; column < currentGridColumn + 3; ++column)
		{
			if (m_grid[row][column] == m_numberToInsert)
			{
				m_changeTheNumber = true;
				break;
			}
		}
	}
}
