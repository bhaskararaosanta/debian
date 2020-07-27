#include <stdio.h>

int testFun1()
{
	return 1;
}

int testFun2()
{
	return 2;
}

int testFun3()
{
	return 3;
}

int testFun4()
{
	return 4;
}

// global array contain function pointers
int (*arr[4])() = {testFun1, testFun2, testFun3, testFun4};

// function return array of function pointers
int(*(*pf())[4])()
{
	// Array of function pointers
	int (*(*pfArr)[4])() = &arr;
	return (pfArr);
}

int main()
{
	int (*(*test)[4])() = pf();

	// print function return value
	printf("%d\n", (*test)[0]());
	printf("%d\n", (*test)[1]());
	printf("%d\n", (*test)[2]());
	printf("%d\n", (*test)[3]());

	return 0;
}
