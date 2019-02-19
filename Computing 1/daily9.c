/*
Thiago Lima
9/25/2016
This program will take an input and check if it is a positive integer and a number not a random charater. 
If they both check out it will print the number.
Time spent:1 hour 
*/
/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining
good	order	in the	classroom,	providing	an	enriching	learning
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

int main(int argc, char * argv[])
{
	int number;
	printf("Enter a negative integer:");
	int scanf_return = scanf("%d", &number);
	while (number >= 0 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, you must enter a negative integer greater than zero:");
		int scanf_return = scanf("%d", &number);

	}
	printf("The negative integer was:%d\n",number);
}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}