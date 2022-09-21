#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <array>
#include <random>

using grid_type = std::array<std::array<int, 9>, 9>;

namespace rnd
{
	inline std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min = 1, int max = 9);
}

#endif
