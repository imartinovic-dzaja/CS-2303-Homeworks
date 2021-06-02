#include "Room.h"
#include "AdjMat.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <string>


#ifndef PRODUCTION_H_INCLUDED
#define PRODUCTION_H_INCLUDED

class Production {
private:

    float m_treasureAccum;
    int m_numOfSearchedRooms;

    int m_maxRooms;
    float m_maxTreasure;

    int m_numOfRooms;
    AdjMat m_matrix;
    Room* m_rooms;
    LLNode* m_searchedListP;
    LLNode* m_toBeSearchedListP;


public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool readArguments(int argc, char* argv[]);

	int getNumOfRooms();
	int getNumOfSearchedRooms();
	float getTreasureAccum();
	Room* getRooms();

	AdjMat* getMatrix();
	LLNode* getSearchedList();
	LLNode* getToBeSearchedList();

	void setToBeSearchedList(LLNode*);

	void readFile(char* filename);
	void addTreasure(Room* roomToSearchP);
    void addAjdecentOnToBeSearched(Room* currentRoom);
};

#endif // PRODUCTION_H_INCLUDED
