#include "Tests.h"

#include <stdbool.h>
#include <iostream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}




bool Tests::tests()
{
	bool answer = true;


	//LinkedList
	bool ok1 = testGetElementP();
	bool ok2 = testGetPrevP();
	bool ok3 = testGetNextP();
	bool ok4 = testIsEmpty();
	bool ok5 = testAddElementToLL();
	bool ok6 = testContainsElement();
	bool ok7 = testRemoveFromListWhenListIsEmpty();
	bool ok8 = testRomoveElementFromASingleNodeList();
	bool ok9 = testRemoveRootMiddleLeafAndNonExistentFromList();
	bool ok10 = testGetLeaf();
	bool ok11 = testGetLenght();
	bool ok12 = testAppendList();
	bool ok13 = testgetRandomElement();

	//Pawn
	bool ok14 = testSetIndexAndTestGetIndex();
	bool ok15 = testSetIsRedAndTestGetIsRed();
	bool ok16 = testCanMoveLeftDown();
	bool ok17 = testCanMoveLeftUp();
	bool ok18 = testCanMoveRightDown();
	bool ok19 = testCanMoveRightUp();
	bool ok20 = testCanJumpMoveLeftDown();
	bool ok21 = testCanJumpMoveLeftUp();
	bool ok22 = testCanJumpMoveRightDown();
	bool ok23 = testCanJumpMoveRightUp();
	bool ok24 = testMoveListPawn();
	bool ok25 = testJumpMoveListPawn();
	bool ok26 = testKingMoveList();
	bool ok27 = testKingJumpMoveList();

	//Board
	bool ok28 = testPrintBoard();
	bool ok29 = testFindPieceAtIndex();
	bool ok30 = testPerformMove();
	bool ok31 = testPerformJump();

	bool ok32 = testMakeIntoKing();

	answer &=  ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19 && ok20 && ok21 && ok22 && ok23 && ok24 && ok25 && ok26 && ok27 && ok29 ;
	return answer;
}

bool Tests::testGetElementP() {

	std::cout<<"Starting testGetElementP"<<std::endl;

	int y = 225883;
	LLNode<int> newList(&y);

	int* rP = newList.getElementP();


	bool ok = (&y == rP);

	if(ok) {std::cout<<"testGetElementP passed"<<std::endl;}
	else {std::cout<<"testGetElementP did not pass"<<std::endl;}
	return ok;

}
bool Tests::testGetPrevP() {
	std::cout<<"Starting testGetPrevP"<<std::endl;

	int x = 123;
	int y = 456;
	int z = 789;

	LLNode<int> root(&x);
	LLNode<int> leaf(&z);
	LLNode<int> middle(&leaf, &root, &y);

	LLNode<int>* rootP = middle.getPrevP();

	int* rP = rootP->getElementP();

	bool ok = rP == &x;

	if(ok) {std::cout<<"testGetPrevP passed"<<std::endl;}
	else {std::cout<<"testGetPrevP did not pass"<<std::endl;}
	return ok;

}
bool Tests::testGetNextP() {
	std::cout<<"Starting testGetNextP"<<std::endl;

	int x = 123;
	int y = 456;
	LLNode<int> leaf(&y);
	LLNode<int>  root(&leaf, &x);

	LLNode<int> * leafP = root.getNextP();

	int* rP = leafP->getElementP();

	bool ok = rP == &y;
	if(ok) {std::cout<<"testGetNextP passed"<<std::endl;}
	else {std::cout<<"testGetNextP did not pass"<<std::endl;}

	return ok;
}
bool Tests::testIsEmpty() {
	std::cout<<"Starting testIsEmpty"<<std::endl;

	int x = 123;

	LLNode<int> newList;

	bool ok = newList.isEmpty();

	LLNode<int> newList2(&x);

	ok &= !newList2.isEmpty();

	if(ok) {std::cout<<"testIsEmpty passed"<<std::endl;}
	else {std::cout<<"testIsEmpty did not pass"<<std::endl;}

	return ok;

}
bool Tests::testAddElementToLL() {
	std::cout<<"Starting testAddRoomToLL"<<std::endl;

	int x = 123;
	int y = 456;
	int z = 789;

	LLNode<int> newList;

	newList.addElementToLL(&x);
	newList.addElementToLL(&y);
	newList.addElementToLL(&z);


	LLNode<int>* middle = newList.getNextP();

	LLNode<int>* leaf = middle->getNextP();

	bool ok = (newList.getElementP() == &x);
	ok&= (middle->getElementP() == &y);
	ok&= (leaf->getElementP() == &z);

	if(ok) {std::cout<<"testAddRoomToLL passed"<<std::endl;}
	else {std::cout<<"testAddRoomToLL did not pass"<<std::endl;}

	return ok;
}
bool Tests::testContainsElement() {
	std::cout<<"Starting testContainsElement"<<std::endl;

	LLNode<int> newList;
	int x = 123;
	int y = 456;
	int z = 789;
	int w = 1011;
	int q = 1213;

	newList.addElementToLL(&x);
	newList.addElementToLL(&y);
	newList.addElementToLL(&z);
	newList.addElementToLL(&w);

	bool ok = true;
	ok &= newList.containsElement(&x);
	ok &= newList.containsElement(&y);
	ok &= newList.containsElement(&z);
	ok &= newList.containsElement(&w);
	ok &= !newList.containsElement(&q);


	if(ok) {std::cout<<"testContainsElement passed"<<std::endl;}
	else {std::cout<<"testContainsElement did not pass"<<std::endl;}

	return ok;

}
bool Tests::testRemoveFromListWhenListIsEmpty() {
	std::cout<<"Starting testRemoveFromListWhenListIsEmpty"<<std::endl;

	LLNode<int> newList;
	int x = 123;

	newList.removeFromList(&x);

	bool ok = newList.isEmpty();


	if(ok) {std::cout<<"testRemoveFromListWhenListIsEmpty passed"<<std::endl;}
	else {std::cout<<"testRemoveFromListWhenListIsEmpty did not pass"<<std::endl;}

	return ok;
}
bool Tests::testRomoveElementFromASingleNodeList() {
	std::cout<<"Starting testRomoveElementFromASingleNodeList"<<std::endl;

	LLNode<int> newList;
	int x = 123;
	newList.addElementToLL(&x);
	newList.removeFromList(&x);    //remove

	bool ok = newList.isEmpty();

	if(ok) {std::cout<<"testRomoveElementFromASingleNodeList passed"<<std::endl;}
	else {std::cout<<"testRomoveElementFromASingleNodeList did not pass"<<std::endl;}

	return ok;
}
bool Tests::testRemoveRootMiddleLeafAndNonExistentFromList() {
	std::cout<<"Starting testRemoveRootMiddleAndLeafandNonExistentFromList"<<std::endl;

	LLNode<int> newList;
	int x = 123;
	int y = 456;
	int z = 789;
	int w = 1011;
	int q = 1213;
	int p = 1415;

	newList.addElementToLL(&x);
	newList.addElementToLL(&y);
	newList.addElementToLL(&z);
	newList.addElementToLL(&w);
	newList.addElementToLL(&q);

	newList.removeFromList(&z);    //remove middle
	newList.removeFromList(&x);    //remove root
	newList.removeFromList(&q);    //remove leaf
	newList.removeFromList(&p);    //remove non-existent

	bool ok = true;
	ok &= !newList.containsElement(&x);
	ok &= newList.containsElement(&y);
	ok &= !newList.containsElement(&z);
	ok &= newList.containsElement(&w);
	ok &= !newList.containsElement(&q);
	ok &= !newList.containsElement(&p);


	if(ok) {std::cout<<"testRemoveRootMiddleAndLeafandNonExistentFromList passed"<<std::endl;}
	else {std::cout<<"testRemoveRootMiddleAndLeafandNonExistentFromList did not pass"<<std::endl;}

	return ok;
}
bool Tests::testGetLeaf() {
	std::cout<<"Starting testGetLeaf"<<std::endl;

	int x = 123;
	int y = 456;
	int z = 789;

	LLNode<int> newList;
	bool ok = (newList.getLeaf()->isEmpty());

	newList.addElementToLL(&x);
	ok &= (newList.getLeaf()->getElementP() == &x);

	newList.addElementToLL(&y);
	newList.addElementToLL(&z);
	ok &= (newList.getLeaf()->getElementP() == &z);

	if(ok) {std::cout<<"testGetLeaf passed"<<std::endl;}
	else {std::cout<<"testGetLeaf did not pass"<<std::endl;}

	return ok;

}
bool Tests::testGetLenght() {
	std::cout<<"Starting testGetLenght"<<std::endl;

	int x = 123;
	int y = 456;
	int z = 789;

	LLNode<int> newList;
	bool ok = newList.getLenght() == 0;

	newList.addElementToLL(&x);
	ok &= newList.getLenght() == 1;

	newList.addElementToLL(&y);
	newList.addElementToLL(&z);
	ok &= newList.getLenght() == 3;

	if(ok) {std::cout<<"testGetLenght passed"<<std::endl;}
	else {std::cout<<"testGetLenght did not pass"<<std::endl;}

	return ok;

}
bool Tests::testAppendList() {
	std::cout<<"Starting testAppendList"<<std::endl;

	int x = 123;
	int y = 456;
	int z = 789;
	int w = 1011;
	int q = 1213;
	int p = 1415;

	LLNode<int> newList1;
	newList1.addElementToLL(&x);
	newList1.addElementToLL(&y);
	newList1.addElementToLL(&z);

	LLNode<int> newList2;

	newList1.appendList(&newList2);
	bool ok = newList1.containsElement(&x);
	ok &= newList1.containsElement(&y);
	ok &= newList1.containsElement(&z);

	newList2.addElementToLL(&w);
	newList2.addElementToLL(&q);
	newList2.addElementToLL(&p);
	newList1.appendList(&newList2);

	ok &= newList1.containsElement(&x);
	ok &= newList1.containsElement(&y);
	ok &= newList1.containsElement(&z);
	ok &= newList1.containsElement(&w);
	ok &= newList1.containsElement(&q);
	ok &= newList1.containsElement(&p);


	if(ok) {std::cout<<"testAppendList passed"<<std::endl;}
	else {std::cout<<"testAppendList did not pass"<<std::endl;}

	return ok;


}
bool Tests::testgetRandomElement() {
	std::cout<<"Starting testgetRandomElement"<<std::endl;

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	int h = 8;
	int i = 9;
	int j = 10;

	LLNode<int> newList;
	newList.addElementToLL(&a);
	newList.addElementToLL(&b);
	newList.addElementToLL(&c);
	newList.addElementToLL(&d);
	newList.addElementToLL(&e);
	newList.addElementToLL(&f);
	newList.addElementToLL(&g);
	newList.addElementToLL(&h);
	newList.addElementToLL(&i);
	newList.addElementToLL(&j);

	std::cout<<"Original list contains numbers from 1 to 10"<<std::endl;
	std::cout<<"The test should print out 10 random numbers from this list"<<std::endl;

	for (int counter = 0; counter<9; ++counter) {
		std::cout<<*(newList.getRandomElement())<<" ,";
	}
	std::cout<<std::endl;
	std::cout<<"testgetRandomElement ended"<<std::endl;






}

bool Tests::testSetIndexAndTestGetIndex(){
	std::cout << "starting testSetIndexAndTestGetIndex" << std::endl;

	bool ok = true;

	Pawn* pP = new Pawn();
	pP->setIndex(1);
	if(pP->getIndex()!=1){ok = false;}

	pP->setIndex((Board::BOARDSIZE)*(Board::BOARDSIZE)-1);
	if(pP->getIndex()!=((Board::BOARDSIZE)*(Board::BOARDSIZE)-1)){ok = false;}

	pP->setIndex((Board::BOARDSIZE)*(Board::BOARDSIZE)+1); 	//bigger than max value in board so index should not change
	if(pP->getIndex()!=((Board::BOARDSIZE)*(Board::BOARDSIZE)-1)){ok = false;}

	if(ok) {std::cout<<"testSetIndexAndTestGetIndex passed"<<std::endl;}
	else {std::cout<<"testSetIndexAndTestGetIndex did not pass"<<std::endl;}
	return ok;
}
bool Tests::testSetIsRedAndTestGetIsRed(){
	std::cout << "starting testSetIsRedAndTestGetIsRed" << std::endl;

	bool ok = true;

	Pawn* pP = new Pawn();
	pP->setIsRed(false);
	if(pP->getIsRed() != false){ok = false;}

	pP->setIsRed(true);
	if(pP->getIsRed() != true){ok = false;}

	if(ok) {std::cout<<"testSetIsRedAndTestGetIsRed passed"<<std::endl;}
	else {std::cout<<"testSetIsRedAndTestGetIsRed did not pass"<<std::endl;}

	return ok;
}

bool Tests::testCanMoveLeftDown(){
	std::cout << "starting testCanMoveLeftDown" << std::endl;

	bool ok = true;

	int board[] = { 0,1,0,1,0,0,0,0,
			1,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0};

	Pawn* pP = new Pawn();
	pP -> setIndex(3);          //should be able to move
	if(!(pP -> canMoveLeftDown(board))){
		ok = false;
	}
	pP -> setIndex(8);        // cannot move off the board horizontally
	if(pP -> canMoveLeftDown(board)){
		ok = false;
	}

	pP -> setIndex(58);        // cannot move off the board vertically
	if(pP -> canMoveLeftDown(board)){
		ok = false;
	}

	pP -> setIndex(1);        // cannot move when blocked by another piece
	if(pP -> canMoveLeftDown(board)){
		ok = false;
	}

	if(ok) {std::cout << "testCanMoveLeftDown passed" << std::endl;}
	else {std::cout << "testCanMoveLeftDown did not pass" << std::endl;}

	return ok;
}
bool Tests::testCanMoveLeftUp(){
	std::cout << "starting testCanMoveLeftUp" << std::endl;

	bool ok = true;
	int board[] = { 0,1,0,0,0,0,0,0,
			1,0,1,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0};

	Pawn* pP = new Pawn();
	pP -> setIndex(58);          //should be able to move
	if(!(pP -> canMoveLeftUp(board))){
		ok = false;
	}
	pP -> setIndex(8);        // cannot move off the board horizontally
	if(pP -> canMoveLeftUp(board)){
		ok = false;
	}

	pP -> setIndex(1);        // cannot move off the board vertically
	if(pP -> canMoveLeftUp(board)){
		ok = false;
	}

	pP -> setIndex(10);        // cannot move when blocked by another piece
	if(pP -> canMoveLeftUp(board)){
		ok = false;
	}

	if(ok) {std::cout << "testCanMoveLeftUp passed" << std::endl;}
	else {std::cout << "testCanMoveLeftUp did not pass" << std::endl;}

	return ok;
}
bool Tests::testCanMoveRightDown(){
	std::cout << "starting testCanMoveRightDown" << std::endl;

	bool ok = true;

	int board[] = { 0,1,0,0,0,0,0,0,
			0,0,1,0,0,0,0,1,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0};

	Pawn* pP = new Pawn();
	pP -> setIndex(10);          //should be able to move
	if(!(pP -> canMoveRightDown(board))){
		ok = false;
	}
	pP -> setIndex(15);        // cannot move off the board horizontally
	if(pP -> canMoveRightDown(board)){
		ok = false;
	}

	pP -> setIndex(58);        // cannot move off the board vertically
	if(pP -> canMoveRightDown(board)){
		ok = false;
	}

	pP -> setIndex(1);        // cannot move when blocked by another piece
	if(pP -> canMoveRightDown(board)){
		ok = false;
	}

	if(ok) {std::cout << "testCanMoveRightDown passed" << std::endl;}
	else {std::cout << "testCanMoveRightDown did not pass" << std::endl;}

	return ok;
}
bool Tests::testCanMoveRightUp(){
	std::cout << "starting testCanMoveRightUp" << std::endl;

	bool ok = true;

	int board[] = { 0,1,0,1,0,0,0,0,
			1,0,0,0,0,0,0,1,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0};

	Pawn* pP = new Pawn();
	pP -> setIndex(58);          //should be able to move
	if(!(pP -> canMoveRightUp(board))){
		ok = false;
	}
	pP -> setIndex(15);        // cannot move off the board horizontally
	if(pP -> canMoveRightUp(board)){
		ok = false;
	}

	pP -> setIndex(1);        // cannot move off the board vertically
	if(pP -> canMoveRightUp(board)){
		ok = false;
	}

	pP -> setIndex(8);        // cannot move when blocked by another piece
	if(pP -> canMoveRightUp(board)){
		ok = false;
	}
	if(ok) {std::cout << "testCanMoveRightDown passed" << std::endl;}
	else {std::cout << "testCanMoveRightDown did not pass" << std::endl;}
}

bool Tests::testCanJumpMoveLeftDown(){
	std::cout << "starting testCanJumpMoveLeftDown" << std::endl;

	bool ok = true;

	int board[] = { 1,0,1,0,1,0,1,0,
			0,1,0,1,0,1,0,1,
			0,0,2,0,2,0,0,0,
			0,0,0,2,0,0,0,0,
			0,1,0,0,0,0,0,0,
			2,0,0,0,0,0,0,0,
			2,0,2,1,2,0,2,0,
			0,2,2,2,0,2,0,2};

	Pawn* pP = new Pawn();
	pP -> setIndex(11);             //should be able to jump
	if(!(pP -> canJumpMoveLeftDown(board))){
		ok = false;
	}

	pP -> setIndex(13);             //should not jump 2 pieces
	if(pP -> canJumpMoveLeftDown(board)){
		ok = false;
	}

	pP -> setIndex(2);              // should not jump own piece
	if(pP -> canJumpMoveLeftDown(board)){
		ok = false;
	}

	pP -> setIndex(33);             // should not jump off the board to the left
	if(pP -> canJumpMoveLeftDown(board)){
		ok = false;
	}

	pP ->setIndex(51);          //should not jump off the board down
	if(pP -> canJumpMoveLeftDown(board)){
		ok = false;
	}


	if(ok) {std::cout << "testCanJumpMoveLeftDown passed" << std::endl;}
	else {std::cout << "testCanJumpMoveLeftDown did not pass" << std::endl;}

	return ok;
}
bool Tests::testCanJumpMoveLeftUp(){
	std::cout << "starting testCanJumpMoveLeftUp" << std::endl;

	bool ok = true;

	int board[] = { 1,0,1,0,1,0,1,0,
			0,1,0,2,0,1,0,1,
			0,0,0,0,0,0,0,0,
			1,0,0,0,0,0,0,0,
			0,2,0,0,1,0,0,0,
			0,2,0,1,0,1,0,2,
			2,0,2,0,2,0,2,0,
			0,2,0,2,0,2,0,2};

	Pawn* pP = new Pawn();

	pP -> setIndex(52);             //should be able to jump
	if(!(pP -> canJumpMoveLeftUp(board))){
		ok = false;
	}

	pP -> setIndex(54);             //should not jump 2 pieces
	if(pP -> canJumpMoveLeftUp(board)){
		ok = false;
	}

	pP -> setIndex(50);              // should not jump own piece
	if(pP -> canJumpMoveLeftUp(board)){
		ok = false;
	}

	pP -> setIndex(41);             // should not jump off the board to the left
	if(pP -> canJumpMoveLeftUp(board)){
		ok = false;
	}

	pP ->setIndex(11);          //should not jump off the board up
	if(pP -> canJumpMoveLeftUp(board)){
		ok = false;
	}

	if(ok) {std::cout << "testCanJumpMoveLeftUp passed" << std::endl;}
	else {std::cout << "testCanJumpMoveLeftUp did not pass" << std::endl;}
	return ok;
}
bool Tests::testCanJumpMoveRightDown(){
	std::cout << "starting testCanJumpMoveRightDown" << std::endl;

	bool ok = true;

	int board[] = { 1,0,1,0,1,0,1,0,
			0,1,0,1,0,1,0,1,
			0,0,2,0,2,0,0,0,
			0,0,0,0,0,2,0,0,
			0,0,0,0,0,0,1,0,
			0,0,0,0,0,0,0,2,
			2,0,2,0,1,0,2,0,
			0,2,0,2,0,2,0,2};

	Pawn* pP = new Pawn();
	pP -> setIndex(9);             //should be able to jump
	if(!(pP -> canJumpMoveRightDown(board))){
		ok = false;
	}

	pP -> setIndex(11);             //should not jump 2 pieces
	if(pP -> canJumpMoveRightDown(board)){
		ok = false;
	}

	pP -> setIndex(4);              // should not jump own piece
	if(pP -> canJumpMoveRightDown(board)){
		ok = false;
	}

	pP -> setIndex(38);             // should not jump off the board to the right
	if(pP -> canJumpMoveRightDown(board)){
		ok = false;
	}

	pP ->setIndex(52);          //should not jump off the board down
	if(pP -> canJumpMoveRightDown(board)){
		ok = false;
	}

	if(ok) {std::cout << "testCanJumpMoveRightDown passed" << std::endl;}
	else {std::cout << "testCanJumpMoveRightDown did not pass" << std::endl;}

	return ok;
}
bool Tests::testCanJumpMoveRightUp(){
	std::cout << "starting testCanJumpMoveRightUp" << std::endl;

	bool ok = true;

	int board[] = { 1,0,1,0,1,0,1,0,
			0,1,0,1,0,2,0,1,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,1,0,0,0,
			0,1,0,1,0,0,0,1,
			2,0,2,0,2,0,2,0,
			0,2,0,2,0,2,0,2};

	Pawn* pP = new Pawn();
	pP -> setIndex(48);             //should be able to jump
	if(!(pP -> canJumpMoveRightUp(board))){
		std::cout<<"This is where it fails 1"<<std::endl;
		ok = false;
	}

	pP -> setIndex(50);             //should not jump 2 pieces
	if(pP -> canJumpMoveRightUp(board)){
		std::cout<<"This is where it fails 2"<<std::endl;
		ok = false;
	}

	pP -> setIndex(59);              // should not jump own piece
	if(pP -> canJumpMoveRightUp(board)){
		std::cout<<"This is where it fails 3"<<std::endl;
		ok = false;
	}

	pP -> setIndex(54);             // should not jump off the board to the right
	if(pP -> canJumpMoveRightUp(board)){
		std::cout<<"This is where it fails 4"<<std::endl;
		ok = false;
	}

	pP ->setIndex(13);          //should not jump off the board up
	if(pP -> canJumpMoveRightUp(board)){
		std::cout<<"This is where it fails 5"<<std::endl;
		ok = false;
	}


	if(ok) {std::cout << "testCanJumpMoveRightUp passed" << std::endl;}
	else {std::cout << "testCanJumpMoveRightUp did not pass" << std::endl;}

	return ok;
}

bool Tests::testMoveListPawn() {

	std::cout << "starting testCanJumpMoveRightUp" << std::endl;

	bool ok = true;

	int board[] = { 0,1,0,0,0,0,0,2,
			0,0,1,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			1,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,2,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,2,0,0,
			1,0,0,0,0,0,2,0};

	Pawn* pP = new Pawn();
	int length = 0;

	// Red Pawns
	pP -> setIsRed(true);
	//First pawn
	{
		pP -> setIndex(56);             //should not be able to move
		std::cout<<"Expected moves for pawn 1 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 1 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Second Pawn
	{
		pP -> setIndex(1);             //should be able to move left down only
		std::cout<<"Expected moves for pawn 2 are:"<<std::endl;
		std::cout<<"[ (1, 8) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 2 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Third Pawn
	{
		pP -> setIndex(24);             //should be able to move right down only
		std::cout<<"Expected moves for pawn 3 are:"<<std::endl;
		std::cout<<"[ (24, 33) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 3 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Fourth Pawn
	{
		pP -> setIndex(10);             //should be able to move left and right down
		std::cout<<"Expected moves for pawn 4 are:"<<std::endl;
		std::cout<<"[ (10, 17) (10, 19) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 4 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}

	// Black Pawns
	pP -> setIsRed(false);
	//Fifth pawn
	{
		pP -> setIndex(7);             //should not be able to move
		std::cout<<"Expected moves for pawn 5 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 5 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Sixth Pawn
	{
		pP -> setIndex(39);             //should be able to move left up only
		std::cout<<"Expected moves for pawn 6 are:"<<std::endl;
		std::cout<<"[ (39, 30) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 6 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Seventh Pawn
	{
		pP -> setIndex(62);             //should be able to move right up only
		std::cout<<"Expected moves for pawn 7 are:"<<std::endl;
		std::cout<<"[ (62, 55) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 7 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Eight Pawn
	{
		pP -> setIndex(53);             //should be able to move left and right up
		std::cout<<"Expected moves for pawn 8 are:"<<std::endl;
		std::cout<<"[ (53, 44) (53, 46) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for pawn 8 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}



	return ok;
}
bool Tests::testJumpMoveListPawn() {

	std::cout << "starting testJumpMoveListPawn" << std::endl;

	bool ok = true;

	int board[] = { 0,0,0,0,0,0,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,0,0,0,0,0,
			1,0,1,0,1,0,1,0,
			0,2,0,2,0,2,0,2,
			0,0,0,0,0,0,0,0,
			0,0,0,2,0,0,0,0,
			0,0,0,0,0,0,0,0};

	Pawn* pP = new Pawn();
	int length = 0;

	// Red Pawns
	pP -> setIsRed(true);
	//First pawn
	{
		pP -> setIndex(51);             //should not be able to jump
		std::cout<<"Expected jumps for pawn 1 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 1 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Second Pawn
	{
		pP -> setIndex(30);             //should be able to jump left down only
		std::cout<<"Expected jumps for pawn 2 are:"<<std::endl;
		std::cout<<"[ (30, 44) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 2 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Third Pawn
	{
		pP -> setIndex(24);             //should be able to jump right down only
		std::cout<<"Expected jumps for pawn 3 are:"<<std::endl;
		std::cout<<"[ (24, 42) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 3 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Fourth Pawn
	{
		pP -> setIndex(26);             //should be able to jump left and right down
		std::cout<<"Expected jumps for pawn 4 are:"<<std::endl;
		std::cout<<"[ (26, 40) (26, 44) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 4 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}

	// Black Pawns
	pP -> setIsRed(false);
	//Fifth pawn
	{
		pP -> setIndex(51);             //should not be able to jump
		std::cout<<"Expected jumps for pawn 5 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 5 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Sixth Pawn
	{
		pP -> setIndex(39);             //should be able to jump left up only
		std::cout<<"Expected jumps for pawn 6 are:"<<std::endl;
		std::cout<<"[ (39, 21) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 6 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Seventh Pawn
	{
		pP -> setIndex(33);             //should be able to jump right up only
		std::cout<<"Expected jumps for pawn 7 are:"<<std::endl;
		std::cout<<"[ (33, 19) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 7 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Eight Pawn
	{
		pP -> setIndex(35);             //should be able to jump left and right up
		std::cout<<"Expected jumps for pawn 8 are:"<<std::endl;
		std::cout<<"[ (35, 17) (35, 21) ]"<<std::endl;
		LLNode<Move>* moves1 = pP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual jumps for pawn 8 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}



	return ok;
}

bool Tests::testKingMoveList() {

	std::cout << "starting testKingMoveList" << std::endl;

	bool ok = true;

	int board[] = { 3,1,3,1,0,0,4,3,
			0,0,0,0,0,1,0,1,
			0,0,0,3,1,0,0,0,
			1,0,0,0,1,0,0,0,
			0,0,4,0,0,0,0,4,
			0,1,0,1,0,0,0,0,
			0,1,3,1,0,4,0,0,
			3,1,0,1,0,0,2,0};

	King* kP = new King();
	int length = 0;

	// Red Kings
	kP -> setIsRed(true);
	//First King
	{
		kP -> setIndex(56);             //should not be able to move
		std::cout<<"Expected moves for king 1 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 1 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Second King
	{
		kP -> setIndex(7);             //should be able to move left down only
		std::cout<<"Expected moves for king 2 are:"<<std::endl;
		std::cout<<"[ (7, 14) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 2 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Third King
	{
		kP -> setIndex(0);             //should be able to move right down only
		std::cout<<"Expected moves for king 3 are:"<<std::endl;
		std::cout<<"[ (0, 9) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 3 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Fourth King
	{
		kP -> setIndex(2);             //should be able to move left and right down
		std::cout<<"Expected moves for king 4 are:"<<std::endl;
		std::cout<<"[ (2, 9) (2, 11) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 4 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}

	// Black Kings
	kP -> setIsRed(false);
	//Fifth King
	{
		kP -> setIndex(50);             //should not be able to move
		std::cout<<"Expected moves for king 5 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 5 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Sixth King
	{
		kP -> setIndex(39);             //should be able to move left up or left down only
		std::cout<<"Expected moves for king 6 are:"<<std::endl;
		std::cout<<"[ (39, 30) (39, 46) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 6 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Seventh King
	{
		kP -> setIndex(53);             //should be able to move right up or left up or left down only
		std::cout<<"Expected moves for king 7 are:"<<std::endl;
		std::cout<<"[ (53, 60) (53, 44) (53, 46) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 7 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	//Eight King
	{
		kP -> setIndex(34);             //should be able to move left and right up
		std::cout<<"Expected moves for king 8 are:"<<std::endl;
		std::cout<<"[ (34, 25) (34, 27) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->moveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 8 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<"]"<<std::endl;
	}


	return ok;
}
bool Tests::testKingJumpMoveList() {
	std::cout << "starting testKingJumpMoveList" << std::endl;

	bool ok = true;

	int board[] = {4,0,0,0,0,0,0,0,
			0,3,0,0,0,0,0,0,
			4,0,3,0,3,0,0,0,
			0,4,0,4,0,0,0,0,
			0,3,0,3,0,0,0,0,
			4,0,4,0,0,0,0,0,
			0,3,0,3,0,0,0,0,
			0,0,0,0,0,0,0,0};

	King* kP = new King();
	int length = 0;

	// Red Kings
	kP -> setIsRed(true);
	//First King
	{
		kP -> setIndex(9);             //should not be able to move
		std::cout<<"Expected moves for king 1 are:"<<std::endl;
		std::cout<<"[  ]"<<std::endl;
		LLNode<Move>* moves1 = kP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 1 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}
	//Second King
	{
		kP -> setIndex(20);             //should be able to jump left down
		std::cout<<"Expected moves for king 2 are:"<<std::endl;
		std::cout<<"[ (20, 34) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 2 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}
	//Third King
	{
		kP -> setIndex(18);             //should be able to jump left down and right down
		std::cout<<"Expected moves for king 3 are:"<<std::endl;
		std::cout<<"[ (18, 32) (18, 36) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 3 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}
	//Fourth King
	{
		kP -> setIndex(40);             //should be able to jump right down and right up
		std::cout<<"Expected moves for king 4 are:"<<std::endl;
		std::cout<<"[ (40, 58) (40, 26) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 4 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}
	//Fifth King
	{
		kP -> setIndex(42);             //should be able to jump right down and right up
		std::cout<<"Expected moves for king 5 are:"<<std::endl;
		std::cout<<"[ (42, 54) (42, 58) (42, 24) (42, 28) ]"<<std::endl;
		LLNode<Move>* moves1 = kP->jumpMoveList(board);
		length = moves1->getLenght();
		std::cout<<"Actual moves for king 5 are:"<<std::endl;
		std::cout<<"[ ";
		LLNode<Move>* temp = moves1;
		for (int i = 0; i < length; ++i) {
			Move* m = temp->getElementP();
			m->printMove();
			temp = temp->getNextP();
		}
		std::cout<<" ]"<<std::endl;
	}

	return ok;
}

bool Tests::testPrintBoard(){
	std::cout<<"Starting testPrintBoard"<<std::endl;
	Board* bP = new Board();
	std::cout << "Board should look like:" << std::endl;
    std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"1| 0| 1| 0| 1| 0| 1| 0"<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;
	std::cout<<"0| 2| 0| 2| 0| 2| 0| 2"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;
	std::cout << "Actual board:" << std::endl;
	bP->printBoard();
}

bool Tests::testFindPieceAtIndex(){
	std::cout << "starting testFindPieceAtIndex" << std::endl;

	int ok = true;
	Board* bP = new Board();
	Pawn* pP = new Pawn();

	for(int i=1; i<(Board::BOARDSIZE); i+=2){
		pP = bP->findPieceAtIndex(i);
		ok &= (pP -> getIndex() == i);
		ok &= (pP -> getIsRed() == true);
		if (!ok) {std::cout<<"failed at index"<<i<<std::endl;}
	}

	for(int i=8; i<(Board::BOARDSIZE)*2; i+=2){
		pP = bP->findPieceAtIndex(i);
		ok &= (pP -> getIndex() == i);
		ok &= (pP -> getIsRed() == true);
		if (!ok) {std::cout<<"failed at index"<<i<<std::endl;}

	}

	for(int i=(Board::BOARDSIZE*Board::BOARDSIZE)-2; i>(Board::BOARDSIZE*Board::BOARDSIZE)-(Board::BOARDSIZE); i-=2){
		pP = bP->findPieceAtIndex(i);
		ok &= (pP -> getIndex() == i);
		ok &= (pP -> getIsRed() == false);
		if (!ok) {std::cout<<"failed at index"<<i<<std::endl;}

	}

	for(int i=(Board::BOARDSIZE*Board::BOARDSIZE)-Board::BOARDSIZE - 1 ; i>(Board::BOARDSIZE*Board::BOARDSIZE)-(Board::BOARDSIZE)*2; i-=2){
		pP = bP->findPieceAtIndex(i);
		ok &= (pP -> getIndex() == i);
		ok &= (pP -> getIsRed() == false);
		if (!ok) {std::cout<<"failed at index"<<i<<std::endl;}

	}
	if(ok){
		std::cout << "testFindPieceAtIndex passed" << std::endl;
	} else {
		std::cout << "testFindPieceAtIndex did not pass" << std::endl;
	}
	return ok;
}



bool Tests::testPerformMove() {
	std::cout << "starting testPerformMove" << std::endl;

	Board board;
	//Initial
	/*
                0,1,0,1,0,1,0,1,
                1,0,1,0,1,0,1,0,
                0,1,0,1,0,1,0,1,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                2,0,2,0,2,0,2,0,
                0,2,0,2,0,2,0,2,
                2,0,2,0,2,0,2,0,  */

	//Final
	/*          0,1,0,1,0,1,0,1,
                1,0,1,0,1,0,1,0,
                0,1,0,1,0,1,0,1,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                2,0,2,0,2,0,2,0,
                0,2,0,2,0,2,0,2,
                2,0,2,0,2,0,2,0,  */

	Move myMove(board.findPieceAtIndex(40), 33);
	board.performMove(&myMove);
	board.updateBoard();
	std::cout<<"Expected board is: "<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"1| 0| 1| 0| 1| 0| 1| 0"<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"0| 2| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"0| 0| 2| 0| 2| 0| 0| 2"<<std::endl;
	std::cout<<"0| 2| 0| 2| 0| 2| 0| 2"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;

	std::cout<<"Actual Board Is:"<<std::endl;
	board.printBoard();
}


bool Tests::testPerformJump() {
	std::cout << "starting testPerformJump" << std::endl;

	Board board;
	//Initial
	/*
                0,1,0,1,0,1,0,1,
                1,0,1,0,0,0,1,0,
                0,1,0,1,0,1,0,1,
                0,0,0,0,0,0,0,0,
                0,0,0,1,0,0,0,0,
                2,0,2,0,2,0,2,0,
                0,2,0,2,0,2,0,2,
                2,0,2,0,2,0,2,0,  */

	//Final
	/*
                0,1,0,1,0,1,0,1,
                1,0,1,0,0,0,1,0,
                0,1,0,1,0,1,0,1,
                0,0,0,0,2,0,0,0,
                0,0,0,0,0,0,0,0,
                2,0,0,0,2,0,2,0,
                0,2,0,2,0,2,0,2,
                2,0,2,0,2,0,2,0,  */

	Pawn* pieceP = new Pawn(35, true);
	board.getActiveRedPawns()->addElementToLL(pieceP);
	board.updateBoard();

    Pawn* jumperP = board.findPieceAtIndex(42);
	Move myJump(jumperP, 28);

	board.performJump(&myJump);
	board.updateBoard();
	std::cout<<"Expected board is: "<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"1| 0| 1| 0| 1| 0| 1| 0"<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"0| 0| 0| 0| 2| 0| 0| 0"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"2| 0| 0| 0| 2| 0| 2| 0"<<std::endl;
	std::cout<<"0| 2| 0| 2| 0| 2| 0| 2"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;

	std::cout<<"Actual Board Is:"<<std::endl;
	board.printBoard();
}

bool Tests::testMakeIntoKing(){
	std::cout << "starting testMakeIntoKing" << std::endl;

	Board board;
	Pawn* pieceP = new Pawn(0, false);
	board.getActiveBlackPawns()->addElementToLL(pieceP);

    board.updateBoard();
	board.makeIntoKing();
	board.updateBoard();

	std::cout<<"Expected board is: "<<std::endl;
	std::cout<<"4| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"1| 0| 1| 0| 0| 0| 1| 0"<<std::endl;
	std::cout<<"0| 1| 0| 1| 0| 1| 0| 1"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"0| 0| 0| 0| 0| 0| 0| 0"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;
	std::cout<<"0| 2| 0| 2| 0| 2| 0| 2"<<std::endl;
	std::cout<<"2| 0| 2| 0| 2| 0| 2| 0"<<std::endl;

	std::cout<<"Actual Board Is:"<<std::endl;
	board.printBoard();

	Board* bP;
}
