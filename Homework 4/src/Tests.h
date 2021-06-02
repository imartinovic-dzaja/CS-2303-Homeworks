#include "Room.h"
#include "AdjMat.h"
#include "LinkedList.h"
#include "Production.h"

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	//For Room
	bool testGetRoomNumber();
	bool testGetTreasure();
	bool testGetSearched();
	bool testEmptyTreasure();
	bool testSetSearched();
	//For Adj Mat
	bool testSetEdge();
	bool testGetEdge();
	bool testCreateMainDiagonalSymmetry();
	//For LinkedList
	bool testGetRoomP();
	bool testGetPrevP();
	bool testGetNextP();
    bool testAddRoomToLL();
    bool testIsEmpty();
    bool testRemoveFromListWhenListIsEmpty();
    bool testRomoveElementFromASingleNodeList();
    bool testRemoveRootMiddleLeafAndNonExistentFromList();
    bool testContainsRoom();
    bool testGetLeaf();

    //For Production
    bool testReadFile();
    bool testAddTreasure();
    bool testAddAdjecentOnToBeSearched();


};



#endif // TESTS_H_INCLUDED
