#include <stdio.h>

#define	M	100
#define	N

int main()
{
	int a, b;
#undef	M
	//printf("%d\n", M);
#define	M	200
	printf("%d\n", M);
#if(1)
	printf("%d\n", M);
#else
	printf("Its not true\n");
#endif

	return 0;
}
