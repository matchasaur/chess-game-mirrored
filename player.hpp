#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<set>
#include<vector>
#include<string>
#include<iostream>


 
class Player{

 protected:
   bool whiteSide;
   bool humanPlayer;
   int wincounter;
   int totalgameplayed;
   std::string name;
   std::string level;
 
 public:

   virtual Player() {};    
   virtual ~Player(){};
 
   virtual bool isWhiteSide() const { return whiteSide; }

   virtual bool isHumanPlayer() const { return humanPlayer;}

   double winrate() const {return ((double)wincounter/(double)totalgameplayed);}

   string get_name const{ return name; }

   string get_level const{ return level;}

   void update_level(){

     if(totalgameplayed<2){level = "unranked"; std::cout<<"You'll need to complete 2 competitive matches to get your first rank."; return; } //no idea if this should be print somewhere else. FIX ME!!!!

     if(winrate()<0.5){level = "Silver Elite Master";}
     else if(winrate()<0.6){level = "Gold Nova Master";}
     else if(winrate()<0.7){level = "Distinguished Master Guardian";}
     else if(winrate()<0.8){level = "Legendary Eagle Master";}
     else if(winrate()<0.9){level = "Supreme Master First Class";}
     else {level = "The Global Elite";}

     return;
   }

   void print_status const(){
     std::cout<<"Player " << name << " " << this->ID <<" is now " << level <<std::endl<< name <<" is a";
     if(humanPlayer){std::cout<<"Human Player";}
     else{std::cout<<"ComputerPlayer Player";}
     std::cout<<"with a winrate of " << winrate() << " in " << totalgameplayed << " games->";
   }

   virtual bool cheatenable(){}=0;
 
};

class HumanPlayer : public Player{
  private:
   std::string password;
   bool log_in = false;
   
  public:
    

     HumanPlayer(std::string _name, bool side){
     name=_name; 
     whiteSide = side;
     humanPlayer = true;
     wincounter=0;
     totalgameplayed=0;
     level="BEGINER";
   }
   ~HumanPlayer(){}
   
    void log_in(std::string a) {
      if(password.size()=0){password = a; log_in=true; return;}
      if(a == password){log_in = true;}
      log_in = false;
    }

    void check_log_in()const  {
      return log_in;}

    virtual bool cheatenable(){ return false; }


};


class ComputerPlayer : public Player{

  public:

   ComputerPlayer(std::string _name, bool side){
     name=_name; 
     whiteSide = side;
     humanPlayer = false;
     wincounter=0;
     totalgameplayed=0;
     level="BEGINER";
   }
   ~ComputerPlayer(){}

    bool cheatenable(){return true;}
    bool cheat_instant_max_level_true(){totalgameplayed=100; wincounter=100; update_level(); return true;}
    bool cheat_instant_min_level_true(){totalgameplayed=100; wincounter=0; update_level(); return true;}
};


class PlayerList : public Player{

 public:
  string name;
  vector <Player*> GroupList;


  PlayerList(string new_name,int new_player_count){name=new_name;}
  ~PlayerList(){delete name;  delete[] GroupList }; // FIX ME

  string get_group_name(){return name;}


  void add(player* a){GroupList.push_back(a); } 

  bool is_composit(){return true;}

  player* getPlayer(string comparename){
     for(auto s:GroupList){
      if(s->is_composit){
        s->getPlayer(name)
      }
      else{
        if(s->name == comparename){return s;}
      } 
     }
  }

  void print_list{
    for(auto s:GroupList){
      if(s->is_composit){
        s->print_list();
      }
      else{
        s->print_status();
        cout << endl;
      }
      
    }
  }
 
};






