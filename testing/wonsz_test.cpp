#include <gtest/gtest.h>
#include <wonsz.h>
#include <memory>
#include <cstdlib>

class wonsz_test : public testing::Test
{
public:
	wonsz_test()
	{
		std::srand(1);
		sut = std::make_unique<wonsz>(3,3);
	}

protected:
	std::unique_ptr<wonsz> sut;
};

TEST_F(wonsz_test, start__rand_apple_in_snake_location)
{
	std::srand(8);
//	for (int i = 0; i < 10; i++) {
//		std::cout<<std::rand()<<"\n";
//	}
//
	wonsz uut(2,2);
	map_data map(2,2);
	map[{0, 0}] = '#';
	map[{0, 1}] = 'o';
	EXPECT_EQ(uut.get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, start_more_rows)
{
	std::srand(1);
	wonsz uut(3,1);
	map_data map(map_type({{'#'}, {'o'}, {' '}}));
	EXPECT_EQ(uut.get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, start_more_rows_and_columns)
{
	std::srand(1);
	wonsz uut(3,5);
	map_data map(map_type({{'#',' ',' ',' ',' '},
	                       {' ','o',' ',' ',' '},
	                       {' ',' ',' ',' ',' '}}));
	EXPECT_EQ(uut.get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, simple_updates)
{
	map_data map(map_type({{' ',' ','#'},
	                       {' ','o',' '},
	                       {' ',' ',' '}}));
	sut->update(dir_enum::east);
	sut->update(dir_enum::east);
//	sut->update(dir_enum::south);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, update_out_of_other_boundries)
{
	map_data map(map_type({{' ',' ',' '},
	                       {' ','o',' '},
	                       {' ',' ','#'}}));
	sut->update(dir_enum::north);
	sut->update(dir_enum::west);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, not_squere_map_multiple_updates)
{
	std::srand(1);
	wonsz uut(3,5);
	map_data map(map_type({{' ',' ',' ',' ',' '},
	                       {' ','o',' ',' ',' '},
	                       {'#',' ',' ',' ',' '}}));
	uut.update(dir_enum::south);
	uut.update(dir_enum::west);
	uut.update(dir_enum::west);
	uut.update(dir_enum::south);
	uut.update(dir_enum::east);
	uut.update(dir_enum::south);
	uut.update(dir_enum::west);
	uut.update(dir_enum::north);
	uut.update(dir_enum::east);
	uut.update(dir_enum::east);
	EXPECT_EQ(uut.get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, start_map_with_random_apple_location)
{
	map_data map(map_type({{'#',' ',' '},
	                       {' ','o',' '},
	                       {' ',' ',' '}}));
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, eat_apple_and_rand_new_location)
{
	map_data map(map_type({{' ','o',' '},
	                       {'#','#',' '},
	                       {' ',' ',' '}}));
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, when_trying_to_turn_around__move_the_seme_direction)
{
	map_data map(map_type({{' ',' ','#'},
	                       {' ','o',' '},
	                       {' ',' ',' '}}));
	sut->update(dir_enum::east);
	sut->update(dir_enum::west);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, when_eat_apple__make_snake_longer)
{
	map_data map(map_type({{'#','#',' '},
	                       {'#','o',' '},
	                       {'#','#','#'}}));
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	sut->update(dir_enum::north);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, when_eat_apple_and_move_more)
{
	map_data map(map_type({{' ','o',' '},
	                       {' ',' ',' '},
	                       {' ','#','#'}}));
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, when_eat_apple_and_move_even_more)
{
	map_data map(map_type({{' ','o','#'},
	                       {' ',' ','#'},
	                       {' ',' ',' '}}));
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	sut->update(dir_enum::north);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, when_eat_two_apples)
{
	map_data map(map_type({{' ','#','#'},
	                       {' ',' ','#'},
	                       {' ','o',' '}}));
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	sut->update(dir_enum::north);
	sut->update(dir_enum::west);
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, kill_snake)
{
	map_data map(map_type({{'#','#',' '},
	                       {'#','#',' '},
	                       {'#','o',' '}}));
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	sut->update(dir_enum::north);
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	EXPECT_FALSE(sut->update(dir_enum::west));
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}

TEST_F(wonsz_test, dont_kill_snake_when_4_long)
{
	map_data map(map_type({{' ','o',' '},
	                       {'#',' ','#'},
	                       {'#',' ','#'}}));
	sut->update(dir_enum::east);
	sut->update(dir_enum::south);
	sut->update(dir_enum::south);
	sut->update(dir_enum::east);
	sut->update(dir_enum::east);
	sut->update(dir_enum::north);
	sut->update(dir_enum::west);
	EXPECT_TRUE(sut->update(dir_enum::south));
	EXPECT_EQ(sut->get_map().matrix, map.matrix);
}



