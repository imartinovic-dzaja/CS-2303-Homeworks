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
	bool ok1 = testWatercrafts();
	bool ok2 = testStats();
	bool ok3 = testCell();
	bool ok4 =testCoordinate();
	bool ok5 =testIsWinner();
	bool ok6 =testCheckSunkShip();

	bool ok7 =testPutShipAndCheckShot();
	bool ok8 =updateGameBoard();
	bool ok9 =testIsValidLocation();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;

	return answer;



}

bool Tests::testWatercrafts(){
	bool ok = true;

	std::cout << "starting testWatercrafts" << std::endl;

	Carrier* caP = new Carrier();
	std::cout<<"Expected output:"<<std::endl;
	std::cout<<"Length=5, Symbol=c, Name=Carrier"<<std::endl;
	std::cout<<"Actual output:"<<std::endl;
	std::cout<<"Length="<<caP->getLength()<<" Symbol="<<caP->getSymbol()<<", Name="<<caP->getName()<<std::endl;

	Battleship* bP = new Battleship();
	std::cout<<"Expected output:"<<std::endl;
	std::cout<<"Length=4, Symbol=b, Name=Battleship"<<std::endl;
	std::cout<<"Actual output:"<<std::endl;
	std::cout<<"Length="<<bP->getLength()<<" Symbol="<<bP->getSymbol()<<", Name="<<bP->getName()<<std::endl;

	Cruiser* crP = new Cruiser();
	std::cout<<"Expected output:"<<std::endl;
	std::cout<<"Length=3, Symbol=c, Name=Cruiser"<<std::endl;
	std::cout<<"Actual output:"<<std::endl;
	std::cout<<"Length="<<crP->getLength()<<" Symbol="<<crP->getSymbol()<<", Name="<<crP->getName()<<std::endl;

	Submarine* sP = new Submarine();
	std::cout<<"Expected output:"<<std::endl;
	std::cout<<"Length=3, Symbol=s, Name=Submarine"<<std::endl;
	std::cout<<"Actual output:"<<std::endl;
	std::cout<<"Length="<<sP->getLength()<<" Symbol="<<sP->getSymbol()<<", Name="<<sP->getName()<<std::endl;

	Destroyer* dP = new Destroyer();
	std::cout<<"Expected output:"<<std::endl;
	std::cout<<"Length=2, Symbol=d, Name=Destroyer"<<std::endl;
	std::cout<<"Actual output:"<<std::endl;
	std::cout<<"Length="<<dP->getLength()<<" Symbol="<<dP->getSymbol()<<", Name="<<dP->getName()<<std::endl;


	if(ok){
		std::cout << "testWatercrafts passed" << std::endl;
	} else {
		std::cout << "testWatecrafts did not pass" << std::endl;
	}

	return ok;
}

bool Tests::testStats(){
	bool ok = true;

	std::cout << "starting testStats" << std::endl;

	Stats* sP = new Stats();
	if(sP->getNumHits() != 0 || sP->getnumMisses() != 0 || sP->getTotalShots() != 0 || sP->getHitMissRatio() != -1){	//checks if constructor works properly

		ok = false;
	}

	sP->incrementNumHits();
	sP->incrementTotalShots();
	sP->updateHitMissRatio();

	if(sP->getNumHits() != 1 || sP->getnumMisses() != 0 || sP->getTotalShots() != 1 || sP->getHitMissRatio() != -1){

		ok = false;
	}

	sP->incrementNumMisses();
	sP->incrementTotalShots();
	sP->updateHitMissRatio();

	if(sP->getNumHits() != 1 || sP->getnumMisses() != 1 || sP->getTotalShots() != 2 || sP->getHitMissRatio() != 100){
	         	std::cout << sP->getHitMissRatio()  << std::endl;

		ok = false;
	}

	if(ok){
		std::cout << "testStats passed" << std::endl;
	} else {
		std::cout << "testStats did not pass" << std::endl;
	}

	return ok;
}


bool Tests::testCoordinate() {
	bool ok = true;

	std::cout << "starting testCoorinante" << std::endl;

	Coordinate* cP = new Coordinate(0, 0);

	if(cP->getRow() != 0 || cP->getColumn() != 0) {ok=false;}

	cP->setRow(1);
	cP->setColumn(2);

	if(cP->getRow() != 1 || cP->getColumn() != 2){ok=false;}

	cP->setRowAndColumn(3,4);

	if(cP->getRow() != 3 || cP->getColumn() != 4){ok=false;}

	if(ok){
		std::cout << "testCoorinante passed" << std::endl;
	} else {
		std::cout << "testCoorinante did not pass" << std::endl;
	}

	return ok;
}

bool Tests::testCell(){
	bool ok = true;

	std::cout << "starting testCell" << std::endl;

	Cell* cP = new Cell('s', 0, 1);

	if(cP->getPosition()->getRow() != 0 || cP->getPosition()->getColumn() != 1 || cP->getSymbol() != 's'){ok=false;}

	cP->setSymbol('a');

	if(cP->getSymbol() != 'a'){ok=false;}

	if(ok){
		std::cout << "testCell passed" << std::endl;
	} else {
		std::cout << "testCell did not pass" << std::endl;
	}

	return ok;
}


bool Tests::testIsWinner(){

	std::cout << "starting testIsWinner" << std::endl;

	bool ok = true;


	Game* gP = new Game();


	if(gP->isWinner()){ok = false;}


	for(int i = 0; i<17; i++){
		gP->getPlayerOne()->getStatistics()->incrementNumHits();
	}
	if(!gP->isWinner()){ok = false;}

	if(ok){
		std::cout << "testIsWinner passed" << std::endl;
	} else {
		std::cout << "testIsWinner did not pass" << std::endl;
	}

	return ok;
}
bool Tests::testCheckSunkShip(){

	std::cout << "starting testCheckSunkShip" << std::endl;

	bool ok =true;

	Game* gP = new Game();
	if(gP->checkSunkShip() == true) {ok = false;}


	if(ok){
		std::cout << "testCheckSunkShip passed" << std::endl;
	} else {
		std::cout << "testCheckSunkShip did not pass" << std::endl;
	}

	return ok;
}

bool Tests::testPutShipAndCheckShot(){

	std::cout << "starting testPutShipAndCheckShot" << std::endl;

	bool ok = true;
	Board* bP = new Board();
	Carrier ca;
	Coordinate c; c.setRow(0); c.setColumn(0);
	bP->putShipOnGameBoard(ca, c, SOUTH);

	Coordinate t; t.setColumn(0);
	for(int i =0; i<2; i++){
		c.setRow(i);
		if(!(bP->checkShot(c))){ok = false;}
	}

	if(ok){
		std::cout << "testPutShipAndCheckShot passed" << std::endl;
	} else {
		std::cout << "testPutShipAndCheckShot did not pass" << std::endl;
	}

	return ok;
}
bool Tests::updateGameBoard(){
	std::cout << "starting updateGameBoard" << std::endl;

	bool ok = true;

	Board* bP = new Board();
	Coordinate c; c.setRow(0); c.setColumn(0);
	std::cout << "Expected board:" <<std::endl;
	int i = 0, j = 0;
	printf ("  0 1 2 3 4 5 6 7 8 9\n 0 m ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
	for (i = 1; i < ROWS; i++) {
		std::cout<<" "<< i;
        for (j = 0; j < COLS; j++) {
			std::cout<<" ~";
		}
    std::cout<<std::endl;
	}


std::cout<< "Actual board: " <<std::endl;
bP->updateGameBoard(c);
bP->printGameBoard(true);

std::cout << "updateGameBoard passed" << std::endl;


return ok;
}


bool Tests::testIsValidLocation(){
	std::cout << "starting testIsValidLocation" << std::endl;

	bool ok = true;

	Board* bP = new Board();

    Coordinate c;
	c.setRow(3); c.setColumn(3);
	if(!bP->isValidLocation(c, 4, 2)){
		ok = false;
	}

	Carrier ca;
	c.setRow(0); c.setColumn(0);
	bP->putShipOnGameBoard(ca, c, SOUTH);
	if(bP->isValidLocation(c,  HORIZONTAL, 5)){

		ok = false;
	}

	if(ok){
		std::cout << "testIsValidLocation passed" << std::endl;
	} else {
		std::cout << "testIsValidLocation did not pass" << std::endl;
	}

	return ok;
}
