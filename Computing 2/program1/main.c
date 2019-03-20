#include <stdio.h>
#include <stdlib.h>
#include "bit_flag.h"

int main(int argc, char* argv[])
{
	int i = 0;
	BIT_FLAGS hBit_flags = NULL;
	hBit_flags = bit_flags_init_number_of_bits(16);
	

	bit_flags_set_flag(hBit_flags, 17);
	printf("size: %d\n", bit_flags_get_size(hBit_flags));
	printf("capacity: %d\n", bit_flags_get_capacity(hBit_flags));
	bit_flags_set_flag(hBit_flags, 23);
	printf("size: %d\n", bit_flags_get_size(hBit_flags));
	printf("capacity: %d\n", bit_flags_get_capacity(hBit_flags));
	bit_flags_set_flag(hBit_flags, 54);
	printf("size: %d\n", bit_flags_get_size(hBit_flags));
	printf("capacity: %d\n", bit_flags_get_capacity(hBit_flags));
	bit_flags_set_flag(hBit_flags, 82);
	printf("size: %d\n", bit_flags_get_size(hBit_flags));
	printf("capacity: %d\n", bit_flags_get_capacity(hBit_flags));
	bit_flags_set_flag(hBit_flags, 200);
	bit_flags_unset_flag(hBit_flags, 200);

	printf("size: %d\n", bit_flags_get_size(hBit_flags));
	printf("capa: %d\n", bit_flags_get_capacity(hBit_flags));
	printf("%d\n", bit_flags_check_flag(hBit_flags, 17));

	for (i = 0; i <= bit_flags_get_capacity(hBit_flags) ; i++)
	{
		printf("%d", bit_flags_check_flag(hBit_flags, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
		if (i % 32 == 0)
		{
			printf("\n");
		}
	}
	

	bit_flags_destroy(&hBit_flags);
	
	return 0;
}