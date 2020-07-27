#include <stdio.h>
#define	SWAP(dtype, x, y)	{dtype t; t = x; x = y; y =t;}
int main()
{
	int s = 2, t = 5;	// wrong because variable t is also in define
	SWAP(int, s, t);
	printf("s = %d, t = %d\n", s, t);

	return 0;
}
