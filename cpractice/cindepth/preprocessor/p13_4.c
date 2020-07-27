/* P13.4 */

#include <stdio.h>
#define	PROD(x,y)	x*y
int main()
{
	printf("%d\t", PROD(2, 4));
	printf("%d\n", PROD(3+4, 5+1));	// it is wrong

	return 0;
}
