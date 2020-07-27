#include <stdio.h>

//char *strchr_user(const char *s, int c)
int strchr_user(const char *s, int c)
{
	char *temp = s;
	for( ; *s != (char)c; ++s)
		if(*s == '\0')
			return NULL;
	//return (char *)s;
	return s-temp+1;
}

int main()
{
	char a[30] = "Bhaskar is a good  boy", b;
	/* char *strchr(const char *s, int c); */
	printf("address where the char is stored:%d\n", strchr_user(a, 'i'));

	return 0;
}
