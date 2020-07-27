#include <stdio.h>
#define	SQUARE(x)	((x) * (x))

int square(int p)
{
	return p*p;
}

int main()
{
	int k = 5, s;
	s = SQUARE(k++);
	printf("s = %d, k = %d\n", s, k);

	k = 5;
	s = square(k++);
	printf("s = %d, k = %d\n", s, k);

	return 0;
}
