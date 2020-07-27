/* P8.10: Program to input and display matrix */

#define	ROWS	3
#define	COLS	4
#include <stdio.h>

int main()
{
	int mat[ROWS][COLS], i, j;
	printf("Enter the elements of the matrix[%d x %d] row wise:", ROWS,  COLS);
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			scanf("%d", &mat[i][j]);

	printf("the matrix that you entered is:\n");
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}

	return 0;
}

