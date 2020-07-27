/* P9.20: Passing 1-D array to function */

#include <stdio.h>
void func(int a[]);
int main()
{
	int i, arr[5] = {3, 6, 2, 7, 1};
	func(arr);
	printf("inside main(): ");
	for(i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void func(int a[])
{
	int i;
	printf("inside func(): ");
	for(i = 0; i < 5; i++) {
		a[i] = a[i] + 2;
		printf("%d ", a[i]);
	}
	printf("\n");
}
