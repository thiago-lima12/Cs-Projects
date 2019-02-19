/*
Author: Thiago Lima
Date: 11/16/2016
Time spent: 1 hour
Sources of Help: no help
Purpose: The purpose of the program convert between metric to U.S. unit.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);
void convert_length(void);
void convert_weight(void);
void length_to_metric(double feet, double inches, double* meters, double* centimeters);
void length_to_us(double meter, double centimeters, double* feet, double* inches);
void weight_to_metric(double pounds, double ounces, double* kilograms, double* grams);
void weight_to_us(double kilograms, double grams, double* pounds, double* ounces);
const double inches_to_feets = 12;
const double feets_to_meters = 0.3048;
const double meters_to_centimeters = 100;
const double ounces_to_pounds = 16;
const double pounds_to_kilograms = 2.2046;
const double kilograms_to_grams = 1000;


int main(int argc, char * argv[])
{
	int convert;
	printf("Please enter 0 to exits, 1 for length, 2 to weight: ");
	scanf("%d", &convert);
	while (convert != 0) {
		switch (convert) {
		case 1:
			convert_length();
			break;
		case 2:
			convert_weight();
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
		clear_keyboard_buffer();
		printf("Please enter 0 to exits, 1 for length, 2 to weight: ");
		scanf("%d", &convert);
		
	}
	printf("you chose to exit\n ");
}
void clear_keyboard_buffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
}
void convert_length(void) {
	double feet;
	double inches;
	double meters = 0;
	double centimeters = 0.0;
	printf("you choice to convert the length\n");
	int convert_L;
	printf("Please enter 0 to exits, 1 for length to metric, 2 to length to us: ");
	scanf("%d", &convert_L);
	while (convert_L != 0) {
		switch (convert_L) {
		case 1:
			printf("What is the value of feet/inches?\n");
			printf("feet: ");
			scanf("%lf", &feet);
			printf("inches: ");
			scanf("%lf", &inches);
			length_to_metric(feet, inches, &meters, &centimeters);
			printf("After converting, it is equivalent to %.0f meters %.2f centimeters.\n", meters, centimeters);
			break;
		case 2:
			printf("What is the value of meters/centimeters?\n");
			printf("meters: ");
			scanf("%lf", &meters);
			printf("centimeters: ");
			scanf("%lf", &centimeters);
			length_to_us(meters, centimeters, &feet, &inches);
			printf("After converting, it is equivalent to %.0f feet %.2f inches.\n", feet, inches);
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
		clear_keyboard_buffer();
		printf("Please enter 0 to exits, 1 for length to metric, 2 to length to us: ");
		scanf("%d", &convert_L);
	}
	printf("you chose to exit\n ");
}
void convert_weight(void) {
	double pounds;
	double ounces;
	double kilograms = 0;
	double grams = 0.0;
	printf("you choice to convert the weight\n");
	int convert_W;
	printf("Please enter 0 to exits, 1 for weight to metric, 2 to weight to us: ");
	scanf("%d", &convert_W);
	while (convert_W != 0) {
		switch (convert_W) {
		case 1:
			printf("What is the value of pounds/ounces?\n");
			printf("pounds: ");
			scanf("%lf", &pounds);
			printf("ounces: ");
			scanf("%lf", &ounces);
			weight_to_metric(pounds, ounces, &kilograms, &grams);
			printf("After converting, it is equivalent to %.0f kilograms %.2f grams.\n", kilograms, grams);
			break;
		case 2:
			printf("What is the value of kilograms/grams?\n");
			printf("kilograms: ");
			scanf("%lf", &kilograms);
			printf("grams: ");
			scanf("%lf", &grams);
			weight_to_us(kilograms, grams, &pounds, &ounces);
			printf("After converting, it is equivalent to %.0f pounds %.2f ounces.\n", pounds, ounces);
			break;
		default:
			printf("Invalid choice.\n");
			break;
		}
		clear_keyboard_buffer();
		printf("Please enter 0 to exits, 1 for weight to metric, 2 to weight to us: ");
		scanf("%d", &convert_W);
	}
	printf("you chose to exit\n ");
}
void length_to_metric(double feet, double inches, double* meters, double* centimeters) {
	double x;
	int y;
	x = (feet + inches / inches_to_feets)*feets_to_meters;
	y = x;
	*meters = y;
	*centimeters = (x - *meters) * meters_to_centimeters;

	return;
}
void length_to_us(double meters, double centimeters, double* feet, double* inches) {
	double x;
	int y;
	x = (meters + centimeters / meters_to_centimeters) / feets_to_meters;
	y = x;
	*feet = y;
	*inches = (x - *feet) * inches_to_feets;

}
void weight_to_metric(double pounds, double ounces, double* kilograms, double* grams) {
	double x;
	int y;
	double total;

	total = pounds + ounces / ounces_to_pounds;
	x = pounds / pounds_to_kilograms;
	y = x;
	*kilograms = y;
	*grams = (x - *kilograms) * kilograms_to_grams;

}
void weight_to_us(double kilograms, double grams, double* pounds, double* ounces) {

	double x;
	int y;
	double total;

	total = kilograms + grams / kilograms_to_grams;
	x = kilograms * pounds_to_kilograms;
	y = x;
	*pounds = y;
	*ounces = (x - *pounds) * ounces_to_pounds;
}


