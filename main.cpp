#include <iostream>
#include "board.hpp"
#include "Game.h"
using namespace std;

int main(){
    Game* f = new Game();
    f->PrintMenu(f);
	
    delete f;
    //chessGame.game_start();
	
    return 0;
}
