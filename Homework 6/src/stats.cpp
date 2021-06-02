#include "stats.h"


Stats::Stats() {
    m_numHits = 0;
    m_numMisses = 0;
    m_totalShots = 0;
    m_hitMissRatio = -1;
}

void Stats::incrementNumHits() {++m_numHits;}
void Stats::incrementNumMisses() {++m_numMisses;}
void Stats::incrementTotalShots() {++m_totalShots;}
void Stats::updateTotalShots() {m_totalShots = m_numHits + m_numMisses;}
void Stats::updateHitMissRatio() {
    if (m_numMisses != 0) {m_hitMissRatio= 100* (double)m_numHits/m_numMisses;}
    else {m_hitMissRatio = -1;}}

int Stats::getNumHits() {return m_numHits;}
int Stats::getnumMisses() {return m_numMisses;}
int Stats::getTotalShots() {return m_totalShots;}
double Stats::getHitMissRatio() {return m_hitMissRatio;}


int Player::getPlayerNumber() {return m_playerNumber;}
Stats* Player::getStatistics() {return &m_statistics;}

Player::Player(int playerNumber) {
    m_playerNumber = playerNumber;
}

void Player::printStats() {

    std::cout<<"+===================================================\n";
    std::cout<<"|                    PLAYER STATS                   \n";
    std::cout<<"+---------------------------------------------------\n";
    std::cout<<"| PLAYER "<<m_playerNumber<<": "<<m_statistics.getNumHits()<<" hits                                \n";
    std::cout<<"|            "<<m_statistics.getnumMisses()<<" misses                              \n";
    std::cout<<"|            "<<m_statistics.getTotalShots()<<" total shots                         \n";
    if (m_statistics.getHitMissRatio() == -1) {
    std::cout<<"|            "<<"n/a"<<" hit/miss ratio                 \n";}
    else
    {std::cout<<"|            "<<m_statistics.getHitMissRatio()<<" hit/miss ratio                 \n";}

}

PlayerOne::PlayerOne() : Player (1) {}
PlayerTwo::PlayerTwo() : Player (2) {}
