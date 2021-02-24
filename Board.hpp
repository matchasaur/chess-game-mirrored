#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include<iostream>
#include<map>
#include<list>

class Board{
	std::map<char, int> boxes;
public:
	void Board();
	void resetBoard():
	std::string getBox(char, int);
}
#endif
