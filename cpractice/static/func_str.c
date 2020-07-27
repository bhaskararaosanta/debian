#include <stdio.h>

char **func_str();

int main()
{
	char **ptr = NULL;
	ptr = func_str();
	printf("\n [%s] \n", *ptr);

	return 0;
}

char **func_str()
{
	//char *p = "Linux";		// wrong statement because it will destroy once function ends
	static char *p = "Linux";	// correct statement and this will store in data segment
	return &p;
}
