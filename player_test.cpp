#include "gtest/gtest.h"
#include "../header/player.hpp"

TEST(PLAYER, SIMPLETEST1)
{
  Player* a = new Player("JIMMY",true,true) ;
  EXPECT_EQ(true, a->isWhiteSide());
}

TEST(PLAYER, SIMPLETEST2)
{
  Player* a = new Player("JIMMY",true,true) ;
  EXPECT_EQ(true, a->isHumanPlayer());
}













int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
