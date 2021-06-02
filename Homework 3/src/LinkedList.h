/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Room.h"

struct LLNode;
typedef struct
{
	struct LLNode* next;
	struct LLNode* prev;
	Room* roomP;
}LLNode;



LLNode* makeEmptyLinkedList();
bool isEmpty(LLNode* lp);
void addRoomToLL(LLNode* lp, Room* rP);
LLNode* removeFromList(LLNode* hP, Room* rP);
bool containsRoom(LLNode* listP, Room* rP);



#endif /* LINKEDLIST_H_ */
