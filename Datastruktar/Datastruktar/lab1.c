#include <stdio.h>
#include "simpio.h"
#include "math.h"
 
void printGrayCode(int nBits);
int getNumberOfBits(void);
string* recursion(int nBits, string* graycode);

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
	char** graycode;

	graycode = NewArray(8, char*);

	// Put some stuff into graycode.
	recursion(1, graycode);	// 1 bit, recursion too scary.

	// Printing elements in graycode.
	for(i = 0; i < 2; i++){
		printf("%i %s\n", i, graycode[i]);
	}

	FreeBlock(graycode);
}

string* recursion(int nBits, char** graycode){
		
	if(nBits == 1){ 
		graycode[0] = "0";
		graycode[1] = "1";
		return graycode;
	}
	else{
		//...g�r rekursivt anrop typ, etc... tja!
	}
}
