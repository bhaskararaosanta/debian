/* P11.5: Program to understand pointers to structures */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int marks;
};

int main()
{
	struct student stu = {"bhaskar", 40, 90};
	struct student *ptr = &stu;
	printf("Name	:%s\n", ptr->name);
	printf("rollno	:%d\n", ptr->rollno);
	printf("Marks	:%d\n", ptr->marks);

	return 0;
}
