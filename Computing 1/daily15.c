/*
int main(int argc, char * argv[])
/***********************************************
Author: <Thiago Lima>
Date: <3/28/2016>

Purpose: <this number switches the values of a and b if b is larger than a.>

Explanation for your function:  <the function works by putting the address of a and b 
to the function, which uses the pointer to chage a and b in the address and swaps the 
address of the number and changing them globally.>

Time Spent: <1 hour>
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//function prototype here
void biggest(int *x, int *y);



int main(int argc, const char * argv[]) {
	int a, b;

	printf("Please enter two integers: ");
	scanf("%d,%d", &a, &b);  //enter two integers separated by a ,

	printf("a is: %d\n", a);
	printf("b is: %d\n", b);
	
	if (a < b) {
		biggest(&a, &b);
	}
	/*function call to make sure that
	(1) variable a stores the larger value
	(2) variable b stores the smaller value after the function is called
	*/

	printf("a now becomes the bigger one and the value is: %d\n", a);
	printf("b now becomes the smaller one and the value is: %d\n", b);

	return 0;
}

//function definition here
void biggest(int *x, int *y)
{
	int z;
	
		z = *x;
		*x = *y;
		*y = z;
	

}