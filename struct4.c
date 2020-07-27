#include <stdio.h>

struct student {
       char *name;
	int age;
 	char *program;
	char *subjects[5];
};

int main()
{
	struct student stu = {
		"Lucy", 25, "cs", {"CS-01", "CS-02", "CS-03", "CS-04", "CS-05"}};
	struct student *stu_ptr = &stu;
	int i;
	printf("Accessing members using structure variable:\n");
	printf("Name:%s\n", stu.name);
	printf("Age:%d\n", stu.age);
	printf("Program:%s\n", stu.program);
	for(i = 0; i < 5; i++) {
		printf("Subject[%d]:%s\n", i, stu.subjects[i]);
	}

	printf("Accessing members using structure pointer variable:\n");
	printf("Name:%s\n", stu_ptr->name);
	printf("Age:%d\n", stu_ptr->age);
	printf("Program:%s\n", stu_ptr->program);
	for(i = 0; i < 5; i++) {
		printf("Subject[%d]:%s\n", i, stu_ptr->subjects[i]);
	}

	return 0;
}
