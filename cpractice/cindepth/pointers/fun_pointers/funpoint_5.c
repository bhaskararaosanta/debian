#include <stdio.h>

void print(void)
{
	printf("Hello function pointer\n");
}

void callfun(void (*fun)(void))
{
	fun();
}

void add(int x, int y)
{
	printf("x+y = %d\n", x + y);
}

int main()
{
	int sum;
	void (*fun)(int, int) = add;
	fun(20, 30);
	
	/* void (*fun)(int, int) = &add;
	(*fun)(20, 30);  // instead of these we can use above declaration also */

	callfun(print);
	

	return 0;
}
