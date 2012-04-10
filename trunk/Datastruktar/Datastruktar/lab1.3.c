#include <stdio.h>
#include "graphics.h"
#include "simpio.h"

void drawV(int depth, double xP, double yP);

int main(void){

	//printf("\nwH:%l", GetWindowHeight());
	//printf("\nwH:%l", GetWindowWidth());
	int initLength = 1;
	InitGraphics();
	MovePen(3, 0.2);
	DrawLine(0, initLength);
	drawV(5, 0.1, 0.2);

	return 0;
}

void drawV(int depth, double xP, double yP){
	if (depth <= 0){
		// THEN YOU GET NOTHING
		// At last branch.
	}
	else {
		printf("\nEntering drawV with xS=%f and yS=%f", xP, yP);
		drawV(depth-1, ((xP+0.1)+0.2), ((yP+0.1))-0.2);

		GetLine();
		printf("\nPress enter to continue drawing...");

		DrawLine(xP, yP);
		MovePen(GetCurrentX()-xP, GetCurrentY()-yP);
		DrawLine(-xP, yP);
		//MovePen(GetCurrentX()-xP, GetCurrentY()-yP);
	}
}