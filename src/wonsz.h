#include <vector>

class wonsz
{
public:
	using map_type = std::vector<std::vector<char>>;
	wonsz(int rows, int columns);
	void update(char direction);
	map_type get_map();

private:
	map_type map;
	std::pair<int, int> location;

};
