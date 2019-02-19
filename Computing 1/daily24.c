#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mergeTwoFiles(FILE *inputFile1, FILE *inputFile2, FILE *outputFile);

int main(int argc, char * argv[]) {
	FILE *numbers1 = fopen("numbers1.txt", "r");
	if (numbers1 == NULL) {
		printf("Can't open and write to file numbers1.txt!!\n");
	}
	else {
		FILE *numbers2 = fopen("numbers2.txt", "r");
		if (numbers2 == NULL) {
			printf("Can't open and write to file numbers1.txt!!\n");
		}
		else {
			FILE *outputFile = fopen("outFile.txt", "w");
			mergeTwoFiles(numbers1, numbers2, outputFile);
		}
	}
}
void mergeTwoFiles(FILE *inputfile1, FILE *inputfile2, FILE *outputfile) {
	int num1;
	int num2;
	int reader = fscanf(inputfile1, "%d", &num1);

	while (reader != EOF) {
		while (reader == 1) {
			int reader2 = fscanf(inputfile2, "%d", &num2);
			while (reader2 != EOF) {
				while (reader2 == 1) {
					if (num1 > num2) {
						while (reader || reader2 != EOF) {
							fprintf(outputfile, "d\n", num1);
						}
					}
					if (num2 > num1) {
						while (reader || reader2 != EOF) {
							fprintf(outputfile, "d\n", num2);
						}
					}

				}
			}

		}

	}

}
