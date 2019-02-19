/***********************************************
Author:	<Thiago Lima>
Date:	<10/7/2016>
Purpose:	<improved the rock paper scissors program>
Time	Spent:	<20>
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
Date:10/7/2016
Name:Thiago Lima
***********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);

int main(int argc, char * argv[])
{
	char play1;
	char play2;
	printf("player-1 it is your turn!\n");
	printf("please enter your choice(p)aper, (r)ock, or (s)cissors:");
	scanf("%c", &play1);
	//char play1 = play;
	clear_keyboard_buffer();
	printf("player-2 it is your turn!\n");
	printf("Please enter your choice (p)aper, (r)ock, or (s)cissors:");
	scanf("%c", &play2);
	//char play2 = play;


	if (play1 == 'p' && play2 == 'p') {
		printf("draw\n %c %c", play1, play2);
	}
	else if (play1 == 'p' || play2 == 's') {
			printf("player-2 wins\n");
	}
	else if (play1 == 'p' || play2 == 'r') {
		printf("player-1 wins\n");
	}
	else if (play1 == 's' || play2 == 'p') {
		printf("player-1 wins\n");
	}
	else if (play1 == 's' || play2 == 's') {
		printf("draw\n");
	}
	else if (play1 == 's' || play2 == 'r') {
		printf("player-2 wins\n");
	}
	else if (play1 == 'r' || play2 == 'p') {
		printf("player-2 wins\n");
	}
	else if (play1 == 'r' || play2 == 's') {
		printf("player-1 wins\n");
	}
	else if (play1 == 'r' || play2 == 'r') {
		printf("draw\n");
	}
	else {
		printf("win");
	}

}



void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}

