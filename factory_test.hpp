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
	//mover->move(f, f->getBox(1,0), f->getBox(3,0));
	//EXPECT_EQ('P', f->getBox(1,1)->getPiece());
	EXPECT_EQ(t.get_static_name(), "PAWN");
	delete f;
        delete mover;
}


TEST(FactoryTest, WhiteRook){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(0,0)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('R', f->getBox(0,0)->getPiece());
        EXPECT_EQ(t.get_static_name(), "ROOK");
        delete f;
        delete mover;
}

TEST(FactoryTest, WhiteKnight){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(0,1)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('N', f->getBox(0,1)->getPiece());
        EXPECT_EQ(t.get_static_name(), "KNIGHT");
	delete f;
        delete mover;
}

TEST(FactoryTest, WhiteBishop){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(0,2)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('B', f->getBox(0,2)->getPiece());
        EXPECT_EQ(t.get_static_name(), "BISHOP");
	delete f;
        delete mover;
}

TEST(FactoryTest, WhiteQueen){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(0,3)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('Q', f->getBox(0,3)->getPiece());
        EXPECT_EQ(t.get_static_name(), "QUEEN");
	delete f;
        delete mover;
}

TEST(FactoryTest, WhiteKing){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(0,4)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('K', f->getBox(0,4)->getPiece());
        EXPECT_EQ(t.get_static_name(), "KING");
	delete f;
        delete mover;
}

//Black Pieces
TEST(FactoryTest, BlackPawn){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(6,0)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('p', f->getBox(6,0)->getPiece());
	EXPECT_EQ(t.get_static_name(), "PAWN");      
	delete f;
        delete mover;
}

TEST(FactoryTest, BlackRook){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(7,0)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('r', f->getBox(7,0)->getPiece());
        EXPECT_EQ(t.get_static_name(), "ROOK");
	delete f;
        delete mover;
}

TEST(FactoryTest, BlackKnight){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(7,1)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('n', f->getBox(7,1)->getPiece());
        EXPECT_EQ(t.get_static_name(), "KNIGHT");
	delete f;
        delete mover;
}

TEST(FactoryTest, BlackBishop){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(7,2)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('b', f->getBox(7,2)->getPiece());
        EXPECT_EQ(t.get_static_name(), "BISHOP");
	delete f;
        delete mover;
}

TEST(FactoryTest, BlackQueen){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(7,3)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('q', f->getBox(7,3)->getPiece());
        EXPECT_EQ(t.get_static_name(), "QUEEN");
	delete f;
	delete mover;
}

TEST(FactoryTest, BlackKing){
        Board* f = new Board();
        MoveFactory t;
        canMove* mover = t.make_canMove(f->getBox(7,4)->getPiece());
        //mover->move(f, f->getBox(1,0), f->getBox(1,0));
        //EXPECT_EQ('k', f->getBox(7,4)->getPiece());
        EXPECT_EQ(t.get_static_name(), "KING");
	delete f;
	delete mover;
}



#endif
