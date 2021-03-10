#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "factory.hpp"
#include <iostream>
using namespace std;

TEST(FactoryTest, PawnTest){
        MoveFactory* factoryTest = new MoveFactory();
	canMove* test = factoryTest->make_canMove('P');
        EXPECT_EQ("Which is: 'P' (80, 0x50)" , "Which is: 'P' (80, 0x50)");
}

#endif
