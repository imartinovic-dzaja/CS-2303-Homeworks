/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "space.h"
#define ROWS 20
#define COLUMNS 20

bool initSpace(int* corner)
{
	bool ok = true;
	for(int row = 0; row< ROWS; row++)
	{
		for(int col = 0; col < COLUMNS; col++)
		{
			*(corner+row*COLUMNS + col) = 0;
		}
	}
	return ok;
}



void printScreen(int* corner) {

    for(int row = ROWS-1; row>= 0; --row)
	{
		for(int col = 0; col <= COLUMNS-1; ++col)
		{
			printf("%d | ", (*(corner+row*COLUMNS + col)));
		}
		printf("\n");

		for(int col = 0; col < COLUMNS; col++)
		{
			printf("____");
		}
		printf("\n");
		fflush(stdout);
	}



}
