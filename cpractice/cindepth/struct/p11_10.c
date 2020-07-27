/* P11.10: Program to understand how a pointer to structure is returned from a function */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(struct student *);
struct student *func(struct student *, struct student *);

int main()
{
	struct student *stuptr;
	struct student stu1 = {"bhaskar", 23, 78}, stu2 = {"great", 12, 89};
	stuptr = func(&stu1, &stu2);
	display(stuptr);

	return 0;
}

struct student *func(struct student *p1, struct student *p2)
{
	if(p1->marks > p2->marks) {
		return p1;
	}
	else {
		return p2;
	}
}

void display(struct student *stuptr)
{
	printf("Name	:%s\n", stuptr->name);
	printf("rollno	:%d\n", stuptr->rollno);
	printf("Marks	:%d\n", stuptr->marks);
}


