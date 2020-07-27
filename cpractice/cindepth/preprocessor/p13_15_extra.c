#include <stdio.h>
#define	FLAG	12	// by making FLAG constant less than 3 to test the program
int main()
{
	int a = 20, b = 4;
#if	FLAG>=3
		printf("Value of FLAG is greater than or equal to 3\n");
		a = a+b;
		b = a*b;
#else
		printf("Value of FLAG is less than 3\n");
		a = a-b;
		b = a/b;
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("Program completed\n");

	return 0;
}
