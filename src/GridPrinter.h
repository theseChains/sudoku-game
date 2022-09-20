#ifndef GRID_PRINTER_CLASS_H
#define GRID_PRINTER_CLASS_H

#include <iomanip>
#include <iostream>

using grid_type = std::array<std::array<int, 9>, 9>;

class GridPrinter
{
private:
	grid_type m_numbers{};	

public:
	GridPrinter(const grid_type& numbers);

	void printGrid();

private:
	void printLettersAtTheTop();
	void printTopGridLine();

	void printNonNumberRows(int currentRow);
	void printNumberRows(int currentRow);

	std::ostream& boldOn(std::ostream& out);
	std::ostream& boldOff(std::ostream& out);
};

#endif
