// C program of nested function with the help of gcc extension

#include <stdio.h>
int main(void)
{
	auto int view(); // declare function with auto keyword 
	printf("Main\n");
	view(); // calling function 
	printf("Main\n");
	view(); // calling function 
        int view()
	{
		printf("View\n"); 
		return 1; 
	} 
	printf("GEEKS\n"); 
	return 0; 
} 
