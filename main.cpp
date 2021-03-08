nclude <iostream>
#include "board.hpp"
using namespace std;

int main(){
    Board* f = new Board();
    f->printBoard();

    int startX,startY,endX,endY;
    for(int i = 0; i < 4; ++i){
    cin >> startX;
    cin >> startY;
    cin >> endX;
    cin >> endY;

    f->move(f->getBox(startX, startY), f->getBox(endX,endY));
    f->printBoard();
    }

    return 0;
}
