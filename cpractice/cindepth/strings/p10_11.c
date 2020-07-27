/* P10.11: Program to print the strings of the two-dimensional character array */

#include <stdio.h>
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
	int i;
	for(i = 0; i < M; i++) {
		printf("String = %s\t", arr[i]);
		printf("Address of string = %p\n", arr[i]);
	}

	return 0;
}
