/* Created by Chun on 3/7/2021.*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<set>

#include<vector>

#include<string>

#include<iostream>

using namespace std;

enum color {
  White,
  Black
};

class Player {

  protected:

    bool humanPlayer;
  bool checkmate = false;
  int wincounter;
  int totalgameplayed;
  string name;
  string level;

  color pieces;
  explicit Player(color pieceColor) {
    pieces = pieceColor;
  }

  public:

    Player() =
    default;
  virtual~Player() =
    default;

  virtual color get_color() const {
    return pieces;
  }

  virtual void win_increment() {
    wincounter++;
  }
  virtual int get_wincounter() {
    return wincounter;
  }

  virtual void instantwin(){
    checkmate = true;
  }

  virtual void set_name(string a) {
    name = a;
  }

  virtual int get_size(){return 0;}

  virtual void set_color(color a) {
    pieces = a;
  }

  virtual bool isCheckmate() {
    return checkmate;
  }

  virtual void instantCheckmate() {
    checkmate = true;
  }


  virtual bool isHumanPlayer() const {
    return humanPlayer;
  }

  virtual void game_increment() {
    totalgameplayed++;
  }

  double winrate() const {
    if (totalgameplayed == 0) {
      return 0;
    }
    return ((double) wincounter / (double) totalgameplayed);
  }

  string get_name() const {
    return name;
  }

  string get_level() const {
    return level;
  }

  virtual bool is_composit() {
    return false;
  }

  virtual string print_list() {
    return "";
  }

  virtual Player * getPlayer(string) {
    return this;
  }

  void update_level() {

    if (totalgameplayed < 2) {
      level = "unranked";
      
      return;
    } /*no idea if this should be print somewhere else. FIX ME!!!!*/

    if (winrate() < 0.5) {
      level = "Silver Elite Master";
    } else if (winrate() < 0.6) {
      level = "Gold Nova Master";
    } else if (winrate() < 0.7) {
      level = "Distinguished Master Guardian";
    } else if (winrate() < 0.8) {
      level = "Legendary Eagle Master";
    } else if (winrate() < 0.9) {
      level = "Supreme Master First Class";
    } else {
      level = "The Global Elite";
    }

    return;
  }

  string print_status() {

    string return_string;

    update_level();

    return_string += "Player " + name + " is now " + level + ". " + name + " is a ";

    if (humanPlayer) {
      return_string += "Human Player ";
    } else {
      return_string += "Computer Player ";
    }

    return_string += "with a winrate of " + to_string(winrate()) + " in " + to_string(totalgameplayed) + " games";

    return return_string;
  }

  virtual bool cheatenable() = 0;

};

class HumanPlayer: public Player {
  private: string password;
  bool login = false;

  public:

    HumanPlayer(string _name, color pieceColor) {
      name = _name;
      pieces = pieceColor;
      humanPlayer = true;
      wincounter = 0;
      totalgameplayed = 0;
      level = "BEGINER";
    }~HumanPlayer() {}

  void log_in(string a) {
    if (password.size() == 0) {
      password = a;
      login = true;
      return;
    }
    if (a == password) {
      login = true;
    }
    login = false;
  }

  bool check_log_in() const {
    return login;
  }

  virtual bool cheatenable() {
    return false;
  }


};

class ComputerPlayer: public Player {

  public:

    ComputerPlayer(string _name, color pieceColor) {
      name = _name;
      pieces = pieceColor;
      humanPlayer = false;
      wincounter = 0;
      totalgameplayed = 0;
      level = "BEGINER";
    }~ComputerPlayer() {}

  bool cheatenable() {
    return true;
  }
  bool cheat_instant_max_level_true() {
    totalgameplayed = 100;
    wincounter = 100;
    update_level();
    return true;
  }
  bool cheat_instant_min_level_true() {
    totalgameplayed = 100;
    wincounter = 0;
    update_level();
    return true;
  }
};

class PlayerList: public Player {

  public: string name;
  int size;
  vector < Player * > GroupList;

  PlayerList(string new_name) {
    name = new_name;
    size = 0;
  }
  ~PlayerList(){
    for (auto s: GroupList) {
      if (s -> is_composit()) {
        delete[] s;
      } else {
        delete s;
      }
    } 
  }

  string get_group_name() {
    return name;
  }

  void add(Player * a) {
    GroupList.push_back(a);
    if(!is_composit()){
      size += a->get_size(); }
      
    else{size++;}
    
  }

  virtual bool cheatenable() {
    return false;
  }

  virtual int get_size() {
    return size;
  }

  bool is_composit() {
    return true;
  }

 
  Player * getPlayer(string comparename) {
    for (auto s: GroupList) {
      if (s -> is_composit()) {
        return s -> getPlayer(comparename);
      } else {
        if (s -> get_name() == comparename) {
          return s;
        }
      }
    } return nullptr;
  }

  string print_list() {

    string return_a;
    for (auto s: GroupList) {
      if (s -> is_composit()) {
        return_a += s -> print_list();
      } else {
        return_a += s -> print_status();
        return_a += "\n";
      }

    }

    return return_a;
  }
  

};

#endif //PLAYER_HPP
