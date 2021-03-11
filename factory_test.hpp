#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "factory.hpp"
#include <iostream>
using namespace std;


//WhitePieces
TEST(FactoryTest, WhitePawn){
	Board* f = new Board();
	MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
	mover->move(f, f->getBox(1,0), f->getBox(3,0));
	EXPECT_EQ('P', f->getBox(3,0)->getPiece());
	delete f;
}


TEST(FactoryTest, WhiteRook){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('R', f->getBox(0,0)->getPiece());
        delete f;
}

TEST(FactoryTest, WhiteKnight){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('N', f->getBox(0,1)->getPiece());
        delete f;
}

TEST(FactoryTest, WhiteBishop){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('B', f->getBox(0,2)->getPiece());
        delete f;
}

TEST(FactoryTest, WhiteQueen){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('Q', f->getBox(0,3)->getPiece());
        delete f;
}

TEST(FactoryTest, WhiteKing){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('K', f->getBox(0,4)->getPiece());
        delete f;
}

//Black Pieces
TEST(FactoryTest, BlackPawn){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('p', f->getBox(6,0)->getPiece());
        delete f;
}

TEST(FactoryTest, BlackRook){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('r', f->getBox(7,0)->getPiece());
        delete f;
}

TEST(FactoryTest, BlackKnight){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('n', f->getBox(7,1)->getPiece());
        delete f;
}

TEST(FactoryTest, BlackBishop){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('b', f->getBox(7,2)->getPiece());
        delete f;
}

TEST(FactoryTest, BlackQueen){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('q', f->getBox(7,3)->getPiece());
        delete f;
}

TEST(FactoryTest, BlackKing){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(1,0)->getPiece());
        mover->move(f, f->getBox(1,0), f->getBox(1,0));
        EXPECT_EQ('k', f->getBox(7,4)->getPiece());
        delete f;
}


//Blank Space
TEST(FactoryTest, blankSpace){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(5,5)->getPiece());
        mover->move(f, f->getBox(5,0), f->getBox(3,5));
	EXPECT_EQ('-', f->getBox(5,0)->getPiece());
        delete f;
}

#endif
