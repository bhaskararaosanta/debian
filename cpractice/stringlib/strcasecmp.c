#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool strcasecmp_user(const char *s1, const char *s2)
{
	int c1, c2;
	do {
		c1 = tolower(*s1++);
		c2 = tolower(*s2++);
	}while(c1 == c2 && c1 != '\0');
	return c1-c2;
}

int main()
{
	char a[30], b[30];
	printf("Enter two strings to compare:");
	scanf("%s%s", a, b);
	printf("Entered strings are:%s and %s\n", a, b);
	printf("strings compare value:%d\n", strcasecmp_user(a,b));

	return 0;
}
