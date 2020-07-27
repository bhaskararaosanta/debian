#include <stdio.h>
#include <unistd.h>

#define	TEST

struct student {
	int rollno;
	char name[30];
	int marks;
	int subjects[5];
};


int main()
{
	int i, j;
	struct student stu2, stu1 = {100, "bhaskar", 90, {10, 20, 30, 40, 50}};
	struct student stuarray[3] = {
					{200, "ABCD", 40, {1000, 2000, 3000, 4000, 5000}},
					{300, "PQRS", 50, {10000, 20000, 30000, 40000, 50000}},
					{400, "WXYZ", 60, {100000, 200000, 300000, 400000, 500000}},
				     };

	printf("student roll no	:%d\n", stu1.rollno);
	printf("student name	:%s\n", stu1.name);
	printf("student marks	:%d\n", stu1.marks);
	for(j = 0; j < 5; j++) {
		printf("subjects[%d]	:%d\n", j, stu1.subjects[j]);
	}

	stu2 = stu1;
	printf("student roll no	:%d\n", stu2.rollno);
	printf("student name	:%s\n", stu2.name);
	printf("student marks	:%d\n", stu2.marks);
	for(j = 0; j < 5; j++) {
		printf("subjects[%d]	:%d\n", j, stu2.subjects[j]);
	}

	for(i = 0; i < 3; i++) {
		printf("student[%d] roll no	:%d\n", i, stuarray[i].rollno);
		printf("student[%d] name	:%s\n", i, stuarray[i].name);
		printf("student[%d] marks	:%d\n", i, stuarray[i].marks);
		for(j = 0; j < 5; j++) {
			printf("student[%d] subjects[%d]	:%d\n", i, j, stuarray[i].subjects[j]);
			}
	}


	struct student *ptrstu = &stu1;

	printf("student roll no	:%d\n", ptrstu->rollno);
	printf("student name	:%s\n", ptrstu->name);
	printf("student marks	:%d\n", ptrstu->marks);
#ifdef	TEST
	printf("student roll no	:%d\n", (*ptrstu).rollno);
	printf("student name	:%s\n", (*ptrstu).name);
	printf("student marks	:%d\n", (*ptrstu).marks);
#endif
	/* the following are illegal on structure variables */
	//stu1++;	// wrong type argument to increment
	//stu2 > stu1;	// invalid operands to binary operator '>'

	/* if(stu2 == stu1) { // invalid operands to binary == operator
		printf("both structures are equivalent\n");
	} */

	printf("%d\n", brk(NULL));

	return 0;
}
