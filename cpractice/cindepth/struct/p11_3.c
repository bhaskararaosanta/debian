/* P11.3: Array of structures */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	float marks;
};

int main()
{
	int i;
	struct student stuarr[5];
	for(i = 0; i < 5; i++) {
		printf("Enter name, rollno and marks of student[%d]:", i);
		scanf("%s%d%f", stuarr[i].name, &stuarr[i].rollno, &stuarr[i].marks);
	}

	for(i = 0; i < 5; i++) {
		printf("stu[%d] details: %s %d %.2f\n", i, stuarr[i].name, stuarr[i].rollno, stuarr[i].marks);
	}

	return 0;
}
