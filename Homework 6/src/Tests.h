#include "Production.h"
#include "Watercraft.h"
#include "stats.h"
#include "board.h"
#include "game.h"


#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED



class Tests {
public:

	Tests();
	virtual ~Tests();
	bool tests();

	bool testWatercrafts();
    bool testStats();
    bool testCell();
    bool testCoordinate();
    bool testIsWinner();
    bool testCheckSunkShip();

    bool testPutShipAndCheckShot();
    bool updateGameBoard();
    bool testIsValidLocation();
    bool testConvertStringToPosition();
};



#endif // TESTS_H_INCLUDED
