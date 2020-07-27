/* p8.3 program to count even and add numbers in an array */

#include <stdio.h>
#define	SIZE	10
int main()
{
	int arr[SIZE], i, even = 0, odd = 0;
	for(i = 0; i < SIZE; i++) {
		printf("enter a value for arr[%d]:", i);
		scanf("%d", &arr[i]);
		if(arr[i] %2 == 0)
			even++;
		else
			odd++;
	}
	printf("No of even numbers = %d\nNo of odd numbers = %d\n", even, odd);

	return 0;
}
