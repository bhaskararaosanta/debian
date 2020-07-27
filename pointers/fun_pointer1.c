#include <stdio.h>

void A()
{
	printf("Hello\n");
}

void B(void (*ptr)()) // function pointer as argument
{
	ptr(); // call-back function that "ptr" points to
}

void PrintHello(char *name)
{
	printf("Hello %s\n", name);
}

int Add(int a, int b)
{
	return a+b;
}

int main()
{
	int c;
	//void (*p)() = A;
	//B(p);
	B(A);
	void (*ptr)(char *);
	int (*ptradd)(int, int);
	ptr = &PrintHello;
	(*ptr)("Bhaskar");
	ptr = PrintHello;
	ptr("Bhaskar");

	ptradd = Add;
	printf("sum = %d\n", ptradd(10, 20));

	return 0;
}
