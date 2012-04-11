#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"

// ---- start of main ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //
int main(void){
	static int weights[10];
	static int nWeights = 0;
	int i, totalWeight = 0;

	printf("How many weights should be used?\n");
	while((nWeights = GetInteger()) < 1 || nWeights > 10) printf("Error: Must use at least 1- up to 10 weights\nRetry: ");

	// H�mta vikter fr�n anv�ndaren
	printf("\nPlease input the weights:\n\n");
	for (i = 0; i < nWeights; i++) {
		printf("Weight %d: ", i+1);
		while((weights[i] = GetInteger()) < 1) printf("Error: Weight must weigh at least 1\nRetry: ");
	}

	// Ber�kna totala vikten av alla vikter
	for (i = 0; i < nWeights; i++)
		totalWeight = totalWeight+weights[i];
	printf("\nTotal weight is: %d\n\n", totalWeight);

	// Testa varje m�jlig vikt (fr�n 1 upp till den totala vikten)
	// och skriv ut om det givet de vikter vi har, gick att m�ta
	// eller ej
	for (i = 0; i < totalWeight; i++) {
		if (isMeasurable(i+1, weights, nWeights))
			printf("%d is measurable\n", i+1);
		else
			printf("%d is not measurable\n", i+1);
	}

	GetLine();
	return 0;
}
// ----  end of main  ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- //

bool isMeasurable(int target, int weights[], int nWeights) {

	// 'target' minus vikten p� weights[nWeights] gick j�mnt ut,
	// det gick allts� att m�ta 'target'
	if (target == 0)
		return (TRUE);
	// Slut p� vikter att testa med
	else if (nWeights < 0)
		return (FALSE);
	else if (isMeasurable(target-weights[nWeights-1], weights, nWeights-1))
		return (TRUE);
	else if (isMeasurable(target+weights[nWeights-1], weights, nWeights-1))
		return (TRUE);
	else if (isMeasurable(target, weights, nWeights-1))
		return (TRUE);
}

