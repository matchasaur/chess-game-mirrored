//
// Created by Jared on 3/7/2021.
//
#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

Game::Game(){
    player1 = new Player(White);
    player2 = new Player(Black);
    turn = White;
}

void Game::game_start() {
    string move;
    //instantiate board
    cout << "Let's play chess!" << endl;

    //display board
    while(!player1->isCheckmate() || !player2->isCheckmate()) {
        if (turn == White) {
            cout << "White to move: " << endl;
        }   //Declares whose turn is it
        else {
            cout << "Black to move: " << endl;
        }

        //parse move to appropriate player
        cin >> move;
        //check if checkmate
        //increment turn
        nextTurn();
    }

    declare_win(); //outputs the winner

}

void Game::declare_win() {
    if (player1->isCheckmate()){
        cout << "Black is victorious!" << endl;
    }
    else if (player2->isCheckmate()) {
        cout << "White is victorious!" << endl;
    }
}