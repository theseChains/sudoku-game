#include "grid/GridNumberGenerator.h"
#include "grid/GridPrinter.h"

// easy mode: 30 - 36 clues
// medium mode: 26 - 29 clues
// hard mode: 22 - 25 clues
// expert mode: 18 - 21 clues
// nightmare mode: 17 clues
//
// a better idea would be to fill the board entirely and then remove one number and run a 
// sudoku solver on that board. if more than one solution exists, try removing another number
// do this until you have reached the appropritate number of clues. we also want to remove 
// the numbers randmoly across the board to make it look nicer.

int main()
{	
	GridNumberGenerator gridNumberGenerator{};
	grid_type numbers{ gridNumberGenerator.generateNumbers() };
	
	GridPrinter gridPrinter{ numbers };
	gridPrinter.printGrid();

	return 0;
}
