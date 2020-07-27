/* P9.9: Program to print the value of array elements using pointer and subscript ntation */

#include <stdio.h>
int main()
{
	int arr[5] = {5, 10, 15, 20, 25};
	int i;
	for(i = 0; i < 5; i++) {
		printf("Value of arr[%d] = ", i);
		printf("%d\t", arr[i]);
		printf("%d\t", *(arr+i));
		printf("%d\t", *(i+arr));
		printf("%d\n", i[arr]);	// [arr]i, [i]arr these are illegal
		printf("Address of arr[%d] = %p\t%p\n", i,&arr[i], (arr+i));
	}

	return 0;
}
