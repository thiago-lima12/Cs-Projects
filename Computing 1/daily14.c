/***********************************************
Author:	<Thiago Lima>
Date:	<10/10/2016>
Purpose:	<to make a program that takes positive number and divides both>
Sources	of	Help:	<Please	list	any	sources	that	you	used
for	help:	tutors,	web	sites,	lab	assistants	etc.>

Time	Spent:	<Insert	how	much	time	you	spent
on	the	assignment	here>
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
Date:10/10/2016		
Name:Thiago Lima
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);
int divide(int a, int b);
int main(int argc, char * argv[])
{
	int number;
	printf("Please enter a positive number:");
	int scanf_return = scanf("%d", &number);
	while (number <= 0 || number >= 80 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, that number is unrecognized or out of range, try [1-79]:");
		int scanf_return = scanf("%d", &number);

	}
	int number2;
	printf("Please enter a positive number :");
	scanf("%d", &number2);
	while (number2 <= 0 || number2 >= 80 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, that number is unrecognized or out of range, try [1-79]:");
		scanf("%d", &number2);

	}
	divide(number, number2);
	

}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}
int divide(int a, int b) {
	int c;
	if (a > b) {
		c = b;
		while ((b % c != 0) && (a % c != 0)) {
			c--;
		}
	}
	else {
		a = c;
		while ((a % c != 0) && (b % c != 0)) {
			c--;
		}
	}
	printf("The largest that divides both %d and %d is %d" a, b, c); 
}

