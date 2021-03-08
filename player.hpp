#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<set>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
 
class Player{

 protected:
   bool whiteSide;
   bool humanPlayer;
   int wincounter;
   int totalgameplayed;
   std::string name;
   std::string level;
 
 public:

   Player()= default  ;   
   virtual ~Player()= default  ;
 
   virtual bool isWhiteSide() const { return whiteSide; }

   virtual bool isHumanPlayer() const { return humanPlayer;}

   double winrate() const {
     if(totalgameplayed==0){return 0;}
     return ((double)wincounter/(double)totalgameplayed);
     }

   string get_name() const{ return name; }

   string get_level() const{ return level;}

   virtual bool is_composit() {return false;}

   virtual string print_list() {return "";}

   virtual Player* getPlayer(string) {return this;}

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

   string print_status()const{

    string return_string;
     
     return_string +="Player " + name +" is now " + level +". "+ name +" is a ";

     if(humanPlayer){return_string+= "Human Player ";}
     else{return_string += "Computer Player ";}

     return_string +="with a winrate of " + to_string(winrate()) + " in " + to_string(totalgameplayed) + " games";

     return return_string;
   }

   virtual bool cheatenable()=0;
 
};

class HumanPlayer : public Player{
  private:
   std::string password;
   bool login = false;
   
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
      if(password.size()==0){password = a; login=true; return;}
      if(a == password){login = true;}
      login = false;
    }

    bool check_log_in()const  {
      return login;}

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


  PlayerList(string new_name){name=new_name;}
  ~PlayerList()=default  ; // FIX ME

  string get_group_name(){return name;}


  void add(Player* a){GroupList.push_back(a); } 

  virtual bool cheatenable(){return false;}

  bool is_composit(){return true;}

  Player* getPlayer(string comparename){
     for(auto s:GroupList){
      if(s->is_composit()){
        s->getPlayer(name);
      }
      else{
        if(s->get_name() == comparename){return s;}
      } 
     }
  }

  string print_list(){

    string return_a;
    for(auto s:GroupList){
      if(s->is_composit()){
        return_a += s->print_list();
      }
      else{
        return_a += s->print_status();
        return_a += "\n";
      }
      
    }

    return return_a;
  }
 
};



#endif //PLAYER_HPP





