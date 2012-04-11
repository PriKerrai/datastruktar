#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"

// ---- start of main ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
int main(void){
	static int weights[10];
	static int nWeights = 0;
	int i, totalWeight = 0;

	// H�mta vikter fr�n anv�ndaren
	printf("Please input up to 10 weights to measure:\n\n");
	for (i = 0; i < 10; i++) {
		printf("Weight %d: ", i+1);
		while((weights[i] = GetInteger()) < 1) printf("Error: Weight must weigh at least 1\nRetry: ");
		nWeights++;
	}

	// Ber�kna totala vikten av alla vikter
	for (i = 0; i < nWeights; i++)
		totalWeight = totalWeight+weights[i];
	printf("\nTotal weight is: %d", totalWeight);

	// Testa varje m�jlig vikt (fr�n 1 upp till den totala vikten)
	// och skriv ut om det givet de vikter vi har, gick att m�ta
	// eller ej.
	for (i = 0; i < totalWeight; i++) {
		if (isMeasurable(i, weights, nWeights))
			printf("%d is measurable");
		else
			printf("%d is not measurable");
	}

	GetLine();
	return 0;
}
// ----  end of main  ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //

// Anv�nd modulus? Pr�va st�rsta m�jliga vikt f�rst?
bool isMeasurable(int target, int weights[], int nWeights){

	// basfall... 
	if(nWeights == 0)
		return FALSE;
	if(target - weights[0])
		return TRUE;
	// rekursivt anrop med mindre target/nWeights?
	else{
		
	}
}

