 #include "gtest/gtest.h"
 #include "factory_test.hpp"
 #include "Game_test.h"
 #include "board_test.hpp"
 #include "player_test.cpp"



 int main(int argc, char ** argv) {
   ::testing::InitGoogleTest (& argc, argv);
   return RUN_ALL_TESTS();
}
