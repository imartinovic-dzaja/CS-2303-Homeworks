/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "AdjMat.h"
#include "Room.h"
#include "LinkedList.h"




#define FILENAMELENGTHALLOWANCE 50

bool production(int argc, char* argv[]);
bool readFile(char* filename, int* numOfRooms, AdjMat* adjMP, Room** theRoomP);
void addTreasure(float* treasureAccumP, Room* roomToSearchP, LLNode* searchedList,  LLNode* toBeSearchedList);
void addAjdecentOnToBeSearched(LLNode* toBeSearchedList, Room* currentRoom, AdjMat* matrixP, Room** listOfRooms);

#endif /* PRODUCTION_H_ */
