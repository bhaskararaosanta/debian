/* warning and error directive demonstration */

#include <stdio.h>
int main()
{
	int a = 10, b = 5;
	printf("program started\n");
#warning	this message will show and continue compilation


//#error		the compilation stop in this instruction

	return 0;
}
