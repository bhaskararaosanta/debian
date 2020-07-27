/* P13.6 */

#include <stdio.h>
#define	SQUARE(x)	((x)*(x))
int main()
{
	int k = 5, s;
	s = SQUARE(k++);
	printf("s = %d, k = %d\n", s, k);

	return 0;
}
