#include <wonsz.h>

wonsz::wonsz(int rows, int columns) :
    map(map_data(rows, columns)),
	location(0,0)
{
	map[location] = '#';
}

void wonsz::update(char direction)
{
	map[location] = ' ';

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

	map[location] = '#';
}

map_data wonsz::get_map()
{
	return map;
}
	
