#include "GridNumberGenerator.h"

GridType GridNumberGenerator::generateNumbers()
{
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
