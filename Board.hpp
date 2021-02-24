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
}
#endif
