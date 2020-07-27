#include <stdio.h>
#define	FLAG	1	// by making FLAG constant less than 3 to test the program
int main()
{
	int a = 20, b = 4;
#if	FLAG==0
		printf("Value of FLAG is zero\n");
		a++;
		b++;
#elif	FLAG==1
		printf("Value of FLAG is one\n");
		a--;
		b--;
#elif	FLAG==2
		printf("Value of FLAG is two\n");
		a = a-3;
		b = b-3;
#else	
		printf("Value of FLAG is greater than two or less than zero\n");
		a = a+b;
		b = a-b;
#endif
	printf("a = %d, b = %d\n", a, b);
	printf("Program completed\n");

	return 0;
}
