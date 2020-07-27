#include <stdio.h>
#define	FLAG	12
int main()
{
	int a = 20, b = 4;
#if 	FLAG>=3
		printf("Value of FLAG is greater than or equal to 3\n");
		a = a+b;
		b = a*b;
		printf("Values of variables a and b have been changed\n");
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("program completed\n");

	return 0;
}
