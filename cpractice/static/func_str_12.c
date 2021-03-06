#include <stdio.h>

char **func1_str();
char **func2_str();

int main()
{
	char **ptr1 = NULL;
	char **ptr2 = NULL;

	ptr1 = func1_str();
	printf("\n [%s] :: func1_str() address = [%p], its returned address is [%p]\n", *ptr1, (void *)func1_str, (void *)ptr1);

	ptr2 = func2_str();
	printf("\n [%s] :: func2_str() address = [%p], its returned address is [%p]\n", *ptr2, (void *)func2_str, (void *)ptr2);

	printf("\n [%s] [%p]\n", *ptr1, (void *)ptr1);

	return 0;
}

char **func1_str()
{
	//char *p = "Windows";
	static char *p = "Windows";
	return &p;
}

char **func2_str()
{
	//char *p = "Linux";
	static char *p = "Linux";
	return &p;
}
