#include <stdio.h>

int main()
{
	int arr[10] = {25, 38};
	int *ptr, i;
	printf("arr[0] = %d\narr[1] = %d\n", arr[0], arr[1]);
	printf("address of arr[0] = %p\naddress of arr[1] = %p\n", &arr[0], &arr[1]);
	ptr = arr;
	i = *ptr++;	// equal to *(ptr++)
	printf("i = %d\tptr value = %p\n", i, ptr);
	printf("arr[0] = %d\narr[1] = %d\n", arr[0], arr[1]);
	ptr = arr;
	i = *++ptr;	// equal to *(++ptr)
	printf("i = %d\tptr value = %p\n", i, ptr);
	printf("arr[0] = %d\narr[1] = %d\n", arr[0], arr[1]);
	ptr = arr;
	i = ++*ptr;	// equal to ++(*ptr)
	printf("i = %d\tptr value = %p\n", i, ptr);
	printf("arr[0] = %d\narr[1] = %d\n", arr[0], arr[1]);
	ptr = arr;
	i = (*ptr)++;
	printf("i = %d\tptr value = %p\n", i, ptr);
	printf("arr[0] = %d\narr[1] = %d\n", arr[0], arr[1]);

	return 0;
}


