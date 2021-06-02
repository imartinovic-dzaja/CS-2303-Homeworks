/*
 * marker.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

#ifndef MARKER_H_
#define MARKER_H_

typedef struct
{
   int index;
   int row;
   int col;
}Marker;

#include <stdbool.h>

Marker* placeMarker(int* corner, int row, int column, int index);
int wander(int* corner, int n, void* path);

#endif /* MARKER_H_ */
