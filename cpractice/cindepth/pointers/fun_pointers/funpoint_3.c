#include <stdio.h>
#include <stdlib.h>

void add(int a, int b)
{
	printf("a+b = %d\n", a+b);
}

void subtract(int a, int b)
{
	printf("a-b = %d\n", a-b);
}

void multiply(int a, int b)
{
	printf("a*b = %d\n", a*b);
}

int main()
{
	void(*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a = 15, b = 10;
	printf("Enter user choie:\n0:for add\n1: subtract\n2: multiply\n>=3: exit\n");

	scanf("%d", &ch);
	if(ch > 2) {
		exit(1);
	}

	fun_ptr_arr[ch](a, b);

	return 0;
}
