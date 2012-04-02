#include <stdio.h>
#include "simpio.h"
#include "math.h"
#include "strlib.h"
 
void printGrayCode(int nBits);
int getNumberOfBits(void);
void recursion(int nBits, string* graycode);
char* reverseString(char* str);
char** reverseStringArray(char** strA);

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

	graycode = NewArray(pow((double)2, nBits), char*);

	// Put some stuff into graycode.
	recursion(nBits, graycode);	// 1 bit, recursion too scary.

	// Printing elements in graycode.
	for (i = 0; i < pow((double)2, nBits); i++){
		printf("%i %s\n", i, graycode[i]);
	}

	FreeBlock(graycode);
}

void recursion(int nBits, char** graycode){
		
	int i, powerOfnBits, firstHalf;

	if (nBits == 1){ 

		graycode[0] = "0";
		graycode[1] = "1";
	}
	else {

		// Build the array for nBits - 1.
		recursion(nBits-1, graycode);
		
		// Some variables
		powerOfnBits = pow((double)2, nBits);	// totalt antal element i vektorn för nBits.
		firstHalf = (powerOfnBits/2)-1;

		// Concat a reversed copy of graycode to graycode.
		for (i = (powerOfnBits/2); i < powerOfnBits; i++){	// for second half - (2-3) 2bit
			graycode[i] = graycode[firstHalf];
			firstHalf--;
		}

		// Concat "0" to first half of graycode.
		for (i = 0; i < (powerOfnBits/2); i++){				// for first half - (0-1) 2bit
			graycode[i] = Concat("0", graycode[i]);
		}
		// Concat "1" to second half of graycode.
		for (i = (powerOfnBits/2); i < powerOfnBits; i++){	// for second half - (2-3) 2bit
			graycode[i] = Concat("1", graycode[i]);
		}
	}
}

//works.
char* reverseString(char* str){
	if (str[0] == '\0') return "";
	else {
		return Concat(reverseString(str + 1), CharToString(str[0]));
	}
}

//not finished.
char** reverseStringArray(char** strA, int len){
	
	int i;

	for (i = 0; i < len; i++){

	}

	return strA;
}
