/*E15.12*/
#include<stdio.h>
int main(void)
{
	char str1[]="hockey";
	char str2[]="Cricket";
	char *const p=str1;
	*p='j';
	p=str2;	// This is error because changing const pointer
	return 0;
}
