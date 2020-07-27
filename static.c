#include <stdio.h>
void display();

int main()
{
	int c = 10;
	display();
	printf("%d\n",c);
	c += 5;
	c = 10;
	display();
	printf("%d\n",c);
}
void display()
{
	static int c = 0;
	printf("%d\n",c);
	c += 5;
}
