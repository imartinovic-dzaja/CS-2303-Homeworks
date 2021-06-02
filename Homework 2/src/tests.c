/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#define ROWS 20
#define COLUMNS 20


bool tests()
{
	bool answer = false;

	bool ok1 = testInitSpace();
	bool ok2 = testPlaceMarker();
	bool ok3 = testWander();
	bool ok4 = testMakeEmptyLinkedList();
	bool ok5 = testCreatingLinkedListOFLenghtOne();
	bool ok6 = testAddingElementsToLinkedList();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	//void testPrintScreen();
	return answer;
}

bool testInitSpace() {
    puts("starting testInitSpace");fflush(stdout);

    bool ok = true;
	int* theSpaceP = (int*) malloc(ROWS*COLUMNS*sizeof(int)); // init a screen
	initSpace(theSpaceP);

    for(int row = 0; row< ROWS; row++)
    {
        for(int col = 0; col < COLUMNS; col++)
        {
            ok&=(*(theSpaceP+row*COLUMNS + col) == 0) ;    // check if all pixels are initialized to 0
        }
    }

    if (ok)
       {puts("testInitSpace passed");fflush(stdout);}
    else
        {puts("testInitSpace did not pass");fflush(stdout);}

    return ok;
    }

bool testPlaceMarker() {
puts("Starting testPlaceMarker"); fflush(stdout);

    bool ok = true;

    int* theSpaceP = (int*) malloc(ROWS*COLUMNS*sizeof(int)); // init a screen (this screen will change after we place a marker)
	initSpace(theSpaceP);

	int* theSpaceP2 = (int*) malloc(ROWS*COLUMNS*sizeof(int)); // init a screen (this screen will stay the same, and is used to compare before and after)
	initSpace(theSpaceP2);

	// check that the index is updated for the place where the marker is placed
	// check that all other indexed remained the same

	Marker* marker1 = placeMarker(theSpaceP,5,5,5);   //place a marker at location (5,5) with index 5
	if (marker1 != NULL)
    {
        for(int row = 0; row< ROWS; row++)
            {
                for(int col = 0; col < COLUMNS; col++)
                {
                    if (col != 5 && row != 5) // as long as we are not checking the location where the marker is placed
                    ok &= (*(theSpaceP+row*COLUMNS + col) == *(theSpaceP2+row*COLUMNS + col)); // the values of the first and second screen should be the same
                }
            }

         ok &= (*(theSpaceP+5*20 + 5)  == 5); // check if new index is set to 5

    }
    else {
        puts("Unexpected error, marker1 is null"); fflush(stdout);
        ok = false;
    }

    if (ok)
       {puts("testPlaceMarker passed");fflush(stdout);}
    else
        {puts("testPlaceMarker did not pass");fflush(stdout);}

    return ok;



}


void testPrintScreen() {

    int* theSpaceP = (int*) malloc(ROWS*COLUMNS*sizeof(int));

    for(int row = 0; row< 20; row++)
	{
		for(int col = 0; col < 20; col++)
		{
			*(theSpaceP+row*20 + col) = row;
		}
	}

	printScreen(theSpaceP);
}


bool testWander() {

puts("Starting testWander"); fflush(stdout);
    bool ok = true;
    int* theSpaceP = (int*) malloc(ROWS*COLUMNS*sizeof(int));
    initSpace(theSpaceP);

    ok = (wander(theSpaceP, 25, makeEmptyLinkedList()) == 25);
    if (ok)
       {puts("testWander passed");fflush(stdout);}
    else
        {puts("testWander did not pass");fflush(stdout);}

    return ok;
}

bool testMakeEmptyLinkedList() {
    puts("Starting testMakeEmptyLinkedList"); fflush(stdout);
    bool ok = true;


    LLNode* emptyList = makeEmptyLinkedList();

    ok = (emptyList->next == (struct LLNode*)0) && (emptyList->prev == (struct LLNode*) 0) && (emptyList->payP == (Payload*)0);

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


bool testCreatingLinkedListOFLenghtOne() {

puts("Starting testCreatingLinkedListOFLenghtOne"); fflush(stdout);
    bool ok = true;


    LLNode* newListP = makeEmptyLinkedList();
    Payload* newPayloadP = malloc(sizeof(Payload));

    savePayload(newListP, newPayloadP);


    ok = (newListP->next == (struct LLNode*)0) && (newListP->prev == (struct LLNode*) 0) && (newListP->payP == newPayloadP);

    if (ok)
    {
        puts("testCreatingLinkedListOFLenghtOne passed");
        fflush(stdout);
    }

    else
    {
        puts("testCreatingLinkedListOFLengthOne did not pass");
        fflush(stdout);
    }

    return ok;
}

bool testAddingElementsToLinkedList() {

puts("Starting testAddingElementsToLinkedList"); fflush(stdout);
    bool ok = true;


    LLNode* newListP = makeEmptyLinkedList();
    Payload* newPayloadOneP = malloc(sizeof(Payload));
    Payload* newPayloadTwoP = malloc(sizeof(Payload));
    Payload* newPayloadThreeP = malloc(sizeof(Payload));


    savePayload(newListP, newPayloadOneP);
    savePayload(newListP, newPayloadTwoP);
    savePayload(newListP, newPayloadThreeP);


    ok &= (newListP->payP == newPayloadOneP);
    LLNode* subNode =  (LLNode*) (newListP->next);
    ok &= (subNode->payP == (Payload*) newPayloadTwoP);
    LLNode* lastNode =  (LLNode*) subNode->next;
    ok &= (lastNode->next == (struct LLNode*)0) && ((LLNode*)lastNode->prev == subNode) && (lastNode->payP == newPayloadThreeP);

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
