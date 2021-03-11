#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "board.hpp"
using namespace std;

class MoveFactory {
  public:
    char type;
    string static_name;
    MoveFactory(){}
    //MoveFactory(char t){type = t; make_canMove(t);}
    canMove*  make_canMove(char type) {
    /*  Promotion in chess is a rule that requires a pawn that reaches the eighth rank to be 
 *  replaced by the player's choice of a bishop, knight, rook, or queen of the same color .*/
/* "Choose Your Promotion by entering one of the following (R/Q/B/K)\nR: Rook\n\nQ: Queen\n\nB: Bishop\n\nK: Knight\n" */
/* "Play agaist ComputerPlayer ?(Y/N)*/
	if(type == 'P' || type == 'p'){
	static_name = "PAWN";
	return new PawnMove();
	}
	if (type == 'R' || type ==  'r') {
        static_name = "ROOK";
        return new RookMove();
        }
        if (type == 'Q' || type == 'q') {
          static_name = "QUEEN";
        return new QueenMove();
        }
        if (type == 'B' || type == 'b') {
          static_name = "BISHOP";
        return new BishopMove();
        }
        if (type == 'K' || type == 'k') {
          static_name = "KING";
        return new KingMove();
        }
        if (type == 'N' || type == 'n') {
          static_name = "KNIGHT";
        return new KnightMove();
        }	
	
try {
        if (type == 'R' || 'r') {
          return new RookMove();
        }
        if (type == 'Q' || 'q') {
          return new QueenMove();
        }
        if (type == 'B' || 'b') {
          return new BishopMove();
        }
        if (type == 'K' || 'k') {
          return new KingMove();
        }
        if (type == 'N' || 'n') {
          return new KnightMove();
        }
        if (type == 'P' || 'p') {
          return new PawnMove();
        }
        else {
          throw 1;

        }

      } catch (...) {
       std:: cout << "An exception occurred. Your Input is invalid!" << '\n';
      }

      return nullptr;
    }
	virtual string get_static_name(){
	return static_name;
}

};
#endif // __FACTORY_HPP__
