/*
Thiago Lima
9/23/2015
this work now because we are using a while loop which cuts 
down the time the it takes the computer to do work  
*/
/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining
good	order	in	the	classroom,	providing	an	enriching	learning
COMP.1010 Daily	08 F16	- Dr.	Lin
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
Date:9/23/2016
Name:Thiago Lima
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void loop_down_to_zero(int num);
void loop_up_to_int(int num);
int main(int argc, char * argv[])
{
	int number;
	
	printf("Enter a positive integer:");
	scanf("%d", &number);
	int number2 = number;
	while (number >= 0)
	{
		loop_down_to_zero(number);
		number -= 1;
	}
	printf("****\n");
	while (number < number2)
	{
		number += 1;
		loop_down_to_zero(number);
		
	}
}
void loop_down_to_zero(int num)
{
	printf("%d\n",num);
}
void loop_up_to_int(int num)
{
	printf("%d\n", num);
}
