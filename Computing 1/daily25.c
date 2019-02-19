

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

void PullMatch(FILE *input);
int main(int argc, char * argv[]) {
	FILE *quiz,*output ;
	char quiz = "quiz.txt";
	char output = "average.txt";
	int i = 0;
	char string1[80];
	char ch;

	quiz = fopen("quiz.txt", "r");
	if (quiz == NULL) {
		printf("Can't open and write to file quiz.txt!!\n");
		exit(1);
	}

	output = fopen("average.text", "w");
	if (output == NULL) {
		printf("Could not open output file!\n");
		exit(1);
	}
	char buffer[BUFFER_SIZE];

	int numberOfRead = fscanf(input, "%c", &ch);
	while (numberOfRead != EOF) {
		while (isspace(ch) && numberOfRead == 1) {
			numberOfRead = fscanf(inputFile, "%c", &ch);
		}
		while (!isspace(ch) && numberOfRead == 1 && index < BUFFER_SIZE - 1) {
			buffer[index] = ch;
			index++;
			numberOfRead = fscanf(inputFile, "%c", &ch);
		}
		buffer[index] = '\0';



	string1[i] = '\0';
	PullMatch(input);

	fclose(input);
	printf("Write to file successfully.\n");
}


void PullMatch(FILE *input) {
	

}
