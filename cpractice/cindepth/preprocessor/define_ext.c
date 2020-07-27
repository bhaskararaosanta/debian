#include <stdio.h>

#define	CONST	100
#define	PRINT(var)	printf(#var" = %d\n", var)
#define	PASTE(x, y)	x##y

int main()
{
	int k2 = 30, k3 = 40;
	int i = 200;
	printf("CONST value:%d\n", CONST);

#undef	CONST
	//printf("CONST value:%d\n", CONST);	// CONST undeclared error because of undef used above

	/* stringing operator */
	PRINT(i);




	printf("Value of k2 = %d\nValue of k3 = %d\n", PASTE(k, 2), PASTE(k, 3));
	
#line	100	"newfile.c"
	printf("Filename is:%s\n", __FILE__);
	printf("Line no. is:%d\n", __LINE__);
	printf("Date	 is:%s\n", __DATE__);

#warning	This message will show as warning during compilation \
	but compilation finishes and generates executable

//#error	compilation will halt with this instruction and this message will be shown in output

	return 0;
}

