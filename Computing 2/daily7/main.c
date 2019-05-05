/**********************************************************************
Program: daily 7
Author: Thiago Lima
Date: 8/23/2019
Time spent: 4 hours
Purpose: The purpose of this program is to campare the parenthesis
in a file
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include "status.h"


int main(int argc, char* arg[])
{
	STACK hStack = NULL;
	hStack = stack_init_default();

	int n;
	FILE *file;
	file = fopen("test.txt", "r");


	if (file == NULL) {
		printf("Error: file pointer is null.");
		exit(1);
	}

	fscanf(file, "%d", &n);
	//printf("Number of lines: %d\n", n);
	char ch = getc(file);
	
	for (int i = 0; i < n; i++)
	{
		//printf("line: %d  ", i);
		ch = getc(file);
		//printf("%d START %c\n", i, ch);
		if (ch == '\n' || ch == EOF) {
			printf("Yes\n");
		}
		else {
			
			
			//printf("1: %c\n", ch);
			if ((ch == '(') || (ch == '[') || (ch == '{')) {
				stack_push(hStack, ch);
				//printf("Going\n");
			}
			if ((ch == ')') || (ch == ']') || (ch == '}')) {
				printf("No\n");

			}

			else {
				while ((ch != '\n')) {
					ch = getc(file);
					
					char hold = stack_top(hStack, NULL);
					//printf("2: %c\n", hold);
					//printf("2: %c\n",ch);
					if ((ch == '(') || (ch == '[') || (ch == '{')) {
						stack_push(hStack, ch);
						//printf("Going\n");
					}
					else if (ch == '\n') {
						if (stack_empty(hStack)) {
							printf("Yes\n");
							//printf("hold: %c\n", hold);
							//printf("ch: %c\n",ch);
							break;
						}
						else {
							printf("No\n");
							while (!stack_empty(hStack)) {
								stack_pop(hStack);
							}
							break;
						}
					}
					else {
						if ((hold == '(') && (ch == ')')) {
							stack_pop(hStack);
						}
						else if ((hold == '[') && (ch == ']')) {
							stack_pop(hStack);
						}
						else if ((hold == '{') && (ch == '}')) {
							stack_pop(hStack);
						}
						else if (ch == ' ') {
						}
						else {
							printf("No\n");
							while ((ch != '\n')) {
								ch = getc(file);
								//printf("%c\n", ch);
							}
							while (!stack_empty(hStack)) {
								stack_pop(hStack);
							}
							break;
						}

					}
				}

			}
		}
		
		
	}
	stack_destroy(&hStack);
	fclose(file);
	return 0;
}


