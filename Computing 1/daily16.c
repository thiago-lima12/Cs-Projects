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
I	certify that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	in	a	manner	consistent	with	this	document,	the	course
academic	policy	on	the	course	website	on	Blackboard,	and	the	UMass
Lowell	academic	code.
Date:10/14/2016
Name:Thiago lima
***********************************************/
/***********************************************
Author: <Thiago Lima>
Date: <10/14/2016>

Purpose: <the program is use to calcutar the universal gravitional between two masses>


Time Spent: <1 hour>
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float const UNIVERSAL_GRAVITATIONAL_CONSTANT = 6.673e-8;

void gravitational_attractive(float m1, float m2, float d);
void clear_keyboard_buffer(void);

int main(int argc, char * argv[])
{
	float m1, m2, d, exit;
	printf("Enter the mass for the first body:");
	float scanf_return = scanf("%g", &m1);
	while (m1 <= 0 || m1 >= 80 || scanf_return == 0)
	{
		clear_keyboard_buffer();
		printf("I am sorry, that number is unrecognized or out of range, try a positive number:");
		float scanf_return = scanf("%g", &m1);

	}
		printf("Enter the mass for the second body:");
		float scanf_return = scanf("%g", &m2);
		while (m2 <= 0 || m2 >= 80 || scanf_return == 0)
		{
			clear_keyboard_buffer();
			printf("I am sorry, that number is unrecognized or out of range, try a positive number:");
			float scanf_return = scanf("%g", &m2);

		}
		

		printf("Enter the distance of the bodies:");
		float scanf_return = scanf("%g", &d);
		while (d <= 0 || d >= 80 || scanf_return == 0)
		{
			clear_keyboard_buffer();
			printf("I am sorry, that number is unrecognized or out of range, try a positive number:");
			float scanf_return = scanf("%g", &d);

		}
		
		gravitational_attractive(m1, m2, d);

	
}

void gravitational_attractive(float m1, float m2, float d) {
	float f = (UNIVERSAL_GRAVITATIONAL_CONSTANT * m1 * m2) / (d*d);
	printf("gravitational_attractive is %g\n",f);
}
void clear_keyboard_buffer(void)
{
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}

