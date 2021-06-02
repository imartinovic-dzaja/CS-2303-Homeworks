/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_


#include "Room.h"
#include "LinkedList.h"
#include "AdjMat.h"
#include "production.h"


bool tests();

bool testInitMatrix();
bool testSetEdge();
bool testGetEdge();
bool testCreateMainDiagonalSymmetry();
bool testReadFile();
bool testReadFileWhenFileCannotBeLoaded();
bool testMakeEmptyLinkedList();
bool testAddingElementsToLinkedList();
bool testIsEmpty();
bool testRemoveFromListWhenListIsEmpty();
bool testRemoveFromListWhenListIsNotEmpty();
bool testAddTreasure();
bool testAddAdjecentOnToBeSearched();
bool testContainsRoom();

#endif /* TESTS_H_ */
