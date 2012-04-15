/* Authors:  
Karl Sjöstrand (studentID: s117902)
Martin Nilsson (studentID: s118736)
Josef Holmer   (studentID: s117993)
*/

#include <stdio.h>
#include "genlib.h"
#include "graphics.h"
#include "mazelib.h"

/* Private function prototypes */

static bool SolveMaze(pointT pt);
static pointT AdjacentPoint(pointT pt, directionT dir);
static bool SolveMazeNoUnmark(pointT pt);

static int solveMazeCalls;

/* Main program */

int main(void)
{
	string mazeFile;
	
	//mazeFile = "unmark.maz";
	mazeFile = GetLine();

    InitGraphics();

	
	SetPauseTime(0.001);
    ReadMazeMap(mazeFile);
	solveMazeCalls = 0;
    if (SolveMaze(GetStartPosition())) {
        printf("Number of calls to function when unmarking: %i\n", solveMazeCalls);
    } else {
        printf("No solution exists.\n");
    }

	SetPauseTime(0.1);
	ReadMazeMap(mazeFile);
	solveMazeCalls = 0;
	if (SolveMazeNoUnmark(GetStartPosition())) {
        printf("Number of calls to function when there is no unmarking: %i\n", solveMazeCalls);
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

static bool SolveMaze(pointT pt)
{
    directionT dir;

	solveMazeCalls++;

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

static bool SolveMazeNoUnmark(pointT pt)
{
    directionT dir;

	solveMazeCalls++;

    if (OutsideMaze(pt)) return (TRUE);
    if (IsMarked(pt)) return (FALSE);
    MarkSquare(pt);
    for (dir = North; dir <= West; dir++) {
        if (!WallExists(pt, dir)) {
            if (SolveMazeNoUnmark(AdjacentPoint(pt, dir))) {
                return (TRUE);
            }
        }
    }
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
