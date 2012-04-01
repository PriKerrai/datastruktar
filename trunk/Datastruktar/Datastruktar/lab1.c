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

	printf("n = ");
	return GetInteger();
}

void printGrayCode(int nBits){

	int i;
	int* graycode;

	graycode = NewArray(8, int);

	// Put some good stuff into graycode array.
	recursion(1, graycode);

	// Printing.
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
		//...g�r rekursivt anrop typ, etc... tja!
	}
}
