/* P10.2: Program to print the address and characters of a string using pointer */

#include <stdio.h>
#include <string.h>
int main()
{
	char str[] ="India is great";
	char *p;
	p = str;
	printf("size of string:%d\n", sizeof(str));
	printf("length of string:%d\n", strlen(str));
	while(*p != '\0') {
		printf("Character = %c\n", *p);
		printf("Address   = %p\n", p);
		p++;
	}

	return 0;
}
