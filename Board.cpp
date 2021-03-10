#include "Board.hpp"

void Board::Board(){
	resetBoard();
}
void Board::resetBoard(){
	boxes[0][0] = new Spot(0, 0, new Rook(true));
	boxes[0][1] = new Spot(0, 1, new Knight(true));
	boxes[0][2] = new Spot(0, 2, new Bishop(true));
	boxes[0][3] = new Spot(0, 3, new Queen(true));
	boxes[0][4] = new Spot(0, 4, new King(true));
	boxes[0][5] = new Spot(0, 5, new Bishop(true));
	boxes[0][6] = new Spot(0, 6, new Knight(true));
	boxes[0][7] = new Spot(0, 7, new Rook(true));

	for (int i = 0; i < 8; ++i){
	boxes[1][i] = new Spot(1, i, new Pawn(true));
	}
	//find a way to fill in the space in between, one way is a double for loop see if you can find a more efficent way
	for(int i = 2; i < 6; ++i){
		for(int j = 0; j < 8; ++j){
		boxes[i][j] = new Spot(i, j, nullptr);
		}
	}

	for(int i = 0; i < 8; ++i){
	boxes[6][i] = new Spot(6, i, new Pawn(false));
	}
	
	boxes[7][0] = new Spot(7, 0, new Rook(false));
        boxes[7][1] = new Spot(7, 1, new Knight(false));
        boxes[7][2] = new Spot(7, 2, new Bishop(false));
        boxes[7][3] = new Spot(7, 3, new Queen(false));
        boxes[7][4] = new Spot(7, 4, new King(false));
        boxes[7][5] = new Spot(7, 5, new Bishop(false));
        boxes[7][6] = new Spot(7, 6, new Knight(false));
        boxes[7][7] = new Spot(7, 7, new Rook(false)); 
}
Spot Board::getBox(int a, int x){
	//need to set a condition to check that the box is within the 8x8 range we expect of a board
	return boxes[a][x];
}
