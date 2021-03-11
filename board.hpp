#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include<iostream>
#include<map>
#include<list>
#include <stdlib.h>
#include <queue>
#include <stack>


class Spot{
	int x;
	int y;
    char t;
public:
    Spot() {}
    ~Spot(){}
	Spot(int x, int y, char t){
	this->setPiece(t);
    this->setY(y);
    this->setX(x);
	}
	char getPiece(){return this->t;}
	void setPiece(char t){this->t = t;}
	int getX(){return this->x;}
	void setX(int x){this->x = x;}
	int getY(){return this->y;}
	void setY(int y) {this->y = y;}

};

class Board{
	Spot* boxes[8][8];
    
public:
    std::stack<Spot*> history;
	Board();
	~Board(){
	 for(int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			delete boxes[i][j];
		}
	}
	 while(!history.empty()){
        delete history.top();
        history.pop();
	 }

	}
	void resetBoard();
    void undo();
	Spot* getBox(int, int);
    void printBoard();
    void move(Board*, Spot* startBox, Spot* endBox);
    bool WhitekingCaptured = false;
    bool BlackkingCaptured = false;
    void printOptions(Board*);

    void Capture(int i){
      if (i == 1){BlackkingCaptured=true;} 
      else if(i==2){WhitekingCaptured=true;}
    }
};
class canMove{
    public:
    virtual ~canMove(){}
    virtual bool move (Board*, Spot*, Spot*) = 0;
};

class PawnMove : public canMove{

    canMove* help;
    public:
    ~PawnMove(){}
     PawnMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){

    if(start->getPiece() == 'P'){
        if(start->getX() > end->getX()){
            return false;
        }
        if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' && end->getPiece() != '-' ){
            if(end->getY() != start->getY() && ((end->getX() == start->getX() + 1) || (end->getX() == start->getX() - 1)) ){
                if(end->getPiece() == 'k'){
                    yeet->BlackkingCaptured = true;
                }
                if(end->getX() == 7){
                  end->setPiece('Q');
                  start->setPiece('-');
                  return true;
                }
                end->setPiece(start->getPiece());
			    start->setPiece('-');
               return true;
            }
        }
    }
    if(start->getPiece() == 'p'){
        if(end->getX() > start->getX()){
            return false;
        }
        if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' && end->getPiece() != 'k' && end->getPiece() != '-' ){
            if(end->getY() != start->getY() && ((end->getX() == start->getX() + 1) || (end->getX() == start->getX() - 1)) ){
                if(end->getPiece() == 'K'){
                    yeet->WhitekingCaptured = true;
                }
                if(end->getX() == 0){
                  end->setPiece('q');
                  start->setPiece('-');
                  return true;
                }
                end->setPiece(start->getPiece());
			    start->setPiece('-');
               return true;
            }
        }
    }
    if(start->getX() == 1 || start->getX() == 6){
        if((end->getY() == start->getY() && (abs(start->getX() - end->getX()) <= 2) && end->getPiece() == '-')){
        end->setPiece(start->getPiece());
		start->setPiece('-');
        return true;
        }
    }
    if((end->getY() == start->getY()) && (abs(start->getX() - end->getX()) <= 1) && end->getPiece() == '-'){
        end->setPiece(start->getPiece());
		start->setPiece('-');
        return true;
    }

        return false;
    }
        
};

class RookMove : public canMove{
    public:
    ~RookMove(){}
    RookMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){
        if(start->getPiece() == 'R'){
            if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' ){
                if((start->getX() == end->getX()) && (start->getY() != end->getY())){
                    for(int i = start->getY() + 1; i < end->getY(); ++i){
                        if(yeet->getBox(start->getX(), i)->getPiece() != '-'){
                            return false;
                        }
                    }
                    if(end->getPiece() == 'k'){
                        yeet->BlackkingCaptured = true;;
                    }
                        end->setPiece(start->getPiece());
		                start->setPiece('-');
                        return true;
                }
                if((start->getY() == end->getY()) && (start->getX() != end->getX())){
                    for(int i = start->getX() + 1; i < end->getX(); ++i){
                       if(yeet->getBox(i, start->getY())->getPiece() != '-'){
                            return false;
                        }
                    }
                            end->setPiece(start->getPiece());
		                    start->setPiece('-');
                            return true;
                }
            }
        }
        if(start->getPiece() == 'r'){
            if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' && end->getPiece() != 'k' ){
                if(start->getX() == end->getX() && start->getY() != end->getY()){
                    for(int i = start->getY() - 1 ; i > end->getY(); --i){
                        if(yeet->getBox(start->getX(), i)->getPiece() != '-'){
                            return false;
                        }
                    }
                    if(end->getPiece() == 'K'){
                        yeet->WhitekingCaptured = true;;
                    }
                            end->setPiece(start->getPiece());
		                    start->setPiece('-');
                            return true;
                }
                if(start->getY() == end->getY() && start->getX() != end->getX()){
                    for(int i = start->getX() - 1; i > end->getX(); --i){
                       if(yeet->getBox(i, start->getY())->getPiece() != '-'){
                            return false;
                        }
                    }
                            end->setPiece(start->getPiece());
		                    start->setPiece('-');
                            return true;
                }
            }
        }

        return false;
    }
};

class KnightMove : public canMove{
    public:
    ~KnightMove(){}
    KnightMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){
        if(start->getPiece() == 'N'){
            if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' ){
                if( ( abs(start->getX() - end->getX()) == 1 || abs(start->getX() - end->getX()) == 2 ) && (abs(start->getX() - end->getX()) == 1 || abs(start->getX() - end->getX()) == 2) && (abs(start->getX() - end->getX()) != abs(start->getY() - end->getY()) )){
                    if(end->getPiece() == 'k'){
                        yeet->BlackkingCaptured = true;;
                    }
                    end->setPiece(start->getPiece());
		            start->setPiece('-');
                    return true;
                }
            }
        }

        if(start->getPiece() == 'n'){
            if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' && end->getPiece() != 'q' ){
                if( ( abs(start->getX() - end->getX()) == 1 || abs(start->getX() - end->getX()) == 2 ) && (abs(start->getX() - end->getX()) == 1 || abs(start->getX() - end->getX()) == 2) && (abs(start->getX() - end->getX()) != abs(start->getY() - end->getY()) )){
                    if(end->getPiece() == 'K'){
                        yeet->WhitekingCaptured = true;;
                    }
                    end->setPiece(start->getPiece());
		            start->setPiece('-');
                    return true;
                }
            }            
        }
        return false;
    }
};

class KingMove : public canMove{
    public:
    ~KingMove(){}
    KingMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){
        if(start->getPiece() == 'K'){
            if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' ){
                if((abs(start->getX() - end->getX()) <= 1) && (abs(start->getY() - end->getY()) <= 1) ){
                    if(end->getPiece() == 'k'){
                        yeet->BlackkingCaptured = true;;
                    }
                    end->setPiece(start->getPiece());
		            start->setPiece('-');
                    return true;
                }
            }
        }
        if(start->getPiece() == 'k'){
            if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' ){
                if((abs(start->getX() - end->getX()) <= 1) && (abs(start->getY() - end->getY()) <= 1) ){
                    if(end->getPiece() == 'K'){
                        yeet->WhitekingCaptured = true;;
                    }
                    end->setPiece(start->getPiece());
		            start->setPiece('-');
                    return true;
                }
            }
        }
        return false;
    }
};

class BishopMove : public canMove{
    public:
    ~BishopMove(){}
    BishopMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){
        if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' ){
            if((start->getX() != end->getX()) && (end->getY() != start->getY())){
                if((end->getX() > start->getX()) && (end->getY() > start->getY())){
                    for(int i = start->getX()+ 1; i < end->getX(); ++i){
                        for(int j = start->getY() + 1; j < end->getY(); ++j){
                            if(yeet->getBox(i,j)->getPiece() != '-' || yeet->getBox(start->getX(), i)->getPiece() != 'B'){
                                return false;
                            }
                        }
                    
                    }
                }
                if((start->getX() > end->getX()) && (start->getY() > end->getY())){
                    for(int i = start->getX()- 1; i > end->getX(); --i){
                        for(int j = start->getY() - 1; j > end->getY(); --j){
                            if(yeet->getBox(i,j)->getPiece() != '-' || yeet->getBox(start->getX(), i)->getPiece() != 'B'){
                                return false;
                            }
                        }
                    
                    }
                }
                if(end->getPiece() == 'k'){
                    yeet->BlackkingCaptured = true;;
                }
                end->setPiece(start->getPiece());
		        start->setPiece('-');
                return true;
            }
        }
        if(start->getPiece() == 'b'){
            if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' &  end->getPiece() != 'q' && end->getPiece() != 'k' ){
                if((start->getX() != end->getX()) && (end->getY() != start->getY())){
                if((end->getX() > start->getX()) && (end->getY() > start->getY())){
                    for(int i = start->getX()+ 1; i < end->getX(); ++i){
                        for(int j = start->getY() + 1; j < end->getY(); ++j){
                            if(yeet->getBox(i,j)->getPiece() != '-' || yeet->getBox(start->getX(), i)->getPiece() != 'b'){
                                return false;
                            }
                        }
                    
                    }
                }
                if((start->getX() > end->getX()) && (start->getY() > end->getY())){
                    for(int i = start->getX()- 1; i > end->getX(); --i){
                        for(int j = start->getY() - 1; j > end->getY(); --j){
                            if(yeet->getBox(i,j)->getPiece() != '-' || yeet->getBox(start->getX(), i)->getPiece() != 'b'){
                                return false;
                            }
                        }
                    
                    }
                }
                }
            }
            if(end->getPiece() == 'K'){
                    yeet->WhitekingCaptured = true;;
                }
            end->setPiece(start->getPiece());
		    start->setPiece('-');
            return true;
            
        }
        return false;
    }
};

class QueenMove : public canMove{
    public:
    ~QueenMove(){}
    QueenMove(){}
    virtual bool move(Board* yeet, Spot* start, Spot* end){
        if(start->getPiece() == 'Q'){
            if(end->getPiece() != 'P' && end->getPiece() != 'R' && end->getPiece() != 'B' && end->getPiece() != 'N' && end->getPiece() != 'Q' && end->getPiece() != 'K' ){
                if(end->getPiece() == 'k'){
                    yeet->BlackkingCaptured = true;;
                }
            }
            end->setPiece(start->getPiece());
		    start->setPiece('-');
            return true;
        }
        if(start->getPiece() == 'q'){
            if(end->getPiece() != 'p' && end->getPiece() != 'r' && end->getPiece() != 'b' && end->getPiece() != 'n' && end->getPiece() != 'q' && end->getPiece() != 'k' ){
                if(end->getPiece() == 'K'){
                    yeet->WhitekingCaptured = true;;
                }
            }
            end->setPiece(start->getPiece());
		    start->setPiece('-');
            return true;
        }
        return false;
    }
};

#endif