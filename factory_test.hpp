#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "factory.hpp"
#include <iostream>
using namespace std;

TEST(FactoryTest, PawnTest){
	char* test_val[1]; test_val[0] = "./test";
        MoveFactory* factoryTest = new MoveFactory(test_val, 1);
	string results = test->history.pop();
        EXPECT_EQ("P", results);
}

#endif
