/*
thiago lima
03/25/2016
this program use the fibonacci number to tell you the growth of crud over a number of days.
20 minutes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);
int fibonacci(int num);
int main(int argc, char * argv[])
{
	char answer = 'y';
	while (answer == 'y') {
		int crud;
		printf("Please enter the initial size of the green crud:");
		int scanf_return = scanf("%d", &crud);
		while (crud <= 1 || scanf_return == 0)
		{
			clear_keyboard_buffer();
			printf("I am sorry, that value is unrecognized or negative.");
			int scanf_return = scanf("%d", &crud);

		}
		int days;
		printf("Please enter the number of days:");
		scanf("%d", &days);
		while (days < 0 || scanf_return == 0)
		{
			clear_keyboard_buffer();
			printf("I am sorry, that value is unrecognized or negative.");
			int scanf_return = scanf("%d", &days);

		}
		printf("with an initial population of %d pounds of crud growing for %d days\n",crud,days);
		int final = fibonacci(days);
		final *= crud;
		printf("the final population would be %d\n", final);
		clear_keyboard_buffer();
		printf("would you like to continue?(y/n)");
		scanf("%c", &answer);
	}
	
}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}
int fibonacci(int num)
{
	num /=  5;
	int count = 1;
	int sum = 1;
	int presum = 1;
	int hold_sum;
	if (num == 1 || num == 0) {
		return sum;
	}
	else {
		while (num > count) {
			hold_sum = sum;
			sum += presum;
			presum = hold_sum;
			count++;
		}
		return sum;
	}
}

