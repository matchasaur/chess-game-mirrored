#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include<iostream>
#include<map>
#include<list>
#include "game.hpp"
#include "piece.hpp"

class Board{
	int box[8][8];
public:
	void Board();
	void resetBoard():
	std::string getBox(int, int);
};

class Spot{
	Piece piece;
	int x;
	int y;
public:
	void spot(int x, int y, Piece piece){
	this->setPiece(piece);
	this->setY(y);
	this->setX(x);
	}

	Piece getPiece(){return this->piece;}
	void setPiece(Piece p);
	int getX(){return x;}
	void setX(int x){this->x = x;}
	int getY(){return y;}
	void setY(int y) {this->y = y;}
}
#endif;
