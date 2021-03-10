//
// Created by Jared on 3/7/2021.
// Modified by Chun on 3/9/2021. /// Merge with PlayerClass

#include "Game.h"

#include "player.hpp"

#include <string>

#include <iostream>

#include <sstream>

#include <stdlib.h>

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
  Player* winnerptr;
  int winner = -2;


  cout << "Let's play chess!" << endl;

  

if(queue->get_size()>1){

  string name1; 
  string name2;
  

  delete player1;
  delete player2;

  cout<< queue->print_list();
  cout<<"Who is player 1?(White)\n";
  cin >> name1;
  cout<< "Who is player 2?(Black)\n";
  cin >> name2;

  player1 = queue->getPlayer(name1);
  player1->set_color(White);
  player2 = queue->getPlayer(name2);
  player1->set_color(Black);
  player1->game_increment();
  player2->game_increment();

}
else if (queue->get_size()== 1) {cout<< "WINNER WINNER CHICKEN DINNER!\n" << "YOU ARE THE TOURNAMENT CHAMPION!"; cout<< queue->print_list(); exit(1);}


  chessBoard->printBoard();

  while (!player1 -> isCheckmate() || !player2 -> isCheckmate()) {

    if (turn == White) {
      cout << "White to options: " << endl;
    } 
    else {
      cout << "Black to options: " << endl;
    }

    chessBoard->printOptions(chessBoard);


    //parse move to appropriate player
    parseMove(turn);
    //display board

//     chessBoard->printOptions(chessBoard);

//     getline(cin, input);
//     stringstream move(input);
//     parseMove(move, turn);



    chessBoard->printBoard();
    nextTurn();
  }
  if(winner==-2) {declare_win(chessBoard);}  //outputs the winner
  
  if(winner ==1){player1->win_increment(); winnerptr = player1;}
  else if(winner ==2){player2->win_increment(); winnerptr = player2;}
  else {PrintMenu(this);}

  
  if (queue->get_size()-1 == winnerptr->get_wincounter()) {cout<< "WINNER WINNER CHICKEN DINNER!\n" << "YOU ARE THE TOURNAMENT CHAMPION!"; exit(1);}
  else{
    char temp;
    cout << "There are more players waiting to play with you in the queue, do you want to continute? Do you want to see your rank? (Y/N/R)\n";
     cin >> temp;
     if(temp == 'Y'){game_start();}
     else if (temp == 'R') {winnerptr->print_status();}
     else {exit(1);}
  }

}



int Game::PrintMenu(Game* t) {
  std: string menu_string;
  int option;

  cout << "Option 1: New Game 1V1 (Win Rate would not be recorded in this mode)" << endl;
  cout << "Option 2: View rules of chess From Wikipedia, the free encyclopedia" << endl;
  cout << "Option 8: Multiplayer Mode (More than 2 players would be waiting in a queue)" << endl;
  cout << "Option 9: Exit" << endl;

  cin >> option;

  switch (option) {

  case 1:
    cin.ignore();
    t -> game_start();
    break;
  case 2:
    cin.ignore();
    this -> Print_rules();
    PrintMenu(t);
    break;
  case 8:
    cin.ignore();
    this -> AddPlayer();
    t -> game_start();
    break;
  case 9:
    cin.ignore();
    cout << "Have a good day!\n";
    RandomChessQuotes();
    return 2;
    exit(1);
    break;

  default:
    cout << "Invalid input, please try again\n";
    PrintMenu(t);
    break;

  }
  return -1;
}

void Game::AddPlayer() {
  string input = "";
 
  cout << "Enter New Player Name or \"NA\" to stop\n";
  cin >> input;
  

  while (input != "NA") {
  
    Player * temp = new HumanPlayer(input, White);
    queue -> add(temp);
    
    cout << "Enter New Player Name or \"NA\" to stop\n";

    cin >> input;
  
  }

 
  return;
}

int Game::declare_win(Board* t) {
  if (t -> WhitekingCaptured) {
    cout << "Black is victorious!" << endl;
    return 1;
  } else if (t -> BlackkingCaptured) {
    cout << "White is victorious!" << endl;
    return 2;
  }
  return -1; //tie
}

int Game::declare_win(int a) {
  if (a == 1) {
    cout << "Black is victorious!" << endl;
    return 1;
  } else if (a == 2) {
    cout << "White is victorious!" << endl;
    return 2;
  }
  return -1; //tie
}



void Game::parseMove(color playerTurn) {

    pair<int, int> startCoords, endCoords;
    string start, end, input;
    bool validInput = false;

    while (!validInput) {
        getline(cin, input);
        if (input.empty()){
            cout << "Invalid input!" << endl << "Please enter in valid notation (i.e. \"e2 e4\")" << endl;
            continue;
        }
        stringstream move(input);

        move >> start >> end;

        if (validateInput(start) && validateInput(end)) {
            validInput = true;
        }
        else{
            cout << "Invalid input!" << endl << "Please enter in valid notation (i.e. \"e2 e4\")" << endl;
        }
    }

    startCoords = getCoordinates(start);
    endCoords = getCoordinates(end);

    cout << "StartCoords: " << startCoords.first << ", " << startCoords.second << endl;
    cout << "EndCoords: " << endCoords.first << ", " << endCoords.second << endl;
    
    chessBoard->move(chessBoard, chessBoard->getBox(startCoords.first, startCoords.second), chessBoard->getBox(endCoords.first, endCoords.second));
}

pair<int, int> Game::getCoordinates(string coordinate) {
    pair<int, int> xyCoordinates;

    map<char, int> file;
    file.insert(pair<char, int>('a', 0));
    file.insert(pair<char, int>('b', 1));
    file.insert(pair<char, int>('c', 2));
    file.insert(pair<char, int>('d', 3));
    file.insert(pair<char, int>('e', 4));
    file.insert(pair<char, int>('f', 5));
    file.insert(pair<char, int>('g', 6));
    file.insert(pair<char, int>('h', 7));
    xyCoordinates.first = 8 - (coordinate.at(1) - '0');
    xyCoordinates.second = file[coordinate.at(0)];

    return xyCoordinates;
}


/*clean*/

void Game::Print_rules() const {
  cout << "\n\nChess is a two-player board game using a chessboard and sixteen pieces of six types for each player. Each type of piece moves in a distinct way. The object of the game is to checkmate (threaten with inescapable capture) the opponent's king. Games do not necessarily end in checkmate; players often resign if they believe they will lose. A game can also end in a draw in several ways.\n\n";
}

void Game::RandomChessQuotes() const {
  int a = rand() % 10 + 1;

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

bool Game::validateInput(string move) {
    if (isalpha(move.at(0)) && (tolower(move.at(0)) == 'a' || tolower(move.at(0)) == 'b' || tolower(move.at(0)) =='c' || tolower(move.at(0)) == 'd' || tolower(move.at(0)) == 'e' || tolower(move.at(0)) == 'f' || tolower(move.at(0)) == 'g' || tolower(move.at(0)) == 'h')) {
        return (((move.at(1) - '0') > -1) && ((move.at(1) - '0') < 9));
    }
    return false;
}