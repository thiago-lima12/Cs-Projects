/***********************************************************
Author: <Thiago Lima>
Date: <2/3/2017>
Effort: <1 hour>
Purpose: <this program puts a 1 in a location on a 32 bits string 
and then remove some of them and then displays it>
***********************************************************/

#include <stdio.h>
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);
int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others
	//to zero by default.
		set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	display_flags(flag_holder, 5);
	printf("\n\n");
	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	display_flags(flag_holder, 5);
	return 0;
}





void set_flag(unsigned int flag_holder[], int flag_position)
{
	int r = flag_position / 32;

	int pos = flag_position % 32;

	unsigned int tester = 1 << pos;

	flag_holder[r] = flag_holder[r] | tester; // flag_holder = 0000...000...0000  
											//        flag = 0000...000...1000
											//	0000 | 1000 = 1000
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
	int r = flag_position / 32;

	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int tester = 1 << pos;

	tester = ~tester;           // flag = 1111...101..111

	flag_holder[r] = flag_holder[r] & tester; // flag_holder = 0000...000...0000  
											//        flag = 0000...000...1000
											//	1110 & 1000 = 0110

}

int check_flag(unsigned int flag_holder[], int flag_position) {

	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int tester = 1 << pos;     // flag = 0000...010...000   (shifted k positions)
		
		if ((flag_holder[0] & tester) != 0) {
			return 1;
		}
		else {
			return 0;
		}

}


void display_32_flags_as_array(unsigned int flag_holder) {
	int i;
	int x = 1;
	for (i = 0; i <= 31; i++, x++)
	{
		printf("%d", check_flag(&flag_holder, i));
		if (x % 4 == 0)
		{
			printf(" ");
		}
	}

}
void display_flags(unsigned int flag_holder[], int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		display_32_flags_as_array(flag_holder[i]);
		printf("\n");
	}
}