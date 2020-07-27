#include <stdio.h>

/* count characters in input: 1st version */

int main()
{
	int nc, c;
	while((c = getchar()) != EOF) {
		nc++;
	}
	printf("no of characters in input:%d\n", nc);

	return 0;
}
