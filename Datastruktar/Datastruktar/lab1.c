#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"
 
void printGrayCode(int nBits);
int getNumberOfBits(void);
void recursion(int nBits, string* graycode);
char* reverseString(char* str);

int main(void){
	printf("%s\n", reverseString("karl"));
	//CURRENTLY HARDCODED FOR MAX 3BIT, 8 element sized array, holding the graycode........
	printGrayCode(getNumberOfBits());

	// Wait.
	printf("\nWaiting...");
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
	recursion(nBits, graycode);	// 1 bit, recursion too scary.

	// Printing elements in graycode.
	for (i = 0; i < pow((double)2, nBits); i++){
		printf("%i %s\n", i, graycode[i]);
	}

	FreeBlock(graycode);
}

void recursion(int nBits, char** graycode){
		
	int i, powerOfnBits;

	if (nBits == 1){ 

		graycode[0] = "0";
		graycode[1] = "1";
	}
	else {	//...gör rekursivt anrop typ, etc... tja!

		recursion(nBits-1, graycode);
		
		powerOfnBits = pow((double)2, nBits);	// totalt antal element i yttersta vektorn.

		for (i = (powerOfnBits/2); i < powerOfnBits; i++){	// for second half
			graycode[i] = reverseString(graycode[i]);
		}

		for (i = 0; i < (powerOfnBits/2); i++){				// for first half
			graycode[i] = Concat("0", graycode[i]);
		}
		for (i = (powerOfnBits/2); i < powerOfnBits; i++){	// for second half
			graycode[i] = Concat("1", graycode[i]);
		}
	}
}

char* reverseString(char* str){
	if (str[0] == '\0') return "";
	else {
		return Concat(reverseString(str + 1), CharToString(str[0]));
	}
}
