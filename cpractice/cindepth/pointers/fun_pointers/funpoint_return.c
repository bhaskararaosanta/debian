#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

typedef int (*mathfunc)(int, int);

mathfunc fun(int type) 
{
	if(type == 1)
		return add;
	if(type == 2)
		return sub;
}

/* Below is without typedef */

/*
int (*fun(int type))(int, int)
{
	if(type == 1)
		return add;
	if(type == 2)
		return sub;
}
*/


int main()
{
	int (*somefun)(int, int);
	somefun = fun(1);
	int c = somefun(1, 2);
	printf("c = %d\n", c);

	return 0;
}
