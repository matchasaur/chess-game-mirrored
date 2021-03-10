#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "factory.hpp"
#include <iostream>
using namespace std;



TEST(FactoryTest, PawnTest){
	char* test_val[2]; test_val[0] = "./test"; test_val[1] = "P";
        MoveFactory* f = new MoveFactory();
	canMove* test = f->make_canMove(test_val, 2);
	string results = test->make_canMove();
        EXPECT_EQ("P", results);
}



TEST(FactoryTest, PawnTest){
        char* test_val[2]; test_val[0] = "./test"; test_val[1] = "P";
	Board* f = new Board();
	MoveFactory* test = f->move();
        string results = test->make_canMove();
        EXPECT_EQ("P", results);
}



#endif
