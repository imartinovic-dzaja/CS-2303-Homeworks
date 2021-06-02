/*
 * LinkedList.c
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */


#include "LinkedList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isEmpty(LLNode* lp)
{
	bool ans = false;
	if(lp->roomP == (Room*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* makeEmptyLinkedList()
{
	LLNode* lp = (LLNode*) malloc(sizeof(LLNode));
	lp->next = (struct LLNode*)0;
	lp->prev = (struct LLNode*)0;
	lp->roomP = (Room*)0;

	return lp;
}

void addRoomToLL(LLNode* lp, Room* rP)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty(lp))
	{
		lp->roomP = rP;
	}
	else
	{
		LLNode* temp = lp;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();
		newList->roomP = rP;
		temp->next = (struct LLNode*)newList;
		newList->prev = (struct LLNode*) temp;
	}
}

LLNode* removeFromList(LLNode* hP, Room* rP)
{
	if(isEmpty(hP))
	{
		//nothing to do
	}
	else

	{
	    // if we are trying to remove the root
        if(hP->roomP == rP)
        {
             // if the root is the only thing
            if (!(hP->next)) {
                return makeEmptyLinkedList();
            }
            return ((LLNode*) hP->next); // return everything except the root
        }

        else {
        // step trough every element looking for the pointer
        LLNode* temp = (LLNode*) hP->next;


        while (temp->next)
        {
             LLNode* nextTemp = (LLNode*) temp->next;
             LLNode* prevTemp = (LLNode*) temp->prev;
            // if we find the thing we are looking for
            if(temp -> roomP == rP) {

                    // we skip that element when returning
        prevTemp->next = (struct LLNode*) nextTemp;
        nextTemp->prev = (struct LLNode*) prevTemp;
                return hP;
            }

            else {
                temp = temp->next;
            }

        }
        if (temp->roomP == rP) {
            LLNode* prevTemp = (LLNode*) temp->prev;
            prevTemp->next = makeEmptyLinkedList();
        }
    return hP;
    }
}}

bool containsRoom(LLNode* listP, Room* rP)
{
    if(isEmpty(listP))
	{
            return false;
    }
	else
	{
		LLNode* temp = listP;
		while(temp->next)
		{
		    if (temp->roomP == rP)
            {
                return true;
            } // we found the room

			temp=(LLNode*)temp->next;
		}

		if(temp->roomP == rP) {
            return true;
		}
		// we did not find the room;
		return false;
    }
}

void printList(LLNode* listP) {
    if (isEmpty(listP))
{
    printf("Nothing to print, list is empty\n");
}
else
{
    LLNode* temp = listP;
    while (temp -> next) {
        printf("Room#:%d\n", temp->roomP->roomNumber);
        temp = (LLNode*) temp->next;
    }
        printf("Room#:%d\n", temp->roomP->roomNumber);
}
}
