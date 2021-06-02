#include <iostream>

#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

class Stats {
private:
    int        m_numHits;
	int        m_numMisses;
	int        m_totalShots;
	double     m_hitMissRatio;

public:
    Stats();

    void incrementNumHits();
    void incrementNumMisses();
    void incrementTotalShots();
    void updateTotalShots();
    void updateHitMissRatio();

    int getNumHits();
    int getnumMisses();
    int getTotalShots();
    double getHitMissRatio();



};

class Player {
private:
    int m_playerNumber;
    Stats m_statistics;

public:
    Player(int playerNumber);

    int getPlayerNumber();
    Stats* getStatistics();

    void printStats();


};


class PlayerOne : public Player {
    public:
    PlayerOne();
};

class PlayerTwo: public Player {
public:
    PlayerTwo();
};

#endif // STATS_H_INCLUDED
