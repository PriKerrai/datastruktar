#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"

// ---- start of main ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
int main(void){

	// Wait.
	printf("\nWaiting...");
	GetLine();
	return 0;
}
// ----  end of main  ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
// Använd modulus? Pröva största möjliga vikt först?
bool isMeasurable(int target, int weights[], int nWeights){

	// basfall... 
	if(nWeights == 0) return FALSE;
	if(target - weights[0]) return TRUE;		
	// rekursivt anrop med mindre target/nWeights?
	else{
														
	}
}


static int sampleWeights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
