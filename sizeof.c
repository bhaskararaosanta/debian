#include<stdio.h>
struct emp{
	int eno;
	char ename[20];
	float esal;
};
int main()
{
	char *cp;
	int *ip;
	struct emp *point;
	printf("size of char * is:%d\n",sizeof(cp));
	printf("size of int * is:%d\n",sizeof(ip));
	printf("size of struct emp * is:%d\n",sizeof(struct emp *));
	printf("size of struct emp * is:%d\n",sizeof(point));
	printf("size of char is:%d\n",sizeof(char));
	printf("size of int is:%d\n",sizeof(int));
	printf("size of struct emp is:%d\n",sizeof(struct emp));
	printf("size of struct emp is:%d\n",sizeof(point));
	printf("size of main function is:%d\n",sizeof(main()));
	return 0;
}
