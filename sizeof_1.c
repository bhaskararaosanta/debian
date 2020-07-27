#include <stdio.h>

struct employee {
	int account;
	char name[40];
	float salary;
};

int main()
{
	struct employee *emp;
	int a, b, c;
	int *aptr, *bptr, *cptr;
	float x, y, z;
	float *xptr, *yptr, *zptr;
	char i, j, k;
	char *iptr, *jptr, *kptr;

	printf("size of int a					:%d\n", sizeof(a));
	printf("size of float x					:%d\n", sizeof(x));
	printf("size of int pointer				:%d\n", sizeof(aptr));
	printf("size of float pointer				:%d\n", sizeof(xptr));
	printf("size of char i					:%d\n", sizeof(i));
	printf("size of char pointer				:%d\n", sizeof(iptr));
	printf("size of struct employee				:%d\n", sizeof(struct employee));
	printf("size of struct employee pointer			:%d\n", sizeof(emp));
	printf("size of int pointer derefence (*aptr)		:%d\n", sizeof(*aptr));
	printf("size of float pointer derefence (*xptr)		:%d\n", sizeof(*xptr));
	printf("size of char pointer derefence (*iptr)		:%d\n", sizeof(*iptr));
	printf("size of struct employee pointer dereference	:%d\n", sizeof(*emp));
	printf("\n");
	printf("size of long int				:%d\n", sizeof(long int));
	printf("size of long long int				:%d\n", sizeof(long long int));
	//printf("size of long long long int			:%d\n", sizeof(long long long int));
	printf("size of double					:%d\n", sizeof(double));
	printf("size of long double				:%d\n", sizeof(long double));
	//printf("size of long long double			:%d\n", sizeof(long long double));



	return 0;
}


