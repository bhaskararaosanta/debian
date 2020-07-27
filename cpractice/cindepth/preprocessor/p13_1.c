/* P13.1: Program to show macro expansion */

#include <stdio.h>
#define	MSSG	"I Understand the use of #define\n"

int main()
{
	printf(MSSG);

	//printf("MSSG"); This is not useful because it will not call macro and instead print MSSG on output
	
	return 0;
}
