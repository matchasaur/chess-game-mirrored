#include <iostream>
#include "board.hpp"
using namespace std;

int main(){
    Board* f = new Board();
    f->printBoard();

    int startX = 0;
    int startY = 0;
    int endX=0;
    int endY=0;
    for(int i = 0; i < 2; ++i){
    cin >> startX;
    cin >> startY;
    cin >> endX;
    cin >> endY;

    f->move(f,f->getBox(startX, startY), f->getBox(endX,endY));
    f->printBoard();
    }
	delete f;
    return 0;
}
