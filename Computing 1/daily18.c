/*
Thiago Lima
3/29/2016
the program tells the user the amount of quarters. dines, nickels and pennies depending on the
amount of cents you have.
no extra sources
25 minute
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void count_coin(int *numQuarters, int *numDimes, int *numNickels, int *numPennies, int totalCents);

int main(int argc, char * argv[]) {
	int totalCents;
	int numQuarters = 0, numDimes = 0, numNickels = 0, numPennies = 0;

	printf("Please enter the total number of cents (0-1000): ");
	scanf("%d", &totalCents);

	//call your function below
	count_coin(&numQuarters, &numDimes, &numNickels, &numPennies, totalCents);

	//print the result to the screen
	printf("The total number of quarters is: %d\n", numQuarters);
	printf("The total number of dimes is: %d\n", numDimes);
	printf("The total number of nickels is: %d\n", numNickels);
	printf("The total number of pennies is: %d\n", numPennies);

	return 0;
}

//define your function here
void count_coin(int *numQuarters, int *numDimes, int *numNickels, int *numPennies, int totalCents) {
	*numQuarters = totalCents / 25;
	totalCents = totalCents % 25;
	*numDimes = totalCents / 10;
	totalCents = totalCents % 10;
	*numNickels = totalCents / 5;
	totalCents = totalCents % 5;
	*numPennies = totalCents / 1;
}