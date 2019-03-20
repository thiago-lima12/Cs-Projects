/***********************************************************
Author: <Thiago Lima>
Date: <2/5/2019>
Effort: <1 hour>
Purpose: <this program puts a 1 in a location on a 32 bits string and then remove some of them and then displays it>
***********************************************************/
#include <stdio.h>
void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);
int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	display_32_flags(flag_holder);
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);
	display_32_flags(flag_holder);
	return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
	int pos = flag_position % 32;

	unsigned int tester = 1 << pos;

	flag_holder[0] = *flag_holder | tester; // flag_holder = 0000...000...0000  
											//        flag = 0000...000...1000
											//	0000 | 1000 = 1000

}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int tester = 1 << pos;

	tester = ~tester;           // flag = 1111...101..111

	flag_holder[0] = *flag_holder & tester; // flag_holder = 0000...000...0000  
										  //        flag = 0000...000...1000
										  //	1110 & 1000 = 0110
}

int check_flag(unsigned int flag_holder, int flag_position)
{
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

void display_32_flags(unsigned int flag_holder) {
	int i;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");

}

