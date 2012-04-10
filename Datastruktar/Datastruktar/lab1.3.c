#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "simpio.h"

#define Pi 3.1415926535

void drawV(int depth, double angle, double len);
void drawPolarLine(double r, double theta);

int main(void){

	int initLength = 1;
	InitGraphics();

	// Rita stammen.
	MovePen(3, 0.2);
	// Börja rita förgreningar...	första argumentet är djupet.
	//drawV(9, 30, 0.5);
	
	return 0;
}

// 0.2
void drawV(int depth, double angle, double len){
	if (depth <= 0){
		// Basfall.
	}
	else {

		// Rita linje med mindre vinkel
		drawPolarLine(len-0.2, angle-30);
		// Rekursivt anrop med lägre djup och mindre längd - på VÄNSTER gren
		//...

		// Rita linje med större vinkel
		drawPolarLine(len-0.2, angle+30);
		// 
		//...
		// Rekursivt anrop med lägre djup och mindre längd - på HÖGER gren
		//...
	}
}

void drawPolarLine(double r, double theta){

	double radians;

	radians = theta / 180 * Pi;
	DrawLine(r * cos(radians), r * sin(radians));
}

// 0.1
/*void drawV(int depth, double xP, double yP){
	printf("\nEnter drawV(%i, %f, %f)", depth, xP, yP);
	if (depth <= 0){
		// THEN YOU GET NOTHING
		// Depth has been reached. Going back...
	}
	else {
		
		//GetLine();
		//printf("\nPress enter to continue drawing...");

		printf("\nDrawing... (%i, %f, %f) ...", depth, xP, yP);
		//GetLine();
		DrawLine(xP, yP);
		MovePen(GetCurrentX()-xP, GetCurrentY()-yP);
		DrawLine(-xP, yP);
		//xP = xP - (xP/2);
		//yP = yP + (yP/2);
		drawV(depth-1, (xP*0.65), (yP*0.65));
	}
}*/

