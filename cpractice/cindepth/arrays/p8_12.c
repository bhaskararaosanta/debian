/* P8.12: Multiplication of two matrices */
#include <stdio.h>

#define	ROWS1	3
#define	COLS1	4
#define	ROWS2	COLS1
#define	COLS2	2

int main()
{
	int mat1[ROWS1][COLS1], mat2[ROWS2][COLS2], mat3[ROWS1][COLS2];
	int i, j, k;
	printf("Enter matrix mat1(%d x %d) row wise:\n", ROWS1, COLS1);
	for(i = 0; i < ROWS1; i++)
		for(j = 0; j < COLS1; j++)
			scanf("%d", &mat1[i][j]);
	printf("Enter matrix mat2(%d x %d) row wise:\n", ROWS2, COLS2);
	for(i = 0; i < ROWS2; i++)
		for(j = 0; j < COLS2; j++)
			scanf("%d", &mat2[i][j]);
	printf("\n");
	printf("Enteried matrix mat1(%d x %d) row wise:\n", ROWS1, COLS1);
	for(i = 0; i < ROWS1; i++)
		for(j = 0; j < COLS1; j++)
			printf("%d ", mat1[i][j]);
	printf("\n");
	printf("Entered matrix mat2(%d x %d) row wise:\n", ROWS2, COLS2);
	for(i = 0; i < ROWS2; i++)
		for(j = 0; j < COLS2; j++)
			printf("%d ", mat2[i][j]);
	printf("\n");
	/* Multiplication */
	for(i = 0; i < ROWS1; i++)
		for(j = 0; j < COLS2; j++)
		{
			mat3[i][j] = 0;
			for(k = 0; k < COLS1; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];
		}
	printf("The resultant matrix mat3 is:\n");
	for(i = 0; i < ROWS1; i++)
	{
		for(j = 0; j < COLS2; j++)
			printf("%5d", mat3[i][j]);
		printf("\n");
	}

	return 0;
}

