/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"




Production::Production() {
    m_treasureAccum = 0.0f;
    m_numOfSearchedRooms = 0;
    m_maxRooms = 0;
    m_maxTreasure = 0.0f;
    m_numOfRooms = 0;
    m_matrix = (AdjMat) 0;
    m_rooms = (Room*) 0;
    m_searchedListP = new LLNode;
    m_toBeSearchedListP = new LLNode;

}

Production::~Production() {
    m_matrix.~AdjMat();
    delete m_rooms;
    delete m_searchedListP;
    delete m_toBeSearchedListP;
}

bool Production::prod(int argc, char* argv[])
{

    if(this->readArguments(argc, argv)) {

    this->readFile("houseGraph.txt");
    m_matrix.printMatrix();

    std::ofstream outputFile;
    outputFile.open ("output.txt");

    //In every house we will start from Room1:
    m_toBeSearchedListP->addRoomToLL(m_rooms);

    while (m_treasureAccum < m_maxTreasure && m_numOfSearchedRooms < m_maxRooms)
    {
        std::cout<<std::endl;
        m_numOfSearchedRooms++;
        Room* rP = m_toBeSearchedListP->getLeaf()->getRoomP();

        this->addAjdecentOnToBeSearched(rP);
        this->addTreasure(rP);

        std::cout<<"Currently searching room# "<< rP->getRoomNumber()<<std::endl;
        std::cout<<"Current accumulated treasure is (including current) "<< m_treasureAccum<<std::endl;
        std::cout<<"Current number of rooms searched (including current) "<< m_numOfSearchedRooms<<std::endl;
        std::cout<<"Those include:"<<std::endl;
        m_searchedListP->printList();


        outputFile<<rP->getRoomNumber()<<"  "<<m_treasureAccum<<"\n";




    }
        outputFile.close();



     std::cout<<"Total accumulated treasure is "<< m_treasureAccum<<std::endl;
     std::cout<<"Total number of rooms searched (inlcuding current) "<< m_numOfSearchedRooms<<std::endl;
     std::cout<<"Those rooms include:"<<std::endl;
     m_searchedListP->printList();

	return true;

}
  else {
        std::cout<<"Something was wrong with the argument(s)"<<std::endl;
        return false;
    }

}

AdjMat* Production::getMatrix() {return &m_matrix;}

LLNode* Production::getSearchedList() {return m_searchedListP;}

LLNode* Production::getToBeSearchedList() {return m_toBeSearchedListP;}

void Production::setToBeSearchedList(LLNode* newListP) {m_toBeSearchedListP = newListP;}

int Production::getNumOfRooms() {return m_numOfRooms;}

int Production::getNumOfSearchedRooms() {return m_numOfSearchedRooms;}

float Production::getTreasureAccum() {return m_treasureAccum;}

Room* Production::getRooms() {return m_rooms;}

void Production::readFile(char* filename) {
     FILE* fileP = fopen(filename, "r");
    if (fileP == NULL)
    {
        std::cout<<"Error reading file."<<std::endl;
        return;
    }
    else {
    float* temp = new float;
    fscanf(fileP, "%f", temp);
    // set the number of rooms
    m_numOfRooms = (int) *temp;
    // initialize Adjeceny matrix
    m_matrix = AdjMat(m_numOfRooms);
    for (int row = 1; row<m_numOfRooms; ++row)
    {
        for (int column = 0; column<row; ++column)
        {
            fscanf(fileP, "%f", temp);
            if (*temp) {
                m_matrix.setEdge(row, column);
            }
        }
    }
    // symmetrize the matrix
    m_matrix.createMainDiagonalSymmetry();
    // create an array for all the rooms
     m_rooms = new Room[m_numOfRooms];
    for (int i = 0; i < m_numOfRooms; ++i)
    {
        fscanf(fileP, "%f", temp);
        (m_rooms + i)->setRoomNumber(i+1);
        (m_rooms + i)->setTreasure(*temp);
        (m_rooms + i)->setSearched(false);
    }
    return;
    }
}

void Production::addTreasure(Room* roomToSearchP) {

    this->m_treasureAccum += roomToSearchP->getTreasure();
    roomToSearchP->setTreasure(0.0f);
    roomToSearchP->setSearched(true);
    this->getSearchedList()->addRoomToLL(roomToSearchP);
    LLNode* temp = this->getToBeSearchedList()->removeFromList(roomToSearchP);
    this->setToBeSearchedList(temp);

}

void Production::addAjdecentOnToBeSearched(Room* currentRoom) {
    int numOfRooms = this->getNumOfRooms();
    int column = (currentRoom->getRoomNumber()) - 1;
    Room* listOfRooms = this->getRooms();
    AdjMat* matrixP = this->getMatrix();
    LLNode* toBeSearchedList = this->getToBeSearchedList();

    // go through each row of the matrix with column number same as current column except
    // the current room

    for (int row = 0; row< numOfRooms; ++row) {
            // if we can get to the room from current room and that room has not been searched
            // we add it to the to be searched list
        Room* roomP = (listOfRooms + row);
        bool ok = true;

        ok &= (row != column);                      // we do not want to add the current room
        ok &= matrixP->getEdge(row, column);        //we want to add rooms that we can gt to according to adjecency matrix
        ok &= !(toBeSearchedList->containsRoom((listOfRooms)+row));    // we do not want to add rooms which are already in the to be searched list
        ok &= !(roomP->getSearched());                   // we do not want to add the rooms which are already searcherd

        if (ok) {
                toBeSearchedList->addRoomToLL(listOfRooms+row);
                }
  }
}

bool Production::readArguments(int argc, char* argv[]) {
    // beginning of argument reading logic
	bool answer = true;

	if(argc <=2) //no interesting information
	{
		std::cout<<"Didn't find enough command line arguments."<<std::endl;
        std::cout<<"Please enter the amount of treasure you wish to find."<<std::endl;
        std::cin>>m_maxTreasure;

        std::cout<<"Please enter the maximum amount of rooms you wish to search."<<std::endl;
        std::cin>>m_maxRooms;

		answer &= (m_maxTreasure>0 && m_maxRooms >0);
	}
	else //there is interesting information
	{
		std::cout<<"Found "<<argc<<" arguments."<<std::endl;
		char filename[256];
		char* eptr= new char[100];
		long aL=-1L;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//this is maximum number of rooms

				aL= strtol(argv[i], &eptr, 10);
				m_maxRooms = (int) aL;
				if(m_maxRooms <0)
				{
					answer = false;
				}
				std::cout<<"Number of rooms is "<<m_maxRooms<<std::endl;
				break;
			case 2:
				//this is maximum amount of treasure

				aL= strtol(argv[i], &eptr, 10);
				m_maxTreasure = (int) aL;
				if(m_maxTreasure <0)
				{
					answer = false;
				}
				std::cout<<"Amount of treasure is "<<m_maxTreasure<<std::endl;
				break;

			default:
				std::cout<<"Unexpected argument count."<<std::endl;
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count



    }
    std::cout<<"MaxRooms is: "<<m_maxRooms<<", MaxTreasure is: "<<m_maxTreasure<<std::endl;

    return answer;
}


