#include "Watercraft.h"
#include "cell.h"
#include "board.h"


#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game{
private:
Player* players[2];
Board playerOneGameBoard;       /* Player one game board */
Board playerTwoGameBoard;       /* Player two game board */
Coordinate target;             /* x, y value of a target */
Coordinate targetTemp;         /* x, y value that holds a temporary value*/
Coordinate targetOrigin;       /* x, y value of the original target */
Coordinate targetAI;           /* x, y value of the targets using AI technique */
Watercraft* ship[NUM_OF_SHIPS];


	bool    huntMode;                           /* mode of randomly selecting a target */
	bool    targetMode;                         /* mode when there is a hit */
	bool    flipper;                            /* flips values of boolean */
	bool    cardinals[4];                       /* represents the 4 cardinals, N, S, W, E */
	bool    hasAShipSunked;                     /* if a ship has sank */

short sunkShip[2][NUM_OF_SHIPS];

    short player;  	           /* 0 -> player1, 1 -> player2 */
	short shot;                 /* holds temp value if ship has been shot */
	int   option;               /* option for player to place ship manually or randomly */
	int   north;                /* holds change of value when going north */
	int	  south;                /* holds change of value when going south */
	int	  east;                 /* holds change of value when going east */
	int	  west;                 /* holds change of value when going west */
	int   i;
	int	  counter;              /* i and counter are used as counters */

	char  shipSymbol;        /* temporary value to save character symbol of the ship */

	FILE *outStream;        /* stream to output file battleship.log */

public:
Game();
Game(bool special);
void welcomeScreen();
bool checkSunkShip ();
void systemMessage (char *message);
bool isWinner ();
Coordinate getTarget ();
void checkBoundsOfCardinal (bool cardinals[], int bound, int direction);
Player* getPlayerOne(){return players[0];}


void startGame();

};


#endif // GAME_H_INCLUDED
