#include "data_types.h"

class wonsz
{
public:
	wonsz(unsigned rows, unsigned columns);
	bool update(dir_enum direction);
	map_data get_map() const;

private:
	void move_head(unsigned direction, int diff);
	std::array<unsigned, 2> rand_apple();
	void change_direction(dir_enum direction);
	void check_dir(dir_enum direction);
	void eat_apple();
	void move_body();

private:
	map_data map;
	std::vector<std::array<unsigned, 2>> locations;
	std::array<unsigned, 2> head_location;
	std::array<unsigned, 2> tail_location;
	std::array<unsigned, 2> apple;
	dir_enum prev_direction;
	bool has_eaten;

};
