#include <stdio.h>
#define	FLAG
int main()
{
	int a = 20, b = 4;
#ifdef	FLAG
		printf("FLAG is defined\n");
		a++;
		b++;
#endif
#undef FLAG
//#ifdef	FLAG
#ifndef	FLAG
		printf("preprocessor\n");
		a++;
		b++;
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("Program completed\n");

	return 0;
}
