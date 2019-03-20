#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	int c;
	FILE* fp = fopen("test.txt", "r");

	Status q_status;
	q_status = SUCCESS;
	struct Queue *left = createQueue();
	struct Queue *right = createQueue();


	fscanf(fp, "%d", &c);

	for (int i = 0; i < c; i++)
	{
		int l = 0, m = 0, num = 0, hold = 0, temp = 0, checker = 0, cross = 0;
		char side[6];
		fscanf(fp, "%d", &l);
		fscanf(fp, "%d", &m);
		l *= 100;
		for (int j = 0; j < m; j++)
		{
			fscanf(fp, "%d", &num);
			fscanf(fp, "%s", side);
			printf("%d\n", num);

			printf("%s\n", side);
			if (side[0] == 'l')
			{
				enQueue(left, num);
			}
			else
			{
				enQueue(right, num);
			}

		}
		
		
			
		while (m > 0)
		{
			

			if (next(left) != NULL)
			{
				checker = 0;
				while (checker == 0)
				{
					temp = front(left);
					if ((hold + temp) < l)
					{
						printf("the hold is :%d + %d < %d\n", hold, temp, l);
						hold += temp;
						deQueue(left);
						m--;
					}
					else
						checker = 1;

					if (next(left) == NULL)
						break;
				}

			}
			
			cross++;
			hold = 0;
			
			if (next(right) != NULL)
			{
				checker = 0;
				while (checker == 0)
				{
					temp = front(right);
					if ((hold + temp) < l)
					{
						hold += temp;
						deQueue(right);
						m--;
					}
					else
						checker = 1;

					if (next(right) == NULL)
						break;

				}
			}
			
			printf("number of cars %d\n", m);
			if ( (next(right) == NULL) && (next(left) == NULL) && hold == 0 )
				break;

			hold = 0;
			cross++;
			
		}
		printf("Crossing number is: %d\n", cross);
	}
	fclose(fp);
	
	
	

	return 0;
}