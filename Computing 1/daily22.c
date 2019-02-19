/*
thiago Lima
11/9/16
this program print the index of the highest number in the value.
2 hours
*/
#define size 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char * argv[]) {
	FILE *inputfile;
	inputfile = fopen("numbers.txt", "r");
	if (inputfile == NULL) {
		printf("could not open input file!\n");
		exit(1);
	}
	int number, big, small;
	double average;
	int holder = 0;
	int counter = 0;
	int sum = 0;
	int x[size];
	int reader = fscanf(inputfile, "%d", &number);
	while (reader != EOF) {
		while (reader == 1 && holder < size - 1)
		{
			x[holder] = number;
			holder++;
			sum = sum + number;
			counter++;
			reader = fscanf(inputfile, "%d", &number);
		}	

	}
	average = sum / counter;
	int tester = 0;
	big = x[0];
	small = x[0];
	int holder2 = holder;
	int total = holder;
	while (tester <= holder) {
		if (x[holder] >= big)
		{
			big = x[holder];
		}

		holder--;
	}
	holder2 -= 1;
	while (tester <= holder2) {
		if (x[holder2] < small)
		{
			small = x[holder2];
		}
		holder2--;
	}
	printf("there were %d integers in the file.\n",total);
	printf("The sum is %d\n", sum);
	printf("The average is %f\n", average);
	printf("The smallest number is %d\n", small);
	printf("The largest number is %d\n", big);

	fclose(inputfile);
	return 0;

}
