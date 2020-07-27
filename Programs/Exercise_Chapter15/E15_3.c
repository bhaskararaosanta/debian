/*E15.3*/
#include<stdio.h>
struct tag
{
	auto int x;	// Can not be used auto in struct members
	static int y;	// Can not be used static in struct members
}; 
int main(void)
{
	struct tag s;
	s.x=4;
	s.y=5;
	return 0;
}
