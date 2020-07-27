#include <stdio.h>

int fact(int x)
{
	int factorial = 1;
	if(x == 1) {
		return 1;
	}
	factorial = x * fact(x-1);
	return factorial;
}	

int main()
{
	int a = 5;
	printf("%d\n", fact(a));

	return 0;
}
