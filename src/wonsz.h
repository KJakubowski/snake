#include <vector>

using map_type = std::vector<std::vector<char>>;

struct map_data
{
	map_type matrix;

	map_data(int rows, int columns) :
	    matrix(std::vector<std::vector<char>>(rows, std::vector<char>(columns, ' ')))
	{}

	map_data(map_type map) :
	    matrix(map)
	{}

	char& operator[](std::pair<int, int> location)
	{
		return matrix[location.first][location.second];
	}

	bool operator==(const map_data& map) const
	{
		return map.matrix == matrix;
	}
};

class wonsz
{
public:
	wonsz(int rows, int columns);
	void update(char direction);
	map_data get_map();

private:
	map_data map;
	std::pair<int, int> location;

};
