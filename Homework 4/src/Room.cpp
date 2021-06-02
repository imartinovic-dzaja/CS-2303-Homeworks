#include "Room.h"

Room::Room() {}

Room::Room(int roomNumber, float treasure, bool searched) {

    m_roomNumber = roomNumber;
    m_treasure = treasure;
    m_searched = searched;

}

Room::~Room() {

}

int Room::getRoomNumber() {
    return m_roomNumber;
}

float Room::getTreasure() {
    return m_treasure;
}
bool Room::getSearched() {
    return m_searched;
}

void Room::setRoomNumber(int number) {
    m_roomNumber = number;
}

void Room::setTreasure(float treasure) {
     m_treasure = treasure;
}
void Room::setSearched(bool searched) {
     m_searched = searched;
}


void Room::emptyTreasure() {
    m_treasure = 0.0f;
}

void Room::setSearched() {
    m_searched = true;
}



