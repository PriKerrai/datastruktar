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

	if(1) return 1;	// basfall...
	else{
		return 0;		// rekursivt anrop med mindre target/nWeights?
	}
}