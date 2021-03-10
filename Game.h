//
// Created by Jared on 3/7/2021.
// Modified by Chun on 3/9/2021. /// Merge with PlayerClass

#ifndef _GAME_H
#define _GAME_H
#include "player.hpp"
#include "board.hpp"
using namespace std;


class Game {
  private:
    color turn;
  Board* chessBoard;
  Player * player1;
  Player * player2;
  PlayerList * queue;

  public:
  Game();
  void game_start();
  void parseMove(stringstream& input, color playerTurn);
  int PrintMenu(Game* t);
  void Print_rules() const;
  void AddPlayer();
  void RandomChessQuotes() const;




  void nextTurn() {
    if (turn == White) {
      turn = Black;
    } else if (turn == Black) {
      turn = White;
    }
  }
  int declare_win(Board*);
  int declare_win(int);
  pair<int, int> getCoordinates(string cordinate);
};


#endif //FINAL_PROJECT_DMIRZ001_JTANU002_FQUIR007_CWONG165_1_GAME_H
