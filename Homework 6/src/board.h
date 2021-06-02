#include "stats.h"
#include "cell.h"
#include "Watercraft.h"
#include <stdlib.h>
#include <conio.h>
#include <fstream>


#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

/* CONSTANT MACROS */

#define ROWS 10
#define COLS 10

#define LOG_FILE_NAME "battleship.log"

#define NUM_OF_SHIPS  5

#define HORIZONTAL    0
#define VERTICAL      1

#define PLAYER_ONE    0
#define PLAYER_TWO    1


#define WATER         '~'
#define HIT           '*'
#define MISS          'm'

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3


typedef Cell myType[ROWS][COLS];

enum ShipType{
	CARRIER_L    = 5,
	BATTLESHIP_L = 4,
	CRUISER_L    = 3,
	SUBMARINE_L  = 3,
	DESTROYER_L  = 2
};

class Board {
    private:
    Cell gameBoard[ROWS][COLS];
    short sunkShip[2][NUM_OF_SHIPS];

    public:
    Board();

    char getSymbol(int row, int col);

    void printGameBoard(bool showPegs);
    void putShipOnGameBoard(Watercraft ship, Coordinate position, int direction);
    void manuallyPlaceShipsOnGameBoard (Watercraft* ship[]);
    void randomlyPlaceShipsOnGameBoard (Watercraft* ship[]);
    void updateGameBoard (Coordinate target);
    bool isValidLocation (Coordinate position, int direction, int length);
    bool convertStringtoPosition (Coordinate position[], char *stringPosition, int length);
    Coordinate generatePosition (int direction, int length);
    short checkShot (Coordinate target);
};

int getRandomNumber(int, int);

#endif // BOARD_H_INCLUDED
