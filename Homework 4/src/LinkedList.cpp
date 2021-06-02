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
#include <iostream>

LLNode::LLNode() {

    m_next = (LLNode*) 0;
    m_prev = (LLNode*) 0;
    m_roomPointer = (Room*) 0;

}

LLNode::~LLNode() {


	if(this->isEmpty()){	}
	else {delete m_next;}
}

// for testing
LLNode::LLNode(Room* rP) {

    m_next = (LLNode*) 0;
    m_prev = (LLNode*) 0;
    m_roomPointer = rP;

}

LLNode::LLNode(LLNode* nextP, Room* rP) {
    m_next = (LLNode*)nextP;
    m_prev = (LLNode*) 0;
    m_roomPointer = rP;
}

LLNode::LLNode(LLNode* nextP, LLNode* prevP, Room* rP) {
    m_next = (LLNode*)nextP;
    m_prev = (LLNode*)prevP;
    m_roomPointer = rP;
}

Room* LLNode::getRoomP() {
    return m_roomPointer;
}

LLNode* LLNode::getPrevP() {
    return (LLNode*)m_prev;
}

LLNode* LLNode::getNextP() {
    return (LLNode*)m_next;
}

void LLNode::addRoomToLL(Room* rP) {
    LLNode* temp = this;

	if(this->isEmpty())
	{
		m_roomPointer = rP;
	}
	else if(temp->getNextP())
    {
        temp=(LLNode*)temp->getNextP();
        temp->addRoomToLL(rP);
    }

    else
	{
	    LLNode* newListP = new LLNode(rP);
		this->m_next = (class LLNode*) newListP;
		newListP->m_prev =(class LLNode*) this;
	}
}

bool LLNode::isEmpty() {
    bool ok = false;
    if (this == (LLNode*)0) {ok = true;}
    else if (m_roomPointer == (Room*) 0) {ok = true;}
    return ok;
}

bool LLNode::containsRoom(Room* rP) {
    LLNode* temp = this;

      if(this->isEmpty())
	{
            return false;
    }
	else if (this->getRoomP() == rP)
    {
        //we found the room
        return true;
    }

    else if(temp->getNextP()) {     // otherwise continue searching
        temp=(LLNode*)temp->getNextP();
        temp->containsRoom(rP);
    }

    else    // if not found return false
	{
		return false;
    }
}

LLNode* LLNode::removeFromList(Room* rP) {

	if(this->isEmpty())
	{}
	else

	{	    // if we are trying to remove the root
        if(this->m_roomPointer == rP)
        {return this->getNextP();}
        else {
        // step trough every element looking for the pointer
        LLNode* temp = this->getNextP();

        while (temp->getNextP())
        {
             LLNode* nextTemp = temp->getNextP();
             LLNode* prevTemp = temp->getPrevP();
            // if we find the thing we are looking for
            if(temp -> m_roomPointer == rP) {

                    // we skip that element when returning
        prevTemp->m_next = (class LLNode*) nextTemp;
        nextTemp->m_prev = (class LLNode*) prevTemp;
                return this;
            }
            // otherwise continue searching
            else {
                temp = temp->getNextP();
            }
        }
        //check if last is the thing we are looking for
        if (temp->m_roomPointer == rP) {
            LLNode* prevTemp = temp->getPrevP();
            prevTemp->m_next = (class LLNode*) 0;
        }
        return this;
        }
    }
}

LLNode* LLNode::getLeaf() {

    LLNode* temp = this;

      if(this->isEmpty())
	{
            return (LLNode*) 0;
    }
	else if (this->getNextP())
    {
        temp = temp->getNextP();
        temp ->getLeaf();
    }

    else    // if not found return false
	{
		return temp;
    }
}

void LLNode::printList() {
    if (this->isEmpty() || this == (LLNode*) 0)
{
    std::cout<<"Nothing to print, list is empty"<<std::endl;
}
else
{
    LLNode* temp = this;
    while (temp->getNextP()) {
        std::cout<<"Room#: "<<temp->getRoomP()->getRoomNumber()<<std::endl;
        temp = (LLNode*) temp->getNextP();
    }
        std::cout<<"Room#: "<<temp->getRoomP()->getRoomNumber()<<std::endl;
}
}



