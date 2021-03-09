#include "board.hpp"
#include <iostream>
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
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            std::cout << boxes[i][j]->getPiece() << " ";
        }
		std::cout << endl;
    }
}
Spot* Board::getBox(int i, int j){
	return boxes[i][j];
}
void Board::move(Board*, Spot* startBox, Spot* endBox){
	Spot* start = startBox;
	Spot* end = endBox;
	
	if(start->getPiece() == 'P' || start->getPiece() == 'p'){
		canMove* shit = new PawnMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}
	if(start->getPiece() == 'R' || start->getPiece() == 'r'){
		canMove* shit = new RookMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}
	if(start->getPiece() == 'N' || start->getPiece() == 'n'){
		canMove* shit = new KnightMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}
	if(start->getPiece() == 'K' || start->getPiece() == 'k'){
		canMove* shit = new KingMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}
	if(start->getPiece() == 'B' || start->getPiece() == 'b'){
		canMove* shit = new BishopMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}
	if(start->getPiece() == 'Q' || start->getPiece() == 'q'){
		canMove* shit = new QueenMove();
		if(!shit->move(this, start, end)){
			std::cout << "Invalid move" << endl;
		}
		delete shit;
	}		
}
