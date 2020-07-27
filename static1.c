#include<stdio.h>
 
void staticDemo()
{
	static int i;
	{
	        static int i = 20;
		printf("%d ", i);
		i++;
	}
	printf("%d\n", i);
	i++;
}
 
int main()
{
	staticDemo();
	staticDemo();
	staticDemo();
	return 0;
}
