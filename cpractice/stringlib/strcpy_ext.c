#include <stdio.h>

void strcat_user(char *dest, const char *src)
{
	while(*dest) {
		dest++;
		/* to reach end of actual string */
	}

	while(*dest++ = *src++) {
		/* to append string */
	}

}

int strcmp_user(const char *s1, const char *s2)
{
	int c1, c2;
	do {
		c1 = *s1++;
		c2 = *s2++;
	}while(c1 == c2 && c1 != '\0');
	
	return c1-c2;
}


char *strcpy_user(char *dest, const char *src)
{
	char *temp = dest;
	//while((*dest++ = *src++) != '\0') {
	while(*dest++ = *src++)  {
		/* nothing can be done */
	}

	return temp;
}


int main()
{
	char a[30], b[30], *c = "bangalore";
	printf("Enter a string to copy:");
	scanf("%s", a);
	printf("Entered string is:%s\n", a);
	strcpy_user(b, a);
	printf("\nCopied string is:%s\n", b);
	strcpy_user(b, "Embedded");
	printf("\nCopied string is:%s\n", b);
	strcpy_user(b, c);
	printf("\nCopied string is:%s\n", b);

	char x[30], y[30];
	int z;
	printf("Enter two strings to compare:");
	scanf("%s%s", x, y);
	z = strcmp_user(x, y);
	printf("result of string comparision:%d\n", z);

	char p[50] = "Embedded ", q[20] ="is great";
	strcat_user(p, q);
	printf("concatenated string:%s\n", p);

	return 0;
}
