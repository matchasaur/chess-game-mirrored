#include "board.hpp"
#include <iostream>
#include <queue>
using namespace std;
Board::Board(){
	resetBoard();
}
void Board::resetBoard(){
	boxes[0][0] = new Spot(0, 0, 'R');
	boxes[0][1] = new Spot(0, 1, 'N');
	boxes[0][2] = new Spot(0, 2, 'B');
	boxes[0][3] = new Spot(0, 3, 'Q');
	boxes[0][4] = new Spot(0, 4, 'K');
	boxes[0][5] = new Spot(0, 5, 'B');
	boxes[0][6] = new Spot(0, 6, 'N');
	boxes[0][7] = new Spot(0, 7, 'R');

	for (int i = 0; i < 8; ++i){
	boxes[1][i] = new Spot(1, i, 'P');
	}
	for(int i = 2; i < 6; ++i){
		for(int j = 0; j < 8; ++j){
		boxes[i][j] = new Spot(i, j, '-');
		}
	}
	for(int i = 0; i < 8; ++i){
	boxes[6][i] = new Spot(6, i, 'p');
	} 
	boxes[7][0] = new Spot(7, 0, 'r');
	boxes[7][1] = new Spot(7, 1, 'n');
	boxes[7][2] = new Spot(7, 2, 'b');
	boxes[7][3] = new Spot(7, 3, 'q');
	boxes[7][4] = new Spot(7, 4, 'k');
	boxes[7][5] = new Spot(7, 5, 'b');
	boxes[7][6] = new Spot(7, 6, 'n');
	boxes[7][7] = new Spot(7, 7, 'r');
}
void Board::printBoard(){
	std::cout << "  A B C D E F G H \n";
	std::cout << "8 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[0][i]->getPiece() << ' ';
	}
	std::cout << "\n7 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[1][i]->getPiece() << ' ';
	}
	std::cout << "\n6 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[2][i]->getPiece() << ' ';
	}
	std::cout << "\n5 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[3][i]->getPiece() << ' ';
	}
	std::cout << "\n4 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[4][i]->getPiece() << ' ';
	}
	std::cout << "\n3 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[5][i]->getPiece() << ' ';
	}
	std::cout << "\n2 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[6][i]->getPiece() << ' ';
	}
	std::cout << "\n1 ";
	for(int i = 0; i < 8; ++i){
		std::cout << boxes[7][i]->getPiece() << " ";
	}
	std::cout << std::endl;
}
Spot* Board::getBox(int i, int j){
	return boxes[i][j];
}



/*FACTORY IMPLEMENT */
void Board::move(Board*, Spot* startBox, Spot* endBox){
	Spot* start = startBox;
	Spot* end = endBox;
	history.push(new Spot(start->getX(), start->getY(), start->getPiece()));
	history.push(new Spot(end->getX(), end->getY(), end->getPiece()));
  
  canMove* mover = new canMove(start->getPiece());

  if(!mover->move(this, start, end)|| mover == nullptr){
			history.pop();
			history.pop();
			std::cout << "Invalid move" << endl;
		}
	delete mover;
}

void Board::undo(){
	Spot* end = history.top();
	history.pop();
	Spot* start = history.top();
	history.pop();
	char top = end->getPiece();
	char bottom = start->getPiece();
	getBox(start->getX(), start->getY())->setPiece(bottom);
	getBox(end->getX(), end->getY())->setPiece(top);

	delete end;
	delete start;
}

