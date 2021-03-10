#include "gtest/gtest.h"
#include "player.hpp"


TEST(PLAYER, SIMPLETEST1)
{
  HumanPlayer* a = new HumanPlayer("JIMMY",true) ;
  EXPECT_EQ(true, a->isWhiteSide());
  EXPECT_EQ(true, a->isHumanPlayer());
  a->log_in("yoyoyoyoyo"); //First time password = set password // You must have a password before exporting data.
  EXPECT_EQ(true, a->check_log_in());
  EXPECT_EQ(false, a->cheatenable());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games", a->print_status());
  EXPECT_EQ("JIMMY", a->get_name());
  EXPECT_EQ("BEGINER", a->get_level());
}


TEST(PLAYER, SIMPLETEST2)
{
  ComputerPlayer* a = new ComputerPlayer("JIMMY",true) ;
  EXPECT_EQ(true, a->isWhiteSide());
  EXPECT_EQ(false, a->isHumanPlayer());
  EXPECT_EQ(true, a->cheatenable());
  EXPECT_EQ("JIMMY", a->get_name());
  EXPECT_EQ("BEGINER", a->get_level());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games", a->print_status());
  a->cheat_instant_max_level_true();
  a->update_level();
  EXPECT_EQ("The Global Elite", a->get_level());
  EXPECT_EQ("Player JIMMY is now The Global Elite. JIMMY is a Computer Player with a winrate of 1.000000 in 100 games", a->print_status());
  a->cheat_instant_min_level_true();
  a->update_level();
  EXPECT_EQ("Silver Elite Master", a->get_level());
  EXPECT_EQ("Player JIMMY is now Silver Elite Master. JIMMY is a Computer Player with a winrate of 0.000000 in 100 games", a->print_status());
 

}

TEST(PLAYERLIST, HarderTest1)
{
  HumanPlayer* a = new HumanPlayer("JIMMY",true) ;
  ComputerPlayer* b = new ComputerPlayer("JIMMY",true) ;
  PlayerList * Sum_List = new PlayerList("Sum_List");
  EXPECT_EQ(false, a->is_composit());
  EXPECT_EQ(false, b->is_composit());
  Sum_List->add(a); Sum_List->add(b);
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n",Sum_List->print_list());
  
}


TEST(PLAYERLIST, HarderTest2)
{
  HumanPlayer* a = new HumanPlayer("JIMMY",true) ;
  ComputerPlayer* b = new ComputerPlayer("JIMMY",true) ;
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  EXPECT_EQ(false, a->is_composit());
  EXPECT_EQ(false, b->is_composit());
  Sub_List->add(a); Sub_List->add(b);
  Sum_List->add(Sub_List);
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n",Sub_List->print_list());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n",Sum_List->print_list());
  
}

TEST(PLAYERLIST, HarderTest3)
{
  HumanPlayer* a = new HumanPlayer("JIMMY",true) ;
  ComputerPlayer* b = new ComputerPlayer("JIMMY",true) ;
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  PlayerList * Sub_List2 = new PlayerList("Sub_List2");
  EXPECT_EQ(false, a->is_composit());
  EXPECT_EQ(false, b->is_composit());
  Sub_List->add(a); Sub_List2->add(b);
  Sum_List->add(Sub_List);
  Sum_List->add(Sub_List2);
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n",Sum_List->print_list());
  
}



int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}




