#include "Game.h"
#include "board.hpp"
#include "player.hpp"

TEST(Board, SimpleMoveTest){
        Board* f = new Board();
        f->move(f, f->getBox(1,0),f->getBox(3,0));
        EXPECT_EQ('P', f->getBox(3,0)->getPiece());
        EXPECT_EQ('-', f->getBox(1,0)->getPiece());
	delete f;
}
TEST(Board, invalidPawn){
        Board* f = new Board();
        f->move(f, f->getBox(1,0),f->getBox(3,0));
        EXPECT_EQ('P', f->getBox(3,0)->getPiece());
        EXPECT_EQ('-', f->getBox(1,0)->getPiece());
	f->move(f, f->getBox(3,0),f->getBox(1,0));
	EXPECT_EQ('-', f->getBox(1,0)->getPiece());
	delete f;
}

TEST(Board, SimpleMoveTest2){
        Board* f = new Board();
        f->move(f, f->getBox(1,0),f->getBox(3,0));
        f->move(f, f->getBox(0,0), f->getBox(2,0));
        EXPECT_EQ('R', f->getBox(2,0)->getPiece());
        EXPECT_EQ('P', f->getBox(3,0)->getPiece());
        EXPECT_EQ('-', f->getBox(1,0)->getPiece());
	delete f;
}
TEST(Board, SimpleMoveTest3){
        Board* f = new Board();
        f->move(f, f->getBox(1,0),f->getBox(3,0));
        f->move(f, f->getBox(0,0), f->getBox(2,0));
        EXPECT_EQ('R', f->getBox(2,0)->getPiece());
        f->move(f, f->getBox(2,0), f->getBox(2,5));
         EXPECT_EQ('R', f->getBox(2,5)->getPiece());
        EXPECT_EQ('P', f->getBox(3,0)->getPiece());
        EXPECT_EQ('-', f->getBox(1,0)->getPiece());
	delete f;
}
TEST(Board, SimpleMoveTestEmpty){
        Board* f = new Board();
        f->move(f, f->getBox(2,0),f->getBox(3,0));
        EXPECT_EQ('-', f->getBox(2,0)->getPiece());
        EXPECT_EQ('-', f->getBox(3,0)->getPiece());
	delete f;
}
TEST(Board, HorseMove){
        Board* f = new Board();
        f->move(f, f->getBox(0,1), f->getBox(2,2));
        EXPECT_EQ('N', f->getBox(2,2)->getPiece());
	delete f;
}
TEST(Board, HorseMove2){
        Board* f = new Board();
        f->move(f, f->getBox(0,6), f->getBox(2,5));
        EXPECT_EQ('N', f->getBox(2,5)->getPiece());
	delete f;
}
TEST(Board, HorseMove3){
        Board* f = new Board();
        f->move(f, f->getBox(0,1), f->getBox(2,0));
        EXPECT_EQ('N', f->getBox(2,0)->getPiece());
	delete f;
}
TEST(Board, HorseMove4){
        Board* f = new Board();
        f->move(f, f->getBox(7,1), f->getBox(5,2));
        EXPECT_EQ('n', f->getBox(5,2)->getPiece());
	delete f;
}
TEST(Board, HorseMove5){
        Board* f = new Board();
        f->move(f, f->getBox(7,6), f->getBox(5,5));
        EXPECT_EQ('n', f->getBox(5,5)->getPiece());
	delete f;
}
TEST(Board, HorseMove6){
        Board* f = new Board();
        f->move(f, f->getBox(7,6), f->getBox(5,7));
        EXPECT_EQ('n', f->getBox(5,7)->getPiece());
	delete f;
}
TEST(Board, QueenMove){
        Board* f = new Board();
        f->move(f, f->getBox(0,3), f->getBox(2,3));
        EXPECT_EQ('Q', f->getBox(2,3)->getPiece());
	delete f;
}
TEST(Board, QueenMove2){
        Board* f = new Board();
        f->move(f, f->getBox(0,3), f->getBox(1,3));
        EXPECT_EQ('Q', f->getBox(1,3)->getPiece());
	delete f;
}
TEST(Board, KingMove){
	Board* f = new Board(); 
	f->move(f, f->getBox(1,4), f->getBox(3,4));
        EXPECT_EQ('P', f->getBox(3,4)->getPiece());
	f->move(f, f->getBox(0,4), f->getBox(1,4));
        EXPECT_EQ('K', f->getBox(1,4)->getPiece());
	delete f;
}
TEST(Board, blackPawn){
Board* f = new Board();
        f->move(f, f->getBox(6,0), f->getBox(4,0));
        EXPECT_EQ('p', f->getBox(4,0)->getPiece());
	delete f;
}
TEST(Board, blackRook){
	Board* f = new Board();
        f->move(f, f->getBox(6,0), f->getBox(4,0));
        EXPECT_EQ('p', f->getBox(4,0)->getPiece());
	f->move(f, f->getBox(7,0), f->getBox(5,0));
        EXPECT_EQ('r', f->getBox(5,0)->getPiece());

        delete f;
}
TEST(Spot, Xcoordinate){
	Spot* f = new Spot(0,0,'R');
	EXPECT_EQ(0, f->getX());
	delete f;
}
TEST(Spot, Ycoordinate){
        Spot* f = new Spot(0,1,'R');
        EXPECT_EQ(1, f->getY());
        delete f;
}
TEST(Spot, char){
        Spot* f = new Spot(0,1,'R');
        EXPECT_EQ('R', f->getPiece());
        delete f;
}


