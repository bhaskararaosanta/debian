#include <stdio.h>

int main()
{
	int i, j;
	int arr[5] = {10, 20, 30, 40, 50};
	int twodarr[3][4] = {
				{11, 12, 13, 14},
				{21, 22, 23, 24},
				{31, 32, 33, 34}
			       };

	int *p  = arr;
	int (*ptr)[4] = twodarr;
	printf("1-D array elements:\n");
	for(i = 0; i < 5; i++) {
		printf("%d %d %d %d\n", arr[i], *(arr+i), p[i], *(p+i));
	}
	printf("\n");
	printf("2-D array elements:\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 4; j++) {
			printf("%d %d %d %d", twodarr[i][j], *(*(twodarr+i)+j), ptr[i][j], *(*(ptr+i)+j));
		}
		printf("\n");
	}

	return 0;
}

