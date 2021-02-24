#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<set>
#include<string>
#include<iostream>

int Get_ID = 0;
 
class Player{
 protected:
   bool whiteSide;
   bool humanPlayer;
   int ID;
   int wincounter;
   int totalgameplayed;
   std::string name;
   std::string level;
   std::set<Player*> FriendList;


 public:
   Player(std::string _name, bool side, bool human){
     name=_name; 
     whiteSide = side;
     humanPlayer = human;
     wincounter=0;
     totalgameplayed=0;
     level="BEGINER";
     ID = Get_ID;
     Get_ID++;
     //example call Player("JIMMY",TRUE,TURE) // PLYAER JIMMY is White side and is human    
     //example call Player("JIMMY",FALSE,FALSE) // PLYAER JIMMY is BLACK side and is AI   
   }

   ~Player(){for(auto s:FriendList){delete s;}}
 
   bool isWhiteSide() const {
     return whiteSide;
   }

   bool isHumanPlayer() const {
     return humanPlayer;
   }

   void addFriend(Player* new_friend){
     FriendList.insert(new_friend);
     
   }

   void removeFriend(Player* old_friend){
     FriendList.erase(old_friend);
     old_friend->removeFriend(this);
   }

   double winrate() const {
     return ((double)wincounter/(double)totalgameplayed);
   }

   int get_ID() const {
     return ID;
   }

   void update_level(){

     if(totalgameplayed<3){level = "unranked"; std::cout<<"You'll need to complete 3 competitive matches to get your first rank."; return; }

     if(winrate()<0.5){level = "Silver Elite Master";}
     else if(winrate()<0.6){level = "Gold Nova Master";}
     else if(winrate()<0.7){level = "Distinguished Master Guardian";}
     else if(winrate()<0.8){level = "Legendary Eagle Master";}
     else if(winrate()<0.9){level = "Supreme Master First Class";}
     else {level = "The Global Elite";}

     return;
   }

   void print_status(){
     std::cout<<"Player " << name << " " << this->ID <<" is now " << level <<std::endl<< name <<" is a";
     if(humanPlayer){std::cout<<"Human Player";}
     else{std::cout<<"AI Player";}
     std::cout<<"with a winrate of " << winrate() << " in " << totalgameplayed << " games." << std::endl;
   }
 
};
 

class HumanPlayer : public Player{
  private:
   std::string password;

  public:
    bool log_in(std::string a) const {
      if(a == password){return true;}
      return false;
    }

};


class AI : public Player{

  public:
    bool cheatenable(){return true;}
    bool cheat_instant_max_level_true(){totalgameplayed=100; wincounter=100; update_level(); return true;}
    bool cheat_instant_min_level_true(){totalgameplayed=100; wincounter=0; update_level(); return true;}
};


 
 
#endif //PLAYER_HPP
