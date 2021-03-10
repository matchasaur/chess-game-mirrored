#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


class MoveFactory {
  public:
    make_canMove * make_op(char type,bool a) {
    /*  Promotion in chess is a rule that requires a pawn that reaches the eighth rank to be 
 *  replaced by the player's choice of a bishop, knight, rook, or queen of the same color .*/
/* "Choose Your Promotion by entering one of the following (R/Q/B/K)\nR: Rook\n\nQ: Queen\n\nB: Bishop\n\nK: Knight\n" */
/* "Play agaist ComputerPlayer ?(Y/N)*/

try {
        if (type == 'R' || 'r') {
          return new RookMove(a);
        }
        if (type == 'Q' || 'q') {
          return new QueenMove(a);
        }
        if (type == 'B' || 'b') {
          return new BishopMove(a);
        }
        if (type == 'K' || 'k') {
          return new KingMove(a);
        }
        if (type == 'N' || 'n') {
          return new KnightMove(a);
        }
        if (type == 'P' || 'p') {
          return new PawnMove(a);
        }
        else {
          throw 1;

        }

      } catch (...) {
        cout << "An exception occurred. Your Input is invalid!" << '\n';
      }

      return nullptr;
    }

};
#endif // __FACTORY_HPP__
