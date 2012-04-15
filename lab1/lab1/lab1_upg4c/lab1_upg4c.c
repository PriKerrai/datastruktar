/*
 * File: maze.c
 * ------------
 * This program solves a maze by recursive backtracking.
 */

#include <stdio.h>
#include "genlib.h"
#include "mazelib.h"

/*
 * Constants
 * ---------
 * MazeFile -- Name of the file containing the maze
 */

#define MazeFile "example.maz"

/* Private function prototypes */

static bool SolveMaze(pointT pt);

/* Main program */

main(){
    ReadMazeMap(MazeFile);
		SetPauseTime(0.3);
    if (SolveMaze(GetStartPosition())) {
        printf("The marked squares show a solution path.\n");
    } else {
        printf("No solution exists.\n");
    }
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

static bool SolveMaze(pointT pt){
    directionT dir;
    if (OutsideMaze(pt)) return (TRUE);
    if (IsMarked(pt)) return (FALSE);
    MarkSquare(pt);
    for (dir = North; dir <= West; dir++) {
        if (!WallExists(pt, dir)) {
            if (SolveMaze(AdjacentPoint(pt, dir))) {
                return (TRUE);
            }
        }
    }
    UnmarkSquare(pt);
    return (FALSE);
}

