#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

typedef struct hold
{
	int priority;
	int data;
	int ticket;
};
typedef struct hold Hold;

struct queue
{
	Hold* item;
	int size;
	int capacity;
	int ticket_count;
};

typedef struct queue Queue;

void fix_up(PRIORITY_QUEUE hQueue, int index)
{
	int index_of_parent;
	Hold temp;
	
	Queue* pQueue = (Queue*)hQueue;
	index_of_parent = (index - 1) / 2;
	

	if (index >= 1 && pQueue->item[index].priority > pQueue->item[index_of_parent].priority)
	{
		temp = pQueue->item[index];
		pQueue->item[index] = pQueue->item[index_of_parent];
		pQueue->item[index_of_parent] = temp;
		fix_up(hQueue, index_of_parent);
	}
}

void fix_down(PRIORITY_QUEUE hQueue, int index, int size)
{
	Queue* pQueue = (Queue*)hQueue;
	int index_of_left_child;
	int index_of_right_child;
	int index_of_larger_child = size;
	Hold temp;

	index_of_left_child = index * 2 + 1;
	index_of_right_child = index * 2 + 2;

	if (index_of_right_child < size)  
	{
		if (pQueue->item[index_of_left_child].priority > pQueue->item[index_of_right_child].priority)
		{
			index_of_larger_child = index_of_left_child;
		}
		else
		{
			index_of_larger_child = index_of_right_child;
		}
	}
	else if (index_of_left_child < size) 
	{
		index_of_larger_child = index_of_left_child;
	}

	if (index_of_larger_child < size && pQueue->item[index_of_larger_child].priority > pQueue->item[index].priority)
	{
		temp = pQueue->item[index];
		pQueue->item[index] = pQueue->item[index_of_larger_child];
		pQueue->item[index_of_larger_child] = temp;
		fix_down(hQueue, index_of_larger_child, size);
	}

}


PRIORITY_QUEUE priority_queue_init_default(void)
{
	Queue* pQueue;
	pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue != NULL)
	{
		pQueue->capacity = 8;
		pQueue->size = 0;
		pQueue->ticket_count = 0;
		pQueue->item = (Hold*)malloc(sizeof(Hold) * (pQueue->capacity + 1));
		if (pQueue->item == NULL)
		{
			free(pQueue);
			pQueue = NULL;
		}

	}
	return pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	Queue* pQueue = (Queue*)hQueue;
	Hold* temp;
	int i;


	if (pQueue->size >= pQueue->capacity) 
	{
		temp = (Hold*)malloc(sizeof(Hold) * pQueue->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pQueue->size; i++)
		{
			temp[i].data= pQueue->item[i].data;
			temp[i].priority = pQueue->item[i].priority;
			temp[i].ticket = pQueue->item[i].ticket;
		}
		pQueue->capacity *= 2;
		free(pQueue->item);
		pQueue->item = temp;
	}
	pQueue->item[pQueue->size].data = data_item;
	pQueue->item[pQueue->size].priority = priority_level;
	pQueue->item[pQueue->size].ticket = pQueue->ticket_count;
	pQueue->size++;
	pQueue->ticket_count++;

	fix_up(pQueue,pQueue->size);
	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;

	if (priority_queue_is_empty(hQueue))
	{
		return FAILURE;
	}
	pQueue->item[0] = pQueue->item[pQueue->size - 1];
	pQueue->size--;
	fix_down(pQueue, 0, pQueue->size);
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status)
{
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue->size != 0)
	{
		return pQueue->item[0].data;
	}
	return 0;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue->size == 0)
	{
		return TRUE;
	}
	return FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Queue* pQueue = (Queue*)*phQueue;
	free(pQueue->item);
	free(pQueue);
	*phQueue = NULL;
}
