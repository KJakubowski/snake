#include "data_types.h"

class wonsz
{
public:
	wonsz(unsigned rows, unsigned columns);
	void update(char direction);
	map_data get_map() const;

private:
	void change_location(unsigned direction, int diff);
	std::array<unsigned, 2> rand_apple();
	void move(char direction);

private:
	map_data map;
	std::array<unsigned, 2> location;
	std::array<unsigned, 2> apple;
	char prev_direction;

};
