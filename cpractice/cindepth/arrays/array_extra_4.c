#include <stdio.h>

#define	ROWS	3
#define	COLS	4

int main()
{
	int s_arr[COLS] = {100, 200, 300, 400};
	int *sptr = s_arr;
	int d_arr[ROWS][COLS] = {
					{10, 11, 12, 13},
					{20, 21, 22, 23},
					{30, 31, 32, 33}
				     };
	int (*dptr)[COLS] = d_arr;

	int i = 0, j = 0;
	for(i = 0; i < COLS; i++) {
		printf("address of s_arr[%d]:%p\t%p\t%p\n", i, sptr++, &s_arr[i], (s_arr+i));
	}
	printf("\n");

	for(i = 0; i < COLS; i++) {
		printf("1D array elements:%d\t", s_arr[i]);
	}
	printf("\n");

	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("address of d_arr[%d][%d]:%p\t%p\t%p\t%p\n", i, j, &d_arr[i][j], (*(d_arr + i)+j), \
					(d_arr[i]+j), (*(dptr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("2D array elements:%d\t", d_arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}

