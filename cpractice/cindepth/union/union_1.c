#include <stdio.h>
#include <string.h>

int main()
{
	typedef union {
		int a;
		char b[10];
		float c;
	} Union;

	Union x, y = {100};
	printf("size of union:%d or %d\n", sizeof(x), sizeof(Union));
	x.a = 50;
	strcpy(x.b, "hello");
	//x.c = 21.50;
	
	printf("Union x:\n%d\n %s\n %f\n", x.a, x.b, x.c);
	printf("Union y:\n%d\n %s\n %f\n", y.a, y.b, y.c);

	return 0;
}
