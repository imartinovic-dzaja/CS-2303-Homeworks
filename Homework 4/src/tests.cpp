#include "Tests.h"

#include <stdbool.h>
#include <iostream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}




bool Tests::tests()
{
	bool answer = true;
	bool ok1 = testGetRoomNumber();
	bool ok2 = testGetTreasure();
	bool ok3 = testGetSearched();
    bool ok4 = testEmptyTreasure();
    bool ok5 = testSetSearched();
    bool ok6 = testGetEdge();
    bool ok7 = testSetEdge();
    bool ok8 = testCreateMainDiagonalSymmetry();
    bool ok9 = testGetRoomP();
    bool ok10 = testGetPrevP();
    bool ok11 = testGetNextP();
    bool ok12 = testIsEmpty();
    bool ok13 = testAddRoomToLL();
    bool ok14 = testContainsRoom();
    bool ok15 = testRemoveFromListWhenListIsEmpty();
    bool ok16 = testRomoveElementFromASingleNodeList();
    bool ok17 = testRemoveRootMiddleLeafAndNonExistentFromList();
    bool ok18 = testGetLeaf();
    bool ok19 = testReadFile();
    bool ok20 = testAddTreasure();
    bool ok21 = testAddAdjecentOnToBeSearched();
	answer &= ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19 && ok20 && ok21;
	return answer;
}



bool Tests::testGetRoomNumber() {

    std::cout<<"Starting testGetRoomNumber"<<std::endl;
    Room newRoom(5, 6.6f, true);

    bool ok = (newRoom.getRoomNumber() == 5);

    if(ok) {std::cout<<"testGetRoomNumber passed"<<std::endl;}
    else {std::cout<<"testGetRoomNumber did not pass"<<std::endl;}
    return ok;
}

bool Tests::testGetTreasure() {
    std::cout<<"Starting testGetTreasure"<<std::endl;
    Room newRoom(5, 6.6f, true);

    bool ok = (newRoom.getTreasure() >= 6.5f) && (newRoom.getTreasure() <= 6.7f);

    if(ok) {std::cout<<"testGetTreasure passed"<<std::endl;}
    else {std::cout<<"testGetTreasure did not pass"<<std::endl;}
    return ok;
 }

 bool Tests::testGetSearched() {
    std::cout<<"Starting testGetSearched"<<std::endl;
    Room newRoom(5, 6.6f, true);

    bool ok = (newRoom.getSearched() == true);

    if(ok) {std::cout<<"testGetSearched passed"<<std::endl;}
    else {std::cout<<"testGetSearched did not pass"<<std::endl;}
    return ok;
 }

 bool Tests::testEmptyTreasure() {
    std::cout<<"Starting testEmptyTreasure"<<std::endl;
    Room newRoom(5, 6.6f, true);
    newRoom.emptyTreasure();
    bool ok = (newRoom.getTreasure() >= -0.1f) && (newRoom.getTreasure() <= 0.1f);

    if(ok) {std::cout<<"testEmptyTreasure passed"<<std::endl;}
    else {std::cout<<"testEmptyTreasure did not pass"<<std::endl;}
    return ok;
 }

 bool Tests::testSetSearched() {
    std::cout<<"Starting testSetSearched"<<std::endl;
    Room newRoom1(5, 6.6f, false);
    Room newRoom2(5, 6.6f, true);

    newRoom1.setSearched();
    newRoom2.setSearched();

    bool ok = (newRoom1.getSearched() == true);
    ok &= (newRoom2.getSearched() == true);

    if(ok) {std::cout<<"testSetSearched passed"<<std::endl;}
    else {std::cout<<"testSetSearched did not pass"<<std::endl;}
    return ok;
 }

bool Tests::testGetEdge() {
    std::cout<<"Starting testGetEdge"<<std::endl;

    int edges[] = {1, 1, 1, 1, 1,
                   1, 1, 1, 1, 1,
                   1, 0, 1, 1, 1,
                   1, 1, 0, 1, 1,
                   1, 1, 1, 1, 1,
    };

    AdjMat matrix(5, edges);

    bool ok = (matrix.getEdge(3,3) == 1) && (matrix.getEdge(2,1) == 0);

    if(ok) {std::cout<<"testGetEdge passed"<<std::endl;}
    else {std::cout<<"testGetEdge did not pass"<<std::endl;}
    return ok;
 }

bool Tests::testSetEdge() {
    std::cout<<"Starting testSetEdge"<<std::endl;

    AdjMat matrix(5);

    matrix.setEdge(3,3);

    bool ok = true;
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col <5; ++col) {
            if (row ==3 and col == 3) {ok &= matrix.getEdge(row, col);}
            else {ok &= !matrix.getEdge(row, col);}
        }
    }
    if(ok) {std::cout<<"testSetEdge passed"<<std::endl;}
    else {std::cout<<"testSetEdge did not pass"<<std::endl;}
    return ok;
 }

bool Tests::testCreateMainDiagonalSymmetry() {
   std::cout<<"Starting testCreateMainDiagonalSymmetry"<<std::endl;

    int edgesInitial[] = {0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   0, 1, 0, 0, 0,
                   1, 0, 1, 0, 0,
    };

    int edgesFinal[5][5] = {{1, 0, 1, 0, 1,},
                            {0, 1, 0, 1, 0,},
                            {1, 0, 1, 0, 1,},
                            {0, 1, 0, 1, 0,},
                            {1, 0, 1, 0, 1,}
    };

    AdjMat matrix(5, edgesInitial);

    matrix.createMainDiagonalSymmetry();

    bool ok = true;

    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col <5; ++col) {
                ok &= (matrix.getEdge(row, col) == edgesFinal[row][col]);
            }
    }


    if(ok) {std::cout<<"testCreateMainDiagonalSymmetry passed"<<std::endl;}
    else {std::cout<<"testCreateMainDiagonalSymmetry did not pass"<<std::endl;}
    return ok;
 }

bool Tests::testGetRoomP() {
    std::cout<<"Starting testGetRoomP"<<std::endl;

    Room room1(1, 0 , false);
    LLNode newList(&room1);

    Room* rP = newList.getRoomP();

    if (rP == (Room*) 0) {
        std::cout<<"testGetRoomP did not pass"<<std::endl;
        return false;
    }

    bool ok = (rP->getRoomNumber() == room1.getRoomNumber());
    ok &= (rP->getTreasure() == room1.getTreasure());
    ok &= (rP->getSearched() == room1.getSearched());

    if(ok) {std::cout<<"testGetRoomP passed"<<std::endl;}
    else {std::cout<<"testGetRoomP did not pass"<<std::endl;}
    return ok;

}

bool Tests::testGetPrevP() {
    std::cout<<"Starting testGetPrevP"<<std::endl;

    Room room1(1, 0, false);
    Room room2(2, 0, false);
    Room room3(3, 0, false);

    LLNode root(&room1);
    LLNode leaf(&room3);
    LLNode middle(&leaf, &root, &room2);

    LLNode* rootP = middle.getPrevP();

      if (rootP == (LLNode*) 0) {
        std::cout<<"testGetPrevP did not pass"<<std::endl;
        return false;
    }

    Room* rP = rootP->getRoomP();



    bool ok = (rP->getRoomNumber() == room1.getRoomNumber());
    ok &= (rP->getTreasure() == room1.getTreasure());
    ok &= (rP->getSearched() == room1.getSearched());

    if(ok) {std::cout<<"testGetPrevP passed"<<std::endl;}
    else {std::cout<<"testGetPrevP did not pass"<<std::endl;}
    return ok;

}

bool Tests::testGetNextP() {
    std::cout<<"Starting testGetNextP"<<std::endl;

    Room room1(1, 0, false);
    Room room2(2, 0, false);
    LLNode leaf(&room2);
    LLNode root(&leaf, &room1);

    LLNode* leafP = root.getNextP();

      if (leafP == (LLNode*) 0) {
        std::cout<<"testGetNextP did not pass"<<std::endl;
        return false;
    }

    Room* rP = leafP->getRoomP();

    bool ok = (rP->getRoomNumber() == room2.getRoomNumber());
    ok &= (rP->getTreasure() == room2.getTreasure());
    ok &= (rP->getSearched() == room2.getSearched());

    if(ok) {std::cout<<"testGetNextP passed"<<std::endl;}
    else {std::cout<<"testGetNextP did not pass"<<std::endl;}

    return ok;
}

bool Tests::testIsEmpty() {
    std::cout<<"Starting testIsEmpty"<<std::endl;

    Room room1(1, 0, false);

    LLNode newList;

    bool ok = newList.isEmpty();

    LLNode newList2(&room1);

    ok &= !newList2.isEmpty();

    if(ok) {std::cout<<"testIsEmpty passed"<<std::endl;}
    else {std::cout<<"testIsEmpty did not pass"<<std::endl;}

    return ok;

}

bool Tests::testAddRoomToLL() {
    std::cout<<"Starting testAddRoomToLL"<<std::endl;

    Room room1(1, 0, false);
    Room room2(2, 0, false);
    Room room3(3, 0, false);

    LLNode newList;

    newList.addRoomToLL(&room1);
    newList.addRoomToLL(&room2);
    newList.addRoomToLL(&room3);

    if(newList.getRoomP() == (Room*)0)
    {
        std::cout<<"testAddRoomToLL did not pass"<<std::endl;
        return false;
    }

    LLNode* middle = newList.getNextP();
    if (middle == (LLNode*) 0)
    {
        std::cout<<"testAddRoomToLL did not pass"<<std::endl;
        return false;
    }
    LLNode* leaf = middle->getNextP();
     if (leaf == (LLNode*) 0)
    {
        std::cout<<"testAddRoomToLL did not pass"<<std::endl;
        return false;
    }

    bool ok = (newList.getRoomP() == &room1);
    ok&= (middle->getRoomP() == &room2);
    ok&= (leaf->getRoomP() == &room3);

    if(ok) {std::cout<<"testAddRoomToLL passed"<<std::endl;}
    else {std::cout<<"testAddRoomToLL did not pass"<<std::endl;}

    return ok;
}

bool Tests::testContainsRoom() {
    std::cout<<"Starting testContainsRoom"<<std::endl;

    LLNode newList;
    Room room1(1, 0, false);
    Room room2(1, 0, false);
    Room room3(1, 0, false);
    Room room4(1, 0, false);
    Room room5(1, 0, false);

    newList.addRoomToLL(&room1);
    newList.addRoomToLL(&room2);
    newList.addRoomToLL(&room3);
    newList.addRoomToLL(&room4);

    bool ok = true;
    ok &= newList.containsRoom(&room1);
    ok &= newList.containsRoom(&room2);
    ok &= newList.containsRoom(&room3);
    ok &= newList.containsRoom(&room4);
    ok &= !newList.containsRoom(&room5);


    if(ok) {std::cout<<"testContainsRoom passed"<<std::endl;}
    else {std::cout<<"testContainsRoom did not pass"<<std::endl;}

    return ok;

}

bool Tests::testRemoveFromListWhenListIsEmpty() {
    std::cout<<"Starting testRemoveFromListWhenListIsEmpty"<<std::endl;

    LLNode newList;
    Room room1(1, 0, false);

    newList.removeFromList(&room1);

    bool ok = newList.isEmpty();

    if(ok) {std::cout<<"testRemoveFromListWhenListIsEmpty passed"<<std::endl;}
    else {std::cout<<"testRemoveFromListWhenListIsEmpty did not pass"<<std::endl;}

    return ok;
}

bool Tests::testRomoveElementFromASingleNodeList() {
    std::cout<<"Starting testRomoveElementFromASingleNodeList"<<std::endl;

    LLNode newList;
    Room room1(1, 0, false);
    newList.addRoomToLL(&room1);
    LLNode* iteration1 = newList.removeFromList(&room1);    //remove

    bool ok = iteration1->isEmpty();
    if(ok) {std::cout<<"testRomoveElementFromASingleNodeList passed"<<std::endl;}
    else {std::cout<<"testRomoveElementFromASingleNodeList did not pass"<<std::endl;}

    return ok;
    }

bool Tests::testRemoveRootMiddleLeafAndNonExistentFromList() {
    std::cout<<"Starting testRemoveRootMiddleAndLeafandNonExistentFromList"<<std::endl;
    LLNode newList;
    Room room1(1, 0, false);
    Room room2(2, 0, false);
    Room room3(3, 0, false);
    Room room4(4, 0, false);
    Room room5(5, 0, false);
    Room room6(6, 0, false);

    newList.addRoomToLL(&room1);
    newList.addRoomToLL(&room2);
    newList.addRoomToLL(&room3);
    newList.addRoomToLL(&room4);
    newList.addRoomToLL(&room5);

    LLNode* iteration1 = newList.removeFromList(&room3);    //remove middle
    LLNode* iteration2 = iteration1->removeFromList(&room1);    //remove root
    LLNode* iteration3 = iteration2->removeFromList(&room5);    //remove leaf
    LLNode* iteration4 = iteration3->removeFromList(&room6);    //remove non-existent

    bool ok = true;
    ok &= !iteration4->containsRoom(&room1);
    ok &= iteration4->containsRoom(&room2);
    ok &= !iteration4->containsRoom(&room3);
    ok &= iteration4->containsRoom(&room4);
    ok &= !iteration4->containsRoom(&room5);
    ok &= !iteration4->containsRoom(&room6);


    if(ok) {std::cout<<"testRemoveRootMiddleAndLeafandNonExistentFromList passed"<<std::endl;}
    else {std::cout<<"testRemoveRootMiddleAndLeafandNonExistentFromList did not pass"<<std::endl;}

    return ok;
}

bool Tests::testGetLeaf() {
    std::cout<<"Starting testGetLeaf"<<std::endl;

    Room room1(1, 0, false);
    Room room2(2, 0, false);
    Room room3(3, 0, false);

    LLNode newList;
    bool ok = (newList.getLeaf() == (LLNode*) 0);

    newList.addRoomToLL(&room1);
    ok &= (newList.getLeaf()->getRoomP() == &room1);

    newList.addRoomToLL(&room2);
    newList.addRoomToLL(&room3);
    ok &= (newList.getLeaf()->getRoomP() == &room3);

    if(ok) {std::cout<<"testGetLeaf passed"<<std::endl;}
    else {std::cout<<"testGetLeaf did not pass"<<std::endl;}

    return ok;

}

bool Tests::testReadFile() {
    std::cout<<"Starting testReadFile"<<std::endl;
    int expectedEdges[25] = {  1, 1, 0, 1, 0,
                               1, 1, 1, 0, 1,
                               0, 1, 1, 1, 0,
                               1, 0, 1, 1, 1,
                               0, 1, 0, 1, 1
                                };

    Room room1(1, 5.0f, false);
    Room room2(2, 10.0f, false);
    Room room3(3, 15.0f, false);
    Room room4(4, 20.0f, false);
    Room room5(5, 25.0f, false);
    Room expectedRooms[5] = {room1, room2, room3, room4, room5};

    Production testProduction;

    testProduction.readFile("testFile.txt");

    bool ok = true;
    ok &= (testProduction.getNumOfRooms() == 5);
    if(ok){std::cout<<"Number of rooms is correct!"<<std::endl;}

    for(int i = 0; i< testProduction.getNumOfRooms(); ++i)
    {
        AdjMat* matrixP = testProduction.getMatrix();
        for(int j = 0; j<testProduction.getNumOfRooms(); ++j)
        {
            ok&= matrixP->getEdge(i, j) == expectedEdges[5*i+j];
        }
    }
    if(ok) {std::cout<<"Matrix is correct!"<<std::endl;}
    for (int i = 0; i<testProduction.getNumOfRooms(); ++i)
    {
        Room* roomP = testProduction.getRooms() + i;
        std::cout<<"Room number is "<<roomP->getRoomNumber()<<", Room treasure is "<<roomP->getTreasure()<<", room is searched: "<< roomP->getSearched()<<std::endl;
        ok &= ((roomP->getRoomNumber() == expectedRooms[i].getRoomNumber()) && (roomP->getTreasure() == expectedRooms[i].getTreasure()) && (roomP->getSearched() == false ));
    }
    if (ok)
    {
        std::cout<<"The Rooms have correct number, treasure and searched state."<<std::endl;
        std::cout<<"testReadFile passed"<<std::endl;
    }
    else
    {std::cout<<"testReadFile did not pass"<<std::endl;}
    return ok;
}

bool Tests::testAddTreasure() {
    std::cout<<"Starting testAddTreasure"<<std::endl;

    Production testProduction;

    Room* newRoomOneP = new Room(1, 25.5f, false);
    testProduction.getToBeSearchedList()->addRoomToLL(newRoomOneP);

    testProduction.addTreasure(newRoomOneP);

    bool ok= true;

    ok&= (newRoomOneP->getRoomNumber() == 1);
    ok&= (newRoomOneP->getSearched() == true);
    ok&= (newRoomOneP->getTreasure() == 0);

    ok &= testProduction.getToBeSearchedList()->isEmpty();
    if(ok) {std::cout<<"toBeSearchedList is empty as supposed"<<std::endl;}
    else {std::cout<<"toBeSearchedList is not empty -> error!"<<std::endl;}
    ok &= (testProduction.getSearchedList()->getRoomP() == newRoomOneP);

    if(ok) {std::cout<<"testAddTreasure passed"<<std::endl;}
    else  {std::cout<<"testAddTreasure did not pass"<<std::endl;}
    return ok;
}

bool Tests::testAddAdjecentOnToBeSearched() {
    std::cout<<"Starting testAddAdjecentOnToBeSearched"<<std::endl;
    Production testProduction;

    testProduction.readFile("testFile2.txt");
    Room* rooms = testProduction.getRooms();
    rooms->setSearched(true);

    testProduction.getToBeSearchedList()->addRoomToLL(rooms+1);
    testProduction.getToBeSearchedList()->addRoomToLL(rooms+4);
    bool ok = true;
    // if we run addAdjecentOnToBeSearched on Room4, where room1 has been searched and  room2 and room 5
    // are already in to be searched, we expect the new LinkedList to contain room3
    // alongside rooms 2 and 5
    testProduction.addAjdecentOnToBeSearched(rooms+3);

    LLNode* toBeSearchedListP = testProduction.getToBeSearchedList();

    LLNode* subNode1 = toBeSearchedListP->getNextP();
    LLNode* subNode2 = subNode1->getNextP();
    ok &= (toBeSearchedListP->getRoomP() == &rooms[1]);
    ok &= (subNode1->getRoomP() == &rooms[4]);
    if (subNode2->isEmpty()) {ok = false;}
    else {ok &= (subNode2->getRoomP() == &rooms[2]);}


    if(ok) {std::cout<<"testAddAdjecentOnToBeSearched passed"<<std::endl;}
    else  {std::cout<<"testAddAdjecentOnToBeSearched did not pass"<<std::endl;}
    return ok;

}





