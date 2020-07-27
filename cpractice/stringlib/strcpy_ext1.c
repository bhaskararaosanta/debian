#include <stdio.h>

void strcpy_user(char *dest, const char *src)
{
	while(*dest++ = *src++) {
		/* do wait for copy the string */
	}

	return;
}

int strlen_user(const char *s)
{
	const char *temp = s;
	while(*temp) {
		temp++;
	}
	return temp - s;
}

int strcmp_user(const char *p, const char *q)
{
	while(*p == *q && *p != '\0') {
		p++;
		q++;
	}
	return *p-*q;
}

void strcat_user(char *a, const char *b)
{
	while(*a) {
		a++;
	}
	while(*a = *b) {
		a++;
		b++;
	}
}

int main()
{
	char a[30] = "Embedded is good", b[30];
	strcpy_user(b, a);
	printf("copied string is:%s\n", b);
	printf("length of copied string:%d\n", strlen_user(b));

	char x[10] = "ball", y[10] = "bell";
	printf("comparision of ball and bell strings:%d\n", strcmp_user(x, y));
	strcat_user(x, y);
	printf("concatenate string y to the x:%s\n", x);

	return 0;
}
