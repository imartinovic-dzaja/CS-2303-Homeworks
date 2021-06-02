#include "Board.h"

Board::Board() {
	m_gameHasEnded = false;
	m_redsTurn = true;
	board = new int[64]{    0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		2,0,2,0,2,0,2,0,
		0,2,0,2,0,2,0,2,
		2,0,2,0,2,0,2,0};

	m_activeRedPawns.addElementToLL(new Pawn(1, true));
	m_activeRedPawns.addElementToLL(new Pawn(3, true));
	m_activeRedPawns.addElementToLL(new Pawn(5, true));
	m_activeRedPawns.addElementToLL(new Pawn(7, true));
	m_activeRedPawns.addElementToLL(new Pawn(8, true));
	m_activeRedPawns.addElementToLL(new Pawn(10, true));
	m_activeRedPawns.addElementToLL(new Pawn(12, true));
	m_activeRedPawns.addElementToLL(new Pawn(14, true));
	m_activeRedPawns.addElementToLL(new Pawn(17, true));
	m_activeRedPawns.addElementToLL(new Pawn(19, true));
	m_activeRedPawns.addElementToLL(new Pawn(21, true));
	m_activeRedPawns.addElementToLL(new Pawn(23, true));



	m_activeBlackPawns.addElementToLL(new Pawn(62, false));
	m_activeBlackPawns.addElementToLL(new Pawn(60, false));
	m_activeBlackPawns.addElementToLL(new Pawn(58, false));
	m_activeBlackPawns.addElementToLL(new Pawn(56, false));
	m_activeBlackPawns.addElementToLL(new Pawn(55, false));
	m_activeBlackPawns.addElementToLL(new Pawn(53, false));
	m_activeBlackPawns.addElementToLL(new Pawn(51, false));
	m_activeBlackPawns.addElementToLL(new Pawn(49, false));
	m_activeBlackPawns.addElementToLL(new Pawn(46, false));
	m_activeBlackPawns.addElementToLL(new Pawn(44, false));
	m_activeBlackPawns.addElementToLL(new Pawn(42, false));
	m_activeBlackPawns.addElementToLL(new Pawn(40, false));

}

Board::~Board()
{
	delete board;

}


bool Board::getHasEnded() { return m_gameHasEnded;}
void Board::setHasEnded(bool state) {m_gameHasEnded = state;}
void Board::setActiveRedPawns(LLNode<Pawn> activeRedPawns) {m_activeRedPawns = activeRedPawns;}
void Board::setActiveBlackPawns(LLNode<Pawn> activeBlackPawns) {m_activeBlackPawns = activeBlackPawns;}
LLNode<Pawn>* Board::getActiveBlackPawns() {return &m_activeBlackPawns;}
LLNode<Pawn>* Board::getActiveRedPawns() {return &m_activeRedPawns;}



void Board::printBoard(){
	for(int row = 0; row < BOARDSIZE; row++){
		for(int col = 0; col < BOARDSIZE; col++){
			std::cout<<board[row*BOARDSIZE + col];
			if(col < BOARDSIZE-1){
				std::cout<<"| ";
			}
		}
		std::cout << std::endl;
	}
}

// Assume a piece is guaranteed to be at the given index
Pawn* Board::findPieceAtIndex(int index) {
	LLNode<Pawn>* temp = &m_activeRedPawns;

	if(temp->isEmpty()) {} // nothing to do

	else {
		while (temp){

			Pawn* currentPawn = temp->getElementP();
			if (currentPawn->getIndex() == index)
			{
				return currentPawn;
			}

			temp = temp->getNextP();
		}
	}

	temp = &m_activeBlackPawns;

	if(temp->isEmpty()) {} // nothing to do

	else {
		while (temp){

			Pawn* currentPawn = temp->getElementP();
			if (currentPawn->getIndex() == index)
			{
				return currentPawn;
			}

			temp = temp->getNextP();
		}
	}
}

void Board::updateBoard() {
	for (int i = 0; i<BOARDSIZE*BOARDSIZE;   ++i)
	{
		board[i] =0;
	}

	LLNode<Pawn>* temp = &m_activeRedPawns;

	while(temp && !m_activeRedPawns.isEmpty()){
		Pawn* pP = temp->getElementP();
		King* kP = dynamic_cast<King*> (pP);
		if(kP != (King*) 0){
			board[pP->getIndex()] = 3;
			temp = temp->getNextP();
		}
		else {
			board[pP->getIndex()] = 1;
			temp = temp->getNextP();
		}
	}

	temp = &m_activeBlackPawns;
	while(temp && !m_activeBlackPawns.isEmpty()){
		Pawn* pP = temp->getElementP();

		King* kP = dynamic_cast<King*> (temp->getElementP());
		if(kP != NULL){
			board[pP->getIndex()] = 4;
			temp = temp->getNextP();
		} else {

			board[pP->getIndex()] = 2;
			temp = temp->getNextP();
		}
	}
}
LLNode<Move>* Board::getMoves(LLNode<Pawn> activePawns) {
	LLNode<Move>* dummy = (LLNode<Move>*) 0;
}

void Board::performJump(Move* m){
	Pawn* pieceWhichMoves = m->m_pawnP;
	int indexToWhichItMoves = m->m_next;


	if(pieceWhichMoves->getIsRed()){
		int indexOfPawnWhichWeAreRemoving = (pieceWhichMoves->getIndex()+indexToWhichItMoves)/2;
		Pawn* pawnWhichWeAreRemoving = findPieceAtIndex(indexOfPawnWhichWeAreRemoving);

		m_activeBlackPawns.removeFromList(pawnWhichWeAreRemoving);

	}
	else {
		int indexOfPawnWhichWeAreRemoving = (pieceWhichMoves->getIndex()+indexToWhichItMoves)/2;

		Pawn* pawnWhichWeAreRemoving = findPieceAtIndex(indexOfPawnWhichWeAreRemoving);

		m_activeRedPawns.removeFromList(pawnWhichWeAreRemoving);

	}
	performMove(m);
}
void Board::performMove(Move* m){
	m->m_pawnP->setIndex(m->m_next);
}

void Board::makeIntoKing(){
	//check if the pawn is the right color and correct position to be crowned king (also if it is not already a king)
	for(int i = 0; i<BOARDSIZE; i++){
		if (board[i]) {
            Pawn* pP = findPieceAtIndex(i);
            if (board[i] > 2) {} // if it is already a king nothing to do
            else if (!pP->getIsRed())  //if it is red and in correct position
            {
                m_activeBlackPawns.addElementToLL(new King (i, false));
                m_activeBlackPawns.removeFromList(pP);
            }
		}
	}
	for(int i = BOARDSIZE*BOARDSIZE -1; i>=(BOARDSIZE*BOARDSIZE)-BOARDSIZE; --i){
        if (board[i]) {

		Pawn* pP = findPieceAtIndex(i);
		if (board[i] > 2) {} // if it is already a king nothing to do
		else if (pP->getIsRed())  //if it is red and in correct position
		{
			m_activeRedPawns.addElementToLL(new King (i, true));
			m_activeRedPawns.removeFromList(pP);
		}
        }
	}
}

LLNode<Move>* Board::getAllMoves() {
	LLNode<Move>* returnList = new LLNode<Move>;
	LLNode<Pawn>* temp;

	if(m_redsTurn) {
		temp = &m_activeRedPawns;
	} else {
		temp = &m_activeBlackPawns;
	}
	while(temp) {
		Pawn* pP = temp->getElementP();
		King* kP = dynamic_cast<King*> (pP);
		if(kP != (King*) 0){
			LLNode<Move>* currentMoves = kP->moveList(board);
			returnList->appendList(currentMoves);
			temp = temp ->getNextP();
		}
		else {
			LLNode<Move>* currentMoves = pP->moveList(board);
			returnList->appendList(currentMoves);
			temp = temp ->getNextP();
		}
	}

	return returnList;
}

LLNode<Move>* Board::getAllJumps() {
	LLNode<Move>* returnList = new LLNode<Move>;
	LLNode<Pawn>* temp;

	if(m_redsTurn) {
		temp = &m_activeRedPawns;
	} else {
		temp = &m_activeBlackPawns;
	}
	while(temp) {
		Pawn* pP = temp->getElementP();
		LLNode<Move>* currentMoves = pP->jumpMoveList(board);
		returnList->appendList(currentMoves);
		temp = temp ->getNextP();
	}

	return returnList;
}

void Board::startGame() {
	int numOfMoves = 0;
	setHasEnded(false);
	m_redsTurn = false;
	std::cout<<"___________________________________________________\n"<<std::endl;
	LLNode<Pawn>* relevantPawns;

	while(!m_gameHasEnded && numOfMoves <= 1000) {
		std::cout<<"Currently on step: "<<numOfMoves<<std::endl;

		updateBoard();

		printBoard();

		if(m_redsTurn) {
			relevantPawns = &m_activeRedPawns;}
		else {
			relevantPawns = &m_activeBlackPawns;
		}

		if (relevantPawns->isEmpty()) {
			std::cout<<"All pawns are gone"<<std::endl;
			setHasEnded(true);
		}
		else {
			LLNode<Move>* jumpMoves = getAllJumps();
			if (!jumpMoves->isEmpty()) {
				while (!jumpMoves->isEmpty()) { // keep performing jumps
                    std::cout<<"Number of possible valid jumps "<<jumpMoves->getLenght()<<std::endl;

					Move* randomJump = jumpMoves->getRandomElement();
					int indexOfRandom = randomJump->m_pawnP->getIndex();
					std::cout<<"The jump chosen was from row "<<(indexOfRandom / BOARDSIZE) + 1<<" and column "<<(indexOfRandom % BOARDSIZE) + 1<<" to row "<<(randomJump->m_next / BOARDSIZE) + 1<<" and column "<<(randomJump->m_next % BOARDSIZE) + 1<<std::endl ;

					performJump(randomJump);
					updateBoard();
					makeIntoKing();
					updateBoard();
					std::cout<<"___________________________________________________\n"<<std::endl;
                    std::cout<<"Currently on step: "<<numOfMoves<<std::endl;

					printBoard();
					jumpMoves = getAllJumps();
					++numOfMoves;
				}
			}
			else {
				LLNode<Move>* regularMoves = getAllMoves();
				if(regularMoves->isEmpty())
				{
					std::cout<<"No moves left"<<std::endl;

					setHasEnded(true);
				}
				else {
                    std::cout<<"Number of possible valid moves "<<regularMoves->getLenght()<<std::endl;

					Move* randomMove = regularMoves->getRandomElement();
					int indexOfRandom = randomMove->m_pawnP->getIndex();
					std::cout<<"The jump chosen was from row "<<(indexOfRandom / BOARDSIZE) + 1<<" and column "<<(indexOfRandom % BOARDSIZE) + 1<<" to row "<<(randomMove->m_next / BOARDSIZE) + 1<<" and column "<<(randomMove->m_next % BOARDSIZE) + 1<<std::endl ;


					performMove(randomMove);
					updateBoard();
					makeIntoKing();
				}
			}
		}


		m_redsTurn = !m_redsTurn;
		++numOfMoves;
	}
	std::cout<<"___________________________________________________\n"<<std::endl;
	printBoard();
	std::cout<<"Game has ended!"<<std::endl;
}

