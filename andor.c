#include<stdio.h>

int main(void)
{
	int i, j;
	int x=7,y=19;
	printf("%d  %d  ",x&y,x&&y);
	printf("%d  %d  ",x|y,x||y);
	printf("%d\n",x^y);
	for(i = 0; i < 10; i++) {
		printf("1 << %d = %d\t%x\n", i, 1<<i, 1<<i);
	}
	for(i = 0; i < 10; i++) {
		printf("1 >> %d = %f\n", i, (float)(1>>i));
	}
	for(j = 0; j < 10; j++) {
		printf("1/%d = %f\n", j, (float)(1/(j+1)));
	}

	return 0;
}
