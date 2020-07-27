#include <stdio.h>

int main()
{
	int a, b;
	a = b = 100;
//#error	The compilation will stop by showing this message as error directive
#warning	The comilation will continue but it will show this message as warning directive

	printf("a = %d\nb = %d\n", a, b);

	return 0;
}
