/* P10.15: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *arrp[10], str[20];
	int i;
	for(i = 0; i < 10; i++) {
		printf("Enter string %d:", i+1);
		gets(str);
		/* Now allocate memory sufficinet to hold the string */
		arrp[i] = (char *)malloc(strlen(str) + 1);
		strcpy(arrp[i], str);
	}
	for(i = 0; i < 10; i++) {
		printf("%s\t", arrp[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++) {
		free(arrp[i]);
	}

	return 0;
}
