/***********************************************
Author:	<Thiago Lima>
Date:	<12/1/2016>
Purpose:	<tells you was yesturday and days date is>
Sources	of	Help:	<Please	list	any sources	that	you	used
for	help:	tutors,	web	sites,	lab	assistants	etc.>
Time	Spent:	<10 minutes>
***********************************************/


/***********************************************
Computing	I	-- COMP.1010	Honor	Statement
The	practice	of	good	ethical	behavior	is	essential	for	maintaining	good	order	in	the
classroom,	providing	an	enriching	learning	experience	for	students,	and	as	training
as	a	practicing	computing	professional	upon	graduation.		This	practice	is	manifested
in	the	University’s	Academic	Integrity	policy.	Students	are	expected	to	strictly
avoid	academic	dishonesty	and	adhere	to	the	Academic	Integrity	policy	as	outlined	in
the	course	catalog.		Violations	will	be	dealt	with	as	outlined	therein.
All	programming	assignments	in	this	class	are	to	be	done	by	the	student	alone.	 No
outside	help	is	permitted	except	the	instructor	and	approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was	generated	in	a
manner	consistent	with	this	document,	the	course	academic	policy	on	the	course
website	on	Blackboard,	and	the	UMass	Lowell	academic	code.
Date:12/1/2016
Name:Thiago Lima
***********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct date
{
	int month;
	int day;
	int year;
};
typedef struct date Date;
const int daysInMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30,
31, 30, 31 };
void displayDateAfter(char *str, Date aDay);

int main(int argc, char * argv[]) {
	Date today;
	printf("Please enter a month <1-12>:");
	scanf("%d", &today.month);
	printf("Please enter a valid day in the month :");
	scanf("%d", &today.day);
	today.year = 2016;
	printf("today is:%d/%d/%d\n", today.month, today.day, today.year);
	displayDateAfter("Tomorrow", today);
	}

void displayDateAfter(char *dayName, Date aDay) {
	if ((aDay.day -= 1) < 1) {
		//printf("Yesterdaay was :%d/%d/%d\n", aDay.month, aDay.day, daysInMonth[aDay.month-2]);
		aDay.day = daysInMonth[aDay.month-2];
		aDay.month -= 1;
	}
	
	if (aDay.month < 1) {
		aDay.year -= 1;
		aDay.month = 12;
		aDay.day = 31;
	}
	else {
	}
	printf("Yesterday was :%d/%d/%d\n", aDay.month, aDay.day, aDay.year); 
	
}



	



