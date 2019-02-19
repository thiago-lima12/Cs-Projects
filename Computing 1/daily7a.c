/*
Thiago Lima 
9/221/2015
if you put a number too big it will run the program, then it will put the end results and a few result before it, but 
they will be only limited number of results before the end results.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void recursive_down_to_zero(int num);
void recursive_up_to_int(int num, int num2);
int main(int argc, char * argv[])
{
	int x;
	scanf("%d",&x);
	int number;
	int number2 = 0;
	printf("Enter a positive integer:\n");
	scanf("%d", &number);
	recursive_down_to_zero(number);
	recursive_up_to_int(number,number2);
}
void recursive_down_to_zero(int num)
{
	if (num >= 1) {	
		num -= 1;
		printf("%d\n", num);
		recursive_down_to_zero(num);
	}
	else {
		printf("****\n");
	}
}
void recursive_up_to_int(int num,int num2)
{
	
	if (num>=num2) {
		printf("%d\n", num2);
		num2 += 1;
		recursive_up_to_int(num,num2);
	}
	else {
	}
}