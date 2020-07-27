#include <stdio.h>

char *strchr_user(const char *s, int c)
{
	for( ; *s != (char)c; ++s)
		if(*s == '\0')
			return NULL;
	return (char *)s;
}

int strcmp_user(const char *s1, const char *s2)
{
	unsigned int c1, c2;
	do {
		c1 = *s1++;
		c2 = *s2++;
	}while(c1 == c2 &&c1 != '\0');

	return c1-c2;
}

void strcat_user(char *dest, const char *src)
{
	while(*dest) {
		dest++;
	}
	while(*dest++ = *src++) {
		/* do nothing */
	}
}

int strlen_user(char *s)
{
	char *temp = s;
	while(*s) {
		s++;	
	}

	return s-temp;
}

char *strcpy_user(char *dest, const char *src)
{
	char *temp = dest;
	while(*dest++ = *src++) {
		/* do nothing until copy */
	}

	return temp;
}


int main()
{
	char a[30], b[30];
	printf("Enter a string to copy:");
	scanf("%s", a);
	strcpy_user(b, a);
	printf("Copied string is:%s\n", b);
	strcpy_user(b, "embedded");
	printf("Direct Copied string is:%s\n", b);
	
	
	printf("string 'a' length is:%d\n", strlen_user(a));
	printf("string 'Bangalire' length is:%d\n", strlen_user("Bangalore"));

	char p[30] = "New Year ", q[15] = "resolution";
	strcat_user(p, q);
	printf("concatenated string is:%s\n", p);
	
	char x[30], y[30];
	int n;
	printf("Enter two strings to compare:");
	scanf("%s%s", x, y);
	n = strcmp_user(x, y);
	printf("strcmp of %s and %s is:%d\n", x, y, n);

	char c[30] = "All is well", *ptr;
	ptr = strchr_user(c, 'i');
	printf("character 'i' is found at position:%d\n", ptr-c+1);
	
	return 0;
}
