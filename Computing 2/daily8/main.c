#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQueue = NULL;
	int i;
	int j;

	hQueue = priority_queue_init_default();
	if (hQueue == NULL)
	{
		printf("Failed to allocate space for queue object.\n");
		exit(1);
	}

	priority_queue_insert(hQueue, 10, 11);
	priority_queue_insert(hQueue, 4, 7);
	priority_queue_insert(hQueue, 5, 12);
	priority_queue_insert(hQueue, 12, 14);
	priority_queue_insert(hQueue, 8, 4);
	priority_queue_insert(hQueue, 2, 3);
	priority_queue_insert(hQueue, 1, 6);

	while (!priority_queue_is_empty(hQueue))
	{
		printf("The value at the front is: %d\n", priority_queue_front(hQueue, NULL));
		priority_queue_service(hQueue);
	}
	printf("going");
	priority_queue_destroy(&hQueue);


	return 0;
}