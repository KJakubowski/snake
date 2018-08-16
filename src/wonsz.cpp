#include <wonsz.h>
#include <iostream>
#include <algorithm>

wonsz::wonsz(unsigned rows, unsigned columns) :
    map(map_data(rows, columns)),
	locations {{0,0}},
	head_location {0, 0},
	tail_location {0, 0},
	apple(rand_apple()),
	prev_direction(dir_enum::east),
	has_eaten(false)
{
	map[locations[0]] = '#';
	map[apple] = 'o';
}

bool wonsz::update(dir_enum direction)
{
	check_dir(direction);
	change_direction(prev_direction);
	move_body();

	if (head_location == apple) {
		eat_apple();
	} else 	if (std::find(locations.begin() + 4, locations.end(),
	                      head_location) != locations.end()) {
		return false;
	} else {
		map[tail_location] = ' ';
		tail_location = locations.back();
	}
	map[head_location] = '#';
	return true;
}

void wonsz::change_direction(dir_enum direction)
{
	switch(direction) {
		case dir_enum::east:
			move_head(1, 1);
			break;
		case dir_enum::south:
			move_head(0, 1); break;
		case dir_enum::west:
			move_head(1, -1);
			break;
		case dir_enum::north:
			move_head(0, -1);
			break;
	}
}

map_data wonsz::get_map() const
{
	return map;
}

void wonsz::move_head(unsigned direction, int diff)
{
	int loc_buffer = locations[0][direction] + diff;
	if (loc_buffer < 0) {
		head_location[direction] = map.size()[direction] - 1;
	} else if (loc_buffer >= static_cast<int>(map.size()[direction])) {
		head_location[direction] = 0;
	} else {
		head_location[direction] = loc_buffer;
	}
}

std::array<unsigned, 2> wonsz::rand_apple()
{
	std::array<unsigned, 2> apple_loc;
	do {
		apple_loc[0] = std::rand() % map.size()[0];
		apple_loc[1] = std::rand() % map.size()[1];
	} while (std::find(locations.begin(), locations.end(), apple_loc) != locations.end());
	return apple_loc;
}

void wonsz::check_dir(dir_enum direction)
{
	int dir_diff = direction - prev_direction;
	if (abs(dir_diff) != 2) {
		prev_direction = direction;
	}
}

void wonsz::eat_apple()
{
	locations.push_back(tail_location);
	apple = rand_apple();
	map[apple] = 'o';
}

void wonsz::move_body()
{
	for (int i = locations.size() - 1; i > 0; i--) {
		locations[i] = locations[i-1];
	}
	locations[0] = head_location;
}

