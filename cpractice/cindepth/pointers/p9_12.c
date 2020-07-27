
/* P9.12: Program to dereference a pointer to an array */

#include <stdio.h>
int main()
{
	int *a;
	printf("value of a = %p\n", a);
	int arr[5] = {3, 5, 6, 7, 9};
	int *p = arr;
	int (*ptr)[5] =&arr;
	printf("p = %, ptr = %p\n", p, ptr);
	printf("*p = %d, *ptr = %p\n", *p, *ptr);
	printf("sizeof (p) = %u, sizeof (*p) = %u\n", sizeof(p), sizeof(*p));
	printf("sizeof (ptr) = %u, sizeof (*ptr) = %u\n", sizeof(ptr), sizeof(*ptr));

	return 0;
}
