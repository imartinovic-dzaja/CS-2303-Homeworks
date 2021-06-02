/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"



bool tests()
{
	bool answer = false;
	bool ok1 = testInitMatrix();
	bool ok2 = testSetEdge();
	bool ok3 = testGetEdge();
	bool ok4 = testCreateMainDiagonalSymmetry();
	bool ok5 = testReadFile();
	bool ok6 = testReadFileWhenFileCannotBeLoaded();
	bool ok7 = testMakeEmptyLinkedList();
	bool ok8 = testAddingElementsToLinkedList();
	bool ok9 = testIsEmpty();
	bool ok10 = testRemoveFromListWhenListIsEmpty();
	bool ok11 = testRemoveFromListWhenListIsNotEmpty();
	bool ok12 = testAddTreasure();
	bool ok13 = testContainsRoom();
	bool ok14 = testAddAdjecentOnToBeSearched();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 &&ok11 && ok12 && ok13 && ok14;
	return answer;

}


bool testInitMatrix() {
    printf("Testing InitMatrix\n");

    int numOfNodes = 5;
    int edges[25] = {1,1,1,1,1,
                     1,1,1,1,1,
                     1,1,1,1,1,
                     1,1,1,1,1,
                     1,1,1,1,1};
    AdjMat* matrixP = (AdjMat*) malloc (sizeof(AdjMat));
    matrixP->n = numOfNodes;
    matrixP->edgesP = edges;
    initMatrix(matrixP);
    int* matrixEdgesP  = matrixP->edgesP;
    bool ok = true;

    for(int i = 0; i<25; ++i)
    {
        ok &= (matrixEdgesP[i]==0);
    }

    if(ok)
        printf("testInitMatrix passed\n");

    else
        printf("testInitMatrix did not pass\n");

    return ok;
}

bool testSetEdge() {
    printf("Testing setEdge\n");

    int numOfNodes = 5;
    int edges[25];
    AdjMat* matrixP = (AdjMat*) malloc (sizeof(AdjMat));
    matrixP->n = numOfNodes;
    matrixP->edgesP = edges;

    initMatrix(matrixP);
    int* matrixEdgesP  = matrixP->edgesP;

    setEdge(matrixP, 4, 4);

    bool ok = true;
    //check if all others remained the same, while only the one set changed
    for(int i = 0; i<25; ++i)
    {
        if (i==24)
        {
            ok &= (matrixEdgesP[i]==1);
        }
        else {
        ok &= (matrixEdgesP[i]==0);
        }
    }

    if(ok)
        printf("testSetEdge passed\n");

     else
        printf("testSetEdge did not pass\n");

    return ok;
}

bool testGetEdge() {

     printf("Testing getEdge\n");

    int numOfNodes = 5;
    int edges[25] = {1, 2, 3, 4, 5,
                     6, 7, 8, 9, 10,
                     11, 12, 13, 14, 15,
                     16, 17, 18, 19, 20,
                     21, 22, 23, 24, 25};
    AdjMat* matrixP = (AdjMat*) malloc (sizeof(matrixP));
    matrixP->n = numOfNodes;
    matrixP->edgesP = edges;

    bool ok = true;
    //check if all others remained the same, while only the one set changed
    for(int i = 0; i<5; ++i)
    {
        for(int j = 0; j<5; ++j)
        {
                    ok&= (getEdge(matrixP, i, j) == 5*i + j + 1);

        }

    }

    if(ok)
        printf("testGetEdge passed\n");
     else
        printf("testGetEdge did not pass\n");

    return ok;
}

bool testCreateMainDiagonalSymmetry() {
    printf("Testing createMainDiagonalSymmetry\n");
    int numOfNodes = 5;
    int edges[25] = {0, 0, 0, 0, 0,
                     1, 0, 0, 0, 0,
                     0, 1, 0, 0, 0,
                     1, 0, 1, 0, 0,
                     1, 1, 0, 1, 0};
     int resultEdges[25] = {1, 1, 0, 1, 1,
                            1, 1, 1, 0, 1,
                            0, 1, 1, 1, 0,
                            1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1};

    AdjMat* matrixP = (AdjMat*) malloc (sizeof(AdjMat));
    matrixP->n = numOfNodes;
    matrixP->edgesP = edges;

    createMainDiagonalSymmetry(matrixP);

    bool ok = true;

    for(int i = 0; i<5; ++i)
    {
        for(int j = 0; j<5; ++j)
        {
                    ok&= (getEdge(matrixP, i, j) == resultEdges[5*i+j]);

        }

    }

    if (ok)
        printf("testCreateMainDiagonalSymmetry passed\n");

    return ok;

}


bool testReadFile() {

    printf("Testing read file\n");

    int expectedEdges[25] = {  1, 1, 0, 1, 0,
                               1, 1, 1, 0, 1,
                               0, 1, 1, 1, 0,
                               1, 0, 1, 1, 1,
                               0, 1, 0, 1, 1
                                };


    Room room1;
    room1.roomNumber = 1;
    room1.treasure = 5.0f;
    room1.searched = false;

    Room room2;
    room2.roomNumber = 2;
    room2.treasure = 10.0f;
    room2.searched = false;

    Room room3;
    room3.roomNumber = 3;
    room3.treasure = 15.0f;
    room3.searched = false;

    Room room4;
    room4.roomNumber = 4;
    room4.treasure = 20.0f;
    room4.searched = false;

    Room room5;
    room5.roomNumber = 5;
    room5.treasure = 25.0f;
    room5.searched = false;

    Room expectedRooms[5] = {room1, room2, room3, room4, room5};




    AdjMat matrix;
    Room* rooms;
    int numOfRooms;


    readFile("testFile.txt", &numOfRooms, &matrix, &rooms);

    bool ok = true;





    ok &= (numOfRooms == 5);

    if(ok)
    {
        printf("Number of rooms is correct\n");
    }

    for(int i = 0; i< numOfRooms; ++i)
    {
        for(int j = 0; j<numOfRooms; ++j)
                    ok&= (getEdge(&matrix, i, j) == expectedEdges[5*i+j]);

    }



     if(ok)
    {
        printf("Matrix is correct\n");
    }

    for (int i = 0; i<numOfRooms; ++i)
    {
        Room* roomP = rooms + i;
        printf("Room number is %d, Room treasure is %f, room is searched %d\n", roomP->roomNumber, roomP->treasure, roomP->searched);
        ok &= ((roomP->roomNumber == expectedRooms[i].roomNumber) && (roomP->treasure == expectedRooms[i].treasure) && (roomP->searched == false ))  ;
    }


    if (ok)
    {
        printf("The Rooms have correct number, treasure and searched state\n");
        printf("testReadFile passed \n");
    }
    else
    {
        printf("testReadFile did not pass \n");

    }

    return ok;

}


bool testReadFileWhenFileCannotBeLoaded()
{
    printf("Testing whether readFile can handle non-existent files\n");
    AdjMat matrix;
    Room* rooms;
    int numOfRooms;

    if (readFile("dummy", &numOfRooms, &matrix, &rooms))
    {
        printf("Something went wrong\n");
        return false;
    }

    else
    {
        printf("readFile properly identified a non-existent file\n");
        return true;
    }
}

bool testMakeEmptyLinkedList() {
    puts("Starting testMakeEmptyLinkedList"); fflush(stdout);
    bool ok = true;


    LLNode* emptyList = makeEmptyLinkedList();

    ok = (emptyList->next == (struct LLNode*)0) && (emptyList->prev == (struct LLNode*) 0) && (emptyList->roomP == (Room*)0);

    if (ok)
    {
        puts("testMakeEmptyLinkedList passed");
        fflush(stdout);
    }

    else
    {
        puts("testMakeEmptyLinkedList did not pass");
        fflush(stdout);
    }

    return ok;
}

bool testAddingElementsToLinkedList() {

puts("Starting testAddingElementsToLinkedList"); fflush(stdout);
    bool ok = true;


    LLNode* newListP = makeEmptyLinkedList();
    Room* newRoomOneP = malloc(sizeof(Room));
    Room* newRoomTwoP = malloc(sizeof(Room));
    Room* newRoomThreeP = malloc(sizeof(Room));


    addRoomToLL(newListP, newRoomOneP);
    addRoomToLL(newListP, newRoomTwoP);
    addRoomToLL(newListP, newRoomThreeP);


    ok &= (newListP->roomP == newRoomOneP);
    LLNode* subNode =  (LLNode*) (newListP->next);
    ok &= (subNode->roomP == (Room*) newRoomTwoP);
    LLNode* lastNode =  (LLNode*) subNode->next;
    ok &= (lastNode->next == (struct LLNode*)0) && ((LLNode*)lastNode->prev == subNode) && (lastNode->roomP == newRoomThreeP);

    if (ok)
    {
        puts("testAddingElementsToLinkedList passed");
        fflush(stdout);
    }

    else
    {
        puts("testAddingElementsToLinkedList did not pass");
        fflush(stdout);
    }

    return ok;
}

bool testIsEmpty() {
    LLNode* newListP = makeEmptyLinkedList();

    bool ok = true;

    ok &= isEmpty(newListP);

    Room* newRoomOneP = malloc(sizeof(Room));
    Room* newRoomTwoP = malloc(sizeof(Room));
    Room* newRoomThreeP = malloc(sizeof(Room));

    addRoomToLL(newListP, newRoomOneP);
    addRoomToLL(newListP, newRoomTwoP);
    addRoomToLL(newListP, newRoomThreeP);

    ok &= !isEmpty(newListP);

    if(ok) {
        printf("testIsEmpty passed\n");
    }
    else {
        printf("testIsEmpty did not pass\n");
    }

    return ok;



}

bool testRemoveFromListWhenListIsEmpty() {
    printf("Testing removeElementFromList when the list is empty\n");
    LLNode* emptyList = makeEmptyLinkedList();
    Room* newRoomOneP = malloc(sizeof(Room));

    removeFromList(emptyList, newRoomOneP);

    if (isEmpty(emptyList))
    {
        printf("testRemoveFromListWhenListIsEmpty passed\n");
        return true;
    }
    else
    {
        printf("testRemoveFromListWhenListIsEmpty did not pass\n");
        return false;
    }
}

bool testRemoveFromListWhenListIsNotEmpty() {
    printf("Testing removeElementFromList when the list is not empty\n");
    LLNode* newListP = makeEmptyLinkedList();
    Room* newRoomOneP = malloc(sizeof(Room));
    Room* newRoomTwoP = malloc(sizeof(Room));
    Room* newRoomThreeP = malloc(sizeof(Room));
    Room* newRoomFourP = malloc(sizeof(Room));
    Room* newRoomFiveP = malloc(sizeof(Room));


    newRoomOneP->roomNumber = 1;
    newRoomTwoP->roomNumber = 2;
    newRoomThreeP->roomNumber = 3;
    newRoomFourP->roomNumber = 4;
    newRoomFiveP->roomNumber = 5;




    addRoomToLL(newListP, newRoomOneP);
    addRoomToLL(newListP, newRoomTwoP);
    addRoomToLL(newListP, newRoomThreeP);
    addRoomToLL(newListP, newRoomFourP);
    addRoomToLL(newListP, newRoomFiveP);


    LLNode* parsedList = removeFromList(newListP, newRoomOneP);
    parsedList = removeFromList(parsedList, newRoomThreeP);
    bool ok = true;
    ok &= !containsRoom(parsedList, newRoomOneP);
    ok &= containsRoom(parsedList, newRoomTwoP);
    ok &= !containsRoom(parsedList, newRoomThreeP);
    ok &= containsRoom(parsedList, newRoomFourP);
    ok &= containsRoom(parsedList, newRoomFiveP);
    if (ok)
    {
        printf("testRemoveFromListWhenListIsNotEmpty passed\n");
        return true;
    }
    else
    {
        printf("testRemoveFromListWhenListIsNotEmpty did not pass\n");
        return false;
    }
}

bool testAddTreasure() {
printf("Testing addTreasure\n");

    float* treasureAccum = (float*)malloc(sizeof(float));
    *treasureAccum = 0.0f;
    LLNode* toBeSearchedList = makeEmptyLinkedList();
    LLNode* searchedList = makeEmptyLinkedList();
    Room* newRoomOneP = malloc(sizeof(Room));
    newRoomOneP->roomNumber = 1;
    newRoomOneP->searched = false;
    newRoomOneP->treasure = 25.5;
    addRoomToLL(toBeSearchedList, newRoomOneP);

    addTreasure(treasureAccum, newRoomOneP, searchedList, toBeSearchedList);

    bool ok= true;

    ok&= (newRoomOneP->roomNumber == 1);
    ok&= (newRoomOneP->searched == true);
    ok&= (newRoomOneP->treasure == 0);

    ok &= isEmpty(toBeSearchedList);
    if(ok) {printf("List is empty as supposed\n");}
    else {printf("List is not empty\n");}
    ok &= (searchedList->roomP == newRoomOneP);

    if (ok)
    {
        printf("testAddTreasure passed\n");
        return true;
    }

    else
    {
        printf("testAddTreasure did not pass\n");
        return false;
    }
}

bool testContainsRoom() {
    printf("Testing containsRoom\n");

    LLNode* newListP = makeEmptyLinkedList();
    Room* newRoomOneP = malloc(sizeof(Room));

    bool ok = true;

    ok &= !containsRoom(newListP, newRoomOneP);

    Room* newRoomTwoP = malloc(sizeof(Room));
    Room* newRoomThreeP = malloc(sizeof(Room));
    Room* newRoomFourP = malloc(sizeof(Room));
    Room* newRoomFiveP = malloc(sizeof(Room));

    addRoomToLL(newListP, newRoomOneP);
    addRoomToLL(newListP, newRoomTwoP);
    addRoomToLL(newListP, newRoomThreeP);
    addRoomToLL(newListP, newRoomFourP);

    ok &= containsRoom(newListP, newRoomTwoP);
    ok &= containsRoom(newListP, newRoomFourP);
    ok &= !containsRoom(newListP, newRoomFiveP);

    if (ok)
    {
        printf("testContainsRoom passed \n");

    }
    else {
        printf("testContainsRoom did not pass \n");
    }

    return ok;

}

bool testAddAdjecentOnToBeSearched() {
    printf("Testing addAdjecentOnToBeSearched\n");
    LLNode* toBeSearchedListP = makeEmptyLinkedList();
    AdjMat matrix;
    Room* rooms;
    int numOfRooms;

    readFile("testFile2.txt", &numOfRooms, &matrix, &rooms);



    rooms->searched = true;

    addRoomToLL(toBeSearchedListP, rooms+1);
    addRoomToLL(toBeSearchedListP, rooms+4);
    bool ok = true;
    // if we run addAdjecentOnToBeSearched on Room4, where room1 has been searched and  room2 and room 5
    // are already in to be searched, we expect the new LinkedList to contain room3
    // alongside rooms 2 and 5
    addAjdecentOnToBeSearched(toBeSearchedListP, rooms+3, &matrix, &rooms);


    LLNode* subNode1 = (LLNode*) toBeSearchedListP->next;
    LLNode* subNode2 = (LLNode*) subNode1->next;
    ok &= (toBeSearchedListP->roomP == &rooms[1]);
    ok &= (subNode1->roomP == &rooms[4]);
    ok &= (subNode2->roomP == &rooms[2]);


    if(ok) {
        printf("testAddAdjecentOnToBeSearched passed\n");
    }
    else {
        printf("testAddAdjecentOnToBeSearched did not pass\n");
    }
    return ok;
}
