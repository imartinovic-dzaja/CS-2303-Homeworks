/*
 * Pawn.cpp
 *
 *  Created on: Feb 26, 2020
 *      Author: jakef
 */

#include "Pawn.h"
#include "Board.h"

Move::Move() {}
Move::Move(Pawn* pawnP, int next) {m_pawnP = pawnP; m_next = next;}

void Move::printMove() {
	std::cout<<"("<<m_pawnP->getIndex()<<", "<<m_next<<") ";
}


Pawn::Pawn(){
	index=-1;
}

Pawn::Pawn(int newIndex, bool newIsRed) {
    index = newIndex;
    isRed = newIsRed;
}

Pawn::~Pawn(){}
King::King(){}
King::~King(){}
King::King(int newIndex, bool newIsRed): Pawn{newIndex, newIsRed}
{

}


void Pawn::setIndex(int i){
	if(i>=0 && i<Board::BOARDSIZE*Board::BOARDSIZE){
		index = i;
	}
}
void Pawn::setIsRed(bool r){isRed = r;}
int Pawn::getIndex(){return index;}
bool Pawn::getIsRed(){return isRed;}

// these functions test if the piece can make a regular move (they do not take into consideration
// the color of the piece and will be used by both the pawn and king classes
bool Pawn::canMoveLeftDown(int* board){
	// 1) cannot move off board horizontally
	// 2) cannot move off board vertically
	// 3) cannot move if blocked
	bool answer = index%8 != 0; // horizontal
	answer &= index < 56; // vertical
	answer &= board[index + Board::BOARDSIZE - 1] == 0; //not blocked

	return answer;
}
bool Pawn::canMoveLeftUp(int* board){

	// 1) cannot move off board horizontally
	// 2) cannot move off board vertically
	// 3) cannot move if blocked
	bool answer = index%8 != 0; // horizontal
	answer &= index >= 8; // vertical
	answer &= board[index - Board::BOARDSIZE - 1] == 0; //not blocked

	return answer;
}
bool Pawn::canMoveRightDown(int* board){
	// 1) cannot move off board horizontally
	// 2) cannot move off board vertically
	// 3) cannot move if blocked
	bool answer = index%8 != 7; // horizontal
	answer &= index < 56; // vertical
	answer &= board[index + Board::BOARDSIZE + 1] == 0; //not blocked

	return answer;
}
bool Pawn::canMoveRightUp(int* board){
	// 1) cannot move off board horizontally
	// 2) cannot move off board vertically
	// 3) cannot move if blocked
	bool answer = index%8 != 7; // horizontal
	answer &= index >= 8; // vertical
	answer &= board[index - Board::BOARDSIZE + 1] == 0; //not blocked

	return answer;
	return index%8 != 7 && board[index - Board::BOARDSIZE + 1] == 0;
}


// these functions test if the piece can make a jump move (they do not take into consideration
// the color of the piece and will be used by both pawn and king classes
bool Pawn::canJumpMoveLeftDown(int* board){
	// 1) cannot jump off board
	// 2) cannot jump own pieces
	// 3) cannot jump if there are 2 opponent pieces diagonally
	// 4) can jump only if a single opponent piece is diagonally left and down
	bool answer = ((index%8 != 0) && (index%8 != 1));          //if piece is in the second column to the left, no jumping
	answer &= !(index >= 48);                              //if piece is second to last row (down), no jumping
	answer &=  board[index + Board::BOARDSIZE - 1] != 0;        //there exists a piece to the left and down
	answer &= ((board[index + Board::BOARDSIZE - 1]) % 2) != (board[index]) % 2;   // if opposite colors it is possible
	answer &= !(board[index + 2* Board::BOARDSIZE - 2]); //make sure there are no pieces directly behind the piece we are jumping
	return answer;
}
bool Pawn::canJumpMoveLeftUp(int* board){
	// 1) cannot jump off board
	// 2) cannot jump own pieces
	// 3) cannot jump if there are 2 opponent pieces diagonally
	// 4) can jump only if a single opponent piece is diagonally left and up
	bool answer = ((index%8 != 0) && (index%8 != 1));          //if piece is in the second column left, no jumping
	answer &= !(index < 16);                            //if piece is firs or second, no jumping
	answer &=  board[index - Board::BOARDSIZE  - 1] != 0;        //there exists a piece to the left and up
	answer &= ((board[index - Board::BOARDSIZE - 1]) % 2) != (board[index]) % 2;   // if opposite colors it is possible
	answer &= !(board[index - 2* Board::BOARDSIZE - 2]); //make sure there are no pieces directly behind the piece we are jumping
	return answer;
}
bool Pawn::canJumpMoveRightDown(int* board){
	// 1) cannot jump off board
	// 2) cannot jump own pieces
	// 3) cannot jump if there are 2 opponent pieces diagonally
	// 4) can jump only if a single opponent piece is diagonally right and down
	bool answer = ((index%8 != 6) && (index%8 != 7));          //if piece is in the second right column, no jumping
	answer &= !(index >= 48);                            //if piece is last 2 rows, no jumping
	answer &=  board[index + Board::BOARDSIZE  + 1] != 0;        //there exists a piece to the right and down
	answer &= ((board[index + Board::BOARDSIZE + 1]) % 2) != (board[index]) % 2;   // if opposite colors it is possible
	answer &= !(board[index + 2* Board::BOARDSIZE + 2]); //make sure there are no pieces directly behind the piece we are jumping
	return answer;

	if (!answer) {std::cout<<index<<" is where it fails"<<std::endl;}

}
bool Pawn::canJumpMoveRightUp(int* board){
	// 1) cannot jump off board
	// 2) cannot jump own pieces
	// 3) cannot jump if there are 2 opponent pieces diagonally
	// 4) can jump only if a single opponent piece is diagonally right and down
	bool answer = ((index%8 != 6) && (index%8 != 7));          //if piece is in the second right column, no jumping
	answer &= !(index < 16);                            //if piece is in first 2 rows, no jumping
	answer &=  board[index - Board::BOARDSIZE  + 1] != 0;        //there exists a piece to the right and down
	answer &= ((board[index - Board::BOARDSIZE + 1]) % 2) != (board[index]) % 2;   // if opposite colors it is possible
	answer &= !(board[index - 2* Board::BOARDSIZE + 2]); //make sure there are no pieces directly behind the piece we are jumping
	return answer;

}


// this function return the list of all possible regular moves for a single Pawn
// Kings will have a implementation which overrides this one
LLNode<Move>* Pawn::moveList(int* board){
	LLNode<Move>* lP = new LLNode<Move>();

	if (this->isRed) {
		if (this->canMoveLeftDown(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() + Board::BOARDSIZE - 1));
		}
		if (this->canMoveRightDown(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() + Board::BOARDSIZE + 1));
		}
	}
	else {
		if (this->canMoveLeftUp(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() - Board::BOARDSIZE - 1));
		}
		if (this->canMoveRightUp(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() - Board::BOARDSIZE + 1));
		}
	}

	return lP;
}

LLNode<Move>* Pawn::jumpMoveList(int* board){
	LLNode<Move>* lP = new LLNode<Move>();

	if (this->isRed) {
		if (this->canJumpMoveLeftDown(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() + 2*Board::BOARDSIZE - 2));
		}
		if (this->canJumpMoveRightDown(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() + 2*Board::BOARDSIZE + 2));
		}
	}
	else {
		if (this->canJumpMoveLeftUp(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() - 2*Board::BOARDSIZE - 2));
		}
		if (this->canJumpMoveRightUp(board)) {
			lP->addElementToLL(new Move(this, this->getIndex() - 2*Board::BOARDSIZE + 2));
		}
	}

	return lP;
}


LLNode<Move>* King::moveList(int* board){
	LLNode<Move>* lP = new LLNode<Move>();

	if (this->canMoveLeftDown(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() + Board::BOARDSIZE - 1));
	}
	if (this->canMoveRightDown(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() + Board::BOARDSIZE + 1));
	}

	if (this->canMoveLeftUp(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() - Board::BOARDSIZE - 1));
	}
	if (this->canMoveRightUp(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() - Board::BOARDSIZE + 1));
	}
	return lP;
}
LLNode<Move>* King::jumpMoveList(int* board){
	LLNode<Move>* lP = new LLNode<Move>();
	if (this->canJumpMoveLeftDown(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() + 2*Board::BOARDSIZE - 2));
	}
	if (this->canJumpMoveRightDown(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() + 2*Board::BOARDSIZE + 2));
	}

	if (this->canJumpMoveLeftUp(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() - 2*Board::BOARDSIZE - 2));
	}
	if (this->canJumpMoveRightUp(board)) {
		lP->addElementToLL(new Move(this, this->getIndex() - 2*Board::BOARDSIZE + 2));
	}
	return lP;
}

