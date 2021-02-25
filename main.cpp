#include <iostream>
#include <string>
using namespace std;
void PrintMenu() {
  std: string menu_string ;

  cout<< "Option 1: Log In" << endl;
  cout<< "Option 2: New Game 1V1" << endl;
  cout<< "Option 3: New Game with Computer Player" << endl;
  cout<< "Option 4: Rules of chess From Wikipedia, the free encyclopedia" << endl;



  cout<< "Option 9: Exit" << endl;
  //option 2077 is hidden, designed to allow developer to debug game, also easter egg

}

void print_rules(){
  cout<< "Chess is a two-player board game using a chessboard and sixteen pieces of six types for each player. Each type of piece moves in a distinct way. The object of the game is to checkmate (threaten with inescapable capture) the opponent's king. Games do not necessarily end in checkmate; players often resign if they believe they will lose. A game can also end in a draw in several ways." << endl;
}


int main() {

  int option = 0; 
   cout << "Welcome to Chess 2077" << endl;
   PrintMenu();
  
   cin >> option;
   if(option == 1){/*Log_in()*/;}
   if(option == 2){/*Log_in()*/;}
   if(option == 3){/*Log_in()*/;}
   if(option == 4){print_rules();}
   if(option == 2077){/*Log_in()*/;}
   
}





