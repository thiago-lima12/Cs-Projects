/***********************************************************
Author: <Thiago Lima>
Date: <2/28/2017>
Effort: <2 week>
Purpose: <to set and unset flags in a bit and store in a vector>
Interface proposal: <I think a display flag would be a good idea>
***********************************************************/
#include <stdlib.h>
#include "bit_flag.h"

struct bit_flags
{
	int size;
	int capacity;
	int* data;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) 
{
	int i = 0;
	Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	int r = number_of_bits / 32;

	if (pBit_flags != NULL)
	{
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = number_of_bits * 2;
		pBit_flags->data = (int*)malloc(sizeof(int) * (pBit_flags->capacity / 32));
		
		if (pBit_flags->data == NULL)
		{
			free(pBit_flags);
			return NULL;
		}
	}
	
	unsigned int flag = 0;
	for (int i = 0; i < pBit_flags->capacity / 32; i++)
	{
		pBit_flags->data[i] = flag;
	}
	
	return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int* temp;
	int i = 0;
	int capa_temp;
	
	int r = flag_position / 32;

	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int flag = 1;   // flag = 0000.....00001

	flag = flag << pos;      // flag = 0000...010...000   (shifted k positions)

	capa_temp = pBit_flags->capacity;
	
	while (capa_temp <= flag_position) 
	{
		capa_temp += 32;
	}
	
	int x = capa_temp / 32;

	while (flag_position >= pBit_flags->capacity) //no room
	{
		temp = (int*)malloc(sizeof(int) * (pBit_flags->capacity + 32));
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i <= (pBit_flags->capacity / 32); i++)
		{
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		int x = capa_temp / 32;
		int z = pBit_flags->capacity / 32;
		unsigned int flag_2 = 0;
		
		while (z <= x)
		{
			
			pBit_flags->data[z] = flag_2;
			z++; 
		}
		pBit_flags->capacity += 32;
	}
	if (pBit_flags->size < flag_position)
	{
		pBit_flags->size = flag_position;
	}
	pBit_flags->data[r] = pBit_flags->data[r] | flag;
	return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int r = flag_position / 32;

	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int flag = 1;   // flag = 0000.....00001

	flag = flag << pos;      // flag = 0000...010...000   (shifted k positions)

	flag = ~flag;           // flag = 1111...101..111
													 // flag_holder = 0010...010...0010  
	pBit_flags->data[r] = pBit_flags->data[r] & flag;//        flag = 1111...101...1111

	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) 
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int r = flag_position / 32;

	int pos = flag_position % 32;          // pos = bit position in A[i]

	unsigned int flag = 1;   // flag = 0000.....00001
	flag = flag << pos;      // flag = 0000...010...000   (shifted k positions)

	if(flag_position > pBit_flags->capacity)
	{
		return -1;
	}
	if ((pBit_flags->data[r] & flag) != 0) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	
}

int bit_flags_get_size(BIT_FLAGS hBit_flags) 
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*) *phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}
