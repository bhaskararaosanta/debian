#include <stdio.h>

#define	M	3
#define	N	4

int main()
{
	int arr[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("arr[%d][%d] = %2d\t", i, j, arr[i][j]);
		}
		printf("\n");
	}




	return 0;
}
