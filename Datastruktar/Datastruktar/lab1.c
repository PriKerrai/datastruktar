#include <stdio.h>
#include "simpio.h"
#include "math.h"
 
void printGrayCode(int nBits);
int getNumberOfBits(void);
int* recursion(int nBits, int* graycode);

int main(void){

	//CURRENTLY HARDCODED FOR 3BIT, 8 element sized array, holding the graycode........
	printGrayCode(getNumberOfBits());

	// Wait.
	GetLine();
	return 0;
}

int getNumberOfBits(void){

	printf("How many bits ey!? ");
	return GetInteger();
}

void printGrayCode(int nBits){

	int i;
	int* graycode;
	graycode = NewArray(8, int);

	// LÄGGER IN LITE VÄRDEN FÖR Å TESTA ARRAY
	graycode[3] = 9;
	graycode[2] = 8;

	for(i = 0; i < 8; i++){
		printf("%d %d\n", i, graycode[i]);
	}
}

int* recursion(int nBits, int* graycode){
		
	if(nBits == 1){ 
		graycode[0] = 0;
		graycode[1] = 1;
		return graycode;
	}
	else{
		//...gör rekursivt anrop typ, etc... tja!
	}
}
