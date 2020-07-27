#include <stdio.h>

void fun1(void)
{
	printf("fun1\n");
}

void fun2(void)
{
	printf("fun2\n");
}

void wrapper(void (*fun)()) // formal arg is a function pointer to fun1 and fun2 for their respective calls
{
	fun();			// using function pointer we are calling functions
}

int main()
{
	wrapper(fun1);
	wrapper(fun2);

	return 0;
}
