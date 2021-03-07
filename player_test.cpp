#include "gtest/gtest.h"
#include "../header/player.hpp"

TEST(PLAYER, SIMPLETEST1)
{
  HumanPlayer* a = new HumanPlayer("JIMMY",true) ;
  EXPECT_EQ(true, a->isWhiteSide());
  EXPECT_EQ(true, a->isHumanPlayer());
  a->log_in("yoyoyoyoyo"); //First time password = set password // You must have a password before exporting data.
  EXPECT_EQ(true, a->check_log_in());
  EXPECT_EQ(false, a->cheatenable());
  EXPECT_EQ("0", a->get_ID());
  EXPECT_EQ("???", a->print_status());
  EXPECT_EQ("JIMMY", a->get_name());
  EXPECT_EQ("BEGINER", a->get_level());


}


TEST(PLAYER, SIMPLETEST2)
{
  AI* a = new AI("JIMMY",true) ;
  EXPECT_EQ(true, a->isWhiteSide());
  EXPECT_EQ(false, a->isHumanPlayer());
  EXPECT_EQ(true, a->cheatenable());
  EXPECT_EQ("0", a->get_ID());
  EXPECT_EQ("JIMMY", a->get_name());
  EXPECT_EQ("BEGINER", a->get_level());
  EXPECT_EQ("???", a->print_status());
  a->cheat_instant_max_level_true();
  a->update_level();
  EXPECT_EQ("The Global Elite", a->get_level());
  EXPECT_EQ("???", a->print_status());
  a->cheat_instant_min_level_true();
  a->update_level();
  EXPECT_EQ("Silver Elite Master", a->get_level());
  EXPECT_EQ("???", a->print_status());

}




int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
