#include <stdio.h>

#define	M	3
#define	N	4

int main()
{
	int arr[M][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int i, j;
	int (*ptr)[4] = arr;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("arr[%d][%d] = %d\t", i, j, arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("ptr[%d][%d] = %d\t", i, j, ptr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	
	printf("addr of 0th row 1 dimension array:%p\n", arr);
	printf("addr of 1st row 1 dimension array:%p\n", arr+1);
	printf("addr of 2nd row 1 dimension array:%p\n", arr+2);
	printf("\n");
	

	printf("addr of 0th row 0th col element:%p\n", *arr+0);
	printf("addr of 0th row 1st col element:%p\n", *arr+1);
	printf("addr of 0th row 2nd col element:%p\n", *arr+2);
	printf("addr of 0th row 3rd col element:%p\n", *arr+3);

	printf("\n");
	
	printf("addr of 1st row 0th col element:%p\n", *(arr+1)+0);
	printf("addr of 1st row 1st col element:%p\n", *(arr+1)+1);
	printf("addr of 1st row 2nd col element:%p\n", *(arr+1)+2);
	printf("addr of 1st row 3rd col element:%p\n", *(arr+1)+3);

	printf("\n");
	
	printf("addr of 2nd row 0th col element:%p\n", *(arr+2)+0);
	printf("addr of 2nd row 1st col element:%p\n", *(arr+2)+1);
	printf("addr of 2nd row 2nd col element:%p\n", *(arr+2)+2);
	printf("addr of 2nd row 3rd col element:%p\n", *(arr+2)+3);

	return 0;
}
