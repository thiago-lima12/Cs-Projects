
/***********************************************
Author:	<Thiago Lima>
Date:	<12/7/2016>
Purpose:	<to use dynamic memory to storer integers>
Sources	of	Help:	< Pro. Sirong>
Time	Spent:	<1 hour>
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
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was	generated	in	a
manner	consistent	with	this	document,	the	course	academic	policy	on	the	course
website	on	Blackboard,	and	the	UMass	Lowell	academic	code.
Date:12/7/2016
Name:Thiago Lima
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);

int main(int argc, char * argv[]) {
	int *pNumber;
	int x;
	int y;
	
	
	
	printf("Please enter the number of elements of your dynamic array:");
	scanf("%d", &x);
	clear_keyboard_buffer();
	pNumber = (int *)malloc(x * sizeof(int));
	if (pNumber == NULL) {
		printf("Can't allocate memory!");
		exit(1);
	}
	x -= 1;
	int z = x;
	while (x >= 0) {
		printf("Element at index %d:", x);
		scanf("%d", &y);
		clear_keyboard_buffer();
		pNumber[x] = y; 
		x--;

	}
	printf("***\n");
	x += 1;
	while (x <= z) {
		printf("Element at index %d: %d\n", x, pNumber[x]);
		x++;
	}

	free(pNumber);
	return 0;


}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}