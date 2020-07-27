#include <stdio.h>

void fun1()
{
	printf("func1.\n");
}

void fun2()
{
	printf("func2.\n");
}

void wrapper(void (*fun)())
{
	fun();
}

int main()
{
	wrapper(fun1);
	wrapper(fun2);

	return 0;
}
