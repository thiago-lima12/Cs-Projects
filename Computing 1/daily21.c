/*
thiago Lima
11/4/16
this program print the index of the highest number in the value.
2 hours
*/
/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining
good	order	in	the	classroom,	providing	an	enriching	learning
experience	for	students,	and	as	training	as	a	practicing	computing
professional	upon	graduation.		This	practice	is	manifested	in	the
University’s	Academic	Integrity	policy.	Students	are	expected	to
strictly	avoid	academic	dishonesty	and	adhere	to	the	Academic
Integrity	policy	as	outlined	in	the course	catalog.		Violations	will
be	dealt	with	as	outlined	therein.
All	programming	assignments	in	this	class	are	to	be	done	by	the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted with	this	assignment	is	mine	and	was
generated	in	a	manner	consistent	with	this	document,	the	course
academic	policy	on	the	course	website	on	Blackboard,	and	the	UMass
Lowell	academic	code.
Date:
Name:
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void getbiggest(int x[10]);
void swapInt(int *a,int *b);

int main(int argc, char * argv[]) {
	int x[10];
	int i;
	printf("Enter 10 integer values\n");
	for (i = 0; i < 10; ++i) {
		printf("value %d:", i + 1);
		scanf("%d",&x[i]);
	}
	/*Precondition-10 integer must have happen inputed and store each in an element of the x array */
	getbiggest(x);
	/*Postcondition-the function much have 10 element and compare each element starting with the first 
	and second. till the larger one is found and stored in a, then printed*/

}
void swapInt(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void getbiggest(int x[10]) {
	int a;
	int hold = 0;
	for (a = 1; a <= 10 - 1; a++) {
		if (x[hold] < x[a]) {
			hold = a;
			
			
		}
		
	}
	printf("The index of the maximum is %d\n", hold);
	
}