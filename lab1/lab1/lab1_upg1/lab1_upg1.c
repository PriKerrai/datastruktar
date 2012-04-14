#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"
 
void printGrayCode(int nBits);
int getN(void);
void buildGraycCode(int nBits, string* graycode);
bool isMeasurable(int target, int weights[], int nWeights);

// ---- start of main ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
int main(void){

	printGrayCode(getN());

	printf("\nPress enter to exit...");
	GetLine();
	return 0;
}
// ----  end of main  ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //

int getN(void){

	printf("n = ");
	return GetInteger();
}

void printGrayCode(int nBits){

	int i;
	char** graycode;

	// Input check.
	if (nBits < 1) return;

	graycode = NewArray(pow((double)2, nBits), char*);

	// Put some stuff into graycode.
	buildGraycCode(nBits, graycode);

	// Print graycode.
	for (i = 0; i < pow((double)2, nBits); i++){
		printf("%i %s\n", i, graycode[i]);
	}

	FreeBlock(graycode);
}

void buildGraycCode(int nBits, char** graycode){
		
	int i, powerOfnBits, firstHalf;

	if (nBits == 1){ 

		graycode[0] = "0";
		graycode[1] = "1";
	}
	else {

		// Build the array for nBits - 1.
		buildGraycCode(nBits-1, graycode);
		
		// Some variables - to better performance/readability of the for loops.
		powerOfnBits = pow((double)2, nBits);
		firstHalf = (powerOfnBits/2)-1;

		// Increase number of elements by adding a reversed copy of graycode to graycode.
		for (i = (powerOfnBits/2); i < powerOfnBits; i++){
			graycode[i] = graycode[firstHalf];
			firstHalf--;
		}

		// Concat "0" to first half of graycode.
		for (i = 0; i < (powerOfnBits/2); i++){
			graycode[i] = Concat("0", graycode[i]);
		}
		// Concat "1" to second half of graycode.
		for (i = (powerOfnBits/2); i < powerOfnBits; i++){
			graycode[i] = Concat("1", graycode[i]);
		}
	}
}
