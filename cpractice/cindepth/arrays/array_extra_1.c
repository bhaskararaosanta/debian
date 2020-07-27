#include <stdio.h>

#define	ROWS	3
#define	COLS	4
#define	COUNT	6

int main()
{
	int i;
	int arr[COUNT] = {100, 500, 800, 200, 700, 400};
	int *ptr;
	ptr = arr;
	for(i = 0; i < COUNT; i++) {
		printf("Addr  of arr[%d]:%p %p\t", i, &arr[i], (arr+i));
		printf("Value of arr[%d]:%d %d\n", i, arr[i], *(arr+i));
	}
	printf("\n");
	printf("address where pointer variable stored:%p\n", &ptr);

	for(i = 0; i < COUNT; i++) {
		printf("Addr  of arr[%d]:%p %p\t", i, &ptr[i], (ptr+i));
		printf("Value of arr[%d]:%d %d\n", i, ptr[i], *(ptr+i));
	}

	//arr++;	// invalid with lvalue required error and its const pointer
	ptr++;		// valid because ptr is a pointer variable

	return 0;
}
