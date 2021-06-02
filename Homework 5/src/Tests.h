#include "LinkedList.h"
#include "Production.h"
#include "Pawn.h"
#include "Board.h"

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED



class Tests {
public:

	Tests();
	virtual ~Tests();
	bool tests();

	//For LinkedList
	bool testGetElementP();
	bool testGetPrevP();
	bool testGetNextP();
	bool testAddElementToLL();
	bool testIsEmpty();
	bool testRemoveFromListWhenListIsEmpty();
	bool testRomoveElementFromASingleNodeList();
	bool testRemoveRootMiddleLeafAndNonExistentFromList();
	bool testContainsElement();
	bool testGetLeaf();
	bool testGetLenght();
	bool testAppendList();
	bool testgetRandomElement();

	//For Pawn
	//setters
	bool testSetIndexAndTestGetIndex();
	bool testSetIsRedAndTestGetIsRed();
	//regular moves
	bool testCanMoveLeftDown();
	bool testCanMoveLeftUp();
	bool testCanMoveRightDown();
	bool testCanMoveRightUp();

	//jump moves
	bool testCanJumpMoveLeftDown();
	bool testCanJumpMoveLeftUp();
	bool testCanJumpMoveRightDown();
	bool testCanJumpMoveRightUp();
	bool testJumpMoveLeft();
	bool testJumpMoveTestRight();
	//list construction
	bool testMoveListPawn();
	bool testJumpMoveListPawn();
	//special
	bool testMakeIntoKing();

	//For King
	bool testMoveOppLeft();
	void testMoveOppRight();
	bool testKingMoveList();
	bool testKingJumpMoveList();

	//For Board
	bool testPrintBoard();
	bool testFindPieceAtIndex();
	bool testUpdateBoard();
	bool testPerformMove();
	bool testPerformJump();

};



#endif // TESTS_H_INCLUDED
