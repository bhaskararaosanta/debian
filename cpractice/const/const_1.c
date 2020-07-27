#include <stdio.h>

#define	MAXTWO(a, b)		(((a) > (b)) ? (a) : (b))
#define	MAXTHREE(a, b, c)	(((a) > (b) && (a) > (c)) ? (a) : ((b) > (c))? (b) : (c))
#define	SWAP(byte)		((((byte) & 0xff00) >> 8) | (((byte) & 0x00ff) << 8))

int main()
{
	int a = 10;
	const int b = 20;
	int *aptr = &a;
	int *bptr = &b;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("a = %d\n", *aptr);
	printf("b = %d\n", *bptr);
	a++;
	//b++; // error like incrementing read-only constant
	++*aptr;
	++*bptr;
	printf("a = %d\n", *aptr);
	printf("b = %d\n", *bptr);
	printf("\n\n");
	
	int c = 10;
	const int d = 20;
	const int *const cptr = &c;
	int *dptr = &d;

	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("c = %d\n", *cptr);
	printf("d = %d\n", *dptr);
	c++;
	//d++; // error such as incrementing read-only constant
	//++*cptr;
	++*dptr;
	//++cptr; // error such as incrementing read only pointer
	printf("c = %d\n", *cptr);
	printf("d = %d\n", *dptr);
#line	150
	printf("demonstrating line directive:\n");
	printf("line number:%d\n", __LINE__);

	int x = 1000, y = 2000, z = 3000;
	printf("finding maximum of x and y using macro:%d\n", MAXTWO(x, y));
	printf("finding maximum of x, y and z using macro:%d\n", MAXTHREE(x, y, z));

	printf("finding maximum of 2500 and 2100 using macro:%d\n", MAXTWO(x+1500, y+100));
	printf("finding maximum of 4000, 3000 and 5000 using macro:%d\n", MAXTHREE(x+3000, y+1000, z+2000));
	
	int h = 0xA0F2;
	printf("swap bytes in variable h:%X\n", SWAP(h));

	return 0;
}
