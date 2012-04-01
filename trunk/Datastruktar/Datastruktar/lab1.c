#include <stdio.h>
#include "simpio.h"
 
void PrintGrayCode(int nBits);
int getNumberOfBits(void);
int* recursion(int nBits, int* graycode);

int main(void){
	int n;
	
	
	//...

	// Wait.
	GetLine();
	return 0;
}

int GetNumberOfBits(void){

	printf("How many bits ey!?");
	return GetInteger();
}

void PrintGrayCode(int nBits){

	int i;
	int graycode[(nBits^2)];

	for(i = 0; i < (nBits^2); i++){
		printf("%i %i", i, graycode[i]);
	}
}

int* recursion(int nBits, int* graycode){
		
	if(nBits == 1){ 
		//...gör liten lista eller nåt
	}
	else{
		//...gör rekursivt anrop typ, etc... tja!
	}
}