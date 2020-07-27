#include <stdio.h>

char *strcpy_user(char *dest, const char *src)
{
	//char *tmp = dest;
	while((*dest++ = *src++) != '\0')
		/* do nothing */   ;
	//return tmp;
}

int main()
{
	char a[30], b[30];
	printf("Enter a string to copy into other variable:");
	scanf("%s", a);
	printf("String to be copied:%s\n", a);

	strcpy_user(b, a);
	printf("Copied string is:%s\n", b);

	return 0;
}
