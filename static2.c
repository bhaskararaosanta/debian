#include<stdio.h>
static int gInt = 1;
static void staticDemo()
{
	static int i;
	{
		printf("%p\n", &i);
		static int i = 10;
		printf("%d\t%p ", i, &i);
		i++;
	}
	printf("%d\t%p\n", gInt,&gInt);
	gInt++;
}
 
int main()
{
	int j=100;
	int k=200;
	printf("%d\t%p\n", j, &j);
	printf("%d\t%p\n", k, &k);
	staticDemo();
	staticDemo();
	static int i;
	printf("%d\t%p ", i,&i);
	i++;
	printf("%d\t%p\n", gInt,&gInt);
	gInt++;
}
