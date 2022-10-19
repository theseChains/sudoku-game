#ifndef GRID_PRINTER_CLASS_H
#define GRID_PRINTER_CLASS_H

#include <array>
#include <iomanip>
#include <iostream>

using GridType = std::array<std::array<int, 9>, 9>;

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
