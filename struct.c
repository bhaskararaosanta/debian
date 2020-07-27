#include<stdio.h>
#include<string.h>
struct address{
	char house[25];
	char city[25];
	char pincode[25];
};

struct employee{
	int id;
	char name[25];
	float salary;
	struct address add;
};

int main()
{
	int i;
	struct employee e;
	printf("enter employee id:\n");
	scanf("%d", &e.id);
	printf("enter employee name:\n");
	scanf("%s", e.name);
	printf("enter employee salary:\n");
	scanf("%f", e.salary);
	printf("enter employee house no:\n");
	scanf("%s", e.add.house);
	printf("enter employee city:\n");
	scanf("%s", e.add.city);
	printf("enter employee pincode:\n");
	scanf("%s", e.add.pincode);

	printf("Details of employees\n");
	printf("employee id:%d\n",e.id);
	printf("employee name:%s\n",e.name);
	return 0;
}



	
