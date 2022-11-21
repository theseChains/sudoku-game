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

	int m_numberToInsert{};

public:
	GridNumberGenerator() = default;

	void generateNumbers(int numberOfClues);

	GridType getGrid() const;
};

#endif
