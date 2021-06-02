/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "AdjMat.h"
#include "Room.h"
#include "LinkedList.h"
bool production(int argc, char* argv[])
{
    // beginning of argument reading logic
	bool answer = true;
	float maxTreasure;
	int maxRooms;

	if(argc <=2) //no interesting information
	{
		printf("Didn't find enough command line arguments.\n");
        printf("Please enter the amount of treasure you wish to find.\n");

        char line[100];
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f", &maxTreasure);

        printf("Please enter the maximum amount of rooms you wish to search.\n");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &maxRooms);

		answer &= (maxTreasure>0 && maxRooms >0);
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//this is maximum number of rooms

				aL= strtol(argv[i], &eptr, 10);
				maxRooms = (int) aL;
				if(maxRooms <0)
				{
					answer = false;
				}
				printf("Number of rooms is %d\n",maxRooms);
				break;
			case 2:
				//this is maximum amount of treasure

				aL= strtol(argv[i], &eptr, 10);
				maxTreasure = (int) aL;
				if(maxTreasure <0)
				{
					answer = false;
				}
				printf("Amount of treasure is %f\n",maxTreasure);
				break;

			default:
				printf("Unexpected argument count.\n");
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count



    }
    printf("MaxRooms is: %d, MaxTreasure is: %f\n", maxRooms, maxTreasure);

    ///End of argument reading logic

    if(answer) {

    float treasureAccumulator = 0.0f;
    int numOfVisitedRooms = 0;

    AdjMat matrix;
    Room* rooms;
    int numOfRooms;
    LLNode* toBeSearchedListP = makeEmptyLinkedList();
    LLNode* searchedListP = makeEmptyLinkedList();

    readFile("houseGraph.txt", &numOfRooms, &matrix, &rooms);

    //In every house we will start from Room1:

    addRoomToLL(toBeSearchedListP, rooms);

    while (treasureAccumulator < maxTreasure && numOfVisitedRooms < maxRooms)
    {
        printf("\n");
        numOfVisitedRooms++;
        Room* rP = toBeSearchedListP->roomP;

        addAjdecentOnToBeSearched(toBeSearchedListP, toBeSearchedListP->roomP, &matrix, &rooms);
        addTreasure(&treasureAccumulator, toBeSearchedListP->roomP,searchedListP, toBeSearchedListP);

        printf("Currently searching room# %d\n", rP->roomNumber);
        printf("Current accumulated treasure is (including current) %f\n", treasureAccumulator);
        printf("Current number of rooms searched (including current) %d\n", numOfVisitedRooms);
        printf("Those include:\n");
        printList(searchedListP);

    }

     printf("Total accumulated treasure is %f\n", treasureAccumulator);
     printf("Total number of rooms searched (inlcuding current) %d\n", numOfVisitedRooms);
     printf("Those rooms include:\n");
     printList(searchedListP);

	return answer;

}
  else {
        printf("Something was wrong with the argument(s)\n");
        return false;
    }

}



bool readFile(char* filename, int* numOfRoomsP, AdjMat* adjMP, Room** theRoomPP)
{
    FILE* fileP = fopen(filename, "r");

    if (fileP == NULL)
    {
        printf("Error reading file\n");
        return false;
    }

    else {

    float* temp = (float*) malloc(sizeof (float));
    fscanf(fileP, "%f", temp);

    // set the number of rooms
    *numOfRoomsP = (int) *temp;

    // initialize Adjeceny matrix
    adjMP->n = *numOfRoomsP;
    initMatrix(adjMP);

    for (int row = 1; row<*(numOfRoomsP); ++row)
    {
        for (int column = 0; column<row; ++column)
        {
            fscanf(fileP, "%f", temp);
            if (*temp) {
                setEdge(adjMP, row, column);
            }
        }
    }
    // symmetrize the matrix
    createMainDiagonalSymmetry(adjMP);

    // create an array for all the rooms
     *theRoomPP = (Room*) malloc(sizeof(Room) * (*numOfRoomsP));
     Room* roomArray = *theRoomPP;

    for (int i = 0; i < *numOfRoomsP; ++i)
    {
        fscanf(fileP, "%f", temp);
        (roomArray + i)->roomNumber = i+1;
        (roomArray + i)->treasure = *temp;
        (roomArray + i)->searched = false;
    }

    return true;
        }
    }



void addTreasure(float* treasureAccumP, Room* roomToSearchP,
                 LLNode* searchedList, LLNode* toBeSearchedList) {
    *treasureAccumP += roomToSearchP->treasure;
    roomToSearchP->treasure = 0;
    roomToSearchP->searched = true;
    addRoomToLL(searchedList, roomToSearchP);
    *toBeSearchedList = *removeFromList(toBeSearchedList, roomToSearchP);
}

void addAjdecentOnToBeSearched(LLNode* toBeSearchedList, Room* currentRoom, AdjMat* matrixP, Room** listOfRooms) {

    int numOfRooms = matrixP->n;
    int column = (currentRoom->roomNumber) - 1;

    // go through each row of the matrix with column number same as current column except
    // the current room

    for (int row = 0; row< numOfRooms; ++row) {
            // if we can get to the room from current room and that room has not been searched
            // we add it to the to be searched list
        Room* roomP = (*listOfRooms + row);
        bool ok = true;

        ok &= (row != column);                      // we do not want to be adding the current room
        ok &= getEdge(matrixP, row, column);        //we want to add rooms that we can gt to according to adjecency matrix
        ok &= !(containsRoom(toBeSearchedList, (*listOfRooms)+row));    // we do not want to add rooms which are already in the to be searched list
        ok &= !(roomP->searched);                   // we do not want to add the rooms which are already searcherd

        if (ok) {
                addRoomToLL(toBeSearchedList, *listOfRooms+row);
                }
  }

}
