#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<set>
#include<string>

static int ID_MASK = 0;
 
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
     ID = ID_MASK;
     ID_MASK++;
     //example call Player("JIMMY",TRUE,TURE) // PLYAER JIMMY is White side and is human    
     //example call Player("JIMMY",FALSE,FALSE) // PLYAER JIMMY is BLACK side and is AI   
   }

   ~Player(){for(auto s:FriendList){delete s;}}
 
   bool isWhiteSide(){
     return whiteSide;
   }

   bool isHumanPlayer(){
     return humanPlayer;
   }

   void addFriend(Player* new_friend){
     FriendList.insert(new_friend);
     
   }

   void removeFriend(Player* old_friend){
     FriendList.erase(old_friend);
     old_friend->removeFriend(this);
   }

   double winrate(){
     return ((double)wincounter/(double)totalgameplayed);
   }

   int get_ID(){
     return ID;
   }
 
};
 

class HumanPlayer : public Player{
  private:
   std::string password;

  public:
    bool log_in(std::string a){
      if(a == password){return true;}
      return false;
    }
};


class AI : public Player{

  public:
    // FIX ME implement special functions
};

 
 
#endif //PLAYER_HPP
