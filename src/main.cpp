#include "grid/GridNumberGenerator.h"
#include "grid/GridPrinter.h"

// easy mode: 30 - 36 clues
// medium mode: 26 - 29 clues
// hard mode: 22 - 25 clues
// expert mode: 18 - 21 clues
// nightmare mode: 17 clues

int main()
{
	GridNumberGenerator gridNumberGenerator{};
	GridType numbers{ gridNumberGenerator.generateNumbers(17) };

	GridPrinter gridPrinter{ numbers };
	gridPrinter.printGrid();

	return 0;
}
