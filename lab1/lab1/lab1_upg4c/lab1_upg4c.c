/*
 * File: maze.c
 * ------------
 * This program solves a maze by recursive backtracking.
 */

#include <stdio.h>
#include "genlib.h"
#include "graphics.h"
#include "mazelib.h"

/*
 * Constants
 * ---------
 * MazeFile -- Name of the file containing the maze
 */

#define MazeFile "example.maz"
#define MaxPath 50

/* Private function prototypes */

static bool SolveMaze(pointT pt, pointT* path, int len);
static pointT AdjacentPoint(pointT pt, directionT dir);
int FindPath(pointT pt, pointT path[], int maxPathSize);
int pathLen(pointT path[]);
void reverseSort(pointT* path, int length);

/* Main program */
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
main()
{
	pointT path[MaxPath];
	int i, len;
	string mazeFile;

	mazeFile = "pathlen.maz";
	//MazeFile = GetLine();


	// Initialize the vector with -1 as the x-cordinate, to surely measure length of the saved path using function pathLen.
	for (i = 0; i < MaxPath; i++){
		path[i].x = -1;
	}

	SetPauseTime(0.1);
	InitGraphics();
	ReadMazeMap(MazeFile);

	len = FindPath(GetStartPosition(), path, MaxPath);

	if (len == 0) {
		printf("No solution exists.\n");
	} 
	else {
		//reverseSort(path, pathLen(path));
		printf("The following path is a solution:\n");
		for (i = 0; i < len; i++) {
			printf(" (%d, %d)\n", path[i].x, path[i].y);
		}
	}
	GetLine();
}
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

int pathLen(pointT path[]){

	int len = 0;

	while (path[len].x > -1){
		len++;
	}

	return len;
}

void reverseSort(pointT path[], int length) {
	int i;
	pointT tmp;

	for (i = 0; i < length; i++) {
	  tmp = path[i];
	  path[i] = path[length-(i+1)];
	  path[length-(i+1)] = tmp;
	  printf("length-(i+1)=%i\n", length-(i+1));
	}
}

int FindPath(pointT pt, pointT path[], int maxPathSize){
	
	int len = 0;

	SolveMaze(pt, path, len);
	return pathLen(path);
}

/*
 * Function: SolveMaze
 * Usage: if (SolveMaze(pt)) . . .
 * -------------------------------
 * This function attempts to generate a solution to the current
 * maze from point pt.  SolveMaze returns TRUE if the maze has
 * a solution and FALSE otherwise.  The implementation uses
 * recursion to solve the submazes that result from marking the
 * current square and moving one step along each open passage.
 */

static bool SolveMaze(pointT pt, pointT path[], int len)
{
	directionT dir;

	if (OutsideMaze(pt)){
		path[len].x = pt.x;
		path[len].y = pt.y;
		len++;
		return (TRUE);
	}

	if (IsMarked(pt)){
		len--;
		return (FALSE);
	}

    MarkSquare(pt);
	path[len].x = pt.x;
	path[len].y = pt.y;
	len++;

    for (dir = North; dir <= West; dir++){
        if (!WallExists(pt, dir)) {
            if (SolveMaze(AdjacentPoint(pt, dir), path, len)) {
				path[len].x = AdjacentPoint(pt, dir).x;
				path[len].y = AdjacentPoint(pt, dir).y;
				len++;
                return (TRUE);
            }
        }
    }

	len--;
    return (FALSE);
}

/*
 * Function: AdjacentPoint
 * Usage: newpt = AdjacentPoint(pt, dir);
 * --------------------------------------
 * This function returns the pointT that results from moving
 * one square from pt in the direction specified by dir.  For
 * example, if pt is the point (1,1), AdjacentPoint(pt, East)
 * would return the point (2,1).
 */

static pointT AdjacentPoint(pointT pt, directionT dir)
{
    pointT newpt;

    newpt = pt;
    switch (dir) {
      case North: newpt.y++; break;
      case East:  newpt.x++; break;
      case South: newpt.y--; break;
      case West:  newpt.x--; break;;
    }
    return (newpt);
}
