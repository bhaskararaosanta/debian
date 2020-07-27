#include <stdio.h>

char *strncpy_user(char *dest, const char *src, size_t count)
{
	char *tmp = dest;
	while(count) {
		if((*tmp = *src) != '\0')
			src++;
		tmp++;
		count--;
	}
	return dest;
}

int main()
{
	char a[30], b[50];
	int n;
	printf("Enter the string to copy:");
	scanf("%s", a);
	strncpy_user(b, a, 7);
	printf("copied string with n characters:%s\n", b);

	return 0;
}
