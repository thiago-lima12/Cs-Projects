#include <stdio.h>
char* reverse(char *str);

int main(int argc, char* argv[])
{
	int x;
	char word[] = "Happy Birthday!";
	printf("%s\n", word);
	reverse(word);
	printf("%s\n", word);
	printf("%s\n", reverse(word));
	printf("%s\n", word);
	
	return 0;
}

char* reverse(char *str)
{	
	
	int y;
	char temp;
	int count = 0;
	int hold;
	char *p;
	int x = 0;
	while (str[count] != '\0') {
		count++;
	}
	count--;
	hold = count / 2;
	
	while (hold >= 0) {
		
		temp = str[count];
		str[count] = str[x];
		str[x] = temp;
		count--;
		hold--;
		x++;
	}

	return str;
}