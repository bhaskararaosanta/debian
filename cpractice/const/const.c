#include <stdio.h>

struct student {
	int rollno;
	char name[30];
};

struct employee {
	const int empid;
	char empname[30];
};

int main()
{
	int i = 10;
	int arr[5] = {100, 200, 300, 400, 500};
	float f = 20.00;
	char c = 'a';
	struct student stu = {10, "bhaskar"};
	
	printf("normal variable - i value:%d\n", i);
	printf("normal variable - arr[0] value:%d\n", arr[0]);
	printf("normal variable - f value:%f\n", f);
	printf("normal variable - c value:%d\n", c);
	printf("normal variable - struct rollno member value:%d\n", stu.rollno);
	printf("\n");

	i++;
	//f++;	// post and pre increment and decrements can be only used with integers
	c++;
	
	const int ci = 20;
	const int carr[5] = {200, 400, 600, 800, 1000};
	const float cf = 40.00;
	const char cc = 'b';
	const struct student cstu = {40, "DONT KNOW"};

	printf("const variable - ci value:%d\n", ci);
	printf("const variable - carr[0] value:%d\n", carr[0]);
	printf("const variable - cf value:%f\n", cf);
	printf("const variable - cc value:%d\n", cc);
	printf("const variable - struct rollno member value:%d\n", cstu.rollno);

	//ci++;	// not allowed to change read-only integer
	//cf++;	// not allowed to change read-only number
	//cc++;	// not allowed to change read-only character
	//cstu.rollno++;// not allowed to change read-only integer memeber
	//carr[0]++;	// not allowed to change read-only integer

	struct employee emp = {1000, "Nanapatekar"};
	printf("const member variable - struct empid member value:%d\n", emp.empid);
	//emp.empid++;	// not allowed to change read-only integer
	emp.empname[0] = 'B';
	printf("struct member variable - struct employee name:%s\n", emp.empname);

	
	char *p = "test string";
	printf("%s\n", p);
	const char *q = "under test";
	q++;	// valid and only object pointed by q is const
	const char *const r = "ultra test";
	//r++;	// invalid because read-only pointer trying to modify

	const int j = 100;
	printf("j = %d\n", i);
	const int *x = &j;
	printf("*x = %d\n", *x);
	int k = 200;
	const int *const y = &k;
	k++;
	//y++;	// trying to modify the const pointer


	return 0;
}
