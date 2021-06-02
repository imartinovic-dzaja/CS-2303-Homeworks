/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"
#include <stdio.h>

void initMatrix(AdjMat* adjMP)
{
	int ncols = adjMP->n;
	adjMP->edgesP = (int*) malloc(ncols * ncols *sizeof (int));

	for(int row = 0; row<ncols; ++row)

		for(int col = 0; col<ncols; col++)
		{
			*((adjMP->edgesP)+(row*ncols)+col)= 0;
		}
}


void setEdge(AdjMat* adjMP, int row, int col)
{

	int ncols = adjMP->n;
	int* arrayBeginning = adjMP->edgesP;
	*(arrayBeginning + (ncols*row) +col) = 1;
	*(arrayBeginning + (ncols*col) + row) = 1;
}
int getEdge(AdjMat* adjMP, int row, int col)
{

	int ncols = adjMP->n;

	int* arrayBeginning = adjMP->edgesP;

	return *(arrayBeginning + (ncols*row) +col) ;
}

void createMainDiagonalSymmetry(AdjMat* matrixP) {
    int ncols = matrixP ->n;
    int* edges = matrixP ->edgesP;

    for(int row = 0; row<ncols; ++row)
    {
        setEdge(matrixP, row, row);

		for(int col = 0; col<row; col++)
		{
               if (getEdge(matrixP, row, col))
                    setEdge(matrixP, col, row);
		}
    }
}
