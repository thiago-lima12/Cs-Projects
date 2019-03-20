/***********************************************************
Author: Thiago Lima
Date: 1/29/2019
Effort: 20 minute
Purpose: to wrote a program that will left shift a number in a loop and 
save it then repeat that process.
***********************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	unsigned int x = 1;
	for (int i = 0; i < 32; ++i) {
		printf("%d: %u\n",i, x);
		x <<= 1;
	}
	return 0;
}