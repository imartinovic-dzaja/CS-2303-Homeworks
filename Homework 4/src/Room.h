#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room
{
    private:
	int m_roomNumber;
	float m_treasure;
	bool m_searched;

	public:
    Room();
    Room (int, float, bool);
    ~Room();

    int getRoomNumber();
    float getTreasure();
    bool getSearched();

    void setRoomNumber(int);
    void setTreasure(float);
    void setSearched(bool);

    void emptyTreasure();
    void setSearched();
};


#endif // ROOM_H_INCLUDED
