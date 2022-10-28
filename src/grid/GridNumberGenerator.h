#ifndef GRID_NUMBER_GENERATOR_CLASS
#define	GRID_NUMBER_GENERATOR_CLASS

#include <array>
#include <tuple>

#include "../util.h"

#include "GridSolver.h"

class GridNumberGenerator
{
private:
	GridType m_grid{};
	GridSolver m_solver{};

	bool m_changeTheNumber{};
	int m_numberToInsert{};

	int m_row{};
	int m_column{};

public:
	GridNumberGenerator() = default;

	GridType generateNumbers(int numberOfClues);

private:
	void checkForNumberChange();
	void checkIfRowHasNumber();
	void checkIfColumnHasNumber();
	void checkIf3x3BoxHasNumber();
};

#endif
