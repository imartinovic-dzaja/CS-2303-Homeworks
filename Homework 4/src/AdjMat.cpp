/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"
#include <stdio.h>
#include <iostream>


AdjMat::AdjMat() {}

AdjMat::AdjMat(int numberOfRooms) {
    m_n = numberOfRooms;
    m_edgesP = new int[m_n * m_n];
        for (int row = 0; row < m_n; ++row)
        {
            for (int column = 0; column < m_n; ++ column)
                {
                    m_edgesP[row * m_n + column] = 0;
                }
        }
}

// for testing purposes we need this constructor as well

AdjMat::AdjMat(int numberOfRooms, int* edges) {
    m_n = numberOfRooms;
    m_edgesP = edges;
}

AdjMat::~AdjMat() {delete m_edgesP;}


int AdjMat::getEdge(int row, int col) {
    return m_edgesP[m_n*row + col];
}


void AdjMat::setEdge(int row, int col) {
    m_edgesP[m_n*row + col] = 1;
}



void AdjMat::createMainDiagonalSymmetry() {

    for(int row = 0; row<m_n; ++row)
    {
        setEdge(row, row);

		for(int col = 0; col<row; col++)
		{
               if (getEdge(row, col))
                    setEdge(col, row);
		}
    }
}

// for debugging purposes

void AdjMat::printMatrix() {

for(int row = 0; row<m_n; ++row)
    {

		for(int col = 0; col<m_n; col++)
		{
               std::cout<<getEdge(row, col)<<" ";
		}
        std::cout<<std::endl;
    }
}
