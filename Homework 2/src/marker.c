/*
 * marker.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#include "marker.h"
#define ROWS 20
#define COLUMNS 20

Marker* placeMarker(int* corner, int row, int column, int index)
{
	Marker* mP = (Marker*) malloc (sizeof(Marker));

	mP->index = (index % 10);
	mP->col = (column % COLUMNS);
	mP->row = (row % ROWS);

    *(corner+row*COLUMNS + column) = index%10;

	return mP;
}

int wander(int* corner, int n, void* path) {
    int length = 0;
    srand(time(0));

    for (int i=1; i<=n; ++i) {
        unsigned long randomRow = rand()%ROWS;   // used for finding a random row
        unsigned long randomColumn = rand()%COLUMNS;   // used for finding a random column

       savePayload(path, (Payload*)  placeMarker(corner, randomRow, randomColumn, i));

        length++;
    }
    return length;
}




