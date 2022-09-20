#ifndef GRID_CLASS_H
#define GRID_CLASS_H

#include <array>

using grid_type = std::array<std::array<int, 9>, 9>;

class Grid
{
public:
	Grid() = default;

	grid_type m_numbers{};
};

#endif
