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
	wonsz::map_type map {{'#'}};
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, start_more_rows)
{
	wonsz uut(3,1);
	wonsz::map_type map {{'#'}, {' '}, {' '}};
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, start_more_rows_and_columns)
{
	wonsz uut(3,5);
	wonsz::map_type map {{'#',' ',' ',' ',' '},
	                     {' ',' ',' ',' ',' '},
	                     {' ',' ',' ',' ',' '}};
	EXPECT_EQ(uut.get_map(), map);
}

TEST_F(wonsz_test, one_update)
{
	wonsz::map_type map {{' ','#',' '},
	                     {' ',' ',' '},
						 {' ',' ',' '}};
	sut->update('r');
	EXPECT_EQ(sut->get_map(), map);
}

TEST_F(wonsz_test, one_update_down)
{
	wonsz::map_type map {{' ',' ',' '},
	                     {'#',' ',' '},
						 {' ',' ',' '}};
	sut->update('d');
	EXPECT_EQ(sut->get_map(), map);
}

TEST_F(wonsz_test, one_update_different_directions)
{
	wonsz::map_type map {{' ',' ',' '},
	                     {' ','#',' '},
						 {' ',' ',' '}};
	sut->update('d');
	sut->update('r');
	sut->update('u');
	sut->update('r');
	sut->update('d');
	sut->update('l');
	EXPECT_EQ(sut->get_map(), map);
}

