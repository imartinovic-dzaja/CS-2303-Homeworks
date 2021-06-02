#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED


class Coordinate {
private:
	int m_row;
	int m_column;

public:
    Coordinate();
    Coordinate(int row, int column);

    int getRow();
    int getColumn();
    void setRow(int row);
    void setColumn(int column);
    void setRowAndColumn (int row, int column);
};

class Cell {

private:
	char m_symbol;
	Coordinate m_position;

public:
    Cell();
    Cell(char symbol, int row, int column);

    Coordinate* getPosition();
    char getSymbol();


    void setSymbol(char symbol);
};


#endif // CELL_H_INCLUDED
