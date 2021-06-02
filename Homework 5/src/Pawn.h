/*
 * Pawn.h
 *
 *  Created on: Feb 26, 2020
 *      Author: jakef
 */

#ifndef PAWN_H_
#define PAWN_H_
#include "LinkedList.h"

class Move;

class Pawn{

public:
	Pawn();
	Pawn(int newIndex, bool newIsRed);
	virtual ~Pawn();
	void setIndex(int i);
	void setIsRed(bool r);
	int getIndex();
	bool getIsRed();
	void makeMove(Move*);
	bool canMoveLeftDown(int*);
	bool canMoveLeftUp(int*);
	bool canMoveRightDown(int*);
	bool canMoveRightUp(int*);



	bool canJumpMoveLeftDown(int*);
	bool canJumpMoveLeftUp(int*);
	bool canJumpMoveRightDown(int*);
	bool canJumpMoveRightUp(int*);


	LLNode<Move>* moveList(int*);
	LLNode<Move>* jumpMoveList(int*);

private:
	int index;
	bool isRed;
};
class King : public Pawn{
public:
	King();
    King(int newIndex, bool newIsRed);

	virtual ~King();

	LLNode<Move>* moveList(int*);
	LLNode<Move>* jumpMoveList(int*);
};

class Move{
public:
    Move();
    Move(Pawn* pawnP, int next);
	Pawn* m_pawnP;
	int m_next;
	//for testing purposes
	void printMove();
};

#endif /* PAWN_H_ */

