/***********************************************
Author:	<thiago lima>
Date:	<11/29/2016>
Purpose:	<copy a file to another one>
Sources	of	Help:	<Please	list	any	sources	that	you	used
for	help:	tutors,	web	sites,	lab	assistants	etc.>
Time	Spent:	<30 minutes> 
***********************************************/


/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining	good	order	in	the
classroom,	providing	an	enriching	learning	experience	for	students,	and	as	training
as	a	practicing	computing	professional	upon	graduation.		This	practice	is	manifested
in	the	University’s	Academic	Integrity	policy.	Students	are	expected	to	strictly
avoid	academic	dishonesty	and	adhere	to	the	Academic	Integrity	policy	as	outlined	in
the	course	catalog.		Violations	will	be	dealt	with	as	outlined	therein.
All	programming	assignments	in	this	class	are	to	be	done	by	the	student	alone.		No
outside	help	is	permitted	except	the	instructor	and	approved	tutors.
COMP.1010						 Daily	26 F16	- Dr.	Lin
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was	generated	in	a
manner	consistent	with	this	document,	the	course	academic	policy	on	the	course
website	on	Blackboard,	and	the	UMass	Lowell	academic	code.
Date:12/1/2016
Name:thiago lima
***********************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void mergeFiles(FILE *inputFile1, FILE *output);

int main(int argc, char * argv[]) {
	FILE *text = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\daily26\\daily26\\in.txt", "r");
	if (text == NULL) {
		printf("Can't open !\n");
		exit(1);
	}
		FILE *output = fopen("\\Users\\super\\Documents\\Visual Studio 2015\\Projects\\daily26\\daily26\\out.txt", "w");
		mergeFiles(text, output);
	
	fclose(text);
	fclose(output);

	}

void mergeFiles(FILE *inputfile1, FILE *output) {
	char ch;
	while (1) {
		ch = fgetc(inputfile1);

		if (ch == EOF)
			break;
		else
			putc(ch, output);
	}

}
