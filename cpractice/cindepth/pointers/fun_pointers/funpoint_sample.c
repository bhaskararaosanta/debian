#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int  b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}
int callback(int (*ptrcallback)(int, int), int p, int q)
{
	ptrcallback(p, q);
}

int main()
{
	int x = 200, y = 100, c;
	/* int (*funptr)(int, int) = &add;
	c = (*funptr)(x, y); */

	int (*funptr)(int, int) = add;
	c = funptr(x, y);
	
	printf("c = %d\n", c);
	c = 0;

	c = callback(add, x, y);
	printf("c = %d\n", c);


	return 0;
}
