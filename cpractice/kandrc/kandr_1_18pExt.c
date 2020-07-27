#include <stdio.h>

/* count characters in input: 2nd version */

int main()
{
	int nc, c;
	for(nc = 0; getchar() != EOF; nc++) {
		;
	}
	printf("no of characters in input:%d\n", nc);

	return 0;
}
