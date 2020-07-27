#include <stdio.h>
#include <stdlib.h>

void hello(void)
{
	printf("Hello world\n");
}

void bello(void)
{
	printf("Bello world\n");
}

void print(void (*fun)(void))
{
	fun();
}

int add(int x, int y)
{
	return x + y;
}

int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int division(int x, int y)
{
	return x / y;
}


int main()
{
	int a = 10, b = 30, c;
	
	/* This can be written like in two ways and first one is little famous */
	int (*fun)(int, int) = add;
	c = fun(a, b);

	//int (*fun)(int, int) = &add;
	//c = (*fun)(a, b);

	printf("c = %d\n", c);

	print(hello);	
	print(bello);	

	/* array of function pointers */
	int (*funptr[])(int, int) = {sum, sub, mul, division};
	int choice;
	printf("Enter choice to perform required operation:\n0: sum\n1: sub\n2: mul\n3: div\n\
			exit: anything other than listed 0 to 3\n");
	scanf("%d", &choice);
	switch(choice) {
		case 0: c = (*funptr[choice])(a, b);
			printf("c = %d\n", c);
			break;

		case 1: c = (*funptr[choice])(a, b);
			printf("c = %d\n", c);
			break;

		case 2: c = (*funptr[choice])(a, b);
			printf("c = %d\n", c);
			break;

		case 3: c = (*funptr[choice])(a, b);
			printf("c = %d\n", c);
			break;

		default: exit(1);
			 break;
	}


	return 0;
}
	
