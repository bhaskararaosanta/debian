#include <stdio.h>
int main()
{
	int j=10,k=12;
	printf("j = %d\tk = %d\n", j, k);
	{
		int j=20,k=22;
		printf("j = %d\tk = %d\n", j, k);
		{
			int j=30,k=32;
			//k=j;
			//j=k;
			printf("j = %d\tk = %d\n", j, k);
		}
		printf("j = %d\tk = %d\n", j, k);
	}
	printf("j = %d\tk = %d\n", j, k);
	return 0;
}
