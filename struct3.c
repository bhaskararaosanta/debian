#include<stdio.h>

struct student{
	char *name;
	int age;
	char *program;
	char *subjects[5];
};

int main()
{
	struct student stu = {
		"Lucy", 25, "CS", {"CS-01", "CS-02", "CS-03", "CS-04", "CS-05"}
	};
	struct student *ptr_stu = &stu;
	int i;
	printf("accessing members using structure variable:\n");
	printf("Name:%s\n", stu.name);
	printf("Age:%d\n", stu.age);
	printf("Program enrolled:%s\n", stu.program);

	for(i = 0; i < 5; i++)
	{
		printf("subject:%s\n", stu.subjects[i]);
	}
	printf("Accessing members using pointer variable:\n");
	printf("name:%s\n", ptr_stu->name);
	printf("age:%d\n", ptr_stu->age);
	printf("program enrolled:%s\n", ptr_stu->program);
	for(i = 0; i < 5; i++)
	{
		printf("subject:%s\n", ptr_stu->subjects[i]);
	}
	return 0;
}
/* How it works ?

In lines 3-8, a structure student is declared which have four members namely: name, age, program and subjects. The type of members is as follows:
Name 		Type
name 		a pointer to char
age 		int
program 	a pointer to char
subjects 	an array of 5 pointers to char

In lines 12-14, a variable stu of type struct student is declared and initialized. Since name and program are pointers to char so we can directly assign string literals to them. Similarly, subjects is an array of 5 pointers to char, so it can hold 5 string literals.

In line 15, a pointer variable ptr_stu of type struct student is declared and assigned the address of stu using & operator.

From lines 18-21, three printf() statement is used to print name, age and program using structure variable stu.

In lines 22-25, a for loop is used to loop through all the elements of an array of pointers *subjects[5]. And print the names of the subjects using structure variable.

From lines 27-29, three printf() statement is used to print name, age and program using pointer variable ptr_stu.

In lines 30-33, a for loop is used to loop through all the elements of an array of pointers *subjects[5]. And print the names of the subjects using pointer variable. */
