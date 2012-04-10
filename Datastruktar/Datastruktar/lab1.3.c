#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "simpio.h"
#include "random.h"

#define Pi 3.1415926535

void drawV(int depth, double angle, double len);
void drawPolarLine(double r, double theta);

int main(void){

	int initLength = 1;
	InitGraphics();

	// Rita stammen.
	MovePen(3, 0.2);
	DrawLine(0, 1);
	// Börja rita förgreningar...	första argumentet är djupet.
	drawV(10, 90, 1);
	
	return 0;
}

// Kanske måste ha basfall på längden? Lätt ordnat, men tycker det blir lite tråkigare.
//"If the probability of branching is a function of the length of the current branch, the process will eventually terminate as the branches get progressively shorter."
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

		// Rita linje med mindre vinkel.
		drawPolarLine(len, angle-angleV);
		// Rekursivt anrop med lägre djup och mindre längd - på VÄNSTER gren.
		drawV(depth-1, angle-angleV, len);

		
		// Rita linje med större vinkel.
		MovePen(sX, sY);
		drawPolarLine(len, angle+angleV);
		// Rekursivt anrop med lägre djup och mindre längd - på HÖGER gren.
		drawV(depth-1, angle+angleV, len);
	}
}

// Borrowed from the book Programming Abstractions in C - Eric S. Roberts.
// What it does: Draws a line to a given length on a given angle from the current position.
void drawPolarLine(double r, double theta){

	double radians;

	radians = theta / 180 * Pi;
	DrawLine(r * cos(radians), r * sin(radians));
}
