#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
	int i, cpid;
	/* pid_t fork(void); */
	if((cpid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		for(i = 0; i < 50; i++) {
			printf("I am in child process running %d times with pid:%d\n", i, getpid());
			printf("I am in child process with parent pid:%d\n", getppid());
		}
	}
	else {
		for(i = 0; i < 50; i++) { 
			printf("I am in parent process running %d times with pid:%d\n", i, getpid());
			printf("I am in parent process with parent pid:%d\n", getppid());
			//sleep(1);
		}
	}
	
	return 0;
}
