/***********************************************
Author:	<Thiago Lima>
Date:	<12/7/2016>
Purpose:	<to be able to use files successfully and tranfer name and scores from one file to another>
Sources	of	Help:	<Pro. Sirong>

Time	Spent:	<5 hours>
***********************************************/
/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining
good	order	in	the	classroom,	providing	an	enriching	learning
experience	for	students,	and	as	training	as	a	practicing	computing
professional	upon	graduation.		This	practice	is	manifested	in	the
University’s	Academic	Integrity	policy.	Students	are	expected	to
strictly	avoid	academic	dishonesty	and	adhere	to	the	Academic
Integrity	policy	as	outlined	in	the	course	catalog.		Violations	will
be	dealt	with	as	outlined	therein.
All	programming	assignments	in	this	class	are	to	be	done	by	the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	in	a	manner	consistent	with	this	document,	the	course
academic	policy	on	the	course	website	on	Blackboard,	and	the	UMass
Lowell	academic	code.
Date:
Name:
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
void mergeFiles(FILE *newfile, FILE *oldfile);


int main(int argc, char * argv[]) {
	FILE *quiz, *output;
	int a = 0;
	int num;
	int b = 0;
	int c = 0;
	int i = 0;
	int temp = 0;
	double ave = 0;
	int x = 0;


	char lastName[BUFFER_SIZE];
	char firstName[BUFFER_SIZE];
	char Name[BUFFER_SIZE];
	int score[BUFFER_SIZE];
	char ch;
	//open input file quiz
	quiz = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\quiz.txt", "r");
	if (quiz == NULL) {
		printf("Can't open and write to file quiz.txt!!\n");
		exit(1);
	}
	//open output file average
	output = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\average.txt", "w");
	if (output == NULL) {
		printf("Could not open output file!\n");
		exit(1);
	}
	int numberOfRead = fscanf(quiz, "%c", &ch);
	//print layout to the output file
	fprintf(output, "Name          Quiz:  1   2   3   4   5   6   7   8   9  10   Average\n");
	fprintf(output, "=====================================================================\n");
	//run a loop till file is at the end
	while (numberOfRead != EOF) {
		//made all variable 0 again
		x = 0;
		a = 0;
		b = 0;
		c = 0;
		i = 0;
		temp = 0;
		ave = 0;
		if (numberOfRead == 0) {
			numberOfRead = fscanf(quiz, "%c", &ch);
		}
		//read first name
		if (!isspace(ch)) {
			firstName[a] = ch;
			a++;
			numberOfRead = fscanf(quiz, "%c", &ch);
			while (islower(ch) && numberOfRead == 1) {
					firstName[a] = ch;
					a++;
					numberOfRead = fscanf(quiz, "%c", &ch);
			}	
			firstName[a] = '\0';	
			
		}
		//skip spaces
		while (isspace(ch) && numberOfRead == 1) {
			numberOfRead = fscanf(quiz, "%c", &ch);
		}
		//read last naame
		if (!isspace(ch)) {
			lastName[b] = ch;
			b++;
			numberOfRead = fscanf(quiz, "%c", &ch);
			while (islower(ch) && numberOfRead == 1) {
				lastName[b] = ch;
				b++;
				numberOfRead = fscanf(quiz, "%c", &ch);
			}
			lastName[b] = '\0';
		}
		//put last name into str Name
		while (x < b) {
			Name[x] = lastName[x];
			x++;
		}
		//put a space and , in Name
		Name[x] = ',';
		x++;
		Name[x] = ' ';
		x++;
		a += b;
		//put first name in Name
		while (x < a + 2) {
			Name[x] = firstName[temp];
			x++;
			temp++;
		}
		Name[x] = '\0';
		//output name
		fprintf(output, "%-20s", Name);
		//read scores
		numberOfRead = fscanf(quiz, "%d", &num);
		if (numberOfRead == 0) {
			numberOfRead = fscanf(quiz, "%d", &num);
		}
		while (numberOfRead == 1 && c < BUFFER_SIZE - 1) {
			ave += num;
			score[c] = num;
			c++;
			numberOfRead = fscanf(quiz, "%d", &num);
			
		}
		//find average
		while (c < 10) {
			ave += 0;
			score[c] = 0;
			c++;
			
		}
		//output score
		while (i < 10) {
			fprintf(output, "%-4d", score[i]);
			i++;
		}
		//output average
		ave /= 10;
		fprintf(output, "%4.2f", ave);
		fprintf(output, "\n");

	}
	//close file
	fclose(quiz);
	fclose(output);
	//reopen file so quiz writes and average reads
	quiz = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\quiz.txt", "w");
	if (quiz == NULL) {
		printf("Can't open and write to file quiz.txt!!\n");
		exit(1);
	}
	output = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\average.txt", "r");
	if (output == NULL) {
		printf("Could not open output file!\n");
		exit(1);
	}
	//copy average file and quiz
	mergeFiles(output, quiz);
	//reclose
	fclose(quiz);
	fclose(output);
}
void mergeFiles(FILE *newfile, FILE *oldfile) {
	char cha;
	while (1) {
		cha = fgetc(newfile);

		if (cha == EOF)
			break;
		else
			putc(cha, oldfile);
	}
}