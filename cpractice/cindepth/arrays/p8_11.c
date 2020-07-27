/* P8.11: addition of two matrices */

#define	ROWS	3
#define	COLS	4
#include <stdio.h>

int main()
{
	int i, j, mat1[ROWS][COLS], mat2[ROWS][COLS], mat3[ROWS][COLS];
	printf("Enter matrix mat1[%d x %d] row wise:", ROWS,COLS);
	for(i = 0;  i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			scanf("%d", &mat1[i][j]);
	printf("Enter matrix mat2[%d x %d] row wise:", ROWS,COLS);
	for(i = 0;  i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			scanf("%d", &mat2[i][j]);
	/* Addition */
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			mat3[i][j] = mat1[i][j] + mat2[i][j];
	printf("The resultant matrix mat3 is:\n");
	for(i = 0;  i < ROWS; i++) {
		for(j = 0; j < COLS; j++)
			printf("%5d", mat3[i][j]);
		printf("\n");
	}

	return 0;
}


