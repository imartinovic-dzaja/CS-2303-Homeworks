#include <string.h>

#ifndef WATERCRAFT_H_INCLUDED
#define WATERCRAFT_H_INCLUDED

class Watercraft {
private:
    char m_symbol;
    short m_length;
    char* m_name;

public:
    Watercraft();
    short getLength();
    char getSymbol();
    char* getName();

protected:
    Watercraft(char symbol, short length, char* name);


};

class Carrier: public Watercraft {
public:
    Carrier();
};

class Battleship: public Watercraft{
public:
    Battleship();
};

class Cruiser: public Watercraft {
public:
    Cruiser();
};

class Submarine: public Watercraft {
public:
    Submarine();
};

class Destroyer: public Watercraft {
public:
    Destroyer();

};


#endif // WATERCRAFT_H_INCLUDED
