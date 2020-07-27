#include <stdio.h>
#define	PROD(x,y)	x*y	// wrong and it shall be written as ((x)*(y))
int main()
{
	printf("%d\t", PROD(2, 4));
	printf("%d\n", PROD(3+4, 5+1));

	return 0;
}
