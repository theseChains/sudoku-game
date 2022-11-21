#include "grid/GridNumberGenerator.h"
#include "grid/GridPrinter.h"

// easy mode: 36 - 46 clues
// medium mode: 32 - 35 clues
// hard mode: 28 - 31 clues

int main()
{
	GridNumberGenerator gridNumberGenerator{};
	gridNumberGenerator.generateNumbers(28);
	GridType numbers{ gridNumberGenerator.getGrid() };

	GridPrinter gridPrinter{ numbers };
	gridPrinter.printGrid();

	return 0;
}
