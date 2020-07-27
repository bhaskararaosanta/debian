/* P11.9: Program to understand how a structure variable is returned from a function */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(struct student);
struct student change(struct student stu);

int main()
{
	struct student stu1 = {"Bhaskar", 12, 50};
	struct student stu2 = {"Deepak", 18, 58};
	stu1 = change(stu1);
	stu2 = change(stu2);
	display(stu1);
	display(stu2);

	return 0;
}

struct student change(struct student stu)
{
	stu.marks = stu.marks + 5;
	stu.rollno = stu.rollno - 10;
	return stu;
}

void display(struct student stu)
{
	printf("Name	:%s\n", stu.name);
	printf("rollno	:%d\n", stu.rollno);
	printf("marks	:%d\n", stu.marks);
}
