#include <stdio.h>
//#define	MAX
int main()
{
	int a = 20, b = 4;
#ifndef	MAX
		printf("MAX is not defined\n");
		a--;
		b--;
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("Program completed\n");

	return 0;
}
