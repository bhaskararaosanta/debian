#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmp_user(const char *s1, const char *s2)
{
	unsigned char c1, c2;
	do {
		c1 = tolower(*s1++);
		c2 = tolower(*s2++);
	}while((c1 == c2) && (c1 != '\0'));
	return c1-c2;
}

int main()
{
	char a[30] = "ball", b[30] = "bell";

	printf("string comparision betweem ball and bell:%d\n", strcmp_user(a, b));
	printf("string comparision betweem ball and bell usind lib func:%d\n", strcmp(a, b));

	return 0;
}
