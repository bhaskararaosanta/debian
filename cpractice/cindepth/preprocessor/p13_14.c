/* P13.14: Program to understand the use of #if direcive */

#include <stdio.h>
#define	FLAG	8
int main()
{
	int a = 20, b = 4;
#if	FLAG>=3
	printf("Value of FLAG is greater than or equal to 3\n");
	a = a + b;
	b = a * b;
	printf("Value of variables a and b have been changed\n");
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("Prpgram completed\n");

	return 0;
}
