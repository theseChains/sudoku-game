#ifndef GRID_NUMBER_GENERATOR_CLASS
#define	GRID_NUMBER_GENERATOR_CLASS

#include <array>
#include <tuple> 

#include "../util.h"

class GridNumberGenerator
{
private:
	grid_type m_numbers{};
	
	bool m_changeTheNumber{};
	int m_numberToInsert{};
	
	int m_row{};
	int m_column{};

public:
	GridNumberGenerator() = default;

	grid_type generateNumbers();

private:
	void checkForNumberChange();
	void checkIfRowHasNumber();
	void checkIfColumnHasNumber();
	void checkIf3x3BoxHasNumber();
};

#endif
