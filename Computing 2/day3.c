/***********************************************************
Author: Thiago Lima
Date: 1/31/2019
Effort: 30 minutes
Purpose: created a program that turns a bit in a 32 bit set 
on and checks if it is on.
***********************************************************/
#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);

int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void set_flag(int* flag_holder, int flag_position) {
	int pos = flag_position % 32;          

	unsigned int tester = 1 << pos;  

	flag_holder[0] = *flag_holder | tester; // flag_holder = 0000...000...0000  
										  //        flag = 0000...000...1000
										  //	0000 | 1000 = 1000
}

int check_flag(int flag_holder, int flag_position) {
	int pos = flag_position % 32;         

	unsigned int tester = 1 << pos;   

	flag_holder = tester & flag_holder;// flag_holder = 0000...000...1000  
									 //        flag = 0000...000...1000
									 //	1000 & 1000 = 1000 
	if (flag_holder != 0) {
		return 1;
	}
	else {
		return 0;
	}
}