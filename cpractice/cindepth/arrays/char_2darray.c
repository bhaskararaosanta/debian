#include <stdio.h>
#define	MONTHS	12
int main()
{
	int i;
	char *month_name[12] = {
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"October",
				"November",
				"December"
			       };

	for(i = 0; i < MONTHS; i++) {
		printf("Address of month_name[%2d] string:%p\n", i, month_name[i]);
	}
	printf("\n");

	for(i = 0; i < MONTHS; i++) {
		printf("data of month_name[%2d] string:%s\n", i, month_name[i]);
	}
	printf("\n");

	for(i = 0; i < MONTHS; i++) {
		printf("data of month_name[%2d] first char:%c\n", i, *month_name[i]);
	}
	printf("\n");

	return 0;
}

	
