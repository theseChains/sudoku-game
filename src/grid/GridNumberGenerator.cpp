#include "GridNumberGenerator.h"

grid_type GridNumberGenerator::generateNumbers()
{
	for (int gridIndex{ 0 }; gridIndex < 30; ++gridIndex)
	{
		auto position{ std::make_pair(rnd::getNumber(0, 8), rnd::getNumber(0, 8)) };

		while (m_numbers[position.first][position.second])
		{
			position = std::make_pair(rnd::getNumber(0, 8), rnd::getNumber(0, 8));
		}

		m_row = position.first;
		m_column = position.second;

		m_numberToInsert = rnd::getNumber();

		checkForNumberChange();

		m_numbers[m_row][m_column] = m_numberToInsert;
	}

	return m_numbers;
}

void GridNumberGenerator::checkForNumberChange()
{
	while (true)
	{
		m_changeTheNumber = false;

		checkIfRowHasNumber();
		checkIfColumnHasNumber();
		// this function is funky
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
		if (m_numbers[m_row][currentColumn] == m_numberToInsert)
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
		if (m_numbers[currentRow][m_column] == m_numberToInsert)
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
			if (m_numbers[row][column] == m_numberToInsert)
			{
				m_changeTheNumber = true;
				break;
			}
		}
	}
}
