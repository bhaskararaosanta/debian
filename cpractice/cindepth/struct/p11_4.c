/* P11.4: Program to understand arrays within structures */

#include <stdio.h>
struct student {
	char name[20];
	int rollno;
	int submarks[3];
};

int main()
{
	int i, j;
	struct student stuarr[5];
	for(i = 0; i < 5; i++) {
		printf("Enter data for student {%d]\n", i);
		printf("Enter name:");
		scanf("%s", stuarr[i].name);
		printf("Enter roll number:");
		scanf("%d", &stuarr[i].rollno);
		for(j = 0; j < 3; j++) {
			printf("Enter marks for subject[%d]:", j);
			scanf("%d", &stuarr[i].submarks[j]);
		}
	}
	for(i = 0; i < 5; i++) {
		printf("Data of student[%d]:\n", i);
		printf("Name:%s, Rollno:%d\nMarks:", stuarr[i].name, stuarr[i].rollno);
		for(j = 0; j < 3; j++) {
			printf("%d ", stuarr[i].submarks[j]);
		}
		printf("\n");
	}

	return 0;
}
