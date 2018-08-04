#include <wonsz.h>

wonsz::wonsz(int rows, int columns) :
    map(std::vector<std::vector<char>>(rows, std::vector<char>(columns, ' '))),
	location(0,0)
{
	map[0][0] = '#';
}

void wonsz::update(char direction)
{
	map[location.first][location.second] = ' ';

	switch(direction) {
		case 'r':
			location.second++;
			break;
		case 'd':
			location.first++;
			break;
		case 'l':
			location.second--;
			break;
		case 'u':
			location.first--;
			break;
	}

	map[location.first][location.second] = '#';
}

wonsz::map_type wonsz::get_map()
{
	return map;
}
	
