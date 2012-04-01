#include <stdio.h>
#include "simpio.h"
 
void PrintGrayCode(int nBits);

main()
{
	getNumberOfBits();

}

int getNumberOfBits(void) {

	 int nBits;
     printf("How many bits ey!?");
	 nBits = GetInteger();
	 return nBits;

}