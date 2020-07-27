/* P11.7: Program to understand how a structure variable is sent to a function */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(struct student);

int main()
{
	struct student stu1 = {"Bhaskar", 12, 50};
	struct student stu2 = {"Deepak", 18, 58};
	display(stu1);
	display(stu2);

	return 0;
}

void display(struct student stu)
{
	printf("Name	:%s\n", stu.name);
	printf("rollno	:%d\n", stu.rollno);
	printf("marks	:%d\n", stu.marks);
}
