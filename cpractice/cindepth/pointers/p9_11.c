/* P9.11: Program to understand differences between pointer to an integer and pointer to an array of integers */

#include <stdio.h>
int main()
{
	int *p;		// p can point to an integer
	int (*ptr)[5];	// ptr can point to an complete array of 5 integers
	int arr[5];
	p = arr;	// points to the 0th element of arr
	ptr = &arr;	// points to the whole array arr
	printf("p = %p, ptr = %p\n", p, ptr);
	++p;
	++ptr;
	printf("p = %p, ptr = %p\n", p, ptr);

	return 0;
}



