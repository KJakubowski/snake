#include <vector>
#include <array>

using map_type = std::vector<std::vector<char>>;

struct map_data
{
	map_type matrix;

	map_data(unsigned rows, unsigned columns) :
	    matrix(std::vector<std::vector<char>>(rows, std::vector<char>(columns, ' ')))
	{}

	map_data(map_type map) :
	    matrix(map)
	{}

	char& operator[](std::array<unsigned, 2> location)
	{
		return matrix[location[0]][location[1]];
	}

	bool operator==(const map_data& map) const
	{
		return map.matrix == matrix;
	}

	std::array<unsigned, 2> size()
	{
		return {static_cast<unsigned int>(matrix.size()), static_cast<unsigned int>(matrix[0].size())};
	}
};

enum dir_enum
{
	north,
	east,
	south,
	west
};

