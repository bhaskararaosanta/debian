#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int i;
	time_t curtime;
	time(&curtime);
	for(i = 0; i < 60; i++)
	{
		time(&curtime);
		printf("current time is:%s", ctime(&curtime));
		sleep(2);
	}

	return 0;
}
