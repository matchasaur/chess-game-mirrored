#include <iostream>
#include "board.hpp"
using namespace std;

int main(){
    Board* f = new Board();
    f->printBoard();

    int startX,startY,endX,endY;
    f->kingCaptured = false;
    while(f->kingCaptured != true){
    cin >> startX;
    cin >> startY;
    cin >> endX;
    cin >> endY;

    f->move(f, f->getBox(startX, startY), f->getBox(endX,endY));
    f->printBoard();

    }
	//delete f;
    return 0;
}
