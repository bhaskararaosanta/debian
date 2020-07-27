/* P9.2: deferencing pointer variables */

#include <stdio.h>

int main()
{
	int a = 87;
	float b = 4.5;
	int *p1 = &a;
	float *p2 = &b;
	printf("Value of p1 = %p\tAddress of a = %p\n", p1, &a);
	printf("Value of p2 = %p\tAddress of b = %p\n", p2, &b);
	printf("Address of p1 = %p\n", &p1);
	printf("Address pf p2 = %p\n", &p2);
	printf("Value of a = %d %d %d\n", a, *p1, *(&a));
	printf("Value of b = %.1f %.1f %.1f\n", b, *p2, *(&b));

	return 0;
}
