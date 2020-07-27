#include <stdio.h>
#define	NUM	20
#define	NUMSQUARE	(NUM * NUM)
#define	SUM(x, y)	((x) + (y))
#define	PROD(x, y)	((x) * (y))
#define	STRINGIZING(var, format)	printf(#var"=%"#format"\n", var);
#define	TOKENPASTE(a, b)	a##b

int main()
{
	int a = 30, b = 40;
	int k2 = 1000;
	float c = 20;
	printf("NUM value:%d\n", NUM);
	printf("NUMSQUARE value:%d\n", NUMSQUARE);
	printf("Sum of a and b:%d\n", SUM(a, b));
	printf("Sum of a and b:%d\n", SUM(a+10, b+10));
	printf("product of a and b:%d\n", PROD(a, b));
	STRINGIZING(a, d);
	STRINGIZING(c, 0.2f);
	printf("k2 = %d\n", TOKENPASTE(k, 2));

#ifdef	NUM
	printf("NUM value:%d\n", NUM);
#endif

//#undef	NUM

#ifndef	NUM
	printf("NUM directive is not defined\n");
#endif

#if	NUM>=50
	printf("NUM is not greater than 50\n");
#elif	NUM>=30
	printf("NUM is not greater than 30\n");
#elif	NUM>=20
	printf("NUM is greater than or equal to 20\n");
#else
	printf("Invalid\n");
#endif

#warning	This warning message shows during compilation and compilation will not stop.

//#error		This error message shows during compilation and compilation will halt.

	return 0;
}
