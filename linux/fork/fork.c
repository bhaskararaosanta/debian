#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int i, cpid;

	/* pid_t fork(void); */
	if((cpid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		for(i = 0; i < 200; i++) {
			printf("I am in child  process running: %3d times with pid ******:%d\n", i, getpid());
			sleep(1);
		}
	}
	else {
		for(i = 0; i < 200; i++) {
			printf("I am in parent process running: %3d times with pid **    :%d\n", i, getpid());
			sleep(1);
		}
	}

	return 0;
}

