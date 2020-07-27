#include <stdio.h>

#define	TOT	5
#define	ROWS	3
#define	COLS	4

int main()
{
	int a[TOT] = {10, 20, 30, 40, 50};
	int *p;
	p = a;
	int i, j;

	for(i = 0; i < TOT; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i = 0; i < TOT; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");

	int arr[ROWS][COLS] = {
				{100, 200, 300, 400},
				{101, 201, 301, 401},
				{102, 202, 302, 402}
			      };
	int (*ptr)[COLS];
	ptr = arr;

	printf("address of 0th row:%p\n", &arr);
	printf("address of 1st row:%p\n", arr+1);
	printf("address of 2nd row:%p\n", arr+2);
	printf("address of 0th row 0th col element:%p\n", *arr);
	printf("address of 1st row 0th col element:%p\n", *(arr+1));
	printf("address of 2nd row 0th col element:%p\n", *(arr+2));
	printf("address of 0th row 1st col element:%p\n", *arr+1);
	printf("address of 1st row 1st col element:%p\n", *(arr+1)+1);
	printf("address of 2nd row 1st col element:%p\n", *(arr+2)+1);

	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
