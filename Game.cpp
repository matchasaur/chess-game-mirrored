//
// Created by Jared on 3/7/2021.
// Modified by Chun on 3/9/2021. /// Merge with PlayerClass

#include "Game.h"

#include "player.hpp"

#include <string>

#include <iostream>

#include <sstream>


using namespace std;

Game::Game() {
  player1 = new HumanPlayer("Player1", White);
  player2 = new HumanPlayer("Player2", Black);
  queue = new PlayerList("Queue");
  chessBoard = new Board();
  turn = White;

}

void Game::game_start() {
  string input;
  string move;
  //instantiate board
  cout << "Let's play chess!" << endl;
  if (PrintMenu() == 2) {
    return;
  } // END THE GAME HERE

  //display board
  chessBoard->printBoard();
  while (!player1 -> isCheckmate() || !player2 -> isCheckmate()) {
    if (turn == White) {
      cout << "White to move: " << endl;
    } //Declares whose turn is it
    else {
      cout << "Black to move: " << endl;
    }

    //parse move to appropriate player
    getline(cin, input);
    stringstream move(input);
    parseMove(move, turn);

    //display board
    chessBoard->printBoard();

  }

  declare_win(); //outputs the winner

}

void Game::declare_win() {
  if (player1 -> isCheckmate()) {
    cout << "Black is victorious!" << endl;
  } else if (player2 -> isCheckmate()) {
    cout << "White is victorious!" << endl;
  }
}

void Game::Print_rules() const {
  cout << "Chess is a two-player board game using a chessboard and sixteen pieces of six types for each player. Each type of piece moves in a distinct way. The object of the game is to checkmate (threaten with inescapable capture) the opponent's king. Games do not necessarily end in checkmate; players often resign if they believe they will lose. A game can also end in a draw in several ways.\n";
}

int Game::PrintMenu() {
  std: string menu_string;
  int option;

  cout << "Option 1: New Game 1V1 (Win Rate would not be recorded in this mode)" << endl;
  cout << "Option 2: View rules of chess From Wikipedia, the free encyclopedia" << endl;
  cout << "Option 8: Multiplayer Mode (More than 2 players would be waiting in a queue)" << endl;
  cout << "Option 9: Exit" << endl;

  cin >> option;

  switch (option) {

  case 1:
    this -> game_start();
    break;
  case 2:
    this -> Print_rules();
    break;
  case 8:
    this -> AddPlayer();
    break;
  case 9:
    cout << "Have a good day!";
    RandomChessQuotes();
    return 2;

  default:
    cout << "Invalid input, please try again";
    PrintMenu();
    break;

  }
  return -1;
}

void Game::AddPlayer() {
  cout << "Enter New Player Name or \"NA\" to stop\n";
  string input = "";
  string side;
  cin >> input;
  color decision;

  while (input != "NA") {
    cout << "Enter Side (W/B)\n";
    cin >> side;
    if (side == "W") {
      decision = White;
    } else {
      decision = Black;
    }
    Player * temp = new HumanPlayer(input, decision);
    queue -> add(temp);
    cin >> input;
  }
  return;
}

void Game::RandomChessQuotes() const {
  int a = rand() % (10 - 1 + 1);

  switch (a) {

  case 1:
    cout << "“I have come to the personal conclusion that while all artists are not chess players, all chess players are artists.” – Marcel Duchamp\n";
    break;
  case 2:
    cout << "“Unlike other games in which lucre is the end and aim, [chess] recommends itself to the wise by the fact that its mimic battles are fought for no prize but honor. It is eminently and emphatically the philosopher’s game.” – Paul Morphy\n";
    break;
  case 3:
    cout << "“The beauty of chess is it can be whatever you want it to be. It transcends language, age, race, religion, politics, gender, and socioeconomic background. Whatever your circumstances, anyone can enjoy a good fight to the death over the chess board.” – Simon Williams\n";
    break;
  case 4:
    cout << "“Chess is the struggle against the error.”– Johannes Zukertort\n";
    break;
  case 5:
    cout << "“Every chess master was once a beginner.” – Irving Chernev\n";
    break;
  case 6:
    cout << "“Avoid the crowd. Do your own thinking independently. Be the chess player, not the chess piece.” – Ralph Charell\n";
    break;
  case 7:
    cout << "“Chess makes men wiser and clear-sighted.” – Vladimir Putin\n";
    break;
  case 8:
    cout << "“Chess is the gymnasium of the mind.” – Blaise Pascal\n";
    break;
  case 9:
    cout << "“Chess holds its master in its own bonds, shackling the mind and brain so that the inner freedom of the very strongest must suffer.” – Albert Einstein\n";
    break;
  case 10:
    cout << "“Chess is a war over the board. The object is to crush the opponent’s mind.” – Bobby Fischer\n";
    break;
  default:
    cout << "“Chess is beautiful enough to waste your life for.” – Hans Ree\n";
  }

  return;

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
