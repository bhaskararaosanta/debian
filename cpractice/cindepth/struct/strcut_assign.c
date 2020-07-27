#include <stdio.h>

struct student {
	char name[30];
	int rollno;
	int marks;
};

struct employee {
	char name[40];
	int empid;
	int salary;
};

void display(struct employee);

int main()
{
	struct student stu1 = {"Bhaskar", 3000, 80};
	struct student stu2;
	stu2 = stu1;	// valid
	printf("stu1:%s	%d %d\n", stu1.name, stu1.rollno, stu1.marks);
	printf("stu2:%s	%d %d\n", stu2.name, stu2.rollno, stu2.marks);

	/* the following operations on structure variables are invalid */
	//++stu1;			// invalid using unary operator
	//stu1 = stu1+1;	// invalid using arithmetic operator
	//if(stu2 > stu1) {	// invalid using relation operator
	//}
	//stu1 >> 5;		// invalid using bitwise operator

	stu1.rollno += 100;
	stu1.marks *= 2;
	stu1.marks << 3;

	stu2 = stu1;	// valid
	printf("stu1:%s	%d %d\n", stu1.name, stu1.rollno, stu1.marks);
	printf("stu2:%s	%d %d\n", stu2.name, stu2.rollno, stu2.marks);
	printf("%c\n", stu1.name[0]);

	struct employee emp = {"deepak", 1000, 600000};
	display(emp);

	return 0;
}

void display(struct employee emp)
{
	printf("emp:%s	%d %d\n", emp.name, emp.empid, emp.salary);
}
