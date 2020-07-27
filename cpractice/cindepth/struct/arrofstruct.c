#include <stdio.h>

struct student {
	char name[30];
	int rollno;
	int marks;
};

struct employee {
	char name[30];
	int accno;
	int salary[3];
};

int main()
{
	int i, j;
	struct student stuarr[3] = {
					{"bhaskar", 1000, 50},
					{"peepika", 2000, 70},
					{"peeksha", 3000, 90}
				   };

	struct employee emparr[3] = {
					{"bhaskar", 1000, {100, 200, 300}},
					{"peepika", 2000, {400, 500, 600}},
					{"peeksha", 3000, {700, 800, 900}}
				   };

	printf("printing array of structures:\n");
	for(i = 0; i < 3; i++) {
		printf("name	:%s\t", stuarr[i].name);
		printf("rollno	:%d\t", stuarr[i].rollno);
		printf("marks	:%d\n", stuarr[i].marks);
	}

	printf("printing array of structures:\n");
	for(i = 0; i < 3; i++) {
		printf("name	:%s\t", stuarr[i].name);
		printf("rollno	:%d\t", stuarr[i].rollno);
		for(j = 0; j < 3; j++) {
			printf("marks[%d]:%d\t", j, emparr[i].salary[j]);
		}
		printf("\n");
	}

	return 0;
}
