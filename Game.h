//
// Created by Jared on 3/7/2021.
// Modified by Chun on 3/9/2021. /// Merge with PlayerClass

#ifndef _GAME_H
#define _GAME_H
#include "player.hpp"
#include "board.hpp"

/*enum color{White, Black};  now define in player.hpp with added functions

  //test purposes only
  struct Player{
      bool checkmate = false;
      color pieces;
      explicit Player(color pieceColor){pieces = pieceColor;}
  public:
      bool isCheckmate(){return checkmate;}
  };*/

class Game {
  private:
    color turn;
  Player * player1;
  Player * player2;
  PlayerList * queue;

  public:
    void game_start();
  int PrintMenu();
  void parseMove(stringstream& input, color playerTurn);
  void Print_rules() const;
  void AddPlayer();
  void RandomChessQuotes() const;
  Game();

  //helpers
  void nextTurn() {
    if (turn == White) {
      turn = Black;
    } else if (turn == Black) {
      turn = White;
    }
  }
  void declare_win();
  pair<int, int> getCoordinates(string cordinate);
};
};

#endif //FINAL_PROJECT_DMIRZ001_JTANU002_FQUIR007_CWONG165_1_GAME_H
