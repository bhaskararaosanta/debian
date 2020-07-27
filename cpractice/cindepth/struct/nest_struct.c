#include <stdio.h>

struct time {
	int hr;
	int min;
	int sec;
};

struct date {
	int day;
	int month;
	int year;
	struct time t;
};

struct student {
	char name[30];
	struct date dob;
};

int main()
{
	struct student stu = {"bhaskar", {01, 07, 1983, {13, 0}}};
	//struct student stu = {"bhaskar", 01, 07, 1983, 13, 0}; /* this also works unleess all  thee members are initialized */

	printf("stu details:\n");
	printf("name:%s\n", stu.name);
	printf("date of birth:""0""%o-""0""%o-%d %d"":0""%d\n", stu.dob.day, stu.dob.month, stu.dob.year, stu.dob.t.hr, stu.dob.t.min, stu.dob.t.sec);

	return 0;
}
