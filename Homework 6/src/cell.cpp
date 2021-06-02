#include "cell.h"

Coordinate::Coordinate() {m_row = -1; m_column = -1;}
Coordinate::Coordinate(int row, int column) {m_row = row; m_column = column;}

int Coordinate::getRow(){return m_row;}
int Coordinate::getColumn(){return m_column;}
void Coordinate::setRow(int row) {m_row = row;}
void Coordinate::setColumn(int column) {m_column = column;}
void Coordinate::setRowAndColumn (int row, int column) {m_row = row; m_column = column;}

Cell::Cell() : m_position(-1, -1) {m_symbol = 'Q';} //need default constructor to construct board, however all elements will
// be assigned a new symbol and position, so this is okay
Cell::Cell(char symbol, int row, int column) : m_position(row, column) {m_symbol = symbol;}

Coordinate* Cell::getPosition(){return &m_position;}
char Cell::getSymbol(){return m_symbol;}
void Cell::setSymbol(char symbol) {m_symbol = symbol;}
