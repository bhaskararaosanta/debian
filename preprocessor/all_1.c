#include <stdio.h>

#define	CONST	100
#define	TRUE
#define	MAX(p,q)	(((p)>(q))?(p):(q))
#define	PRINT(val)	printf(#val "= %d\n", val)
#define	CONCAT(p,q)	p##q

int main()
{
	int a = 10;
	printf("Value of CONST:%d\n", CONST);
#ifdef	TRUE
	printf("TRUE directive is defined\n");
#else
	printf("TRUE directive is not defined\n");
#endif

#if	a == 10
	printf("value of a is:%d\n", a);
#else
	printf("value of a is not equal to:%d\n", a);
#endif

#warning	Compilation will continue by showing this message as warning

//#error		Compilation will halt by showing this message as error

#line	1000	"testing.c"
	printf("filename and line number:%s %d\n", __FILE__, __LINE__);

	int x = 100, y = 200;
	printf("maximum between x and y:%d\n", MAX(x, y));

	PRINT(x);

	int k2 = 300, k3 = 400;
	printf("Value of k2 and k3 using token paste operator:%d %d\n", CONCAT(k, 2), CONCAT(k, 3));


	return 0;
}
