#include <stdio.h>

#define	NUM	5
#define	ROWS	3
#define	COLS	4

int main()
{
	/* 1-Dimenstional array demonstration */
	int arr[NUM] = {11, 12, 13, 14, 15};
	int *ptrarr = arr;
	int i;
	for(i = 0; i < NUM; i++) {
		printf("addres and value of arr[%d] using array notation   = %p %d\n", i, &arr[i], arr[i]); 
		printf("addres and value of arr[%d] using pointer notation = %p %d\n", i, (arr+i), *(arr+i)); 
		printf("\n");
	}

	for(i = 0; i < NUM; i++) {
		printf("addres and value of arr[%d] using array notation   = %p %d\n", i, &ptrarr[i], ptrarr[i]); 
		printf("addres and value of arr[%d] using pointer notation = %p %d\n", i, (ptrarr+i), *(ptrarr+i)); 
		printf("\n");
	}

	//arr++;		// lvalue required error because array name is constant pointer which can't be moved
	ptrarr++;		// its pointer variable and can be moved to point next integer in the array such as arr[1]	
	printf("ptrarr pointing location of after incrementing is:%p\n", ptrarr);


	/* 2-Dimensional array demonstration */
	int twodarr[ROWS][COLS] = { {11, 12, 13, 14},
				    {21, 22, 23, 24},
				    {31, 32, 33, 34}
				  };
	int (*ptrtwodarr)[COLS] = twodarr;
	int p, q;
	for(p = 0; p < ROWS; p++) {
		for(q = 0; q < COLS; q++) {
			printf("address and value of twodarr[%d][%d] using array notation   = %p %d\n", p, q, &twodarr[p][q], twodarr[p][q]);
			printf("address and value of twodarr[%d][%d] using pointer notation = %p %d\n", p, q, (*(twodarr+p)+q), *(*(twodarr+p)+q));
			printf("\n");
		}
	}

	for(p = 0; p < ROWS; p++) {
		for(q = 0; q < COLS; q++) {
			printf("address and value of twodarr[%d][%d] using array notation   = %p %d\n", p, q, &ptrtwodarr[p][q], ptrtwodarr[p][q]);
			printf("address and value of twodarr[%d][%d] using pointer notation = %p %d\n", p, q, (*(ptrtwodarr+p)+q), *(*(ptrtwodarr+p)+q));
			printf("\n");
		}
	}

	//twodarr++;		// lvalue required error because array name is constant pointer which can't be moved
	ptrtwodarr++;		// its pointer variable and can be moved to point next integer in the array such as arr[1]	
	printf("ptrarr pointing location of after incrementing is:%p\n", ptrtwodarr);

	/* array of pointers or pointer array illustration */
	int a = 100, b = 200, c = 300, d = 400;
	int *arrofpointers[4] = {&a, &b, &c, &d};	
	printf("a, b, c, d values using array of pointers:%d %d %d %d\n", *arrofpointers[0], *arrofpointers[1], *arrofpointers[2], *arrofpointers[3]);
	int n;
	for(n = 0; n < 4; n++) {
		printf("a, b, c, d values using array of pointers:%d\n", *arrofpointers[n]);
	}
	
	for(n = 0; n < 4; n++) {
		printf("a, b, c, d values using array of pointers:%d\n", *(*(arrofpointers+n)));
	}

	printf("addresses of a, b, c, d are:%p %p %p %p\n", &a, &b, &c, &d);
	printf("addresses of a, b, c, d are:");
	for(n = 0; n < 4; n++) {
		printf("%p ", *(arrofpointers+n));
	}
	
	printf("\n");


	return 0;
}
