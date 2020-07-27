/* P11.8: Program to understand how a pointer to a structure variable is sent to a function */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(struct student *);
void inc_marks(struct student *);

int main()
{
	struct student stu1 = {"Bhaskar", 12, 50};
	struct student stu2 = {"Deepak", 18, 58};
	inc_marks(&stu1);
	inc_marks(&stu2);
	display(&stu1);
	display(&stu2);

	return 0;
}

void inc_marks(struct student *stuptr)
{
	(stuptr->marks)++;
}

void display(struct student *stuptr)
{
	printf("Name	:%s\n", stuptr->name);
	printf("rollno	:%d\n", stuptr->rollno);
	printf("marks	:%d\n", stuptr->marks);
}
