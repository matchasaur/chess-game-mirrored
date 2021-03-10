#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "factory.hpp"
#include <iostream>
using namespace std;



TEST(FactoryTest, simplFactTest){
	Board* f = new Board();
	MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
	mover->move(f, f->getBox(1,0), f->getBox(3,0));
	delete f;
}


#endif
