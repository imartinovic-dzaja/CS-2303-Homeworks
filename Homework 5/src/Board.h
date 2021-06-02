#include "LinkedList.h"
#include "Pawn.h"


#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED



class Board {
private:
    bool m_gameHasEnded;
    LLNode<Pawn> m_activeRedPawns;
    LLNode<Pawn> m_activeBlackPawns;
    int* board;

public:

    // these are fields
    bool m_redsTurn;

    //these are constructors/destructors
      Board();
    ~Board();

    //these are member functions
    //setters / getters
    bool getHasEnded();
    void setHasEnded(bool);
    void setActiveRedPawns(LLNode<Pawn> activeRedPawns);
    void setActiveBlackPawns(LLNode<Pawn> activeBlackPawns);
    LLNode<Pawn>* getActiveBlackPawns();
    LLNode<Pawn>* getActiveRedPawns();



    void printBoard();
    Pawn* findPieceAtIndex(int index);
    void updateBoard();
    LLNode<Move>* getMoves(LLNode<Pawn> activePawns);
    void startGame();
    void performMove(Move* moveToMake);
    void performJump(Move* jumoToMake);
    void makeIntoKing();
    LLNode<Move>* getAllMoves();
    LLNode<Move>* getAllJumps();


	static const int BOARDSIZE = 8;
};

#endif // BOARD_H_INCLUDED
