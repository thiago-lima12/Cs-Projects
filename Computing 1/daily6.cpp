/***********************************************
Author:	<thiago lima>
Date:	<9/16/2016>
Purpose:	<to use and undertstand + * / % >

Time	Spent:	<10 minutes>
***********************************************/

#include <stdio.h>

int main(int argc, char * argv[]) {

	int num1 = 100;
	int num2 = 10;
	int num3 = 16;
	int num4 = 4;

	printf("the first number is:%d\n", num1);
	printf("the second number is:%d\n", num2);
	printf("the third number is:%d\n", num3);
	printf("the last number is:%d\n", num4);

	int num1A = num1 + num2;
	int num2A = num1 * num3;
	int num3A = num2 / num4;
	int num4A = num2 % num4;

	printf("the the sum of 100 and 10 is:%d\n", num1A);
	printf("the product of 100 and 16 is:%d\n", num2A);
	printf("the quotient of 10 divide by 4 is:%d\n", num3A);
	printf("the remainder of 10 divide by 4 is:%d\n", num4A);
}