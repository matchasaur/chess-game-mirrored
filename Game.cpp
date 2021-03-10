//
// Created by Jared on 3/7/2021.
//
#include "Game.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game(){
    player1 = new Player(White);
    player2 = new Player(Black);
    chessBoard = new Board();
    turn = White;
}

void Game::game_start() {
    string input;
    //instantiate board
    cout << "Let's play chess!" << endl;

    //display board
    chessBoard->printBoard();

    while(!player1->isCheckmate() || !player2->isCheckmate()) {
        if (turn == White) {
            cout << "White to move: " << endl;
        }   //Declares whose turn is it
        else {
            cout << "Black to move: " << endl;
        }

        //parse move to appropriate player
        getline(cin, input);
        stringstream move(input);
        parseMove(move, turn);

        //display board
        chessBoard->printBoard();

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

void Game::parseMove(stringstream &input, color playerTurn) {
    pair<int, int> startCoords, endCoords;
    string start, end;
    input >> start >> end;

    startCoords = getCoordinates(start);
    endCoords = getCoordinates(end);

    cout << "StartCoords: " << startCoords.first << ", " << startCoords.second << endl;
    cout << "EndCoords: " << endCoords.first << ", " << endCoords.second << endl;
    //NEED TO FIX Board.move() TO ACCEPT PAIRS OF INTS
    //chessBoard->move(chessBoard->getBox(startCoords), chessBoard->getBox(endCoords));
}

pair<int, int> Game::getCoordinates(string coordinate) {
    pair<int, int> xyCoordinates;
    //Creates a map that associates an alpha key to numerical value in-order to represent file (column)
    map<char, int> file;
    file.insert(pair<char, int>('a', 0));
    file.insert(pair<char, int>('b', 1));
    file.insert(pair<char, int>('c', 2));
    file.insert(pair<char, int>('d', 3));
    file.insert(pair<char, int>('e', 4));
    file.insert(pair<char, int>('f', 5));
    file.insert(pair<char, int>('g', 6));
    file.insert(pair<char, int>('h', 7));
    xyCoordinates.first = 8 - (coordinate.at(2) - '0');
    xyCoordinates.second = file[coordinate.at(1)];

    return xyCoordinates;
}
