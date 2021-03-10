#include "gtest/gtest.h"

#include "player.hpp"
#include "Game.h"
#include "board.hpp"
#include "board_test.hpp"
int main(int argc, char ** argv) {
  ::testing::InitGoogleTest( & argc, argv);
  return RUN_ALL_TESTS();
}

TEST(PLAYER, SIMPLETEST1) {
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  EXPECT_EQ(White, a -> get_color());
  a -> set_color(Black);
  EXPECT_EQ(Black, a -> get_color());
  EXPECT_EQ(true, a -> isHumanPlayer());
  a -> log_in("yoyoyoyoyo"); //First time password = set password // You must have a password before exporting data.
  EXPECT_EQ(true, a -> check_log_in());
  EXPECT_EQ(false, a -> cheatenable());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games", a -> print_status());
  EXPECT_EQ("JIMMY", a -> get_name());
  EXPECT_EQ("BEGINER", a -> get_level());
  delete a;
}

TEST(PLAYER, SIMPLETEST2) {
  ComputerPlayer * a = new ComputerPlayer("JIMMY", White);
  EXPECT_EQ(false, a -> isHumanPlayer());
  EXPECT_EQ(true, a -> cheatenable());
  EXPECT_EQ("JIMMY", a -> get_name());
  EXPECT_EQ("BEGINER", a -> get_level());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games", a -> print_status());
  a -> cheat_instant_max_level_true();
  a -> update_level();
  EXPECT_EQ(White, a -> get_color());
  a -> set_color(Black);
  EXPECT_EQ(Black, a -> get_color());
  EXPECT_EQ("The Global Elite", a -> get_level());
  EXPECT_EQ("Player JIMMY is now The Global Elite. JIMMY is a Computer Player with a winrate of 1.000000 in 100 games", a -> print_status());
  a -> cheat_instant_min_level_true();
  a -> update_level();
  EXPECT_EQ("Silver Elite Master", a -> get_level());
  EXPECT_EQ("Player JIMMY is now Silver Elite Master. JIMMY is a Computer Player with a winrate of 0.000000 in 100 games", a -> print_status());
  delete a;
}

TEST(PLAYERLIST, HarderTest1) {
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("JIMMY", Black);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  EXPECT_EQ(false, a -> is_composit());
  EXPECT_EQ(false, b -> is_composit());
  Sum_List -> add(a);
  Sum_List -> add(b);
  EXPECT_EQ(White, a -> get_color());
  a -> set_color(Black);
  EXPECT_EQ(Black, a -> get_color());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n", Sum_List -> print_list());
  delete a;
  delete b;
  delete Sum_List;

}

TEST(PLAYERLIST, HarderTest2) {
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("JIMMY", Black);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  EXPECT_EQ(false, a -> is_composit());
  EXPECT_EQ(false, b -> is_composit());
  Sub_List -> add(a);
  Sub_List -> add(b);
  Sum_List -> add(Sub_List);
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n", Sub_List -> print_list());
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n", Sum_List -> print_list());
  EXPECT_EQ(White, a -> get_color());
  a -> set_color(Black);
  EXPECT_EQ(Black, a -> get_color());
  delete a;
  delete b;
  delete Sum_List;
  delete Sub_List;
}

TEST(PLAYERLIST, HarderTest3) {
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("JIMMY", White);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  PlayerList * Sub_List2 = new PlayerList("Sub_List2");
  EXPECT_EQ(false, a -> is_composit());
  EXPECT_EQ(false, b -> is_composit());
  Sub_List -> add(a);
  Sub_List2 -> add(b);
  Sum_List -> add(Sub_List);
  Sum_List -> add(Sub_List2);
  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer JIMMY is now BEGINER. JIMMY is a Computer Player with a winrate of 0.000000 in 0 games\n", Sum_List -> print_list());
  EXPECT_EQ(White, a -> get_color());
  a -> set_color(Black);
  EXPECT_EQ(Black, a -> get_color());
  delete a;
  delete b;
  delete Sum_List;
  delete Sub_List;
  delete Sub_List2;

}

TEST(GetPlayerFromList, HardestTest1) {
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("ALLEN", White);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  Sum_List -> add(a);
  Sum_List -> add(b);

  EXPECT_EQ(a, Sum_List -> getPlayer("JIMMY"));
  EXPECT_EQ(b, Sum_List -> getPlayer("ALLEN"));
  delete a;
  delete b;
  delete Sum_List;
}

TEST(GetPlayerFromList, HardestTest2) // turns out this is not doable
{
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("ALLEN", White);
  ComputerPlayer * c = new ComputerPlayer("Dola", White);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  Sum_List -> add(a);
  Sub_List -> add(b);
  Sub_List -> add(c);
  Sum_List -> add(Sub_List);

  EXPECT_EQ(a, Sum_List -> getPlayer("JIMMY"));
  EXPECT_EQ(White, Sum_List -> getPlayer("ALLEN") -> get_color());

  delete a;
  delete b;
  delete c;
  delete Sub_List;
  delete Sum_List;
}

TEST(GetPlayerFromList, EvenHardestTest3) // turns out this is not doable
{
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("ALLEN", White);
  ComputerPlayer * c = new ComputerPlayer("Dola", White);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  Sum_List -> add(a);
  Sub_List -> add(b);
  Sub_List -> add(c);
  Sum_List -> add(Sub_List);

  EXPECT_EQ(a, Sum_List -> getPlayer("JIMMY"));
  EXPECT_EQ("ALLEN", Sum_List -> getPlayer("ALLEN") -> get_name());
  EXPECT_EQ("Dola", Sum_List -> getPlayer("Dola") -> get_name());

  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer ALLEN is now BEGINER. ALLEN is a Computer Player with a winrate of 0.000000 in 0 games\nPlayer Dola is now BEGINER. Dola is a Computer Player with a winrate of 0.000000 in 0 games\n", Sum_List -> print_list());

  delete a;
  delete b;
  delete c;
  delete Sum_List;
  delete Sub_List;
}

TEST(GetPlayerFromList, NotFindTest) // turns out this is not doable
{
  HumanPlayer * a = new HumanPlayer("JIMMY", White);
  ComputerPlayer * b = new ComputerPlayer("ALLEN", White);
  ComputerPlayer * c = new ComputerPlayer("Dola", White);
  PlayerList * Sum_List = new PlayerList("Sum_List");
  PlayerList * Sub_List = new PlayerList("Sub_List");
  Sum_List -> add(a);
  Sub_List -> add(b);
  Sub_List -> add(c);
  Sum_List -> add(Sub_List);

  EXPECT_EQ(a, Sum_List -> getPlayer("JIMMY"));
  EXPECT_EQ(NULL, Sum_List -> getPlayer("allen"));
  EXPECT_EQ(NULL, Sum_List -> getPlayer("jeiqw"));

  EXPECT_EQ("Player JIMMY is now BEGINER. JIMMY is a Human Player with a winrate of 0.000000 in 0 games\nPlayer ALLEN is now BEGINER. ALLEN is a Computer Player with a winrate of 0.000000 in 0 games\nPlayer Dola is now BEGINER. Dola is a Computer Player with a winrate of 0.000000 in 0 games\n", Sum_List -> print_list());

  delete a;
  delete b;
  delete c;
  delete Sum_List;
  delete Sub_List;
}
