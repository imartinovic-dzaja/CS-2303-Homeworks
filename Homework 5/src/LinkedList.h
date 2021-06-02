
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


#include "LinkedList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>


template <class T>
class LLNode;

template <class T>
class LLNode
{
private:
    class LLNode<T>* m_next;
	class LLNode<T>* m_prev;
	T* m_elementP;

public:

LLNode() {
    m_next = (LLNode*) 0;
    m_prev = (LLNode*) 0;
    m_elementP = (T*) 0;
}
~LLNode() {
	if(this->isEmpty()){	}
	else {  delete m_elementP;
            delete m_next;}
}

// for testing
LLNode(T* rP) {
    m_next = (LLNode*) 0;
    m_prev = (LLNode*) 0;
    m_elementP = rP;
}
LLNode(LLNode* nextP, T* rP) {
    m_next = (LLNode*)nextP;
    m_prev = (LLNode*) 0;
    m_elementP = rP;
}
LLNode(LLNode* nextP, LLNode* prevP, T* rP) {
    m_next = (LLNode*)nextP;
    m_prev = (LLNode*)prevP;
    m_elementP = rP;
}

T* getElementP() {
    return m_elementP;
}
LLNode<T>* getPrevP() {
    return (LLNode*)m_prev;
}
LLNode<T>* getNextP() {
    return (LLNode*)m_next;
}
void setElementP(T* elementP) {m_elementP = elementP;}
void setNextP(LLNode<T>* nextP) {m_next = nextP;}
void setPrevP(LLNode<T>* prevP) {m_prev = prevP;}
void addElementToLL(T* rP) {
    LLNode<T>* temp = this;

	if(this->isEmpty())
	{
		m_elementP = rP;
	}
	else if(temp->getNextP())
    {
        temp=(LLNode*)temp->getNextP();
        temp->addElementToLL(rP);
    }

    else
	{
	    LLNode* newListP = new LLNode(rP);
		this->m_next = (class LLNode*) newListP;
		newListP->m_prev =(class LLNode*) this;
	}
}
bool isEmpty() {
    bool ok = false;
    if (this == (LLNode*)0) {ok = true;}
    else if (m_elementP == (T*) 0) {ok = true;}
    return ok;
}
bool containsElement(T* rP) {
    LLNode* temp = this;

      if(this->isEmpty())
	{
            return false;
    }
	else if (this->getElementP() == rP)
    {
        //we found the T
        return true;
    }

    else if(temp->getNextP()) {     // otherwise continue searching
        temp=(LLNode*)temp->getNextP();
        temp->containsElement(rP);
    }

    else    // if not found return false
	{
		return false;
    }
}
LLNode<T>* getLeaf() {

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
int getLenght() {
    if (this->isEmpty()) {return 0;} //list was empty;

    int lenght = 1;
    LLNode<T>* temp = this;
    while (temp->getNextP())
    {
        ++lenght;
        temp = temp -> getNextP();
    }

    return lenght;
}
void appendList(LLNode<T>* listToAppend) {
    if (listToAppend->isEmpty()) {} //nothing to do

    else {
        int length = listToAppend->getLenght();

        LLNode<T>* temp = listToAppend;
        for (int i = 0; i< length; ++i) {
            this->addElementToLL(temp->getElementP());
            temp = temp->getNextP();
        }
    }
}
void removeFromList(T* rP) {
	if(this->isEmpty())
	{}      // nothing to do
	else

	{	    // if we are trying to remove the root
	    // if the list consists of a single node


        if(this->m_elementP == rP)
        {
            if(this->getLenght() == 1) // if the list is a single node
            {
                this->setElementP((T*) 0);
            }
            else {
            LLNode<T>* temp = getNextP();
            this->setElementP(temp->getElementP());
            this->setNextP(temp->getNextP());
            temp->setNextP((LLNode<T>*) 0);
            //delete temp;
            }
            }
        else {
        // step trough every element looking for the pointer
        LLNode* temp = this->getNextP();

        while (temp->getNextP())
        {
             LLNode* nextTemp = temp->getNextP();
             LLNode* prevTemp = temp->getPrevP();
            // if we find the thing we are looking for
            if(temp -> m_elementP == rP) {

                    // we skip that element when returning
                prevTemp->setNextP((class LLNode*) nextTemp);
                nextTemp->setPrevP((class LLNode*) prevTemp);
                temp->setNextP((LLNode<T>*) 0); // so we may delete it (this is how the destructor works)
                //delete temp;
                return;
            }
            // otherwise continue searching
            else {
                temp = temp->getNextP();
            }
        }

        //check if last is the thing we are looking for
        if (temp->m_elementP == rP) {

            LLNode* prevTemp = temp->getPrevP();
            prevTemp->setNextP((LLNode<T>*) 0);
            //delete temp;
        }
        }
    }
}

T* getRandomElement() {

    int randomNumber = rand();
    int length = this->getLenght();
    int randomIndex = randomNumber % length;

    LLNode<T>* temp = this;
    for (int i = 0; i<randomIndex; ++i ) {
        temp = temp ->getNextP();
    }

    return temp ->getElementP();
}

};



#endif // LINKEDLIST_H_INCLUDED
