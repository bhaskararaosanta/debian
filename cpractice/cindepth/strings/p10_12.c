/* P10.12: Program to sort the two-dimensional character array */

#include <stdio.h>
#include <string.h>
#define	M	5
#define	N	10
int main()
{
	char arr[M][N] = {
				"white",
				"red",
				"green",
				"yellow",
				"blue"
			};
	char temp[10];
	int i, j;
	printf("Before sorting the array:\n");
	for(i = 0; i < M; i++) {
		printf("String = %s\t", arr[i]);
		printf("Address of string = %p\n", arr[i]);
	}
	printf("\n");
	for(i = 0; i < M; i++)
		for(j = i+1; j < M; j++)
			if(strcmp(arr[i], arr[j]) > 0) {
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], temp);
			}

	printf("After sorting the array:\n");
	for(i = 0; i < M; i++) {
		printf("String = %s\t", arr[i]);
		printf("Address of string = %p\n", arr[i]);
	}

	return 0;
}
