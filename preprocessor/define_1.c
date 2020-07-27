#include <stdio.h>

#define	MAX(A,B)	((A > B)? A : B)
#define	NUM	1000

int main()
{
	int a = 10, b = 20;

#undef	NUM

#define	NUM	2000

	printf("%d\n", NUM);
#if	(1)
	printf("%d\n", NUM);
#else
	printf("else is executed\n");
#endif
	printf("maximum between a and b:%d\n", MAX(a, b));

	return 0;
}
