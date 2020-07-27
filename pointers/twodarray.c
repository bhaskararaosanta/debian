#include <stdio.h>
#define	M	3
#define	N	4

int main()
{
	int arr[M][N] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	//int arr[M][N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("addr arr[%d][%d]:%p\t", i, j, &arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("addr of 0th 1-D array:%p\n", arr);
	printf("addr of 1st 1-D array:%p\n", arr+1);
	printf("addr of 2nd 1-D array:%p\n", arr+2);

	printf("addr of 0th 1-D array 0th element:%p\n", *arr);
	printf("addr of 1st 1-D array 0th element:%p\n", *(arr+1));
	printf("addr of 2nd 1-D array 0th element:%p\n", *(arr+2));

	printf("addr of 0th 1-D array 1st element:%p\n", *(arr)+1);
	printf("addr of 1st 1-D array 1st element:%p\n", *(arr+1)+1);
	printf("addr of 2nd 1-D array 1st element:%p\n", *(arr+2)+1);

	printf("addr of 0th 1-D array 2nd element:%p\n", *(arr)+2);
	printf("addr of 1st 1-D array 2nd element:%p\n", *(arr+1)+2);
	printf("addr of 2nd 1-D array 2nd element:%p\n", *(arr+2)+2);

	printf("addr of 0th 1-D array 3rd element:%p\n", *(arr)+3);
	printf("addr of 1st 1-D array 3rd element:%p\n", *(arr+1)+3);
	printf("addr of 2nd 1-D array 3rd element:%p\n", *(arr+2)+3);


	return 0;
}
