#include "Watercraft.h"

Watercraft::Watercraft() {}

 Watercraft::Watercraft(char symbol, short length, char* name)
 {
    m_symbol = symbol;
    m_length = length;
    m_name = name;
}

short Watercraft::getLength() {return m_length;}
char Watercraft::getSymbol() {return m_symbol;}
char* Watercraft::getName() {return m_name;}

Carrier::Carrier() : Watercraft('c', 5, (char *)"Carrier") {}

Battleship::Battleship() : Watercraft('b', 4, (char *)"Battleship") {}

Cruiser::Cruiser() : Watercraft('c', 3, (char *)"Cruiser") {}

Submarine::Submarine() : Watercraft('s', 3, (char *)"Submarine") {}

Destroyer::Destroyer() : Watercraft('d', 2, (char *)"Destroyer") {}


