/* p13.20: Program to display the values of predefined constants */

#include <stdio.h>
int main()
{
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%s\n", __FILE__);
	printf("%s\n", __LINE__);
	
	return 0;
}
