/* P11.10: Program to understand how an array of structure is sent to a function */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

void display(struct student);
void decrease_marks(struct student stuarr[]);

int main()
{
	int i;
	struct student stuarr[3] = {
					{"bhaskar", 12, 98},
				        {"great", 11, 97},
					{"good", 13, 89}
				   };
	decrease_marks(stuarr);
	for(i = 0; i < 3; i++)
		display(stuarr[i]);
	
	return 0;
}

void decrease_marks(struct student stuarr[])
{
	int i;
	for(i = 0; i < 3; i++) {
		stuarr[i].marks = stuarr[i].marks - 10;
	}
}

void display(struct student stu)
{
	printf("Name	:%7s\t", stu.name);
	printf("rollno	:%d\t", stu.rollno);
	printf("Marks	:%d\n", stu.marks);
}


