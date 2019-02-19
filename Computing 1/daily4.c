/*
Author:	<Thiago Lima>
	Date : <9/12/2016>
	Purpose : <use variables and to learn how to use right and left justification.>
*/

/*
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining
good	order	in	the	classroom,	providing	an	enriching	learning
experience	for	students,	and	as	training	as	a	practicing	computing
professional	upon	graduation.		This	practice	is	manifested	in	the
University’s	Academic	Integrity	policy.	Students	are	expected	to
strictly	avoid	academic	dishonesty	and	adhere	to	the	Academic
Integrity	policy	as	outlined	in	the	course	catalog.		Violations	will
be	dealt	with	as	outlined	therein.
All programming	assignments	in	this	class	are	to	be	done	by	the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	in	a	manner	consistent	with	this	document,	the	course
academic	policy	on	the	course	website	on	Blackboard,	and	the	UMass
Lowell	academic	code.
Date: 9/12/2016
Name: Thiago Lima
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char * argv[]) {
	int *p1, *p2, *p, a, b;

	printf("Please enter two intergers:");
	scanf("%d,%d", &a, &b);

	p1 = &a;
	p2 = &b;
	printf("a=%d, b=%d\n", a, b);
	printf("max=%d, min=%d\n", *p1, *p2);
	if (a < b) {
		p = p1;
		p1 = p2;
		p2 = p;
	}
	printf("a=%d, b=%d\n", a, b);
	printf("max=%d, min=%d, p=%d\n", *p1, *p2, *p);
	return 0;
}