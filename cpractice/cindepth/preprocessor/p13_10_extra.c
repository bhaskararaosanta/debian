#include <stdio.h>
#define	MACRO(x)	if(x == 0) printf("Out for Duck\n")
int main()
{
	int runs = 12;
	if(runs < 100) //{   without these braces result will be unexpected
		MACRO(runs);
	//}
	else //{
		printf("scored a century\n");
	//}

	return 0;
}
