

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Room.h"


class LLNode;

class LLNode
{
private:
	class LLNode* m_next;
	class LLNode* m_prev;
	Room* m_roomPointer;

public:
    LLNode();
    ~LLNode();
    //for testing
    LLNode(Room* rP);
    LLNode(LLNode* nextP, Room* rP);
    LLNode(LLNode* nextP, LLNode* prevP, Room* rP);

    Room* getRoomP();
    LLNode* getPrevP();
    LLNode* getNextP();
    void addRoomToLL(Room* rP);
    bool isEmpty();
    LLNode* removeFromList( Room* rP);
    bool containsRoom(Room* rP);
    void printList();
    LLNode* getLeaf();
};


#endif // LINKEDLIST_H_INCLUDED
