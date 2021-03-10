#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include<iostream>
#include<map>
#include<list>
#include <stdlib.h>

class Spot{
	int x;
	int y;
    char t;
public:
    Spot() {}
	Spot(int x, int y, char t){
	this->setPiece(t);
    this->setY(y);
    this->setX(x);
	}
	char getPiece(){return this->t;}
	void setPiece(char t){this->t = t;}
	int getX(){return this->x;}
	void setX(int x){this->x = x;}
	int getY(){return this->y;}
	void setY(int y) {this->y = y;}
};

class Board{
	Spot* boxes[8][8];
public:
	Board();
	void resetBoard();
	Spot* getBox(int, int);
    void printBoard();
    void move(Spot* startBox, Spot* endBox);
};
class canMove{
    public:
    virtual bool move (Spot*, Spot*) = 0;
};

class PawnMove : public canMove{

    canMove* help;
    public:
    PawnMove(){}
};
/*
virtual bool move(Spot* start, Spot* end){
    if(start->getPiece() == 'P'){
        if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' && end->getPiece() != '-' ){
            if(end->getY() != start->getY() && ((end->getX() == start->getX() + 1) || (end->getX() == start->getX() - 1)) ){
                end->setPiece(start->getPiece());
			    start->setPiece('-');
               return true;
            }
        }
    }
    if(start->getPiece() == 'p'){
        if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' && end->getPiece() != 'k' && end->getPiece() != '-' ){
            if(end->getY() != start->getY() && ((end->getX() == start->getX() + 1) || (end->getX() == start->getX() - 1)) ){
                end->setPiece(start->getPiece());
			    start->setPiece('-');
               return true;
            }
        }
    }
    if(start->getX() == 1 || start->getX() == 6){
        if((end->getY() == start->getY() && (abs(start->getX() - end->getX()) <= 2) && end->getPiece() == '-')){
        end->setPiece(start->getPiece());
		start->setPiece('-');
        return true;
        }
    }
    if((end->getY() == start->getY()) && (abs(start->getX() - end->getX()) <= 1) && end->getPiece() == '-'){
        end->setPiece(start->getPiece());
		start->setPiece('-');
        return true;
    }

        return false;
    }
*/
#endif

