/* P10.10: */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *str;
	str = (char *)malloc(10);
	printf("Enter a string: ");
	scanf("%s", str);
	printf("String entered is:%s\n", str);

	return 0;
}
