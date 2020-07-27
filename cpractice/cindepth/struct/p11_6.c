/* P11.6: Program to understand how structure members are sent to a function */

#include <stdio.h>
#include <string.h>

struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(char name[], int, int);

int main()
{
	struct student stu1 = {"bhaskar", 20, 80};
	struct student stu2;
	strcpy(stu2.name, "deepak");
	stu2.rollno = 30;
	stu2.marks = 90;
	display(stu1.name, stu1.rollno, stu1.marks);
	display(stu2.name, stu2.rollno, stu2.marks);

	return 0;
}

void display(char name[], int rollno, int marks)
{
	printf("Name	:%s\n", name);
	printf("rollno	:%d\n", rollno);
	printf("marks	:%d\n", marks);
}
