/*
/*
Thiago Lima
10/31/2016
Thi program give the use a menu the convert lenght or weight. then enters a new menu for each choice
then converts it to metric or us. And this menu can continue to repeat.
no extra sources
45 minute
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void clear_keyboard_buffer(void);
void convert_length(void);
void convert_weight(void);



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
	printf("you choice to convert the length\n");
	return 0;
}
void convert_weight(void) {
	printf("you choice to convert the weight\n");
	
	return 0;
}

