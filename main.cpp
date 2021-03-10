#include <iostream>
#include "board.hpp"
#include "Game.h"
using namespace std;

int main(){
    Game* f = new Game();
    f->PrintMenu(f);
    //f.game_start();

    return 0;
}





















    //Board* f = new Board();
    //f->printBoard();

    //int startX,startY,endX,endY;
    //f->kingCaptured = false;
    //while(f->kingCaptured != true){
    //cin >> startX;
    //cin >> startY;
    //cin >> endX;
    //cin >> endY;

    //f->move(f, f->getBox(startX, startY), f->getBox(endX,endY));
    //f->printBoard();

    //}
	//delete f;
