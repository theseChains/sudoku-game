#ifndef GRID_NUMBER_GENERATOR_CLASS
#define	GRID_NUMBER_GENERATOR_CLASS

#include <array>
#include <functional>
#include <optional>
#include <tuple> 

#include "Grid.h"

class GridNumberGenerator
{
private:
	std::optional<std::reference_wrapper<Grid>> m_numbers;

	bool m_changeTheNumber{};
	int m_numberToInsert{};
	
	int row{};
	int column{};

public:
	GridNumberGenerator() = default;

	void generateNumbers();

private:
	void checkIfRowHasNumber();
	void checkIfColumnHasNumber();
	void checkIf3x3BoxHasNumber();
};

#endif
