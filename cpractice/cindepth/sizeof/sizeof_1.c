#include <stdio.h>
#include <unistd.h>

void print_bits(int x)
{
	int i, mask;
        for(i = 31; i >= 0; i--) {
		mask = 0x1 << i;
		printf("%c", (x & mask) ? '1' : '0');
		if(i % 8 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	int a = 0xA;
	int b = 1;
	printf("sizeof short int	:%d\n", sizeof(short int));
	printf("sizeof 	     int	:%d\n", sizeof(int));
	printf("sizeof long  int	:%d\n", sizeof(long int));
	printf("sizeof long long int	:%d\n", sizeof(long long int));
	printf("sizeof 	     char	:%d\n", sizeof(char));
	printf("sizeof	     float	:%d\n", sizeof(float));
	printf("sizeof       double	:%d\n", sizeof(double));
	printf("sizeof long  double	:%d\n", sizeof(long double));
	
	print_bits(a);
	a |= (1UL << 2);
	print_bits(a);
	printf("\n");

	print_bits(a);
	a &= ~(1UL << 2);
	print_bits(a);
	printf("\n");

	print_bits(a);
	a ^= (1UL << 2);
	print_bits(a);
	printf("\n");

	/*unsigned char j;
	for(j = 0; j < 260; j++) {
		printf("%d ", j);
		fflush(stdout);
		if(j >= 250) {
			sleep(1);
		}
	} */

	printf("\n");

	return 0;
}
