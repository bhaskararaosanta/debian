/* P9.6: pointer to pointer */

#include <stdio.h>
int main()
{
	int a = 5;
	int *pa;
	int **ppa;
	pa = &a;
	ppa = &pa;
	printf("Address of a = %p\n", &a);
	printf("Value of pa = Address of a = %p\t%p\n", pa, &a);
	printf("Value of *pa = Value of a = %d\t%d\t%d\n", *pa, a, *(&a));
	printf("Address of pa = %p\n", &pa);
	printf("Value of ppa = Address of pa = %p\t%p\n", ppa , &pa);
	printf("Value of *ppa = Value of pa = %p\t%p\n", *ppa, pa);
	printf("Value f **ppa = value of *pa = value of a = %d\t%d\t%d\n", **ppa, *pa, a);
	printf("Address of ppa = %p\n", &ppa);

	return 0;
}
