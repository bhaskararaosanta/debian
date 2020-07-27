#include <stdio.h>
#define	ROWS	3
#define	COLS	4

int main()
{
	int i, j;
	int arr[ROWS][COLS] = {
				{10, 11, 12, 13},
				{20, 21, 22, 23},
				{30, 31, 32, 33}
			      };
	int (*ptr)[4];	// pointer to 1-D array of four integers
	printf("printing array elements using array notation:\n");
	for(i = 0; i < ROWS; i++) {
		for(j =0; j < COLS; j++) {
			printf("arr[%d][%d]:%d %d\n", i, j, arr[i][j], *(*(arr+i)+j));
		}
		printf("\n");
	}

	printf("printing array elements addresses:\n");
	for(i = 0; i < ROWS; i++) {
		for(j =0; j < COLS; j++) {
			printf("arr[%d][%d]:%p %p\n", i, j, &arr[i][j], (*(arr+i)+j));
		}
		printf("\n");
	}

	ptr = arr;
	//ptr++;	// valid and its 1-D array pointer variable
	//arr++;	// lvalue required error because its constant pointer
	printf("printing array elements using 1-D array pointer:\n");
	for(i = 0; i < ROWS; i++) {
		for(j =0; j < COLS; j++) {
			printf("arr[%d][%d]:%d %d\n", i, j, ptr[i][j], *(*(ptr+i)+j));
		}
		printf("\n");
	}

	printf("printing array elements addresses:\n");
	for(i = 0; i < ROWS; i++) {
		for(j =0; j < COLS; j++) {
			printf("arr[%d][%d]:%p %p\n", i, j, &ptr[i][j], (*(ptr+i)+j));
		}
		printf("\n");
	}



	return 0;
}




