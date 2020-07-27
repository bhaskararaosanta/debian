#include <stdio.h>
#define	ROWS	3
#define	COLS	4

int main()
{
	int i, j;
	int arr[ROWS][COLS] = {10, 11, 12, 13, 20, 21, 22, 23, 30, 31, 32, 33};
	int (*ptr)[COLS];
	ptr = arr;
	printf("printing array using array index:\n");
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("arr[%d][%d] = %d\t", i, j, arr[i][j]);
		}
		printf("\n");
	}

	printf("printing each 1-D array and its elements addresses:\n");
	printf("Address of 0th 1-D array:%p\n", arr);
	printf("Address of 1st 1-D array:%p\n", arr+1);
	printf("Address of 2nd 1-D array:%p\n", arr+2);
	printf("Address of 0th 1-D array using array pointer:%p\n", ptr);
	printf("Address of 1st 1-D array using array pointer:%p\n", ptr+1);
	printf("Address of 2nd 1-D array using array pointer:%p\n", ptr+2);

	printf("Address of 0th 1-D array and 0th element:%p\n", *(arr+0));
	printf("Address of 1st 1-D array and 0th element:%p\n", *(arr+1));
	printf("Address of 2nd 1-D array and 0th element:%p\n", *(arr+2));

	printf("Address of 0th 1-D array and 1st element:%p\n", *(arr+0)+1);
	printf("Address of 1st 1-D array and 1st element:%p\n", *(arr+1)+1);
	printf("Address of 2nd 1-D array and 1st element:%p\n", *(arr+2)+1);

	printf("Address of 0th 1-D array and 2nd element:%p\n", *(arr+0)+2);
	printf("Address of 1st 1-D array and 2nd element:%p\n", *(arr+1)+2);
	printf("Address of 2nd 1-D array and 2nd element:%p\n", *(arr+2)+2);

	printf("Address of 0th 1-D array and 3rd element:%p\n", *(arr+0)+3);
	printf("Address of 1st 1-D array and 3rd element:%p\n", *(arr+1)+3);
	printf("Address of 2nd 1-D array and 3rd element:%p\n", *(arr+2)+3);

	printf("Value of 0th 1-D array and 0th element:%d\n", *(*(arr+0)));
	printf("Value of 1st 1-D array and 0th element:%d\n", *(*(arr+1)));
	printf("Value of 2nd 1-D array and 0th element:%d\n", *(*(arr+2)));

	printf("Value of 0th 1-D array and 1st element:%d\n", *(*(arr+0)+1));
	printf("Value of 1st 1-D array and 1st element:%d\n", *(*(arr+1)+1));
	printf("Value of 2nd 1-D array and 1st element:%d\n", *(*(arr+2)+1));

	printf("Value of 0th 1-D array and 2nd element:%d\n", *(*(arr+0)+2));
	printf("Value of 1st 1-D array and 2nd element:%d\n", *(*(arr+1)+2));
	printf("Value of 2nd 1-D array and 2nd element:%d\n", *(*(arr+2)+2));

	printf("Value of 0th 1-D array and 3rd element:%d\n", *(*(arr+0)+3));
	printf("Value of 1st 1-D array and 3rd element:%d\n", *(*(arr+1)+3));
	printf("Value of 2nd 1-D array and 3rd element:%d\n", *(*(arr+2)+3));



	return 0;
}


