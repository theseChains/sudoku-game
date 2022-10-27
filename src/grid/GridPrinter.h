#ifndef GRID_PRINTER_CLASS_H
#define GRID_PRINTER_CLASS_H

#include <iomanip>
#include <iostream>

#include "../util.h"

class GridPrinter
{
private:
	GridType m_numbers{};

public:
	GridPrinter(const GridType& numbers);

	void printGrid();

private:
	void printLettersAtTheTop();
	void printTopGridLine();

	void printNonNumberRows(int currentRow);
	void printNumberRows(int currentRow);
};

#endif
