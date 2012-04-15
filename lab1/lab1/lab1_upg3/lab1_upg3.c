/* Authors:  
Karl Sjöstrand (studentID: s117902)
Martin Nilsson (studentID: s118736)
Josef Holmer   (studentID: s117993)
*/

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "simpio.h"
#include "random.h"
#include "windows.h"

#define Pi 3.1415926535

void drawV(int depth, double angle, double len);
void drawPolarLine(double r, double theta);

int main(void){

	InitGraphics();

	// Draw "trunk".
	MovePen(3.5, 0.2);
	DrawLine(0, 0.8);

	// Draw tree.
	drawV(10, 90, 1);
	
	return 0;
}

void drawV(int depth, double angle, double len){

	double sX, sY, angleV;

	//Randomize();
	
	if ((depth > 0) && (RandomChance(.82))){

		// Reduce length of line.
		len *= 0.77;
		// Specify angle increment/decrement of new branches.
		angleV = 25;

		// Save initial x and y position.
		sX = GetCurrentX();
		sY = GetCurrentY();

		// Delay before each line is drawn to see the recursion. 
		Sleep(3);

		// Draw line with reduced angle.
		drawPolarLine(len, angle-angleV);
		// Recursive call continuing the LEFT branch.
		drawV(depth-1, angle-angleV, len);

		// Delay before each line is drawn to see the recursion. 
		Sleep(3);
		
		// Draw line with increased angle.
		MovePen(sX, sY);
		drawPolarLine(len, angle+angleV);
		// Recursive call continuing the RIGHT branch.
		drawV(depth-1, angle+angleV, len);
	}
}

// Draws a line of a given length, in a given angle.
void drawPolarLine(double r, double theta){

	double radians;

	radians = theta / 180 * Pi;
	DrawLine(r * cos(radians), r * sin(radians));
}
