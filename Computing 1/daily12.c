/*
Thiago lima
10/4/2016
This program ask the user to input the number of asterisks, then check it you see if it is a 
int between 1 and 79. then has them input the number of lines, checks that to be an int between
1 aand 23. then it print out the number of astrisks a line, with the number of line they input.
It took 20 minutes
*/
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
void clear_keyboard_buffer(void);
void draw_line(int num, int num2);
int main(int argc, char * argv[])
{
	int number;
	printf("Please enter the number of percent you want in your line:");
	int scanf_return = scanf("%d", &number);
	while (number <= 0 || number >= 80 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, that number is unrecognized or out of range, try [1-79]:");
		int scanf_return = scanf("%d", &number);

	}
	int number2;
	printf("Please enter the number of lines you want in your box:");
	scanf("%d", &number2);
	while (number2 <= 0 || number2 >= 24 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, that number is unrecognized or out of range, try [1-79]:");
		scanf("%d", &number2);

	}
	draw_line(number, number2);

}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}
void draw_line(int num, int num2) {
	int i, j;
	for (i = num2; i > 0; --i) {
		for (j = num; j > 0; --j)
		{
			printf("%%");
		}
		printf("\n");
	}
}
