#include <stdio.h>
#include "graphics.h"
#include "simpio.h"

void drawV(int depth, double xP, double yP);

int main(void){

	//printf("\nwH:%f", GetWindowHeight());
	//printf("\nwH:%f", GetWindowWidth());
	int initLength = 1;
	InitGraphics();

	// Rita stammen.
	MovePen(3, 0.2);
	DrawLine(0, initLength);
	// Börja rita förgreningar...	första argumentet är djupet.
	drawV(9, 0.1, 0.1);

	return 0;
}

void drawV(int depth, double xP, double yP){
	printf("\nEnter drawV(%i, %f, %f)", depth, xP, yP);
	if (depth <= 0){
		// THEN YOU GET NOTHING
		// Depth has been reached.
	}
	else {
		drawV(depth-1, (xP+0.05), (yP+0.05));

		//GetLine();
		//printf("\nPress enter to continue drawing...");

		printf("\nDrawing... (%i, %f, %f) ...", depth, xP, yP);
		GetLine();
		DrawLine(xP, yP);
		MovePen(GetCurrentX()-xP, GetCurrentY()-yP);
		DrawLine(-xP, yP);
		//MovePen(GetCurrentX()-xP, GetCurrentY()-yP);
	}
}