#include<stdio.h>

int main()
{
	static int var = 10;
	//int var = 10;  
	/* if we remove it will become infinite loop & everytime var initialized 
	 * to 10 unlinke static which initializes only once */
	printf("%d\n", var--);
	if(var)
		main();
	return 0;
}
