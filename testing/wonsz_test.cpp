#include <gtest/gtest.h>
#include <wonsz.h>
#include <memory>

class wonsz_test : public testing::Test
{
public:
	wonsz_test() :
	    sut(std::make_unique<wonsz>(3,3))
	{}

protected:
	std::unique_ptr<wonsz> sut;
};

TEST_F(wonsz_test, start)
{
	wonsz uut(1,1);
	map_data map(1,1);
	map[{0, 0}] = '#';
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, start_more_rows)
{
	wonsz uut(3,1);
	map_data map(map_type({{'#'}, {' '}, {' '}}));
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, start_more_rows_and_columns)
{
	wonsz uut(3,5);
	map_data map(map_type({{'#',' ',' ',' ',' '},
	                       {' ',' ',' ',' ',' '},
	                       {' ',' ',' ',' ',' '}}));
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, one_update)
{
	map_data map(map_type({{' ','#',' '},
	                       {' ',' ',' '},
	                       {' ',' ',' '}}));
	sut->update('r');
	EXPECT_EQ(sut->get_map(), map);
}

TEST_F(wonsz_test, one_update_down)
{
	map_data map(map_type({{' ',' ',' '},
	                       {'#',' ',' '},
	                       {' ',' ',' '}}));
	sut->update('d');
	EXPECT_EQ(sut->get_map(), map);
}

TEST_F(wonsz_test, one_update_different_directions)
{
	map_data map(map_type({{' ',' ',' '},
	                       {' ','#',' '},
				           {' ',' ',' '}}));
	sut->update('d');
	sut->update('r');
	sut->update('u');
	sut->update('r');
	sut->update('d');
	sut->update('l');
	EXPECT_EQ(sut->get_map(), map);
}

