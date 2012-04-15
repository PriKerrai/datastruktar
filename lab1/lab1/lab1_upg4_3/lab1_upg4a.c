/* Authors:  
Karl Sjöstrand (studentID: s117902)
Martin Nilsson (studentID: s118736)
Josef Holmer   (studentID: s117993)
*/

#include <stdio.h>
#include "genlib.h"
#include "graphics.h"
#include "mazelib.h"

/* Constants */

#define NoSolution 10000

/* typedef */

typedef struct {
	int steps;
	int pathLength;
	bool ok;
} splT;

/* Private function prototypes */

static splT SolveMaze(pointT pt, splT spl);
static pointT AdjacentPoint(pointT pt, directionT dir);
int shortestPathLength(pointT pt);

/* Main program */

int main(void)
{
	int spLen;
	string mazeFile;

	mazeFile = GetLine();
	SetPauseTime(0.001);

    InitGraphics();

    ReadMazeMap(mazeFile);

	spLen = shortestPathLength(GetStartPosition());
	if (spLen < NoSolution) printf("The shortest path is: %d\n", spLen);
	else printf("No solution was found.\n");

}

static int shortestPathLength(pointT pt){

	splT spl;
	spl.steps = 0;
	spl.pathLength = 0;
	spl.ok = FALSE;

	spl = SolveMaze(pt, spl);

	if (spl.pathLength > 0)
		return spl.pathLength;
	else
		return NoSolution;
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

static splT SolveMaze(pointT pt, splT spl)
{
    directionT dir;
	
	if (OutsideMaze(pt)){
		if (spl.steps < spl.pathLength || spl.pathLength == 0)
			spl.pathLength = spl.steps;
		spl.ok = FALSE;
		return spl;
	}
	if (IsMarked(pt)) {
		spl.ok = FALSE;
		return spl;	
	};
    MarkSquare(pt);
	spl.steps++;
    for (dir = North; dir <= West; dir++) {
        if (!WallExists(pt, dir)) {
			if ((spl = SolveMaze(AdjacentPoint(pt, dir), spl)).ok) {
				return spl;
            }
        }
    }
    UnmarkSquare(pt);
	spl.steps--;
	spl.ok = FALSE;
	return spl;
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
