#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"
 
void printGrayCode(int nBits);
int getN(void);
void buildGraycCode(int nBits, string* graycode);

// ---- start of main ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
int main(void){

	while (1) {
		printGrayCode(getN());
		printf("\n");
	}

	// Wait.
	printf("\nWaiting...");
	GetLine();
	return 0;
}
// ----  end of main  ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
// Anv�nd modulus? Pr�va st�rsta m�jliga vikt f�rst?
bool isMeasurable(int target, int weights[], int nWeights){

	if(1) return 1;	// basfall...
	else{
		return 0;		// rekursivt anrop med mindre target/nWeights?
	}
}


static int sampleWeights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
