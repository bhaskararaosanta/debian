/* P10.3: Input and output strings using scanf and printf */

#include <stdio.h>
int main()
{
	char name[40];
	printf("Enter a name:");
	scanf("%s", name);
	printf("%s %s\n", name, "srinivasa");

	return 0;
}
