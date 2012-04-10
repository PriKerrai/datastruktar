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
// Använd modulus? Pröva största möjliga vikt först?
bool isMeasurable(int target, int weights[], int nWeights){

	// basfall...
	if(nWeights == 0) return false;
	if(target - weights[0]) return true;		
	// rekursivt anrop med mindre target/nWeights?
	else{
														
	}
}


static int sampleWeights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
