/* P8.13: Transpose of matrix */

#include <stdio.h>
#define	ROWS	3
#define	COLS	4

int main()
{
	int mat1[ROWS][COLS], mat2[COLS][ROWS], i, j;
	printf("Enter matrix mat1(%d x %d) row wise:\n", ROWS, COLS);
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			scanf("%d", &mat1[i][j]);
	for(i = 0; i < COLS; i++)
		for(j = 0; j < ROWS; j++)
			mat2[i][j] = mat1[j][i];
	printf("Transpose of matrix is:\n");
	for(i = 0; i < COLS; i++)
	{
		for(j = 0; j < ROWS; j++)
			printf("%5d", mat2[i][j]);
		printf("\n");
	}

	return 0;
}
