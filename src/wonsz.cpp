#include <wonsz.h>
#include <iostream>

wonsz::wonsz(unsigned rows, unsigned columns) :
    map(map_data(rows, columns)),
	location {0,0},
	apple (rand_apple()),
	prev_direction(' ')
{
	map[location] = '#';
	map[apple] = 'o';
}

void wonsz::update(dir_enum direction)
{
	map[location] = ' ';
	move(direction);
	map[location] = '#';

	if (location == apple) {
		apple = rand_apple();
		map[apple] = 'o';
	}
}

void wonsz::move(dir_enum direction)
{
	switch(direction) {
		case dir_enum::east:
			change_location(1, 1);
			break;
		case dir_enum::south:
			change_location(0, 1);
			break;
		case dir_enum::west:
			change_location(1, -1);
			break;
		case dir_enum::north:
			change_location(0, -1);
			break;
	}
}

map_data wonsz::get_map() const
{
	return map;
}

void wonsz::change_location(unsigned direction, int diff)
{
	int new_location = location[direction] + diff;
	if (new_location < 0) {
		location[direction] = map.size()[direction] - 1;
	} else if (new_location >= static_cast<int>(map.size()[direction])) {
		location[direction] = 0;
	} else {
		location[direction] = new_location;
	}
}

std::array<unsigned, 2> wonsz::rand_apple()
{
	std::array<unsigned, 2> apple_loc;
	do {
		apple_loc[0] = std::rand() % map.size()[0];
		apple_loc[1] = std::rand() % map.size()[1];
	} while (apple_loc == location);
	return apple_loc;
}
